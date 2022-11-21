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

void mark_ticks(vector<string> practice, int y, int x, int k){
    if(practice[y][x] == '*'){
        if( y == 0 || x == 0 || x == practice[0].size() - 1){
            
        }
    }
}

int main() {

    int t;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        int n, m, k;
        cin >> n >> m >> k;
        vector<string> field;
        for(int i = 0; i < n; i++){
            string a;
            cin >> a;
            field.push_back(a);
        }
        for(int y = 0; y < n; y++){
            for(int x = 0; x < m; x++){
                if(field[y][x] == '*'){
                    if(y != 0 && x != 0 && x != m-1 && field[y-1][x-1] == '*' && field[y-1][x+1] == '*'){
                        
                    }
                }
            }
        }
    }
    
    return 0;
}