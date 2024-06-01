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
        vector<ll> prefix_sum(n-1);
        for (ll i = 0; i < n-1; i++){
            cin >> prefix_sum[i];
        }

        vector<ll> diff(n-1);
        diff[0] = prefix_sum[0];
        for (ll i = 1; i < n-1; i++){
            diff[i] = prefix_sum[i] - prefix_sum[i-1];
        }
        sort(diff.begin(), diff.end());

        ll repeated = -1;
        bool repetitive = false;
        bool success = true;
        ll num_missing_numbers = 0;
        ll sum_of_missing_numbers = 0;
        ll sum_without_last = 0;
        ll num_without_last = 0;
        
        for (ll i = 1; i < n-1; i++){
            if (diff[i] == diff[i-1]){
                if (repetitive == true){
                    success = false;
                    break;
                } else {
                    repetitive = true;
                    repeated = diff[i];
                }
            }
            if (diff[i] > diff[i-1] + 1){
                num_missing_numbers += diff[i] - diff[i-1] - 1;
                sum_of_missing_numbers += diff[i] - 1;
                
                if (diff[i] - 2 > diff[i-1]){
                    sum_of_missing_numbers += diff[i] - 2;
                }
                if (i != n-2){
                    sum_without_last += diff[i] - 1;
                    if (diff[i] - 2 > diff[i-1]){
                        sum_without_last += diff[i] - 2;
                    }
                    num_without_last += diff[i] - diff[i-1] - 1;
                }
                if (num_without_last > 2){
                    success = false;
                }
            }
        }

        if (!success){
            cout << "NO" << endl;
            continue;
        }

        bool final_success = false;
        if (num_missing_numbers == 0 && repetitive == false && (diff[0] == 1 || diff[0] == 2)){
            final_success = true;
        } else if (repetitive == true){
            if (num_missing_numbers == 2 && repeated == sum_of_missing_numbers && diff[0] == 2){
                final_success = true;
            } else if (num_missing_numbers == 1 && (repeated - sum_of_missing_numbers == diff[0] - 1) && diff[0] == 2 ){
                final_success = true; 
            } else if ( (num_missing_numbers == 0) && (repeated == diff[0] - 1 + diff[0] - 2) && diff[0] == 3 ){
                final_success = true;
            }
        } else if (num_without_last == 0){
            if ((diff[n-2] == diff[0] - 1 + diff[0] - 2) && diff[0] == 3 ){
                final_success = true;
            } else if ((diff[n-2] == diff[0] - 1 + diff[n-3] + 1) && diff[0] == 2){
                final_success = true;
            } else if (diff[n-2] == diff[n-3] + 1 + diff[n-3] + 2 && diff[0] == 1){
                final_success = true;
            }
        } else if (num_without_last == 1 ){
            if ((diff[n-2] == sum_without_last + diff[0] - 1) && diff[0] == 2 ){
            final_success = true;
            } else if (diff[n-2] == sum_without_last + diff[n-3] + 1 && diff[0] == 1){
                final_success = true;
            } 
        } else if (num_without_last == 2) {
            if (sum_without_last == diff[n-2] && diff[0] == 1){
                final_success = true;
            }
        } 

        if (final_success){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
