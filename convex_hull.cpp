#include <bits/stdc++.h>
#define INF 10000
using namespace std;

/*  Given a set of points in the plane. The convex hull of the set is the smallest
    convex polygon that contains all the points of it.*/

struct Point {
    int x, y;
};

/*  A globle point needed for  sorting points with reference to the first point.
    Used in compare function of qsort() */
Point p0;

/* An utility function to find next to top in a stack */
Point nextToTop(stack<Point> &S) {
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

/* An utility function to swap two points */
int swap(Point &p1, Point &p2) {
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}

/* An utility function to return square of distance between p1 and p2 */
int dist(Point p1, Point p2) {
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}

/*  Functin to find orientation of ordered triplet (p, q, r).
    The function returns following values:
    0 --> p, q and r are colinear
    1 --> Clockwise
    2 --> Counterclockwise */
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if(val == 0) return 0;  /* Colinear */
    if(val > 0) return 1;   /* Clockwise */
    return 2;               /* Counterclockwise */
}

/*  A function used by library function qsort() to sort an array of
    points with respect to the first point */
int compare(const void *vp1, const void *vp2) {
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;

   /* Find orientation */
   int o = orientation(p0, *p1, *p2);
   if(o == 0) return (dist(p0, *p2) >= dist(p0, *p1))? -1 : 1;
   return (o == 2)? -1: 1;
}

/* Prints convex hull of a set of n points. */
void convexHull(Point points[], int n) {
    /* Find the bottommost point */
    int ymin = points[0].y, min = 0;

    for(int i = 1; i < n; i++) {
        int y = points[i].y;

        /* Pick the bottom-most or chose the left most point in case of tie */
        if((y < ymin) || (ymin == y && points[i].x < points[min].x))
            ymin = points[i].y, min = i;
    }

    /*  Place the bottom-most point at first position */
    swap(points[0], points[min]);

    /*  Sort n-1 points with respect to the first point.
        A point p1 comes before p2 in sorted ouput if p2 has
        larger polar angle (in counterclockwise direction) than p1 */
    p0 = points[0];
    qsort(&points[1], n-1, sizeof(Point), compare);

    /*  Create an empty stack and push first three points to it. */
    stack<Point> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    /* Process remaining n-3 points */
    for(int i = 3; i < n; i++) {
        /*  Keep removing top while the angle formed by points next-to-top,
            top, and points[i] makes a non-left turn */
        while(orientation(nextToTop(S), S.top(), points[i]) != 2) S.pop();
        S.push(points[i]);
    }

    /* Now stack has the output points, print contents of stack */
    while (!S.empty()) {
        Point p = S.top();
        printf("(%d, %d)\n", p.x, p.y);
        S.pop();
    }
}

int main() {
    //Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    //int n = sizeof(points)/sizeof(points[0]);
    int n;
    scanf("%d", &n);

    Point points[n];
    for(int i = 0; i < n; i++) scanf("%d %d", &points[i].x, &points[i].y);
    convexHull(points, n);
    return 0;
}
