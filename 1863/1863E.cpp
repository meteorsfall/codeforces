#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <ctime>
#include <stdio.h>      /* printf */
#include <stdlib.h>
#include <queue>

#ifdef SHOW_DEBUG
#define dbg(a, ...) printf("DEBUG: " a "\n", ##__VA_ARGS__)
#else
#define dbg(...) ((void*)(0))
#endif

using namespace std;
typedef long long ll;
template<typename A, typename B>
using hmap = unordered_map<A, B>;
typedef tuple<int, int> ii;
typedef tuple<ll, ll> lii;
#define PI 3.14159265358979323846
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL

void dfs_search(ll a, set<ll>& dependency_chain, vector<ll>& dependency_chain_index, vector<vector<ll>> dependency_list, vector<vector<ll>> dependency_list_index){
    for (ll i = 0; i < dependency_list[a].size(); i++){
        ll b = dependency_list[a][i];
        if (dependency_chain.count(b) == 0){
            dependency_chain.insert(b);
            dependency_chain_index.push_back(dependency_list_index[a][i]);
            dfs_search(b, dependency_chain, dependency_chain_index, dependency_list, dependency_list_index);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt;
    cin >> tt;
    for (ll t = 0; t < tt; t++){
        ll n, m, k;
        cin >> n >> m >> k;
        vector<ll> hours(n);
        for (ll i = 0; i < n; i++){
            cin >> hours[i];
        }
        vector<pair<ll, ll>> dependencies(m);
        for (ll i = 0; i < m; i++){
            ll a, b;
            cin >> a >> b;
            dependencies.push_back({a, b});
        }

        vector<vector<ll>> dependency_list(n);
        vector<vector<ll>> dependency_list_index(n);
        for (ll i = 0; i < m; i++){
            ll a = dependencies[i].first;
            ll b = dependencies[i].second;
            dependency_list[a].push_back(b);
            dependency_list_index[a].push_back(i);
            dependency_list[b].push_back(a);
            dependency_list_index[b].push_back(i);
        }

        set<ll> total_inclusions;
        vector<set<ll>> dependency_inclusions;
        vector<vector<ll>> dependency_inclusions_index;
        for (ll i = 0; i < m; i++){
            ll a = dependencies[i].first;
            ll b = dependencies[i].second;
            if (total_inclusions.count(a) == 0){
                set<ll> dependency_chain;
                vector<ll> dependency_chain_index;
                dependency_chain.insert(a);
                dfs_search(a, dependency_chain, dependency_chain_index, dependency_list, dependency_list_index);
                dependency_inclusions.push_back(dependency_chain);
                dependency_inclusions_index.push_back(dependency_chain_index);
                for (ll elem : dependency_chain){
                    total_inclusions.insert(elem);
                }
            }
        }
        for (ll i = 0; i < dependency_inclusions.size(); i++){
            vector<ll>& indexes = dependency_inclusions_index[i];
            sort(indexes.begin(), indexes.end());
            vector<ll> unique_indexes(1, indexes[0]);
            for (ll j = 1; j < indexes.size(); j++){
                if (indexes[j] != indexes[j-1]){
                    unique_indexes.push_back(indexes[j]);
                }
            }
            
        }

    }

    return 0;
}
