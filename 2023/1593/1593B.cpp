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
    for(int tt = 0; tt < t; tt++){
        string n;
        cin >> n;
        int maxdelete = 18;
        for(int i = 0; i < n.size(); i++){
            if(n[i] == '5' || n[i] == '0'){
                for(int j = 0; j < i; j++){
                    if( (n[i] == '5' && (n[j] == '2' || n[j] == '7'))
                        || (n[i] == '0' && (n[j] == '5' || n[j] == '0'  )) ){
                        int possible = i - j - 1 + (n.size() - 1 - i);
                        if (possible < maxdelete){
                            maxdelete = possible;
                        }
                    }
                }
            }
        }
        cout << maxdelete << endl;
    }
    
    return 0;
}