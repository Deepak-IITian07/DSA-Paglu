#include<iostream>
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;

class Solution {
public:
    ll power(ll base , ll exp) {
        ll res = 1;
        base %= MOD;

        while(exp > 0){
            if(exp % 2 == 1) res = res*base % MOD;
            base = (base*base) % MOD;
            exp /= 2;
        }
        return res%MOD;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    ll n , k;
    cin >> n >> k;

    ll node_below_root = 0;
    ll cur_pow_of_n = 1;
    for(int i = 1; i < k; ++i){
        cur_pow_of_n = (cur_pow_of_n*n)%(MOD-1);
        node_below_root  = (node_below_root+cur_pow_of_n) %  (MOD-1);
    }

    ll ans = (6*s.power(4 , node_below_root))%MOD;
    cout << ans;
    return 0;
};