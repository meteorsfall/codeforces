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
    ll t; 
    cin >> t;
    for (auto i = 0; i < t; i++) {
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<int> freq(26, 0);
        for (ll j = 0; j < n; j++) {
            freq[s[j] - 'a']++;
        }

        ll pairs = 0;
        ll singles = 0;
        for (int j = 0; j < 26; j++) {
            pairs += freq[j] / 2;
            singles += freq[j] % 2;
        }

        ll numpairsinbucket = pairs/k;
        ll numunusedpairs = pairs % k;
        singles += numunusedpairs*2;

        cout << numpairsinbucket*2 + min(1LL, singles/k) << endl;
    }
    return 0;
}
