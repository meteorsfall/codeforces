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
        
        vector<vector<pair<int, int>>> adjacencylist(n);
        for (int i = 0; i < m; i++) {
            int v, u, w;
            cin >> v >> u >> w;
            u--, v--;
            adjacencylist[v].push_back({u, w});
            adjacencylist[u].push_back({v, w});
        }

        int answer = 0;
        for (int bit = 31; bit >= 0; bit--) {
            int current_ority = answer | ((1 << bit) - 1);

            vector<bool> visited(n, false);
            vector<int> queue;
            queue.push_back(0);
            while (!queue.empty()) {
                int vertex = queue.back();
                queue.pop_back();
                if (visited[vertex]) {
                    continue;
                }

                for (auto& edge : adjacencylist[vertex]) {
                    if (!visited[edge.first] && (edge.second | current_ority) == current_ority ) {
                        queue.push_back(edge.first);
                    }
                }

                visited[vertex] = true;
            }

            bool istree = true;
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    istree = false;
                }
            }

            if (!istree) {
                answer |= 1 << bit;
            }
        }

        cout << answer << endl;
    }
    return 0;
}