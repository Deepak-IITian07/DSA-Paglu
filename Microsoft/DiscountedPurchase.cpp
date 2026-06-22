#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int calculateAmount(int n ,vector<int> &arr) {
        int total = arr[0];
        int discount = arr[0];

        for(int i = 1; i < n; ++i) {
            int cost = arr[i]-discount;
            if(cost < 0) cost = 0;
            discount = min(discount , arr[i]);
            total += cost;
        }

        return total;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;

    int n = 4;
    vector<int> arr = {2 , 5 , 1 , 4};
    cout <<"toatl money invested : " << s.calculateAmount(n , arr);

    return 0;
}