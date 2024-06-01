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
        vector<ll> monster_health(n);
        for (ll i = 0; i < n; i++){
            cin >> monster_health[i];
        }

        vector<pair<ll, ll>> modded(n);
        for (ll i = 0; i < n; i++){
            modded[i] = {monster_health[i] % k, -1*i};
            if (modded[i].first == 0){
                modded[i].first = k;
            }
        }

        sort(modded.begin(), modded.end(), greater<pair<ll, ll>>());

        for (ll i = 0; i < n; i++){
            cout << (-1*modded[i].second) + 1 << " ";
        }
        cout << endl;

    }

    return 0;
}
