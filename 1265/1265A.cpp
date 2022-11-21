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

char retrieve(char x, char y){
    if (x == y){
        if(x == 'a'){
            return 'b';
        } else {
            return 'a';
        }
    } else {
        if (x != 'a' && y != 'a'){
            return 'a';
        } else if (x != 'b' && y != 'b'){
            return 'b';
        } else {
            return 'c';
        }
    }
}

int main() {
    
    int t;
    string s;

    cin >> t;

    for(int i = 0; i < t; i++){
        
        cin >> s;
        char end = '*';

        if(s[0] == '?'){
            s[0] = retrieve('?', s[1]);
        }

        for(int j = 0; j < s.size() - 1; j++){
            
            if( s[j+1] == s[j] && s[j] != '?'){
                s = "-1";
                break;
            }

            if(s[j+1] == '?'){

                if(end == '*'){
                    for(int k = j + 2; k < s.size(); k++){
                        if(s[k] != '?'){
                            end = s[k];
                            break;
                        }
                    }
                    if(end == '*'){
                        end = '!';
                    }
                }

                s[j+1] = retrieve(s[j], end);

            } else {
                end = '*';
            }

        }

        cout << s << endl;

    }

    return 0;
}