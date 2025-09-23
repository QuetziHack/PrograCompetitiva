#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAX_MASK = (1 << 26) - 1;
int first_occurrence[MAX_MASK + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    memset(first_occurrence, -1, sizeof(first_occurrence));
    first_occurrence[0] = 0;
    
    int n;
    string s;
    cin >> n >> s;
    
    int mask = 0;
    int max_length = 1;
    
    for (int j = 1; j <= n; ++j) {
        char c = s[j - 1];
        int char_index = c - 'a';
        mask ^= (1 << char_index);
        
        if (first_occurrence[mask] != -1) {
            int length = j - first_occurrence[mask];
            if (length > max_length) {
                max_length = length;
            }
        }
        
        for (int k = 0; k < 26; ++k) {
            int target_mask = mask ^ (1 << k);
            if (first_occurrence[target_mask] != -1) {
                int length = j - first_occurrence[target_mask];
                if (length > max_length) {
                    max_length = length;
                }
            }
        }
        
        if (first_occurrence[mask] == -1) {
            first_occurrence[mask] = j;
        }
    }
    
    cout << max_length << "\n";
    
    return 0;
}

