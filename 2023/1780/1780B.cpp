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
#include <numeric>

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
        vector<ll> array_a;
        for (ll i = 0; i < n; i++){
            ll a;
            cin >> a;
            array_a.push_back(a);
        }
        vector<ll> prefix_sum(n);
        prefix_sum[0] = array_a[0];
        for (ll i = 1; i < n; i++){
            prefix_sum[i] = prefix_sum[i-1] + array_a[i];
            // cout << i << ": " << prefix_sum[i] << " ";
        }
        // cout << endl;
        ll greatest_gcd = 1;
        for (ll i = 0; i < n - 1; i++){
            ll the_gcd = gcd(prefix_sum[n-1] - prefix_sum[i], prefix_sum[i]);
            if (the_gcd > greatest_gcd) {
                greatest_gcd = the_gcd;
            }
        }
        cout << greatest_gcd << endl;
    }

    return 0;
}
