#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;
/*
 * Complete the function below.
 */
int main() {
    int res=0;
    int  _l;
    cin >> _l;   
    int _r;
    cin >> _r;
    size_t len = floor((log(_r^_l)/log(2)));
    res =len==0?0: (2<<len)-1;
    cout<<res;
    return 0;
}
