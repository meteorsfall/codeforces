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

        bool sorted = true;
        for (ll i = 1; i < n; i++){
            if (s[i] < s[i-1]){
                sorted = false;
            }
        }
        if (sorted){
            cout << 0 << endl;
            continue;
        }

        vector<char> reverse_big(n);
        reverse_big[n-1] = s[n-1];
        char biggest = s[n-1];
        for (ll i = n-2; i >= 0; i--){
            if (s[i] > biggest){
                biggest = s[i];
            }
            reverse_big[i] = biggest;
        }

        vector<pair<char, ll>> shift;
        for (ll i = 0; i < n; i++){
            if (s[i] >= reverse_big[i]){
                shift.push_back({s[i], i});
            }
        }

        vector<char> working(n);
        for (ll i = 0; i < n; i++){
            working[i] = s[i];
        }
        for (ll i = 0; i <= (shift.size()-1)/2; i++){
            ll place = shift.size() - 1 - i;
            working[shift[i].second] = shift[place].first;
            working[shift[place].second] = shift[i].first;
        }

        ll count = shift.size() - 1;
        for (ll i = 1; i < shift.size(); i++){
            if (shift[i].first == shift[0].first){
                count--;
            }
        }

        sorted = true;
        for (ll i = 1; i < n; i++){
            if (working[i] < working[i-1]){
                sorted = false;
                break;
            }
        }
        if (!sorted){
            cout << -1 << endl;
        } else {
            cout << count << endl;
        }

    }

    return 0;
}
