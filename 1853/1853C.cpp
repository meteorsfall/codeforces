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

ll find_a_index(vector<ll>& a, ll l, ll r, ll x, ll max_index)
{
    if (r >= l) {
        ll mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (a[mid] == x){
            // cout << "find_a_index: " << mid << " ";
            return mid;
        }
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (a[mid] > x){
            return find_a_index(a, l, mid - 1, x, max_index);
        }
        // Else the element can only be present
        // in right subarray
        if (mid > max_index){
            max_index = mid;
        }
        return find_a_index(a, mid + 1, r, x, max_index);
    }
 
    // We reach here when element is not
    // present in array
    return max_index;
}
 

ll is_smallest(vector<ll>& a, ll guess, ll iteration, ll k){
    ll a_index = find_a_index(a, 0, a.size() - 1, guess, -1);
    if (a_index + 1 >= guess){
        // guess too small
        return -1;
    }
    if (a[a_index] == guess){
        // includes itself
        return 1;
    }
    cout << "a_index: " << a_index << ", ";
    ll temp_guess = guess - (a_index + 1);
    if (temp_guess == 1 && iteration == k){
        return 0;
    }
    if (iteration > k || (iteration >= k && temp_guess > 1)){
        // guess too big
        return 1;
    }
    // return is_smallest(a, temp_guess, iteration + 1, k, a_index);
    return is_smallest(a, temp_guess, iteration + 1, k);
}

ll bin_search_smallest(vector<ll>& a, ll k, ll l, ll r){
    if (r >= l) {
        ll mid = l + (r - l) / 2;
        // cout << "mid: " << mid << endl;
        ll result = is_smallest(a, mid, 1, k);
        // If the element is present at the middle
        // itself
        if (result == 0){
            return mid;
        }
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (result == 1)
            return bin_search_smallest(a, k, l, mid - 1);
 
        // Else the element can only be present
        // in right subarray
        return bin_search_smallest(a, k, mid + 1, r);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt;
    cin >> tt;
    for (ll t = 0; t < tt; t++){
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++){
            cin >> a[i];
        }

        // cout << bin_search_smallest(a, k, 1, 10'000'000'000LL) << endl;
        // cout << find_a_index(a, 0, a.size() - 1, 12, -1) << endl;
        cout << is_smallest(a, 8, 1, k) << endl;
        // cout << bin_search_smallest(a, k, 1, 100);
    }

    return 0;
}
