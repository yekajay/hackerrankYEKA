#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

bool ransom_note(vector<string> magazine, vector<string> ransom) {
    bool result = false;
    unordered_map<string, int> um1;
    unordered_map<string, int> um2;
    sort(magazine.begin(), magazine.end());
    sort(ransom.begin(), ransom.end());
    um1[magazine[0]] = 1;
    um2[ransom[0]] = 1;
    for (unsigned i = 1; i < magazine.size(); ++i) {
        if (magazine[i] != magazine[i-1]) {
            um1[magazine[i]] = 1;
        }
        else {
            um1[magazine[i]] = um1[magazine[i]] + 1;
        }
    }
    for (unsigned i = 1; i < ransom.size(); ++i) {
        if (ransom[i] != ransom[i-1]) {
            um2[ransom[i]] = 1;
        }
        else {
            um2[ransom[i]] = um2[ransom[i]] + 1;
        }
    }
    for (auto aa : um2) {
        if (aa.second <= um1[aa.first]) {result = true;}
        else {return false;}
    }
    return result;
}

int main(){
    int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
