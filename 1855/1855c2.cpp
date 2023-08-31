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
        vector<ll> a(n);
        for (ll i = 0; i < n; i++){
            cin >> a[i];
        }

        ll pos_count = 0;
        ll neg_count = 0;
        ll max_neg = 0;
        ll max_pos = 0;
        ll neg_index = -1;
        ll pos_index = -1;
        for (ll i = 0; i < n; i++){
            if (a[i] > 0){
                pos_count++;
            } else if (a[i] < 0){
                neg_count++;
            }
            if (a[i] > max_pos){
                max_pos = a[i];
                pos_index = i;
            }
            if (a[i] < max_neg){
                max_neg = a[i];
                neg_index = i;
            }
        }
        
        vector<pair<ll, ll>> ops;
        if (max_pos == 0 && max_neg == 0){
            cout << 0 << endl;
            continue;
        } else if (max_pos >= abs(max_neg)){
            if (pos_count >= 8 || neg_count <= 12){
                for (ll i = 0; i < n; i++){
                    if (a[i] < 0){
                        ops.push_back({i, pos_index});
                    }
                }
                for (ll i = 1; i < n; i++){
                    ops.push_back({i, i-1});
                }
            } else {
                for (ll i = 0; i < 5; i++){
                    ops.push_back({neg_index, neg_index});
                }
                ops.push_back({n-2, neg_index});
                if (a[n-2] > 0){
                    ops.push_back({n-2, neg_index});
                }
                for (ll i = n-3; i >= 0; i--){
                    ops.push_back({i, i+1});
                    if (a[i] > 0){
                        ops.push_back({i, i+1});
                    }
                }
            }
        } else {
            if (neg_count >= 8 || pos_count <= 12){
                for (ll i = 0; i < n; i++){
                    if (a[i] > 0){
                        ops.push_back({i, neg_index});
                    }
                }
                for (ll i = n-2; i >= 0; i--){
                    ops.push_back({i, i+1});
                }
            } else {
                for (ll i = 0; i < 5; i++){
                    ops.push_back({pos_index, pos_index});
                }
                ops.push_back({1, pos_index});
                if (a[1] < 0){
                    ops.push_back({1, pos_index});
                }
                for (ll i = 2; i < n; i++){
                    ops.push_back({i, i-1});
                    if (a[i] < 0){
                        ops.push_back({i, i-1});
                    }
                }
            }
        }

        cout << ops.size() << endl;
        for (ll i = 0; i < ops.size(); i++){
            cout << ops[i].first + 1 << " "  << ops[i].second + 1 << endl;
        }

    }

    return 0;
}
