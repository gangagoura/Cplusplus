#include <iostream>
using namespace std;
int main() {
    int t, n, c, m;
    cin >> t;
    while (t--) {
        cin >> n >> c >> m;
        int answer = n / c;
        int wrappers = answer;
        // Spend wrappers for additional chocolates.
        while (wrappers >= m) {
            wrappers -= m;
            // Eat chocolate, produce new wrapper.
            answer++;
            wrappers++;
        }
        cout << answer << endl;
    }
    return 0;
}
