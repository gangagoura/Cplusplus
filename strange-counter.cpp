#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    long long cnt = 3;
    long long x;
    cin >> x;
    
    while(x > cnt) {
        x -= cnt;
        cnt *= 2;
    }
    
    cout << cnt - x + 1 << endl;
    
    return 0;
}
