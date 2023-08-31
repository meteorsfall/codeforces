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
    for (ll i = 0; i < tt; i++){
        ll q;
        cin >> q;
        vector<ll> arr(q);
        for (ll j = 0; j < q; j++){
            cin >> arr[j];
        }
        
        vector<ll> ans(q, 0);
        ans[0] = 1;
        bool has_moved = false;
        ll latest = arr[0];
        for (ll j = 1; j < q; j++){
            if (!has_moved){
                if (arr[j] >= latest){
                    ans[j] = 1;
                    latest = arr[j];
                } else {
                    if (arr[j] <= arr[0]){
                        has_moved = true;
                        latest = arr[j];
                        ans[j] = 1;
                    }
                }
            } else {
                if (arr[j] >= latest && arr[j] <= arr[0]){
                    ans[j] = 1;
                    latest = arr[j];
                }
            }
        }

        for (ll j = 0; j < q; j++){
            cout << ans[j];
        }
        cout << endl;

    }

    return 0;
}
