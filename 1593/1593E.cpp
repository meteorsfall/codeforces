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

int main() {
    int t;
    cin >> t;
    for(int tt = 0; tt < t; tt++) {
        int n, k;
        cin >> n >> k;
        vector<set<int>> tree(n);
        for(int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            tree[u].insert(v);
            tree[v].insert(u);
        }
        vector<int> leaves;
        for(int i = 0; i < n; i++) {
            if(tree[i].size() <= 1) {
                leaves.push_back(i);
            }
        }
        int totalsum = 0;
        for(int i = 0; i < k && leaves.size() > 0; i++) {
            totalsum += leaves.size();
            vector<int> newleaves;
            for(int leaf : leaves) {
                if(tree[leaf].size() == 1) {
                    int parent = *tree[leaf].begin();
                    set<int>& parentsneighbors = tree[parent];
                    for(int w : parentsneighbors) {
                        if(w == leaf) {
                            parentsneighbors.erase(w);
                            break;
                        }
                    }
                    if(parentsneighbors.size() == 1) {
                        newleaves.push_back(parent);
                    }
                }
            }
            leaves = newleaves;
        }
        cout << n - totalsum << endl;
    }
    
    return 0;
}