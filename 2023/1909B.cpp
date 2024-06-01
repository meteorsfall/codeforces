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

ll two_pow(ll a){
    ll ans = 1;
    while(a > 0){
        ans *= 2;
        a--;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt;
    cin >> tt;
    for (ll t = 0; t < tt; t++){
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        ll two = 68;
        for (ll i = 0; i < n; i++){
            ll a = arr[i];
            ll temp_two = 0;
            while(a % 2 == 0){
                a /= 2;
                temp_two++;
            }
            two = min(two, temp_two);
        }

        ll ans = two_pow(two + 1);
        cout << ans << endl;

    }

    return 0;
}
