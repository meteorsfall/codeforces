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
    for (ll t = 0; t < tt; t++) {
        ll n;
        cin >> n;
        vector<ll> numbers;
        for (ll i = 0; i < n; i++){
            ll a;
            cin >> a;
            numbers.push_back(a);
        }
        sort(numbers.begin(), numbers.end());
        if (numbers[n-1] == numbers[0]) {
            cout << n*(n-1) << endl;
        } else {
            ll first_same = 1;
            ll last_same = 1;
            for (ll j = 1; j < n-1; j++) {
                if (numbers[j] == numbers[0]) {
                    first_same++;
                }
                if (numbers[j] == numbers[n-1]) {
                    last_same++;
                }
            }
            cout << 2*first_same*last_same << endl;
            
        }
    }

    return 0;
}
