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
    int t, n;
    cin >> t;
    int upvotes[t];
    for(int i = 0; i < t; i++){
        cin >> n;
        int reviews[n];
        long a = 0;
        long b = 0;
        for(int j = 0; j < n; j++){
            cin >> reviews[j];
            if (reviews[j] == 1){
                if(a >= b){
                    a++;
                } else {
                    b++;
                }
            } else if (reviews[j] == 2){
                if(a >= b){
                    b--;
                } else {
                    a--;
                }
            } else {
                if (a >= b && a >= 0){
                    a++;
                } else if (b >= a && b >= 0){
                    b++;
                } else if (a <= b){
                    a--;
                } else {
                    b--;
                }
            }
        }

        if (a >= b && a >= 0){
            upvotes[i] = a;
        } else if (b >= a && b >= 0){
            upvotes[i] = b;
        } else {
            upvotes[i] = 0;
        }

    }

    for(int i = 0; i < t; i++){
        cout << upvotes[i] << endl;
    }

    return 0;
}