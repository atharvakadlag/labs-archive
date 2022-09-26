#include <bits/stdc++.h>
#define circle vector<pair<int, int>>
#define point pair<int, int>
using namespace std;

circle MCD(int x_center, int y_center, int r) {
    circle c1;

    int x = r, y = 0;
    c1.push_back(point(x, y));
    
    int P  = 1-r;
    while (x>y) {
        y++;

        if (P < 0) {
            // x = x;
            P = P + 2*y + 1; 
        } else {
            x = x - 1;
            P = P + 2*y - 2*x + 1;
        }
        c1.push_back(point(x+x_center, y+y_center));
        c1.push_back(point(-x+x_center, y+y_center));
        c1.push_back(point(x+x_center, -y+y_center));
        c1.push_back(point(-x+x_center, -y+y_center));
        if (x != y) {
            c1.push_back(point(y+x_center, x+y_center));
            c1.push_back(point(-y+x_center, x+y_center));
            c1.push_back(point(y+x_center, -x+y_center));
            c1.push_back(point(-y+x_center, -x+y_center));
        }
    }
    return c1;
}
