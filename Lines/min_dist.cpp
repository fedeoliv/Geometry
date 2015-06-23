#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

#define EPS 1e-9
#define PI acos(-1.0)
using namespace std;

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
};

struct vec {
    double x, y;
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) {
    /* convert 2 points to vector a->b */
    return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s) {
    return vec(v.x * s, v.y * s);
}

point translate(point p, vec v) {
    /* translate p according to v */
    return point(p.x + v.x , p.y + v.y);
}

double dot(vec a, vec b) {
    return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
    return v.x * v.x + v.y * v.y;
}

/* Euclidean distance */
double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

/*  Returns the distance from p to the line defined by two points a and b
    (a and b must be different). The closest point is stored in the 4th parameter.*/
double distToLine(point p, point a, point b, point &c) {
    // formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));     // translate a to c
    return dist(p, c);
}

/* Minimum distance to line segment(defined by two end points a and b). */
double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) {
        c = point(a.x, a.y);    // closer to a
        return dist(p, a);
    }
    // Euclidean distance between p and a
    if (u > 1.0) {
        c = point(b.x, b.y);    // closer to b
        return dist(p, b);
    }
    // Euclidean distance between p and b
    return distToLine(p, a, b, c);
}

int main() {
    point p(1, 2);
    point a(1, 3);
    point b(2, 5);
    point c;
    printf("Distance: %.2lf\n", distToLine(p, a, b, c));
    printf("Point: (%.lf, %.lf)\n", c.x, c.y);
    return 0;
}
