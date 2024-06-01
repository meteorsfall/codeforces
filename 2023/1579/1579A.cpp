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
        string s;
        cin >> s;
        int count_a = 0;
        int count_b = 0;
        int count_c = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'A'){
                count_a++;
                //cout << "a\n";
            } else if (s[i] == 'B'){
                count_b++;
                //cout << "b\n";
            } else if (s[i] == 'C'){
                count_c++;
                //cout << "c\n";
            }
        }
        if(count_b == count_a + count_c){
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}