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


        /*
        ll total_sum = 0;
        for (ll i = 0; i < n; i++) {
            total_sum += array[i];
        }

        ll best_val = 0;
        for (ll i = 0; i < n; i++){
            ll val = total_sum;
            if (i != 0) {
                val -= min_left_sum[i-1].first;
            }
            if (i != n-1) {
                val -= min_right_sum[i+1].first;
            }
            best_val = max(best_val, val);
        }
        */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt;
    cin >> tt;
    for (ll t = 0; t < tt; t++){
        ll n;
        cin >> n;
        vector<ll> array;
        for (ll i = 0; i < n; i++){
            ll a;
            cin >> a;
            array.push_back(a);
        }

        vector<ll> left_sum(n);
        left_sum[0] = array[0];
        vector<ll> right_sum(n);
        right_sum[n-1] = array[n-1];
        for (ll i = 1; i < n; i++){
            left_sum[i] = left_sum[i-1] + array[i];
        }
        for (ll i = n-2; i >= 0; i--){
            right_sum[i] = right_sum[i+1] + array[i];
        }

        vector<pair<ll, ll>> min_left_sum(n);
        min_left_sum[0] = {left_sum[0], 0};
        for (ll i = 1; i < n; i++) {
            if (left_sum[i] < min_left_sum[i-1].first) {
                min_left_sum[i] = {left_sum[i], i};
            } else {
                min_left_sum[i] = min_left_sum[i-1];
            }
        }
        vector<pair<ll, ll>> min_right_sum(n);
        min_right_sum[n-1] = {right_sum[n-1], n-1};
        for (ll i = n-2; i >= 0; i--){
            if (right_sum[i] < min_right_sum[i+1].first) {
                min_right_sum[i] = {right_sum[i], i};
            } else {
                min_right_sum[i] = min_right_sum[i+1];
            }
        }

        // Above is correct

        
    }

    return 0;
}
