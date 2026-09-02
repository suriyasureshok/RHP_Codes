#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    vector<int> b(m);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (int j = 0; j < m; j++) {
        cin >> b[j];
    }
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int c = 0;
    int n1 = a.size() - 1;
    int m1 = b.size() - 1;
    
    while (n1 >= 0 && m1 >= 0) {
        if (a[n1] * 2 >= b[m1]) {
            c++;
            n1--;
            m1--;
        } else {
            m1--;
        }
    }
    
    cout << c << endl;
    
    return 0;
}
