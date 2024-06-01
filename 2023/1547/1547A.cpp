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
    
    int t;
    cin >> t;
    int xa, ya, xb, yb, xf, yf;
    for(int i = 0; i < t; i++){
        cin >> xa >> ya >> xb >> yb >> xf >> yf;
        if (xa == xb && xb == xf){
            if((ya > yb && yf > yb && yf < ya) || (ya < yb && yf > ya && yf < yb)){
                cout << abs(yb - ya) + 2 << endl;
            } else {
                cout << abs(yb - ya) << endl;
            }
            
        } else if (ya == yb && yb == yf){
            if((xa > xb && xf > xb && xf < xa) || (xa < xb && xf > xa && xf < xb)){
                cout << abs(xb - xa) + 2 << endl;
            } else {
                cout << abs(xb - xa) << endl; 
            }
        } else {
            cout << abs(yb - ya) + abs(xb - xa) << endl;
        }
    }
    return 0;
}