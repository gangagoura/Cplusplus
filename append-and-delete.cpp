#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <cmath>
using namespace std;
int main() {
    string s, t;
    cin >> s >> t;
    int k;
    cin >> k;
    
    int i = 0, j = 0;
    for (; i < (int)s.size() && j < (int)t.size(); ++i,++j) {
        if (s[i] != t[j])
            break;
    }
    
    int need = ((int)s.size() - i) + ((int)t.size() - j);
    if ((need <= k && (k-need) % 2 == 0) || k >= (int)s.size() + (int)t.size()) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    
    
    return 0;
}
