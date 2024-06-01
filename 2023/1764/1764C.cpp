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

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++){
        ll n;
        cin >> n;
        vector<ll> altitudes;
        for (int i = 0; i < n; i++){
            ll a;
            cin >> a;
            altitudes.push_back(a);
        }

        sort(altitudes.begin(), altitudes.end());
        vector<pair<ll, ll>> amounts;
        ll running_counter = 0;
        for (int i = 1; i < n; i++){
            if (altitudes[i] != altitudes[i-1]) {
                amounts.push_back({altitudes[i-1], i - running_counter});
                running_counter = i;
            }
        }
        if (amounts[amounts.size() - 1].first != altitudes[n-1] ) {
            amounts.push_back({altitudes[n-1], 1});
        } else {
            amounts[amounts.size() - 1].second++;
        }
        


    }

    return 0;
}
