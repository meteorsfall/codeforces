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

void traverse(vector<vector<ll>>& edges, vector<bool>& leaves, ll node, ll parent){
    for (ll i = 0; i < edges[node].size(); i++){
        ll child = edges[node][i];
        if (child != parent){
            if (edges[child].size() == 1){
                leaves[child] = true;
            } else {
                traverse(edges, leaves, child, node);
            }          
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt;
    cin >> tt;
    for (ll t = 0; t < tt; t++){
        ll n;
        cin >> n;
        
        vector<vector<ll>> edges(n);
        for (ll i = 0; i < n - 1; i++){
            ll u, v;
            cin >> u >> v;
            u--; v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        vector<bool> leaves(n, false);
        ll root = -1;
        for (ll i = 0; i < n; i++){
            if (edges[i].size() > 1){
                root = i;
                break;
            }
        }
        if (root == -1){
            cout << 1 << endl;
            continue;
        }
        traverse(edges, leaves, root, -1);
        ll leaf_count = 0;
        for (ll i = 0; i < n; i++){
            if (leaves[i]){
                leaf_count++;
            }
        }
        ll ans = leaf_count/2;
        if (leaf_count % 2 != 0){
            ans++;
        }

        cout << ans << endl;

    }

    return 0;
}
