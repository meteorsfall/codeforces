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
        vector<ll> l(n);
        for (ll i = 0; i < n; i++){
            cin >> l[i];
        }
        vector<ll> r(n);
        for (ll i = 0; i < n; i++){
            cin >> r[i];
        }
        vector<ll> c(n);
        for (ll i = 0; i < n; i++){
            cin >> c[i];
        }

        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        sort(c.begin(), c.end());
        vector<ll> lengths;
        ll start_index = 0;
        ll start_value = r[0];
        for (ll i = 1; i < n; i++){
            if (l[i] >= start_value){
                for (ll j = 0; j < i - start_index; j++){
                    lengths.push_back(r[start_index + j] - l[i - 1 - j]);
                }
                start_index = i;
                start_value = r[i];
            }
        }
        for (ll i = 0; i < n - start_index; i++){
            lengths.push_back(r[start_index + i] - l[n - 1 - i]);
        }

        /* for (ll i = 0; i < n; i++){
            cout << lengths[i] << " ";
        }
        cout << endl;
        */
        sort(lengths.begin(), lengths.end());
        ll ans = 0;
        for (ll i = 0; i < n; i++){
            ans += c[n - 1 - i]*lengths[i];
        }

        cout << ans << endl;
        
    }

    return 0;
}
