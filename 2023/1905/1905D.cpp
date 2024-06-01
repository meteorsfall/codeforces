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
        vector<ll> arr(n);
        ll zero_loc = -1;
        for (ll i = 0; i < n; i++){
            ll a;
            cin >> a;
            arr[i] = a;
            if (a == 0){
                zero_loc = i;
            }
        }

        vector<ll> working(n);
        for (ll i = 0; i < n; i++){
            working[i] = arr[(i + zero_loc) % n];
        }
        vector<ll> mex(n);
        set<ll> seen;
        ll cur_mex = 0;
        map<ll, ll> freq;
        for (ll i = 0; i < n - 1; i++){
            seen.insert(working[i]);
            while(seen.count(cur_mex) != 0){
                cur_mex++;
            }
            mex[i] = cur_mex;
            freq[cur_mex]++;
        }

        ll sum = 0;
        for (ll i = 0; i < mex.size(); i++){
            sum += mex[i];
        }
        vector<ll> cycles(n);
        cycles[0] = sum;
        cout << "sum: " << sum << endl;
        for (ll i = 1; i < cycles.size(); i++){
            ll gone = working[working.size() - i];
            freq[gone]--;
            sum -= gone;
            ll new_first = working[working.size() - i];
            ll first_count = freq[new_first];
            sum += first_count;jjkj
            freq[new_first] = 0;
            freq[new_first + 1] += first_count;
            cycles[i] = sum;
        }

        for (ll i = 0; i < n; i++){
            cout << cycles[i] << " ";
        }
        cout << endl; 

        ll biggest_sum = 0;
        for (ll i = 0; i < n; i++){
            biggest_sum = max(biggest_sum, cycles[i]);
        }

        cout << biggest_sum + n << endl;

    }

    return 0;
}
