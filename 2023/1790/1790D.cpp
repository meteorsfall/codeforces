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
        vector<ll> dolls(n);
        for (ll i = 0; i < n; i++){
            ll a;
            cin >> a;
            dolls[i] = a;
        }

        sort(dolls.begin(), dolls.end());
        vector<pair<ll, ll>> buckets;
        for (ll i = 0; i < dolls.size(); i++){
            if (buckets.size() > 0 && dolls[i] == buckets[buckets.size() - 1].first) {
                buckets[buckets.size() - 1].second++;
            } else {
                buckets.push_back({dolls[i], 1});
            }
        }
        /*cout << "bucket: ";
        for (ll i = 0; i < buckets.size(); i++){
            cout << "{" << buckets[i].first << ", " << buckets[i].second << "}, ";
        } */

        ll dead = 0;
        for (ll i = 1; i < buckets.size(); i++){
            if ( buckets[i].first == buckets[i - 1].first + 1){
                if (buckets[i-1].second > buckets[i].second){
                    dead += buckets[i-1].second - buckets[i].second;
                } 
            } else {
                dead += buckets[i-1].second;
            }
        }
        cout << dead + buckets[buckets.size() - 1].second << endl;
    }

    return 0;
}
