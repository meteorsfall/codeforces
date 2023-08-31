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
        int n;
        cin >> n;
        vector<int> robots(n);
        int max = 0;
        for (ll j = 0; j < n; j++){
            int a;
            cin >> a;
            robots[j] = a;
            if (a > max){
                max = a;
            }
        }

        vector<int> count(max + 1);
        for (ll j = 0; j < n; j++){
            count[robots[j]]++;
        }
        bool success = true;
        for (ll j = 1; j <= max; j++){
            if (count[j] > count[j-1]){
                success = false;
            }
        }
        if (success){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
