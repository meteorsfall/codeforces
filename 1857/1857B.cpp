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
        string x;
        cin >> x;
        vector<int> a(x.size());
        for (ll i = 0; i < x.size(); i++){
            a[i] = int(x[i]) - 48;
        }

        ll round_position = 0;
        for (ll k = 1; k <= a.size(); k++){
            if (a[a.size() - k] >= 5){
                round_position = k;
            }
            if (k < a.size() && a[a.size() - k - 1] == 9 && round_position == k){
                round_position++;
            }
            if (round_position == k && k < a.size()){
                a[a.size() - k - 1]++;
            }
        }
        /*for (ll i = 0; i < a.size(); i++){
            cout << a[i];
        }*/
        if (round_position == a.size()){
            cout << '1';
        }
        //if (round_position < a.size()){
            cout << round_position << endl;
            for (ll i = 0; i <= a.size() - 1 - round_position; i++) {
                cout << a[i];
            }
        //}
        for (ll i = a.size() - 1 - round_position + 1; i <= a.size() - 1; i++){
            cout << '0';
        } 
        cout << endl;

    }

    return 0;
}
