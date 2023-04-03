#include <bits/stdc++.h>
using namespace std;
int howManyGames(int p, int d, int m, int s) {
    int res = 0;
    while (p <= s) {
        res++; s -= p;
        p = max(m, p - d);
    }
    return res;
}
int main() {
    int p;
    int d;
    int m;
    int s;
    cin >> p >> d >> m >> s;
    int answer = howManyGames(p, d, m, s);
    cout << answer << endl;
    return 0;
}
