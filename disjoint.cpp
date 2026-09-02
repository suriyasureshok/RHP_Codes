#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& ldr, int i) {
    if (ldr[i] == i) {
        return i;
    }
    return find(ldr, ldr[i]);
}

void join(vector<int>& ldr, int lt, int rt) {
    int ldlft = find(ldr, lt);
    int ldrt = find(ldr, rt);
    ldr[ldrt] = ldlft;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> ldr(n + 1);
    for (int i = 1; i <= n; i++) {
        ldr[i] = i;
    }
    
    int m;
    cin >> m;
    
    for (int i = 0; i < m; i++) {
        int lt, rt;
        cin >> lt >> rt;
        join(ldr, lt, rt);
    }
    
    unordered_set<int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(find(ldr, i));
    }
    
    cout << s.size() << endl;
    
    return 0;
}
