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
    ll t, n; 
    cin >> t;
    for (auto i = 0; i < t; i++) {
        cin >> n;
        vector<ll> a(n);
        for (auto j = 0; j < n; j++) {
            cin >> a[j];        
        }
        bool success = true;
        for (auto j = n; j >= 1 && success; j--) {
            success = false;
            for (auto k = 0; k < n; k++) {
                while (a[k] > j) {
                    a[k] = a[k]/2;
                }
                if (a[k] == j) {
                    a[k] = -1;
                    success = true;
                    break;
                }
            }
        }
        if (success) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}