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
        k--;

        vector<ll> fib_a = {1,1};
        vector<ll> fib_c = {0,1};
        for (ll i = 0; i < 100000; i++){
            fib_a.push_back(fib_a[i] + fib_a[i+1]);
            fib_c.push_back(fib_c[i] + fib_c[i+1]);
            if (fib_c[i] > 200000){
                break;
            }
        }

        /*for (ll i = 0; i < 10; i++){
            cout << fib_a[i] << " ";
        }
        cout << endl;
        for (ll i = 0; i < 10; i++){
            cout << fib_c[i] << " ";
        }
        cout << endl; */


        if (n == 0){
            cout << 1 << endl;
        } else if (k >= fib_c.size()){
            cout << 0 << endl;
        } else {
            // cout << "fib_a[k]: " << fib_a[k] << ", fib_c[k]: " << fib_c[k] << endl;
            ll sequence_count = 0;
            for (ll i = 0; i <= n/fib_a[k]; i++){
                if ( (n - fib_a[k]*i) % fib_c[k] == 0 ){
                    sequence_count++;
                }
            }
            cout << sequence_count << endl;
        }

    }

    return 0;
}
