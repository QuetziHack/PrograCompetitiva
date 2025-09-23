#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        total += x;
    }
    
    long long max_divisor = 1;
    for (long long i = 1; i * i <= total; ++i) {
        if (total % i == 0) {
            if (i <= n) {
                max_divisor = max(max_divisor, i);
            }
            long long complement = total / i;
            if (complement <= n) {
                max_divisor = max(max_divisor, complement);
            }
        }
    }
    
    cout << n - max_divisor << '\n';
    
    return 0;
}

