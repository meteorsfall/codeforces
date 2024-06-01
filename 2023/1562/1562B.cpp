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

bool is_prime(int n){
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

int string_to_int(string s){
    int coef = 1;
    int number = 0;
    for(int i = s.size() -1; i >= 0; i--){
        number += (s[i]-'0')*coef;
        coef *= 10;
    }
    return number;
}

int main() {
    
    int t, k;
    string n;
    char a;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> k >> n;
        int three_count = 0; 
        int seven_count = 0; 
        int one_count = 0;
        int two_count = 0;
        bool done = false;

        for(int j = 0; j < k; j++){
           a = n[j];
           if (a == '4' || a == '6' || a == '8' || a == '9' || a == '1'){
               cout << 1 << endl << a << endl;
               done = true;
               break;
           } 
           if (j > 0 && (a == 2 || a == 5)){
               cout << 2 << endl << n[j-1] << a;
               done = true;
               break;
           }
           if (a == '3'){
               three_count++;
           }
            if (a == '7'){
                seven_count++;
            }
            if (a == '1'){
                one_count++;
            }
            if (a == '2'){
                two_count++;
            }
        }

        if(done){
            continue;
        }

        if(three_count >= 2){
            cout << 2 << endl << 33 << endl;
        } else if(seven_count >= 2){
            cout << 2 << endl << 77 << endl;
        } else if (two_count >= 1 && (one_count >= 1 || seven_count >= 1)){
            cout << 2 << endl << 2 << (one_count >= 1 ? 1 : 7) << endl;
        } else if (one_count >= 3){
            cout << 3 << endl << 111 << endl;
        } else {
            int number;
            bool done = false;
            for(int j = 0; j < k; j++){
                for(int u = 0; u < k-1; u++){
                    number = string_to_int(string(n).erase(j,j+1).erase(u,u+1) );
                    if(!is_prime(number)){
                        cout << k-2 << endl << number << endl;
                        j=k;
                        done = true;
                        break;
                    }
                }
            }

            for(int j = 0; j < k; j++){
                number = string_to_int(string(n).erase(j,j+1));
                if(!is_prime(number)){
                    cout << k-1 << endl << number << endl;
                    done = true;
                    break;
                }
            }

            if(!done){
                cout << k << endl << n << endl;
            }
        }
    }

    return 0;
}