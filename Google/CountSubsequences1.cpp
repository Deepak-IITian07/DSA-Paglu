/*
2. Count Subsequences
Description
You are given an array A of N integer elements.
Determine the number of non-empty subsequences of array A such that there do not exist
three consecutive even or three consecutive odd integers in the subsequence.
As the answer can be large, print it modulo 109 +7.
Notes
• Assume 1-based indexing.
• Asubsequence of array A can be obtained by deleting some array elements while keeping
the order of other elements intact.
Constraints
• 1≤T ≤10
• 1≤N ≤105
• 1≤Ai ≤109
Example
Assumptions:
• N =4
• A=[1,2,3,5]
Approach: The following subsequences satisfy the conditions:
• Length 1: {1},{2},{3},{5}
• Length 2: {1,2},{1,3},{1,5},{2,3},{2,5},{3,5}
• Length 3: {1,2,3},{1,2,5},{2,3,5}
• Length 4: {1,2,3,5}
The subsequence {1,3,5} does not satisfy the conditions as it has three consecutive odd integers.
Thus, the required answer is 14.*/

/* LEETCODE : 3686. Number of Stable Subsequences*/

// recursive solution , highly intiutive 

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countStableSubsequences(vector<int>& arr) {
        int l = -1;
        int sl = -1; 
        long long mod = 1e9 + 7;
        long long result = helper(0 , l , sl , arr); // Changed to long long
        return (result - 1 + mod) % mod;
    }
public:
    int helper(int i , int l , int sl , vector<int> &arr){
        if(i == arr.size()) return 1;

        long long mod = 1e9 + 7;
        
        // Choice 1: Don't pick (Changed to long long to prevent overflow)
        long long cnt = helper(i+1 , l , sl , arr); 

        int cur_parity = (arr[i] % 2 + 2) % 2 ;
        
        // Choice 2: Definitely pick case
        if(l != sl  || l == -1 || sl == -1 || (l == sl && l != cur_parity)){
            // This addition is now safe from overflow
            cnt = (cnt + helper(i+1 , cur_parity , l , arr)) % mod;
        }
        return cnt % mod;
    }
};

int main() {
    Solution  s;

    int N = 4;
    vector<int> A = {1 , 2 , 3 , 5};

    // soulution :
    // • Length 1: {1},{2},{3},{5}
    // • Length 2: {1,2},{1,3},{1,5},{2,3},{2,5},{3,5}
    // • Length 3: {1,2,3},{1,2,5},{2,3,5}
    // • Length 4: {1,2,3,5}  

    int ans = s.countStableSubsequences(A);
    cout << ans << endl;  // print : 14
    return 0;
}