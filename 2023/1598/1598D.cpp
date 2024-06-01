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
    int t;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        ll n;
        cin >> n;
        map<ll, ll> topic_freq;
        map<ll, ll> difficulty_freq;
        vector<pair<ll, ll>> problem(n);
        ll ans = 0;
        for(int i = 0; i < n; i++){
            ll a, b;
            cin >> a >> b;
            topic_freq[a]++;
            difficulty_freq[b]++;
            problem[i] = {a,b};
        }
        for(int i = 0; i < n; i++){
            ans += (topic_freq[problem[i].first] - 1)*(difficulty_freq[problem[i].second] - 1);
        }
        cout << n*(n-1)*(n-2)/6 - ans << endl;
    }
    
    return 0;
}