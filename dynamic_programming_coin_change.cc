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

long long make_change(vector<int> coins, int money) {
    vector<long>memo(money+1,0);
    memo[0] = 1;
    for (unsigned i = 0; i < coins.size(); i++) {
        for (unsigned j = coins[i]; j < memo.size(); j++) {
            memo[j] += memo[j-coins[i]];
        }
    }
    return memo[money];
}

int main(){
    int dollar_amount;
    int m;
    cin >> dollar_amount >> m;
    vector<int> coins(m);
    for(int coins_i = 0;coins_i < m;coins_i++) {
       cin >> coins[coins_i];
    }
    cout << make_change(coins, dollar_amount) << endl;
    return 0;
}
