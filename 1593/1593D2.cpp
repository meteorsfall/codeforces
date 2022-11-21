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
        int n;
        cin >> n;
        vector<int> nums;
        map<int, int> same;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            a += 1'000'000;
            nums.push_back(a);
            same[nums[i]]++;
        }
        int working_k = 0;
        for(int k = 2000'000; k > 0 && working_k == 0; k--){
            static int mod[2000'000];
            for(int i = 0; i < n; i++){
                int index = nums[i] % k;
                mod[index]++;
                if(mod[index] >= n/2){
                    working_k = k;
                    break;
                }
            }
            for(int i = 0; i < n; i++){
                int index = nums[i] % k;
                mod[index] = 0;
            }
        }
        for(auto& elem : same){
            if(elem.second >= n/2){
                working_k = -1;
                break;
            }
        }
        cout << working_k << endl;
    }
    
    return 0;
}