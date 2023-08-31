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
        ll n, q;
        cin >> n >> q;
        vector<ll> numbers;
        for (ll i = 0; i < n; i++){
            ll a;
            cin >> a;
            numbers.push_back(a);
        }
        ll even_sum = 0, even_count = 0;
        ll odd_sum = 0, odd_count = 0;
        for (ll i = 0; i < n; i++){
            if (numbers[i] % 2 == 0) {
                even_count++;
                even_sum += numbers[i];
            } else {
                odd_count++;
                odd_sum += numbers[i];
            }
        }
        vector<pair<int, ll>> queries;
        for (ll i = 0; i < q; i++){
            ll a, b;
            cin >> a >> b;
            queries.push_back({a, b});
        }
        for (ll i = 0; i < q; i++){
            if (queries[i].first == 0 && queries[i].second % 2 == 0) {
                even_sum += queries[i].second*even_count;
            } else if (queries[i].first == 0 && queries[i].second % 2 == 1) {
                //adding odd to even numbers
                odd_sum += queries[i].second*even_count + even_sum;
                odd_count += even_count;
                even_sum = 0;
                even_count = 0;
            } else if (queries[i].first == 1 && queries[i].second % 2 == 0) {
                odd_sum += queries[i].second*odd_count;
            } else {
                even_sum += queries[i].second*odd_count + odd_sum;
                even_count += odd_count;
                odd_sum = 0;
                odd_count = 0;
            }
            cout << odd_sum + even_sum << endl;
        }
    }

    return 0;
}
