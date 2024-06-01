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
        ll n, m;
        cin >> n >> m;
        vector<ll> numbers;
        for (ll i = 0; i < n; i++) {
            ll a;
            cin >> a;
            numbers.push_back(a);
        }
        vector<vector<pair<ll, ll>>> diff(n);
        for (ll i = 1; i < m + 1; i++){
            ll a, b;
            cin >> a >> b;
            a--;
            if (diff[a].size() > 0 && diff[a][diff[a].size() - 1].second != b){
                diff[a].push_back({i, b});
            }
        }
        ll running_sum = (m + 1)*m/2*n;
        for (ll i = 0; i < n; i++){
            vector<ll> changes;
            for (ll j = 0; j < diff[i].size()) {
                changes.push_back()
            }
            ll temp_sum = (m + 1)*m/2;
            if (diff[i].size() > 0) {
                vector<ll> changes;
                
            }
        }
    }

    return 0;
}
