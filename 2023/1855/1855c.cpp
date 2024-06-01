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
        vector<ll> a(n);
        for (ll i = 0; i < n; i++){
            cin >> a[i];
        }

        vector<pair<ll, ll>> ops;
        ll index = -1;
        bool positive = false;
        for (ll i = 0; i < n; i++){
            if (a[i] > 0){
                index = i;
                positive = true;
                break;
            } else if (a[i] < 0){
                index = i;
                positive = false;
                break;
            }
        }
        if (index == -1){
            cout << 0 << endl;
            continue;
        }
        index++;
        if (positive){
            for (ll i = 0; i < 6; i++){
                ops.push_back({index, index});
            }
            ops.push_back({n, index});
            ops.push_back({n, index});
            for (ll i = 2; i < n; i++){
                ops.push_back({i, n});
                ops.push_back({n, n});
            }
        } else {
            for (ll i = 0; i < 6; i++){
                ops.push_back({index, index});
                }
                ops.push_back({1, index});
                ops.push_back({1, index});
                for (ll i = n - 1; i > 1; i--){
                    ops.push_back({i, 1});
                    ops.push_back({1, 1});
                }
        }
        
        cout << ops.size() << endl;
        for (ll i = 0; i < ops.size(); i++){
            cout << ops[i].first << " "  << ops[i].second << endl;
        }

    }

    return 0;
}
