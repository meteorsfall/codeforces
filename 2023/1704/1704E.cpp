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

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        int n, m;
        cin >> n >> m;
        vector<ll> vertices;
        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            vertices.push_back(a);
        }
        vector<pair<int, int>> edges;
        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            edges.push_back({x,y});
        }
        
    }
    
    return 0;
}