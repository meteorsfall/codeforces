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
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> not_friends(n);
        for (ll i = 0; i < m; i++) {
            ll a, b;
            cin >> a >> b;
            if (a > b) {
                swap(a, b);
            }
            not_friends[a-1].push_back(b-1);
        }
        for (ll i = 0; i < n; i++) {
            sort((not_friends[i]).begin(), (not_friends[i]).end());
        }
        ll sum_good = n;
        ll start = 0;
        ll prev_end = -1;
        ll alter_start = -1;
        while (start < n - 1) {
            alter_start = -1;
            ll end = n - 1;
            if (not_friends[start].size() != 0) {
                end = not_friends[start][0] - 1;
            }
            for (ll j = start + 1; j < end; j++) {
                if (not_friends[j].size() != 0) {
                    if (not_friends[j][0] < end) {
                        end = not_friends[j][0] - 1;
                        alter_start = j;
                    }
                }
            }

            sum_good += (end - start + 1)*(end - start)/2;
            if (prev_end > start){
                sum_good -= (prev_end - start + 1)*(prev_end - start)/2;
            }
            //cout << "start: " << start << ", end: " << end << endl;
            if (alter_start != -1) {
                start = alter_start + 1;
            } else {
                start = 
            }
            start = j + 1;
        }
        cout << sum_good << endl;
    }

    return 0;
}
