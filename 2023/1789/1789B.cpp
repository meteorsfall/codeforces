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
        string s;
        cin >> s;
        vector<bool> numbers;
        numbers.push_back(false);
        for (ll i = 0; i < s.length(); i++) {
            numbers.push_back(s[i] == '0' ? false : true);
        }

        ll midpoint = n/2 + 1;
        vector<ll> diff_index;
        for (ll i = 1; i < midpoint; i++) {
            //cout << "i: " << i << ", n + 1 - i: " << n + 1 - i << ", ";
            //cout << "i: " << numbers[i] << ", pair: " << numbers[n + 1 - i] << ", ";
            if (numbers[i] != numbers[n + 1 - i]) {
                diff_index.push_back(i);
                //cout << "diff ";
            }
        }
        bool split = false;
        for (ll i = 1; i < diff_index.size(); i++){
            if (diff_index[i] != diff_index[i - 1] + 1) {
                split = true;
            }
        }

        if (split){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }

    }

    return 0;
}
