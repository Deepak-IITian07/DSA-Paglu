#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
private:
    vector<long long> all_spns;

    void generateAllSPNs() {
        // try all possible subsets of digit using bit mask from 1 to 511
        for(int mask = 1; mask < 1<<10; ++mask){
            int odd_count = 0;
            int total_length = 0;

            vector<int> digit_subset;
            for(int d = 1; d <= 9; ++d){
                if(mask & (1 << d)){
                    if(d % 2 != 0) odd_count++;
                    total_length += d;
                    digit_subset.push_back(d);
                }
            }

            // remember subset must have to follow :
            // because of length constraint & must have at most one odd
            if(digit_subset.empty()) continue;  // to handle 0000000001
            if(total_length > 18 || odd_count > 1) continue;

            string left_half = "";
            string middle = "";

            for(int d : digit_subset){
                int half_freq = d/2; // frequency is half in left part of pelindrome
                left_half.append(half_freq , '0'+d);
                if(d % 2 != 0){
                    middle.append(1, '0'+d);
                }
            }

            // sort the left to prepare next permutation
            sort(left_half.begin() , left_half.end());

            // now prepare all permutation using c++ 
            // do while loop process => first do business then compare . repeat...
            do{
                string right_half = left_half;
                reverse(right_half.begin() , right_half.end());

                string full_pelindrome = left_half + middle + right_half;

                all_spns.push_back(stoll(full_pelindrome));
            }while(next_permutation(left_half.begin() , left_half.end()));
        }
        // sort all spetial pelindrome number (SPN) array to apply binary search for each query with nextGreater function
        sort(all_spns.begin() , all_spns.end());
    }

public:
    Solution() {
        generateAllSPNs();
    }

    long long nextGreater(long long N) {
        // C++ upper_bound finds the first stricly greater than N [using binary search]
        auto it  = upper_bound(all_spns.begin() , all_spns.end() , N);
        if(it != all_spns.end()){
            return *it;
        }
        return -1;  // if not fin greater then return -1 
    }
};

int main() {
    // Optimize standard I/O operations for high-performance competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;

    int T = 5;
    vector<long long> query = {2 , 22 , 224523 , 3493898202803 , 100000000000000000};

    for(long long q : query){
        cout << q << " =>   " << s.nextGreater(q) << endl;
    }
    return 0;
};