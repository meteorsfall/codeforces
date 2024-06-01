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
        ll n, m;
        cin >> n >> m;
        m--;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        ll ops = 0;
        if (arr[m] > 0 && n != 1 && m != 0){
            arr[m] *= -1;
            ops++;
        }

        vector<ll> sum_arr(n);
        sum_arr[0] = arr[0];
        for (ll i = 1; i < n; i++){
            sum_arr[i] = sum_arr[i-1] + arr[i];
        }
        ll comp = sum_arr[m];
        map<ll, ll> positives;
        for (ll i = m - 1; i >= 0; i--){
            while (sum_arr[i] < comp){
                auto it = positives.end();
                it--;
                auto pair = (*it);
                ll key = pair.first;
                comp -= 2*key;
                positives[key]--;
                if (positives[key] <= 0){
                    positives.erase(key);
                }
                ops++;
            } 
            if (arr[i] > 0){
                positives[arr[i]]++;
            }
        }

        map<ll, ll> negatives;
        ll sum = 0;
        for (ll i = m+1; i < n; i++){
            sum += arr[i];
            if (arr[i] < 0){
                negatives[arr[i]]++;
            }
            while (sum < 0){
                auto it = negatives.begin();
                auto pair = (*it);
                ll key = pair.first;
                sum -= 2*key;
                negatives[key]--;
                if (negatives[key] <= 0){
                    negatives.erase(key);
                }
                ops++;
            }
        }

        cout << ops << endl;

    }

    return 0;
}
