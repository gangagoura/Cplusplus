#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> height(n);
    int maxall=0;
    for(int height_i = 0; height_i < n; height_i++){
       cin >> height[height_i];
        maxall=max(maxall,height[height_i]);
    }
    cout<<max(0,maxall-k);
    return 0;
}
