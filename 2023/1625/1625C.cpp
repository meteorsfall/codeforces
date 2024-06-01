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

vector<ll> coords;
vector<ll> speeds;

vector<vector<vector<ll>>> memotable; //rightbound, signsremoved, endspeed

ll dp(ll rightbound, ll signsremoved, ll endspeed) {
    for (ll i = 0; i < coords.size(); i++) {
        memotable[left][right][0] = {speeds[left], speeds[left]*coords[left]};
    }
    
}

int main() {
    ll n, l, k;
    cin >> n >> l >> k;
    coords = vector<ll>(n);
    speeds = vector<ll>(n);
    for (int i = 0; i < n; i++) {
        cin >> coords[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> speeds[i];
    }

    memotable = vector<vector<vector<ll>>>(n, vector<vector<ll>>(n, vector<ll>(k)));

    return 0;
}