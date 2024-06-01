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
#include <deque>  

using namespace std;
typedef long long ll;
template<typename A, typename B>
using hmap = unordered_map<A, B>;
typedef tuple<int, int> ii;
typedef tuple<ll, ll> lii;
#define PI 3.14159265358979323846
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3fL

struct card {
    int color = 0;
    int initial_position = 0;
    int initial_index = 0;
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<bool> colors(50);
    deque<card> deck;

    vector<int> answers;
    // color, initial position
    int a;
    int counter = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        if(colors[a] == false){
            colors[a] = true;
            
            deck.push_back({a, i, counter});
            counter++;
            //cout << "{" << a << "," << i << "} ";
        }
        //cout << endl;
    }
    card b;
    int location = 0;
    for(int i = 0; i < q; i++){
        /* for(int j = 0; j < deck.size(); j++){
            cout << "{" << deck[j].color << ", " << deck[j].initial_position << ", " <<  deck[j].initial_index << "} ";
        }
        cout << endl;
        */

        cin >> a;
        //cout << "deck.size: " << deck.size() << " ";
        for(int j = 0; j < deck.size(); j++){
            b = deck.at(j);
            if(b.color == a){
                if(b.initial_position == 0){
                    // cout << "j: " << j << " ";
                    location = j + 1;
                } else {
                    // cout << "second";
                    location = b.initial_position - b.initial_index + j + 1;
                }
                answers.push_back(location);
                deck.erase(deck.begin()+j);
                deck.push_front({a, 0, 0});                
                // cout << "a: " << a << ", b.second: " << b.second << ", counter: " << counter << " ";
            }
        }
    }
    
    for(int i = 0; i < answers.size(); i++){
        cout << answers[i] << " ";
    }

    cout << endl;

    return 0;
}