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
        
        ll smallest = a[n-1];
        ll big_break = 0;
        for (ll i = n-2; i >= 0; i--){
            if (a[i] > smallest){
                if (a[i] > big_break){
                    big_break = a[i];
                }
            }
            if (a[i] < smallest){
                smallest = a[i];
            }
        }

        cout << big_break << endl;

    }

    return 0;
}
