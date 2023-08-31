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

vector<pair<ll, ll>> prime_factor(ll a) {
    vector<pair<ll, ll>> factors;
    ll temp_a = a;
    for (ll i = 2; i*i <= a; i++){
        if (temp_a % i == 0){
            int count = 0;
            while (temp_a % i == 0) {
                count++;
                temp_a = temp_a/i;
            }
            factors.push_back({i, count});
        }
        if (temp_a == 1){
            break;
        }
    }
    if (temp_a > 1) {
        factors.push_back({temp_a, 1});
    }
    return factors;
}

vector<pair<ll, ll>> shared_factor(ll& a, vector<pair<ll, ll>> factors) {
    for (ll i = 0; i < factors.size(); i++){
        while (a % factors[i].first == 0 && factors[i].second > 0) {
            a = a / factors[i].first;
            factors[i].second--;
        }
    }
    return factors;
}

ll multiply_out(vector<pair<ll, ll>> factors) {
    ll a = 1;
    for (ll i = 0; i < factors.size(); i++){
        while(factors[i].second > 0){
            a *= factors[i].first;
            factors[i].second--;
        }
    }
    return a;
}

void print_factors(vector<pair<ll, ll>> factors) {
    cout << "factors: ";
    for (ll i = 0; i < factors.size(); i++){
        cout << "(" << factors[i].first << ", " << factors[i].second << "), ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt;
    cin >> tt;
    for (ll t = 0; t < tt; t++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        vector<pair<ll, ll>> factors = prime_factor(a*b);
        //cout << "prime a ";
        //print_factors(factor_a);

        bool success = false;
        for (ll i = a + 1; i <= c; i++){
            ll x = i;
            //cout << "x: " << x << endl;
            vector<pair<ll, ll>> temp_factor_a = shared_factor(x, factors);
            //print_factors(temp_factor_a);
            ll y = multiply_out(temp_factor_a);
            ll new_y = (d/y)*y;
            if (new_y > b) {
                

                cout << i << " " << new_y << endl;
                success = true;
                break;
            }
        }

        if (!success){
            cout << -1 << " " << -1 << endl;
        }

    }

    return 0;
}
