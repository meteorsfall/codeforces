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
        bool same = true;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            nums.push_back(a);
            if(i > 0){
                if(nums[i] != nums[i-1]){
                    same = false;
                }
            }
        }
        int working_k = 0;
        for(int k = 2000'000; k > 0; k--){
            bool k_works = true;
            for(int i = 1; i < n; i++){
                if( (nums[0] - nums[i]) % k != 0 ){
                    k_works = false;
                }
            }
            if (k_works){
                working_k = k;
                break;
            }
        }
        if(same){
            working_k = -1;
        }
        cout << working_k << endl;
    }
    
    return 0;
}