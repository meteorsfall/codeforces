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

vector<ll> run_dp(vector<ll>& arr, ll sum){
    vector<ll> cur_dp(sum + 1, -1);
    for (ll i = 0; i <= sum; i++){
        cur_dp[i] = i;
        if (arr[0] <= i){
            cur_dp[i] -= arr[0];
        }
    }
    vector<ll> past_dp(sum + 1, -1);
    
    for (ll i = 1; i < arr.size(); i++){
        for (ll j = 0; j <= sum; j++){
            past_dp[j] = cur_dp[j];
        }
        for (ll j = 0; j <= sum; j++){
            cur_dp[j] = past_dp[j];
            if (j >= arr[i]){
                cur_dp[j] = min(past_dp[j - arr[i]], cur_dp[j]);
            }
        }
    }
    return cur_dp;
}

bool good_time(vector<ll>& arr, vector<ll>& dp, ll w, ll f, ll sum, ll t){
    ll smaller = min(w, f);
    ll total = smaller*t;
    if (total >= sum) {
        return true;
    }
    ll val = dp[total];
    ll margin = (w+f)*t - sum;
    return val <= margin;
}

ll ug_bin_time(vector<ll>& arr, vector<ll>& dp, ll w, ll f, ll sum, ll l, ll r){
    if (r < l){
        return -1;
    }
    ll mid = (l + r)/2;
    bool val = good_time(arr, dp, w, f, sum, mid);
    if (val){
        ll left_side = ug_bin_time(arr, dp, w, f, sum, l, mid-1);
        if (left_side != -1){
            return left_side;
        } else {
            return mid;
        }
    } else {
        return ug_bin_time(arr, dp, w, f, sum, mid+1, r);
    }
    
}

ll bin_time(vector<ll>& arr, vector<ll>& dp, ll w, ll f, ll sum, ll lo, ll hi){
    ll ans = -1;
    while(lo <= hi) {
        ll mid = (lo+hi)/2;
        bool works = good_time(arr, dp, w, f, sum, mid);
        if (works) {
            ans = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }
    return ans;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt;
    cin >> tt;
    for (ll t = 0; t < tt; t++){
        ll w, f;
        cin >> w >> f;
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        ll sum = 0;
        for (ll i = 0; i < n; i++){
            sum += arr[i];
        }

        ll per_second = w + f;
        ll min_time = sum/(w + f);
        if ((sum % (w + f)) != 0){
            min_time++;
        }
        ll max_time = sum/max(w, f) + 1;

        vector<ll> dp = run_dp(arr, sum);
        ll ans = bin_time(arr, dp, w, f, sum, min_time, max_time);
        cout << ans << endl;

    }

    return 0;
}
