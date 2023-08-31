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
        vector<ll> a(n);
        for (ll i = 0; i < n; i++){
            cin >> a[i];
        }

        vector<ll> evens;
        vector<ll> odds;
        for (ll i = 0; i < n; i++){
            if (a[i] % 2 == 0){
                evens.push_back(a[i]);
            } else {
                odds.push_back(a[i]);
            }
        }

        
        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end());
        /*for (ll i = 0; i < evens.size(); i++){
            cout << evens[i] << " ";
        }
        cout << endl;
        for (ll i = 0; i < odds.size(); i++){
            cout << odds[i] << " ";
        }
        cout << endl;*/

        bool success = true;
        ll even_index = 0; 
        ll odd_index = 0;
        vector<ll> sorted_a(n, -1);
        for (ll i = 0; i < n; i++){
            if (a[i] % 2 == 0){
                if (i > 0 && evens[even_index] < sorted_a[i-1]){
                    success = false;
                    break;
                } else {
                    sorted_a[i] = evens[even_index];
                    even_index++;
                }
            } else {
                if (i > 0 && odds[odd_index] < sorted_a[i-1]){
                    success = false;
                    break;
                } else {
                    sorted_a[i] = odds[odd_index];
                    odd_index++;
                }
            }
        }
        /* for (ll i = 0; i < n; i++){
            cout << sorted_a[i] << " ";
        }
        cout << endl; */

        if (success){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
