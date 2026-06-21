#include<iostream>
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
class Solution {
public:
    bool isPossible(ll max_cap , vector<ll> &gifts ,ll total_win) {
        ll win_needed = 0;

        for(auto gift : gifts){
            /*The minimum number of winners needed to distribute these Q gifts without anyone exceeding X capacity is ceil of [Q / X]*/
            win_needed += (gift+max_cap-1)/max_cap;
            if(win_needed > total_win){
                return false;
            }
        }
        return win_needed <= total_win;
    }

    void minScamScore(ll N , vector<ll> &gifts) {
        ll low = 1;
        ll high = 0;
        for(ll it : gifts){
            high = max(high , it);
        }

        ll ans = high;
        while(low <= high){
            ll mid = low + (high-low)/2;

            if(isPossible(mid , gifts , N)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        cout <<"min possible max score is : " << ans << endl;
    }
};

/* We want to find the minimum possible maximum gifts any winner receives. This minimax structure screams Binary Search on Answer. */
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;

    int N = 7;
    vector<ll> gifts = {7,1,7,4,4};

    s.minScamScore(N , gifts);

    return 0;
};


