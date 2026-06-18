// probelm that was discused previously , 
// this time we come up with highly optimal solution 

// intution behind the solution :
// Instead of looking backwards at full array configurations, we only care about how many consecutive odds or evens have been picked so far up to the current index.

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countStableSubsequence(vector<int> &arr) {
        long long mod = 1e9 + 7;

        long long even1 = 0 ;   // # of subsequence ending with one even
        long long even2 = 0 ;   // # of subsequence ending with two even
        long long odd1 = 0 ;    // # of subsequence ending with one odd
        long long odd2 = 0 ;    // # of subsequence ending with two odd

        for(const int &num : arr){
            int parity = (num % 2 + 2) % 2;  // to hendal negative integers 

            if(parity == 0){
                long long next_even1 = (even1 + odd1 + odd2 + 1) % mod;
                long long next_even2 = (even1 + even2) % mod;

                even1 = next_even1;
                even2 = next_even2;
            }
            else{
                long long next_odd1 = (even1 + odd1 + even2 + 1) % mod;
                long long next_odd2 = (odd1 + odd2) % mod;

                odd1 = next_odd1;
                odd2 = next_odd2;
            }
        }

        long long total = (even1 + even2 + odd1 + odd2) % mod;
        return total;
    } 
};

int main() {
    Solution s;

    int N = 2;
    vector<int> A = {1 , 2 , 3 , 5};

    // All possible Solutions : 
    // • Length 1: {1},{2},{3},{5}
    // • Length 2: {1,2},{1,3},{1,5},{2,3},{2,5},{3,5}
    // • Length 3: {1,2,3},{1,2,5},{2,3,5}
    // • Length 4: {1,2,3,5}

    cout << s.countStableSubsequence(A);  // print 14

    return 0;
};
