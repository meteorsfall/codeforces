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
        ll m;
        cin >> m;
        ll n = m*(m-1)/2;
        vector<ll> b(n);
        for (ll i = 0; i < n; i++){
            cin >> b[i];
        }

        sort(b.begin(), b.end());
        vector<ll> unique;
        vector<ll> ans;
        unique.push_back(b[0]);
        ans.push_back(unique[0]);
        map<ll, ll> nums;
        for (ll i = 0; i < n; i++){
            nums[b[i]]++;
            if (b[i] != unique[unique.size() - 1]){
                unique.push_back(b[i]);
                ans.push_back(b[i]);
            }
        }
        /*cout << "ans: ";
        for (ll i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        */

        if (n == 1){
            cout << b[0] << " " << b[0] << endl;
            continue;
        }
        if (n > 1 && b[0] == b[b.size() - 1]){
            ans.push_back(ans[0]);
        }
        for (ll i = 0; i <= ans.size() - 2; i++){
            for (ll j = i+1; j <= ans.size() - 1; j++){
                ll minimum = min(ans[i], ans[j]);
                nums[minimum]--;

                if (nums[minimum] < 0){
                    cout << "negative";
                }
                if (nums[minimum] == 0){
                    nums.erase(minimum);
                }
            }
        }
        /*cout << "ans: ";
        for (ll i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;
        for(auto& kv : nums) {
            cout << "key: " << kv.first << ", value: " << kv.second << endl;
        }
        */
        while (nums.size() > 0){
            ll biggest = nums.begin()->first;
            for(auto& kv : nums) {
                if (kv.first > biggest){
                    biggest = kv.first;
                }
            }

            for (ll i = 0; i < ans.size(); i++){
                ll minimum = min(ans[i], biggest);
                nums[minimum]--;

                /*if (nums[minimum] < 0){
                    cout << "negative";
                }*/
                if (nums[minimum] == 0){
                    nums.erase(minimum);
                }
            }
            ans.push_back(biggest);
        }

        for (ll i = 0; i < ans.size(); i++){
            cout << ans[i] << " ";
        }
        cout << endl;

    }

    return 0;
}
