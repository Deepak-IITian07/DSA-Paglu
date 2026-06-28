#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int PalinderomeSubsequence(string &s ,int n){
        /* string only contains '0'  and '1'
            - so all possible pairs are 00 , 01 , 10 ,  11 
            - we look for pair on left then find image pair on right 
            - multiply right_pair to left_pair to get # of palindrome
        */

        long long MOD = 1e9 + 7;
        long long rightPair[2][2] = {};
        long long rightCnt[2] = {};

        long long leftPair[2][2] = {};
        long long leftCnt[2] = {};

        for(char &ch : s){
            rightCnt[ch-'0']++;
        }
        for(char &ch : s){
            int x = ch-'0';
            rightCnt[x]--;
            for(int j = 0 ; j < 2; ++j){
                rightPair[x][j] += rightCnt[j];
            }
        }
        rightCnt[0] = rightCnt[1] = 0;
        for(char &ch : s){
            rightCnt[ch-'0']++;
        }
        
        long long ans = 0;
        for(int i = 0; i < n; ++i){
            int x = s[i]-'0';

            // remove current form right
            rightCnt[x]--;
            for(int j = 0; j < 2 ;++j){
                rightPair[x][j] -= rightCnt[j];
            }

            // count palindrom centered at this location
            for(int a = 0; a < 2; ++a){
                for(int b = 0; b < 2; ++b){
                    ans = (ans + leftPair[a][b] * rightPair[b][a]) % MOD;
                }
            }

            for(int j = 0; j < 2; ++j){
                leftPair[j][x] += leftCnt[j];
            }
            leftCnt[x]++;
        }
        return (int)ans;
    }

};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    string s = "0100110";
    int n = s.length();

    cout << sol.PalinderomeSubsequence(s , n);

    return 0;
};