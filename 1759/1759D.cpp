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
    for (ll t = 0; t < tt; t++){
        ll n, m;
        cin >> n >> m;
        ll nprime = n;
        ll increase = 1;
        while (nprime % 10 == 0) {
            nprime /= 10;
        }
        int factortwo = 0;
        int factorfive = 0;
        while (nprime % 2 == 0) {
            nprime /= 2;
            factortwo++;
            if (increase*5 < m){
                increase *= 5;
                //cout << "increase *5: " << increase << endl;
            }
        } 
        while (nprime % 5 == 0) {
            nprime /= 5;
            factorfive++;
            if (increase*2 < m) {
                increase *= 2;
                //cout << "increase *2: " << increase << endl;
            }
        }
        while (10*increase <= m) {
            increase *= 10;
            //cout << "increase *10: " << increase << endl;
        }
        if (2*increase <= m) {
            //cout << "increase multiple: " << m/increase << endl;
            increase = (m/increase) * increase;
        }
        cout << n*increase << endl;
    }
    
    return 0;
}