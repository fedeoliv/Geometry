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

// to get the other center, reverse p1 and p2
bool circle2PtsRad(point p1, point p2, double r, point &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;

    if (det < 0.0) return false;

    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
}

int main() {
    point p1(1.0, 2.0);
    point p2(2.0, 3.0);
    double r = 1.415;
    point c;

    circle2PtsRad(p1, p2, r, c);
    printf("(%.2lf, %.2lf)\n", c.x, c.y);

    circle2PtsRad(p2, p1, r, c);
    printf("(%.2lf, %.2lf)\n", c.x, c.y);

    return 0;
}
