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

int number_needed(string a, string b) {
    int take_away = 0;
    sort(a.begin(), a.end()); sort(b.begin(), b.end());
    unordered_map<char, int> um1;
    unordered_map<char, int> um2;
    for (char c = 'a'; c <= 'z'; c++) {
        um1[c] = 0;
        um2[c] = 0;
    }
    um1[a[0]] = um1[a[0]] + 1;
    um2[b[0]] = um2[b[0]] + 1;
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] != a[i-1]) {
            um1[a[i]] = 1;
        }
        else {
            um1[a[i]] = um1[a[i]] + 1;
        }
    }
    for (int i = 1; i < b.size(); ++i) {
        if (b[i] != b[i-1]) {
            um2[b[i]] = 1;
        }
        else {
            um2[b[i]] = um2[b[i]] + 1;
        }
    }
    for (auto item1 = um1.begin(); item1 != um1.end(); ++item1) {
        for (auto item2 = um2.begin(); item2 != um2.end(); item2++) {
            if (item1->first == item2->first) {
                take_away += abs(item1->second - item2->second);
                break;
            }
        }
    }
    return take_away;
}

int main(){
    string a;
    cin >> a;
    string b;
    cin >> b;
    cout << number_needed(a, b) << endl;
    return 0;
}
