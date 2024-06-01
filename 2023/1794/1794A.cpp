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
        int n;
        cin >> n;
        vector<string> pre_suffix;
        for (ll i = 0; i < 2*n - 2; i++){
            string a;
            cin >> a;
            if (a.size() == n-1){
                pre_suffix.push_back(a);
            } 
        }

        //cout << pre_suffix.size() << endl;

        bool success = true;
        for (ll i = 0; i < n - 2; i++){
            if (pre_suffix[0][i+1] != pre_suffix[1][i]){
                success = false;
                break;
            }
        }

        string s;
        if (success){
            s = pre_suffix[0];
            s += pre_suffix[1][n-2];
        } else {
            s = pre_suffix[1];
            s += pre_suffix[0][n-2];
        }

        bool palindrome = true;
        for (ll i = 0; i < n/2; i++){
            if (s[i] != s[n-1 - i]){
                palindrome = false;
                break;
            }
        }

        if (palindrome){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }
    return 0;
}
