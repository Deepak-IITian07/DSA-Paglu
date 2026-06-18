/*
1. Sort the Array
Description
You are given an integer array A of size N containing only 1, 2, and 3. You are also given an
integer Q and a 2D array of queries.
You have to answer Q queries:
• For the ith query, perform A[queries[i][0]] = queries[i][1] and determine the minimum
number of swaps required to sort the array in non-decreasing order.
Task
For each query, determine the minimum swaps required to sort the array in non-decreasing order.
Note: Array A and queries follow 0-based indexing.
Example
Assumptions:
• N =5
• A=[1,2,3,1,2]
• Q=2
• queries = [[1,3],[3,3]]
Approach:
1. After the first update (A[1] = 3), the array A becomes [1, 3, 3, 1, 2].
• Swap indices 1 and 3.
• Swap indices 2 and 4.
The minimum swaps required would be 2.
2. After the second update, the array A becomes [1, 3, 3, 3, 2].
• Swap indices 1 and 4.
The minimum swaps required is 1.
*/

/*
LEETCODE : 75. Sort Colors
*/

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getMinSwap(vector<int> &arr , int c1 , int c2 , int c3) {
        int n = arr.size();
        // find mismatch count
        int m12 = 0 , m13 = 0;
        int m21 = 0 , m23 = 0;
        int m31 = 0 , m32 = 0;

        for(int i = 0; i < n; ++i){
            // mismatch M[i][j] means frequency of element i in jth zone
            // zone borders - 1st [0 to c1-1] , 2nd [c1 to c1+c2-1] and 3rd [c1+c2 to N-1]
            if(i < c1){
                if(arr[i] == 2) m21++;
                else if(arr[i] == 3) m31++;
            }
            else if(i < c1+c2){
                if(arr[i] == 1) m12++;
                else if(arr[i] == 3) m32++;
            }
            else{
                if(arr[i] == 1) m13++;
                else if(arr[i] == 2) m23++;
            }
        }

        // direct match
        int direct_12 = min(m12 , m21);
        int direct_13 = min(m13 , m31);
        int direct_23 = min(m23 , m32);

        int swaps = direct_12 + direct_13 + direct_23;

        // cycleic swap 3 type , total mismatch - direct swaps*2
        int total_mismatch = m12 + m21 + m23 + m32 + m13 + m31;
        int direct_swaps = swaps;

        int cycles_mismatch = total_mismatch - 2 * direct_swaps;

        swaps += (cycles_mismatch/3)*2;

        return swaps;
    }
public:
    void sortArray(vector<int> &arr , vector<vector<int>> &query) {
        int q = query.size();
        int n = arr.size();
        vector<int> res(q , n);

        int c1 = 0, c2 = 0, c3 = 0;

        for(int i = 0; i < n; ++i){
            if(arr[i] == 1) c1++;
            else if(arr[i] == 2) c2++;
            else c3++;
        }

        for(int i = 0; i < q; ++i){
            int ind = query[i][0];
            int val = query[i][1];

            // decrement old value frequency
            if(arr[ind] == 1) c1--;
            else if(arr[ind] == 2) c2--;
            else if(arr[ind] == 3) c3--;

            // update the value
            arr[ind] = val;

            // increment new value frequency
            if(arr[ind] == 1) c1++;
            else if(arr[ind] == 2) c2++;
            else if(arr[ind] == 3) c3++;

            int swaps = getMinSwap(arr , c1 , c2 , c3);
            res[i] = swaps;
        }

        for(int i = 0; i < q; ++i){
            cout << res[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution s;

    vector<int> nums = {1, 2, 3, 1, 2};
    vector<vector<int>> query = {{1,3},{3,3}};

    s.sortArray(nums , query);
    return 0;
};



