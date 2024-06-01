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
    
    ll tt; 
    cin >> tt;
    for (int t = 0; t < tt; t++) {
        ll l, r, x, a, b;
        cin >> l >> r >> x >> a >> b;
        int steps = -1;
        if (a == b) {
            steps = 0;
        } else if (abs(a - b) >= x ) {
            steps = 1;
        } else if ( (r - a >= x && r - b >= x )
                || (a - l >= x && b - l >= x) ) {
            steps = 2;
        } else if ( (r - a >= x && b - x >= l )
                || (a - l >= x && b + x <= r) ){
            steps = 3;
        }
        cout << steps << endl;
    }
    
    return 0;
}