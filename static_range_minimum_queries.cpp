#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    int K = 18; // 2^18 >= 200000
    vector<vector<int>> stTable(K + 1, vector<int>(n + 1));
    vector<int> logTable(n + 1);
    
    logTable[1] = 0;
    for (int i = 2; i <= n; i++) {
        logTable[i] = logTable[i / 2] + 1;
    }
    
    for (int i = 1; i <= n; i++) {
        stTable[0][i] = arr[i];
    }
    
    for (int j = 1; j <= K; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            stTable[j][i] = min(stTable[j - 1][i], stTable[j - 1][i + (1 << (j - 1))]);
        }
    }
    
    for (int i = 0; i < m; i++) {
        int L, R;
        cin >> L >> R;
        
        int j = logTable[R - L + 1];
        int mn = min(stTable[j][L], stTable[j][R - (1 << j) + 1]);
        cout << mn << "\n";
    }
    
    return 0;
}
