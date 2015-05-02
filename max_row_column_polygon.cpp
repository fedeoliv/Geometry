#include <stdio.h>
#include <vector>
#include <cmath>
#define LL long long
using namespace std;

/* Maximum number of row/column points in a polygon. */

LL GCD(LL  a, LL  b) {
    while(b) b ^= a ^=b ^= a %=b;
    return a;
}

struct point {
    LL x, y;
    point (LL p1 , LL p2) {
        x = p1;
        y = p2;
    }
};

/* Area of polygon */
LL poly_area(vector<point> P) {
    LL res = 0 , x1 ,y1,x2,y2;

    for(int i = 0, sz = P.size(); i < sz; i++) {
        x1 = P[i].x , x2 = P[(i+1)%sz].x;
        y1 = P[i].y , y2 = P[(i+1)%sz].y;
        res += ( x1 * y2 - x2 * y1 );
    }
    // res is the determinant of these points
    return fabs(res)*0.5 ;
}

LL getBorderPoints(vector<point>P) {
    LL B = 0;
    int n = P.size();

    for(int i = 0, j = n - 1; i < n; j = i++) {
            LL ret = GCD( abs( P[i].x - P[j].x ), abs( P[i].y - P[j].y ) );
            B += ret;
    }
    return B ;
}

int main() {
    int n;
    LL x, y, A, B, I;

    scanf("%d", &n);
    vector<point>P;

    for(int i = 0; i < n; i++) {
        scanf("%lld %lld", &x, &y);
        P.push_back(point(x,y));
    }

    A = poly_area(P);
    B = getBorderPoints(P);
    I = A + 1 - B/2 ;
    // Theorem : A = I + B/2 - 1
    printf("%lld\n", I);
}
