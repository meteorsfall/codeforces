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


ll factor(ll a) {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    for (int t = 0; t < tt; t++){
        ll n, x;
        cin >> n >> x;
        vector<ll> funny;
        for (int i = 0; i < n; i++){
            funny.push_back(i+1);
        }
        funny[0] = x;
        funny[n-1] = 1;
        if (n % x == 0) {
            funny[x - 1] = n;
            
            for (int i = 0; i < n - 1; i++) {
                cout << funny[i] << " ";
            }
            cout << funny[n-1] << endl;
        } else {
            cout << -1;
        }
    }

    return 0;
}
