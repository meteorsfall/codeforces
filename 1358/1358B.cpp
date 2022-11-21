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

    ll t;
    cin >> t;
    vector<vector<ll>> grannies(t);

    for(ll i = 0; i < t; i++){
        
        ll n;
        cin >> n;
        for(ll j = 0; j < n; j++){
            ll a;
            cin >> a;
            grannies[i].push_back(a);
        }
    }    

    for(ll i = 0; i < t; i++){
        ll sum = 1;
        ll runningsum = -1;
        sort(grannies[i].begin(), grannies[i].end());
        for(ll j = 0; j < grannies[i].size(); j++){
            // cout << sum << " ";
            runningsum++;
            if(grannies[i][j] <= sum + runningsum){
                sum = j + 2;
                runningsum = -1;
            }
        }
        cout << sum << endl;
    }

    return 0;

}