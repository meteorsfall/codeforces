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

int fib(int a){
    if(a <= 1)
        return a;
    int b = (a-1) <= 1 ? a-1 : fib(a-2) + fib(a-3);
    int c = fib(a - 2);
    return b + c;
}

int main() {

    cout << fib(42);
    return 0;
}