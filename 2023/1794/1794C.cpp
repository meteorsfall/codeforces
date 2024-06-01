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
        ll n;
        cin >> n;
        vector<ll> seq;
        for (ll i = 0; i < n; i++){
            ll a;
            cin >> a;
            seq.push_back(a);
        }

        ll left_index = 0;
        ll product = 1;
        for (ll i = 0; i < n; i++){
            for (ll j = left_index; j < i; j++){
                if (seq[j] < i - j + 1){
                    product /= seq[j];
                    product *= i - j;
                    left_index++;
                } else {
                    break;
                }
            }
            product *= seq[i];
            product /= i - left_index + 1;
            cout << i - left_index + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}
