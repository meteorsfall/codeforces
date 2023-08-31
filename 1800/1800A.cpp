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
        string s;
        cin >> s;

        int meow_index = -1;
        int success = true;
        string meow = "MmEeOoWwAa";
        for (int i = 0; i < n; i++){
            if (meow_index == -1){
                if (s[i] == meow[0] || s[i] == meow[1]){
                    meow_index++;
                } else {
                    success = false;
                    break;
                }
            } else if (meow_index >= 4) {
                success = false;
                break;
            } else {
                if (s[i] == meow[meow_index*2] || s[i] == meow[meow_index*2 + 1]){
                    
                } else if (s[i] == meow[meow_index*2 + 2] || s[i] == meow[meow_index*2 + 3]){
                    meow_index++;
                } else {
                    success = false;
                    break;
                }
            }
            //cout << "meow_index: " << meow_index << endl;
        }

        if (meow_index == 3 && success){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
