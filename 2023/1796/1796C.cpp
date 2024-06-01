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

ll two_power(ll l, ll r){
    ll ans = 0;
    while (l <= r) {
        ans++;
        l *= 2;
    }
    return ans;
}

ll shifted(ll a, ll times){
    return a * (1 << times - 1);
}

ll find_mid(ll l, ll r, ll times) {
    return r/ (1 << (times - 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt;
    cin >> tt;
    for (ll t = 0; t < tt; t++){
        ll l, r;
        cin >> l >> r;

        ll times = two_power(l, r);
        ll mid = find_mid(l, r, times);
        //cout << "mid: " << mid << endl;
        ll running_sum = mid - l + 1;
        if (r == 1) {
            cout << 1 << " " << 1 << endl;
            continue;
        }

        if (shifted(l, times) * 3/2 <= r){
            ll mid = find_mid(l, r*2/3, times);
            //cout << "mid: " << mid << endl;
            running_sum += (mid - l + 1)*(times - 1) ;
        }
        cout << times << " " << running_sum << endl;

    }

    return 0;
}
