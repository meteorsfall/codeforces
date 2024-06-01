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
        ll n, k;
        cin >> n >> k;
        vector<ll> colors(n);
        for (ll i = 0; i < n; i++){
            cin >> colors[i];
        }

        ll start_color = colors[0];
        ll end_color = colors[n-1];
        ll start_color_count = 0;
        ll end_color_count = 0;
        ll left_index = -1;
        ll right_index = -1;
        for (ll i = 0; i < n; i++){
            if (colors[i] == start_color){
                start_color_count++;
                if (start_color_count == k){
                    left_index = i;
                    break;
                }
            }
        }
        for (ll i = n-1; i >= 0; i--){
            if (colors[i] == end_color){
                end_color_count++;
                if (end_color_count == k){
                    right_index = i;
                    break;
                }
            }
        }
        if (left_index != -1 && right_index != -1 && left_index < right_index){
            cout << "YES" << endl;
        } else if (left_index != -1 && start_color == end_color){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
