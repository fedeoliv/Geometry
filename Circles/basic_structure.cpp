#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

#define EPS 1e-9
#define PI acos(-1.0)
using namespace std;

/* Default constructor */
struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
};


int insideCircle(point p, point c, double r) {
    double dx = fabs(p.x - c.x);
    double dy = fabs(p.y - c.y);
    double euc = dx * dx + dy * dy;
    double diameter = r * r;
    /*  0 = inside
        1 = in the border
        2 = outside */
    // fabs(Euc - diameter) < EPS is the same as:
    // if(Euc == diameter)
    return euc < diameter ? 0 : fabs(euc - diameter) < EPS ? 1 : 2;
}

int main() {
    point p(1.0, 2.0);
    point c(2.0, 3.0);
    double r = 1.415;

    printf("%d\n", insideCircle(p, c, r));

    return 0;
}
