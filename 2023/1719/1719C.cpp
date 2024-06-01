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
        ll n, q;
        cin >> n >> q;
        vector<ll> athletes;
        for (ll j = 0; j < n; j++) {
            ll a;
            cin >> a;
            athletes.push_back(a);
        }

        vector<ll> fought_athletes(n, 0);
        ll winner = athletes[0];
        ll winner_index = 0;
        for (ll j = 1; j < n; j++){
            if (athletes[j] > winner) {
                fought_athletes[j]++;
                winner = athletes[j];
                winner_index = j;
            } else {
                fought_athletes[winner_index]++;
            }
        }
        fought_athletes.push_back(winner);
        for (ll j = 0; j < q; j++) {
            ll i, k;
            cin >> i >> k;
            i--;
            if (i == winner_index && k > n - 1) {
                cout << k - (n - 1) + fought_athletes[winner_index] << endl;
            } else if (i == 0) {
                if (k <= fought_athletes[0]) {
                    cout << k << endl;
                } else {
                    cout << fought_athletes[0] << endl;
                }
            } else {
                if (k < i) {
                    cout << 0 << endl;
                } else if (k <= (i - 1) + fought_athletes[i]) {
                    cout << k - (i - 1) << endl;
                } else {
                    cout << fought_athletes[i] << endl;
                }
            }
        }
    }

    return 0;
}
