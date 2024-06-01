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
    for (ll i = 0; i < tt; i++){
        ll n, k, g;
        cin >> n >> k >> g;
        ll newk = k;
        if (newk > n){
            newk = n;
        }
        //s = silvercount
        ll s = newk*g;
        ll half = (g/2) - 1;
        ll fullcount;
        if (half*n >= s){
            fullcount = s;
        } else {
            fullcount = ceil((s - n*half)/(float)(g - half));
            if ((s - n*half) % (g - half) == 0){
                fullcount = (s - n*half)/(g - half);
            }
        }
        cout << "fullcount; " << fullcount << endl;
        cout << s - fullcount*g << endl;
    }

    return 0;
}
