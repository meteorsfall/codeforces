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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll tt;
    cin >> tt;
    for (ll t = 0; t < tt; t++){
        ll both, alice, bob, neither;
        cin >> both >> alice >> bob >> neither;
        ll alice_mood = both;
        ll bob_mood = both;
        ll jokes = both;
        while ( (alice_mood > 0 && bob > 0) || 
                (bob_mood > 0 && alice > 0) ){
            if (alice_mood > 0 && bob > 0) {
                if (bob >= alice_mood) {
                    jokes += alice_mood;
                    bob -= alice_mood;
                    bob_mood += alice_mood;
                    alice_mood = 0;
                } else {
                    jokes += bob;
                    alice_mood -= bob;
                    bob_mood += bob;
                    bob = 0;
                }
            } else if (bob_mood > 0 && alice > 0) {
                if (alice >= bob_mood) {
                    jokes += bob_mood;
                    alice -= bob_mood;
                    alice_mood += bob_mood;
                    bob_mood = 0;
                } else {
                    jokes += alice;
                    bob_mood -= alice;
                    alice_mood += alice;
                    alice = 0;
                }
            }
        }

        if (alice_mood > 0 && bob_mood > 0 && neither > 0) {
            jokes += min(alice_mood, min(bob_mood, neither));
            neither -= min(alice_mood, min(bob_mood, neither));
        }

        if (neither > 0 || alice > 0 || bob > 0) {
            jokes++;
        }
        cout << jokes << endl;
    }

    return 0;
}
