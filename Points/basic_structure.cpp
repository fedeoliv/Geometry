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

    /* For sorting points */
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;       // first criteria , by x-coordinate
        return y < other.y;           // second criteria, by y-coordinate
    }

    /* Check if two points are equals (for floating points) */
    bool operator == (point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
};

/* Euclidean distance */
double dist(point p1, point p2) {
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

/* Rotate a point by theta degrees counter clockwise */
point rotate(point p, double theta) {
    double rad = (theta*PI)/180.0;
    return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}

int main() {
    vector<point> p;

    p.push_back(point(2, 2));
    p.push_back(point(6, 5));

    sort(p.begin(), p.end());
    for(int i = 0; i < p.size(); i++) printf("%.lf %.lf\n", p[i].x, p[i].y);
    printf("Are points equals? %d\n", p[0] == p[1]);
    printf("Distance: %.2lf\n", dist(p[0], p[1]));

    point P = rotate(point(10, 3), 90);
    printf("Rotation: %.lf %.lf\n", P.x, P.y);
    return 0;
}
