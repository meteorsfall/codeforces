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

    for(ll i = 0; i < t; i++){
        
        ll n;
        cin >> n;
        vector<ll> scores(n + 1);

        for(ll j = 1; j < n+1; j++){
            cin >> scores[j];
        }
        
        vector<ll> scorechange;
        for(ll j = 2; j < n; j++){
            if(scores[j] != scores[j-1]){
                scorechange.push_back(j);
            }
        }

        ll g = 0, s = 0, b = 0;

        if (scorechange.size() < 3){
            cout << "0 0 0" << endl;
            continue;
        }

        g = scorechange[0] - 1;

        ll sindex = 0;
        
        for(ll j = 1; j < scorechange.size(); j++){
            if(scorechange[j] - scorechange[0] > g){
                s = scorechange[j] - scorechange[0];
                sindex = j;
                break;
            }
        }

        for(ll j = scorechange.size() - 1; j > sindex; j--){
            if(scorechange[j] <= n/2 + 1){
                b = scorechange[j] - (g + s + 1);
                break;
            }
        }

        if (g == 0 || s == 0 || b == 0 || g >= s || g >= b){
            cout << "0 0 0" << endl;
            continue;
        } 

        cout << g << " " << s << " " << b << endl;
        
    }
    
    return 0;
}