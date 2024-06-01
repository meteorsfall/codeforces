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
    int n, ans, prevans = 0;
    cin >> n;
    int lowerbound = 1;
    int upperbound = n - 1;
    int add;
    while (lowerbound != upperbound) {
        // cout << "lowerbound: " << lowerbound << ", upperbound: " << upperbound << endl;
        int mid = (lowerbound + upperbound)/2;
        int add = n - (mid % n) - 1;
        cout << "+ " << add << endl;
        cin >> ans;
        if (ans > prevans) {
            lowerbound = ans*n;
            upperbound = upperbound + add;
        } else {
            lowerbound = lowerbound + add;
            upperbound = (ans + 1)*n - 1;
        }
        prevans = ans;
    }
    cout << "! " << lowerbound << endl;
    return 0;
}