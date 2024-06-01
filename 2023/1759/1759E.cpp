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
    for (ll t = 0; t < tt; t++) {
        ll n, h;
        cin >> n >> h;
        vector<ll> astronauts;
        for (ll i = 0; i < n; i++) {
            ll a;
            cin >> a;
            astronauts.push_back(a);
        }
        sort(astronauts.begin(), astronauts.end());
        ll index = 0;
        int green = 2;
        int blue = 1;
        while (astronauts[index] == 1) {
            index++;
        }
        
        while (index < astronauts.size()) {
            if (h > astronauts[index] ) {
                h += astronauts[index]/2;
                //cout << "absorb " << astronauts[index] << " and become: " << h << endl;
            } else {
                break;
            }
            index++;
        }
        cout << index << endl;
    }
    
    return 0;
}