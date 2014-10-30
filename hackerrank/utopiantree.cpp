#include <iostream>
using namespace std;

int height(int n) {
    int c = n/2;
    int m = n%2;
    int h = 1;
    while(c--){
        h = 2*h+1;
    }
    return h*(m+1);
}
int main() {
        int T;
        cin >> T;
        while (T--) {
            int n;
            cin >> n;
            cout << height(n) << endl;
         }
}

