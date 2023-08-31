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
        int n;
        cin >> n;
        vector<ll> odds(3);
        vector<ll> evens(2);
        int odds_count = 0;
        int evens_count = 0;
        for (int i = 1; i < n + 1; i++){
            ll a;
            cin >> a;
            if ((a % 2 == 1) && (odds_count < 3) ) {
                odds[odds_count] = i;
                odds_count++;
            } else if ( (a % 2 == 0) && (evens_count < 2)) {
                evens[evens_count] = i;
                evens_count++;
            }
        }
        if (odds_count == 3){
            cout << "YES" << endl << odds[0] << " " << odds[1] << " " << odds[2] << endl;
        } else if (evens_count == 2 && odds_count >= 1) {
            cout << "YES" << endl << odds[0] << " " << evens[0] << " " << evens[1] << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
