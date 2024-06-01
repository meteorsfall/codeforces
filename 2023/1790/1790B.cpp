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
        int n, s, r;
        cin >> n >> s >> r;
        vector<int> dice(n);
        dice[0] = s - r;
        int max = s - r;
        
        int difference = (n - 1)*max - r;
        for (int i = 1; i < n; i++) {
            if (difference >= max) {
                dice[i] = 1;
                difference -= max - 1;
            } else if (difference > 0) {
                dice[i] = max - difference;
                difference = 0;
            } else {
                dice[i] = max;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << dice[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
