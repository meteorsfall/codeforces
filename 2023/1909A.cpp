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
        ll n;
        cin >> n;
        vector<pair<ll, ll>> points(n);
        for (ll i = 0; i < n; i++){
            ll a, b;
            cin >> a >> b;
            points[i] = {a, b};
        }

        vector<bool> dir(4, false);
        //u, r, d, l
        for (ll i = 0; i < n; i++){
            ll x = points[i].first;
            ll y = points[i].second;
            if (x > 0){
                dir[1] = true;
            } 
            if (x < 0){
                dir[3] = true;
            }
            if (y > 0){
                dir[0] = true;
            }
            if (y < 0){
                dir[2] = true;
            }
        }

        bool success = true;
        if (dir[0] && dir[1] && dir[2] && dir[3]){
            success = false;
        }

        if (success){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
