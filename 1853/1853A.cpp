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

        bool sorted = true;
        for (ll i = 1; i < n; i++){
            if (a[i] < a[i-1]){
                sorted = false;
                break;
            }
        }
        if (sorted == false){
            cout << 0 << endl;
        } else {
            ll min_distance = a[1] - a[0];
            for (ll i = 1; i < n; i++){
                ll diff = a[i] - a[i-1];
                if (diff < min_distance){
                    min_distance = diff;
                }
            }
            cout << min_distance/2 + 1 << endl;
        }
    }

    return 0;
}
