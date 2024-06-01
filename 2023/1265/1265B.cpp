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
    
    int t;
    cin >> t;

    int n;

    for(int i = 0; i < t; i++){

        cin >> n;
        vector<int> nums(n+1);
        vector<int> findnum(n+1);
        vector<int> isperm(n+1, 0);
        
        for(int j = 0; j < n; j++){
            cin >> nums[j+1];
            findnum[nums[j+1]] = j;
        }

        int left = findnum[1];
        int right = findnum[1];
        isperm[1] = 1;
        
        for(int j = 2; j <= n; j++){
            if(findnum[j] < left){
                left = findnum[j];
            }
            if(findnum[j] > right){
                right = findnum[j];
            }

            if( (right - left + 1) == j){
                isperm[j] = 1;
            }
        }
        
        for(int j = 1; j <= n; j++){
            cout << isperm[j];
        }

        cout << endl;

    }

    return 0;
}