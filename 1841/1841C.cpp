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

vector<char> digits = {'A', 'B', 'C', 'D', 'E'};

ll val(char a){
    int ans = 1;
    for (int i = 0; i < digits.size(); i++){
        if (a == digits[i]) {
            for (int j = 1; j <= i; j++){
                ans *= 10;
            }
        }
    }
    return ans;
}

ll count_string(string s){
    ll sum = 0;
    for (int i = 0; i < s.size(); i++){
        sum += val(s[i]);
    }
    return sum;
}

ll count_ranom(string s){
    ll sum = 0; 
    ll biggest = 0;
    for (int i = s.size() - 1; i >= 0; i--){
        ll value = val(s[i]);
        if (value < biggest) {
            sum -= value;
        } else {
            sum += value;
            biggest = value; 
        }
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt;
    cin >> tt;
    for (ll i = 0; i < tt; i++){
        string s;
        cin >> s;

        if (s.size() == 1){
            cout << 10000 << endl;
            continue;
        }

        vector<ll> right_sum(s.size());
        vector<ll> right_high(s.size());
        ll last_index = s.size() - 1;
        right_sum[last_index] = val(s[last_index]);
        right_high[last_index] = val(s[last_index]);
        for (ll j = s.size() - 2; j >= 0; j--){
            if (val(s[j]) >= right_high[j+1]){
                right_sum[j] = right_sum[j+1] + val(s[j]);
                right_high[j] = val(s[j]);
            } else {
                right_sum[j] = right_sum[j+1] - val(s[j]);
            }
        }

        vector<vector<ll>> left_sum(s.size(), vector<ll>(5));
        vector<ll> left_high(s.size());
        for (ll high_index = 0; high_index <= 4; high_index++){
            ll highest = val(digits[high_index]);
            left_sum[0][high_index] = (val(s[0]) <= highest) ? val(s[0]) : -val(s[0]);
            left_high[0] = val(s[0]);
            for (ll j = 1; j < s.size(); j++){
                if (val(s[j]) >= highest) {
                    left_sum[j][high_index] = left_sum[j-1][high_index] + val(s[j]);
                    left_high[j] = val(s[j]);
                } else {
                    left_sum[j][high_index] = left_sum[j-1][high_index] - val(s[j]);
                }
            }
        }
        vector<ll> best(s.size(), -10000LL*200000);
        best[0] = right_sum[1] + 10000;
        vector<ll> pow_ten = {1, 10, 100, 1000, 10000};
        for (ll high_index = 0; high_index <= 4; high_index++){
            ll highest = val(digits[high_index]);
            for (ll change_index = 0; change_index <= 4; change_index++){
                if (left_high[s.size() - 2] <= highest && change_index <= high_index){
                    ll temp_best = left_sum[s.size() - 2][high_index] + pow_ten[change_index];
                    if (temp_best > best[last_index]){
                        best[last_index] = temp_best;
                    }
                }

                for (ll j = 1; j < s.size() - 1; j++){
                    if (left_high[j-1] <= highest && right_high[j+1] <= highest && change_index <= high_index) {
                        ll temp_best = left_sum[j-1][high_index] + right_sum[j+1];
                        if (change_index >= right_high[j+1]){
                            temp_best += pow_ten[change_index];
                        } else {
                            temp_best -= pow_ten[change_index];
                        }
                        if (temp_best > best[j]) {
                            best[j] = temp_best;
                            cout << "change to: " << pow_ten[change_index] << " at index: " << j << endl;
                        }
                    }
                }
            }
        }
        ll super_best = best[0];
        for (ll j = 0; j < s.size(); j++){
            if (best[j] > super_best){
                super_best = best[j];
            }
        }
        cout << super_best << endl;
    }

    return 0;
}
