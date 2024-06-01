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
    for (ll t = 0; t < tt; t++){
        ll n, k;
        cin >> n >> k;
        if (k % 2 == 1) {
            cout << "YES" << endl;
            for (ll i = 0; i < n/4; i++){
                cout << 4*i + 1 << " " << 4*i + 4 << endl;
                cout << 4*i + 3 << " " << 4*i + 2 << endl;
            }
            if (n % 4 == 2) {
                cout << n - 1 << " " << n << endl;
            }
        } else if (k % 4 == 2) {
            cout << "YES" << endl;
            for (ll i = 0; i < n/4; i++){
                cout << 4*i + 1 << " " << 4*i + 4 << endl;
                cout << 4*i + 2 << " " << 4*i + 3 << endl;
            }
            if (n % 4 == 2) {
                cout << n  << " " << n - 1 << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
