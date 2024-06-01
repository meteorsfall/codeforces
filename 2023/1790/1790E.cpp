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
        ll x;
        cin >> x;

        vector<bool> bin_x(32);
        vector<bool> bin_half_x(32);
        ll half_x = x/2;
        if (x % 2 == 1) {
            half_x++;
        }

        for(int i = 0; i < 32; i++){
            if ((x >> i) & 1) {
                bin_x[i] = true;
            } 
            if ((half_x >> i) & 1) {
                bin_half_x[i] = true;
            }
        }

        bool possible = true;
        for (ll i = 0; i < 32; i++){
            if (bin_half_x[i] && bin_x[i]) {
                possible = false;
            }
        }

        vector<bool> bin_a(32);
        vector<bool> bin_b(32);
        for (ll i = 0; i < 32; i++){
            if (bin_x[i]) {
                bin_a[i] = true;
            } else if (bin_half_x[i]) {
                bin_a[i] = true;
                bin_b[i] = true;
            } 
        }

        ll a = 0, b = 0;
        for (ll i = 0; i < 32; i++){
            a += bin_a[i] << i;
            b += bin_b[i] << i;
        }

        if (possible){
            cout << a << " " << b << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
