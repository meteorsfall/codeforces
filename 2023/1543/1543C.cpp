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
typedef long double real;
#define PI 3.14159265358979323846
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL

real v;

real expected(real c, real m) {
    real newc, newm;
    if (c == 0.0) {
        newc = 0.0;
    } else {
        real maxc = max(c-v, 0.0L);
        if(maxc < 1e-14){maxc = 0;}
        real ism = 0;
        if(m > 0) {ism = 1;}
        newc = expected(maxc, m + ism*(c-maxc)/2);
    }
    if (m == 0.0) {
        newm = 0.0;
    } else {
        real maxm = max(m-v, 0.0L);
        if(maxm < 1e-14){maxm = 0;}
        real isc = 0;
        if(c > 0) {isc = 1;}
        newm = expected(c + isc*(m-maxm)/2, maxm);
    }
    return c*newc + m*newm + 1;
}

int main() {
    int T;
    real c, m, p;
    cin >> T;
    cout.precision(10);
    for(int test = 0; test < T; test++) {
        cin >> c >> m >> p >> v;
        cout << expected(c, m) << endl;
    }
    return 0;
}