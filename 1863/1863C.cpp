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
        ll n, k;
        cin >> n >> k;
        vector<ll> numbers(n);
        for (ll i = 0; i < n; i++){
            cin >> numbers[i];
        }

        k = k % (n + 1);
        vector<ll> done(n, -1);
        set<ll> present;
        for (ll i = 0; i < n; i++){
            present.insert(numbers[i]);
        }
        ll missing = -1;
        for (ll i = 0; i <= n; i++){
            if (present.count(i) == 0){
                missing = i;
                break;
            }
        }
        if (k != 0){
            done[k - 1] = missing;
        }
        
        for (ll i = 0; i < n; i++){
            ll new_i = (i + k) % (n + 1);
            if (new_i != n){
                done[new_i] = numbers[i];
            }
        }

        for (ll i = 0; i < n; i++){
            cout << done[i] << " ";
        }
        cout << endl;

    }

    return 0;
}
