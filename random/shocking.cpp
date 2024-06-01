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
        for (ll i = 0; i < n; i++){
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());
        if (arr[0] >= 0 || arr[n-1] <= 0){
            cout << "No" << endl;
            continue;
        }

        ll neg_begin = 0;
        ll neg_end;
        ll pos_begin;
        ll pos_end = n-1;
        for (ll i = 0; i < n; i++){
            if (arr[i] >= 0){
                neg_end = i-1;
                pos_begin = i;
                break;
            }
        }

        vector<ll> ans(n);
        ans[0] = arr[neg_begin];
        neg_begin++;
        ans[1] = arr[pos_end];
        pos_end--;
        ll sum = ans[0] + ans[1];
        ll index = 2;
        //cout << "pos_begin: " << pos_begin << " ";
        while (neg_begin <= neg_end && pos_begin <= pos_end && index < n){
            if (sum >= 0){
                ans[index] = arr[neg_begin];
                neg_begin++;
            } else {
                ans[index] = arr[pos_end];
                pos_end--;
            }
            sum += ans[index];
            index++;
        }
        for (ll i = neg_begin; i <= neg_end; i++){
            ans[index] = arr[i];
            index++;
        }
        for (ll i = pos_begin; i <= pos_end; i++){
            ans[index] = arr[i];
            index++;
        }

        bool possible = true;
        ll least = 0;
        ll greatest = 0;
        ll limit = abs(arr.back() - arr[0]);
        for (ll i = 0; i < n; i++){
            vector<ll> entry = {least + ans[i], greatest + ans[i], ans[i]};
            sort(entry.begin(), entry.end());
            least = entry[0];
            greatest = entry.back();
            if (abs(least) >= limit || greatest >= limit){
                //cout << "i: " << i << ", least: " << least << ", greatest: " << greatest << endl;
                possible = false;
                break;
            }
        }

        if (!possible){
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
            for (ll i = 0; i < n; i++){
                cout << ans[i] << " ";
            }
            cout << endl;
        }

    }

    return 0;
}
