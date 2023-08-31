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

ll generate_dict(int missing_letter, vector<string>& words, vector<vector<ll>>& count, vector<ll>& parity_bits){
    map<ll, ll> dict;
    for (ll i = 0; i < words.size(); i++){
        if (count[i][missing_letter] == 0){
            dict[parity_bits[i]]++;
        }
    }
    ll total = 0;
    for (ll i = 0; i < words.size(); i++){
        if (count[i][missing_letter] == 0) {
            total += dict[~parity_bits[i] & ~(1 << (25 - missing_letter))];
        }
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<string> words;
    for (ll i = 0; i < n; i++){
        string a;
        cin >> a;
        words.push_back(a);
    }

    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    vector<vector<ll>> count(n, vector<ll>(26, 0));
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < words[i].size(); j++){
            for (ll k = 0; k < 26; k++){
                if (words[i][j] == alphabet[k]){
                    count[i][k]++;
                }
            }
        }
    }

    vector<ll> parity_bits(n, 0);

    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < 26; j++){
            parity_bits[i] |= (count[i][j] & 1) << (25 - j);
        }
    }

    ll total = 0;
    for (ll i = 0; i < 26; i++){
        total += generate_dict(i, words, count, parity_bits);
    }

    cout << total << endl;

    return 0;
}
