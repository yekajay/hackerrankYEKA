#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int staircase(int a, vector<int>& memo) { // find relationships
    if (memo[a] != -1) return memo[a];
    else{
        memo[a] = staircase(a-1, memo) + staircase(a-2, memo) + staircase(a-3, memo);
    }
    return memo[a];
}

int main() {
    int s;
    cin >> s;
    vector<int> memo(37, -1);
    memo[0] = 1;
    memo[1] = 1;
    memo[2] = 2;
    memo[3] = 4;
    for (unsigned i = 0; i < s; i++) {
        int k;
        cin >> k;
        cout << staircase(k, memo) << endl;
    }
    return 0;
}
