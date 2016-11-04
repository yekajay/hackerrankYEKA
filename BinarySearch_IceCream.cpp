#include <iostream>
#include <algorithm> // for sort
#include <vector>

using namespace std;

class IceCream {
    public: 
        int flavor_cost;
        int index;
    
        IceCream() {}
        IceCream(int f, int i):flavor_cost{f}, index{i} {}
};


int binarySearch(int first, int last, const vector<IceCream>& arr, int search) {
    if (first > last) return -1; // important base case here
    
    int mid_point = (first + last)/2;
    if (search == arr[mid_point].flavor_cost) return arr[mid_point].index;
    else if (search < arr[mid_point].flavor_cost) {
        return binarySearch(first, mid_point-1, arr, search);
    }
    else {
        return binarySearch(mid_point+1, last, arr, search);
    }
}

bool sort_func(const IceCream& a, const IceCream& b) {
    return (a.flavor_cost < b.flavor_cost);
}

int main() {
    int t;
    int m, n;
    cin >> t;
    for(int test = 0; test < t; test++) {
        cin >> m >> n;
        vector<IceCream> arr(n);

        for (int i = 0; i < n; i++) {
            int cost;
            cin >> cost;
            arr[i] = IceCream{cost, i+1};
        }

        sort(arr.begin(), arr.end(), sort_func); // need to sort first
        for(int i = 0; i < n-1; i++) {
            int search = m - arr[i].flavor_cost;
            if(search >= arr[i].flavor_cost) {
                int index = binarySearch(i + 1, n - 1, arr, search); // it balances out
                if(index != -1) {
                    cout << min(arr[i].index, index) << " " << max(arr[i].index, index) << endl;
                    break;
                }
            }
        }
    }
    
    return 0;
}
