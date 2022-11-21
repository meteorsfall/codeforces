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
        int n;
        cin >> n;
        ll sum = 0;
        map<ll,ll> freq;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            sum += a;
            freq[a]++;
        }
        if( (sum*2) % n != 0){
            cout << 0 << endl;
            continue;
        }
        ll ans = 0;
        for(auto& elem : freq){
            ll u = elem.first;
            ll v = sum*2/n - u;
            if(u > v || !freq.count(v) ){
                continue;
            }
            if(u == v){
                ans += elem.second*(elem.second - 1)/2;
            } else {
                ans += elem.second*freq[v];
            }
        }
        cout << ans << endl;
    }

    return 0;
}