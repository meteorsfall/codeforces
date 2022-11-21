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
    vector<ll> parkn;
    vector<ll> parkm;
    for(ll i = 0; i < t; i++){
        ll a, b;
        cin >> a >> b;
        parkn.push_back(a);
        parkm.push_back(b);
    }

    ll sum = 0;
    for(ll i = 0; i < t; i++){
        sum += (parkn[i] /2 )*(parkm[i] - parkm[i] % 2);
        //cout << sum << " ";
        sum += (parkn[i] % 2 )*parkm[i]/2;
       // cout << sum << " ";
        sum += (parkm[i] % 2 )*parkn[i]/2;
       // cout << sum << " ";
        sum += (parkm[i] % 2 == 1 and parkn[i] % 2 == 1);

        cout << sum << endl;
        // cout << parkn[i] % 2 << " " << parkm[i] % 2 << parkn[i] << parkm[i];
        sum = 0;
    }

    return 0;   
}