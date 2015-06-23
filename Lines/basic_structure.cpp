#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

#define EPS 1e-9
#define PI acos(-1.0)
using namespace std;

struct line {
    double a, b, c;
    line() { a = b = c = 0.0; }
    line(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
};

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

/* Calculate linear equation for two lines */
line pointsToLine(point p1, point p2) {
    line l;

    if (fabs(p1.x - p2.x) < EPS) {  // vertical line is fine
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;      // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    }

    return l;
}

/* Checking if lines are in parallel */
bool areParallel(line l1, line l2) {
    /* Coefficients a and b must be the same */
    return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

/* Checking if lines are the same */
bool areSame(line l1, line l2) {
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS);
}

bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;  // no intersection

    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
    else p.y = -(l2.a * p.x + l2.c);
    return true;
}

int main() {
    point p1(1, 0);
    point p2(2, 3);

    line l = pointsToLine(p1, p2);
    printf("%.lf %.lf %.lf\n", l.a, l.b, l.c);

    line l1(1, 2, 3);
    line l2(1, 1, 5);

    printf("Are in parallel? %d\n", areParallel(l1, l2));
    printf("Are the same? %d\n", areSame(l1, l2));

    point p3;
    printf("Intersect? %d\n", areIntersect(l1, l2, p3));
    printf("Intersection: (%.lf, %.lf)\n", p3.x, p3.y);
    return 0;
}
