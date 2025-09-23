#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    constexpr int ALPHA = 26;
    constexpr int MASK_SIZE = 1 << ALPHA;

    vector<int> first(MASK_SIZE, n+1);
    first[0] = 0;

    int mask = 0;
    int ans = 1;

    for (int i = 0; i < n; ++i) {
        mask ^= (1 << (s[i] - 'a'));
        ans = max(ans, i + 1 - first[mask]);

        for (int j = 0; j < ALPHA; ++j) {
            int test_mask = mask ^ (1 << j);
            ans = max(ans, i + 1 - first[test_mask]);
        }

        first[mask] = min(first[mask], i + 1);
    }

    cout << ans << "\n";
}

