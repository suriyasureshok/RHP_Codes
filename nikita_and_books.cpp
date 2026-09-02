#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        long long surplus = 0;
        bool possible = true;
        
        for (int i = 0; i < n; i++) {
            long long required = i + 1;
            long long available = a[i] + surplus;
            
            if (available < required) {
                possible = false;
                break;
            }
            
            surplus = available - required;
        }
        
        if (possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
