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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt;
    cin >> tt;
    for (ll t = 0; t < tt; t++) {
        int n, r, s;
        cin >> n >> s >> r;
        vector<int> dice(n);
        dice[0] = s - r;
        for (int i = 1; i < n; i++) {
            int average = dice[0]*(n - i);
            if (r > average + 2) {
                dice[i] = 6;
            } else if (r > average) {
                dice[i] = dice[0] + r - average;
            } else if (r < average - 1) {
                dice[i] = 1;
            } else if (r < average){
                dice[i] = dice[0] + r - average;
            } else {
                dice[i] = dice[0];
            }
            r -= dice[i];
        }
        for (int i = 0; i < n; i++) {
            cout << dice[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
