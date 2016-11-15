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


string check_prime(int& a)
{
    int start = 0;
    if (a < 2) return "Not prime";
    if (a == 2) return "Prime";
    for (unsigned i = 2; i <= sqrt(a); i++) {
        if (a%i == 0) return "Not prime";
    }
    return "Prime";
}

int main(){
    int p;
    cin >> p;
    for(int a0 = 0; a0 < p; a0++){
        int n;
        cin >> n;
        cout << check_prime(n) << endl;
    }
    return 0;
}
