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
    ll t, a, b, c, ab, bc, ac;
    cin >> t;
    for (auto i = 0; i < t; i++) {
        cin >> a >> b >> c;
        ab = b - a;
        bc = c - b;
        ac = c - a;
        if ( (b + ab) % c == 0 && (b + ab) / c > 0
            || (b - bc) % a == 0 && (b - bc) / a > 0
            || ac % 2 == 0 && (a + ac/2) % b == 0 && (a + ac/2) / b > 0 ) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}