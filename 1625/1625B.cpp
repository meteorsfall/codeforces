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
        int n;
        cin >> n;
        vector<vector<int>> coordinates(150001);
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            coordinates[a].push_back(i);
        }

        int mindiff = n;
        int particletype = -1;
        for (int i = 0; i < coordinates.size(); i++) {
            for (int j = 0; j + 1 < coordinates[i].size(); j++) {
                int diff = coordinates[i][j + 1] - coordinates[i][j];
                if (diff < mindiff) {
                    mindiff = diff;
                    particletype = i;
                }
            }
        }

        if (mindiff == n) {
            cout << -1 << endl;
        } else {
            cout << n - mindiff << endl;
        }
    }
    return 0;
}