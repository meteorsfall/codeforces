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

char valid(vector<ll> temp){
   if(temp[1] - temp[0] == temp[2] - temp[3] && temp[1] >= temp[0]){
       return 'x';
   } else if (temp[1] - temp[0] == temp[2] - temp[3] - 1 && temp[1] >= temp[0]){
       return 'y';
   } else {
       return '*';
   }
}

int main() {

    vector<ll> nums(4);

    for(int i = 0; i < 4; i++){
        cin >> nums[i];
    }
    
    ll lowest = 3;

    for(int i = 3; i >= 0; i--){
        if(nums[i] != 0){
            lowest = i;
        }
    }

    char mode = '*';
    int begin = -1;

    for(int i = lowest; i <= 3; i++){

         nums[i] -= 1;

        if(valid(nums) != '*'){
            mode = valid(nums);
            begin = i;
            //cout << valid(nums) << endl;
            //cout << begin << endl;
            break;
        } 

    }

    if(mode == '*' || begin == -1){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    for(int i = begin; i >= lowest; i--){
        cout << i << " ";
    }

    int lastprinted = -1;

    for(int i = 0; i < 3; i++){
        if(i < 2){
            while(nums[i] > 0){
                cout << i+1 << " " << i << " ";
                nums[i]--;
                nums[i+1]--;
                lastprinted = i+1;
            }
        } else {
            while(nums[i+1] > 0){
                cout << i+1 << " " << i << " ";
                nums[i]--;
                nums[i+1]--;
                lastprinted = i+1;
            }
        }
    }

    if(nums[2] > 0 && lastprinted != 2){
        cout << "2";
        nums[2]--;
    }

    for(int i = 0; i < 3; i++){
        if(nums[i] > 0 && lastprinted != i){
            cout << i;
            nums[i]--;
            break;
        }
    }

    cout << endl;

    if(nums[0] != 0 || nums[1] != 0 || nums[2] != 0 || nums[3] != 0){
        cout << "failure";
    }

    //cout << nums[0] << " " << nums[1] << " " << nums[2] << " " << nums[3] << endl;

    return 0;
}