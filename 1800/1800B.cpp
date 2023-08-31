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
        ll n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        vector<ll> upper_letter_count(26, 0);
        vector<ll> lower_letter_count(26, 0);
        string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

        for (ll i = 0; i < n; i++){
            for (ll j = 0; j < 52; j++){
                if (s[i] == letters[j]){
                    if (j < 26){
                        upper_letter_count[j]++;
                    } else {
                        lower_letter_count[j - 26]++;
                    }
                }
            }
        }

        ll burl_count = 0;
        ll spares = 0;
        for (ll i = 0; i < 26; i++){
            if (upper_letter_count[i] > 0 && lower_letter_count[i] > 0){
                ll shared = min(upper_letter_count[i], lower_letter_count[i]);
                burl_count += shared;
                upper_letter_count[i] -= shared;
                lower_letter_count[i] -= shared;
            }
            if (upper_letter_count[i] > 0){
                spares += upper_letter_count[i] / 2;
            }
            if (lower_letter_count[i] > 0){
                spares += lower_letter_count[i] / 2;
            }
        }

        cout << burl_count + min(spares, k) << endl;

    }

    return 0;
}
