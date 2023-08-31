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
        ll k, n;
        cin >> n >> k;
        vector<ll> colors(n);
        for (ll i = 0; i < n; i++){
            ll a;
            cin >> a;
            colors[i] = a - 1;
            //cout << colors[i] << " ";
        }
        //cout << endl;

        vector<ll> recent(k, -1);
        vector<ll> longest(k, 0);
        vector<ll> second_longest(k, 0);
        for (ll i = 0; i < n; i++){
            ll cur_color = colors[i];
            ll length = i - recent[cur_color] - 1;
            recent[cur_color] = i;
             if (length > second_longest[cur_color] ){
                if (length > longest[cur_color]){
                    second_longest[cur_color] = longest[cur_color];
                    longest[cur_color] = length;
                } else {
                    second_longest[cur_color] = length;
                }
                //cout << "cur_color: " << cur_color << ", new longest: " << length << " , second longest: " << second_longest[cur_color] << endl;
            }
        }

        //back_loop
        for (ll i = 0; i < k; i++){
            ll cur_color = i;
            ll length = n - recent[cur_color] - 1;
            if (length > second_longest[cur_color] ){
                if (length > longest[cur_color]){
                    second_longest[cur_color] = longest[cur_color];
                    longest[cur_color] = length;
                } else {
                    second_longest[cur_color] = length;
                }
                //cout << "cur_color: " << cur_color << ", new longest: " << length << " , second longest: " << second_longest[cur_color] << endl;
            }
        }

        ll min_planks = 200000;
        for (ll i = 0; i < k; i++){
            ll num_planks = max(longest[i]/2, second_longest[i]);
            if (num_planks <= min_planks){
                min_planks = num_planks;
            } 
        }

        cout << min_planks << endl;

    }

    return 0;
}
