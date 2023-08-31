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
        vector<ll> numbers;
        for (ll i = 0; i < n; i++){
            ll a;
            cin >> a;
            numbers.push_back(a);
        }

        ll num_two = 0;
        for (ll i = 0; i < n; i++){
            while (numbers[i] % 2 == 0){
                num_two++;
                numbers[i] = numbers[i]/2;
            }
        }
        vector<ll> pow_two(n, 0);
        for (ll i = 1; i <= n; i++){
            ll j = i;
            while (j % 2 == 0) {
                pow_two[i - 1]++;
                j = j/2;
            }
        }
        sort(pow_two.begin(), pow_two.end());
        ll two_count = 0;
        for (ll i = n - 1; i >= 0; i--){
            if (num_two >= n){
                break;
            }
            num_two += pow_two[i];
            two_count++;
        }
        if (num_two < n) {
            cout << -1 << endl;
        } else {
            cout << two_count << endl;
        }

    }

    return 0;
}
