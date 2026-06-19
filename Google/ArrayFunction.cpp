#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(int i ,vector<vector<int>> &adj,vector<bool> &vis, vector<int> &A , vector<int> &indexs , vector<int> &values) {
        vis[i] = true;
        indexs.push_back(i);
        values.push_back(A[i]);

        for(int neighbour : adj[i]){
            if(!vis[neighbour]){
                dfs(neighbour , adj , vis , A , indexs , values);
            }
        }
    }
public:
    long long ArrayFunction(int N ,vector<int> &A ,int M, vector<pair<int,int>> &B) {
        vector<vector<int>> adj(N+1);
        for(auto edge : B){
            adj[edge.first].push_back(edge.second);
            adj[edge.second].push_back(edge.first);
        }
        
        vector<bool> vis(N+1 , false);
        long long total_max_sum = 0;
        for(int i = 1; i <= N; ++i){
            if(!vis[i]){
                vector<int> component_indexs;
                vector<int> component_values;

                dfs(i , adj ,vis , A , component_indexs , component_values);

                sort(component_values.begin() , component_values.end() , greater<int>());

                int odd_count = 0 , even_count = 0;
                for(const int ind : component_indexs){
                    if(ind%2 != 0) odd_count++;
                    else even_count++;
                }

                int val_ind = 0;
                for(int j = 0; j < odd_count; ++j){
                    total_max_sum += component_values[val_ind++];
                }
                for(int j = 0; j < even_count; ++j){
                    total_max_sum -= component_values[val_ind++];
                }
            }
        }
        cout << total_max_sum;
        return total_max_sum;
    }
};

int main() {
    // Optimize standard I/O operations for high-performance competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution s;
    int N = 4;
    vector<int> A = {0,3,2,7,5,2};
    int M = 2;
    vector<pair<int,int>> B = {{1,3},{3,4}};

    cout << "Array function output is : " << s.ArrayFunction(N , A , M ,B);
    return 0;
};

// time complexity : O(M + N)