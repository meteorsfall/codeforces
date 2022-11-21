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
    int tt;
    cin >> tt;
    string yes = "YesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYesYes";
    for (int t = 0; t < tt; t++){ 
        string s;
        cin >> s;
        int start;
        if (s[0] == yes[0]) {
            start = 0;
        } else if (s[0] == yes[1]) {
            start = 1;
        } else if (s[0] == yes[2]) {
            start = 2;
        } else {
            start = -1;
        }
        bool success = true;
        for (int i = 0; i < s.size(); i++){
            if (s[i] != yes[i + start]) {
                success = false;
            }
        }
        if (success) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}