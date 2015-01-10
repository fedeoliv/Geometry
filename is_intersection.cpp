#include <bits/stdc++.h>
using namespace std;

/*  Two segments (p1,q1) and (p2,q2) intersect if and only if one of the following two conditions is verified:

    1. General Case:
    – (p1, q1, p2) and (p1, q1, q2) have different orientations and
    – (p2, q2, p1) and (p2, q2, q1) have different orientations

    2. Special Case
    – (p1, q1, p2), (p1, q1, q2), (p2, q2, p1), and (p2, q2, q1) are all collinear and
    – the x-projections of (p1, q1) and (p2, q2) intersect
    – the y-projections of (p1, q1) and (p2, q2) intersect */
struct Point {
    int x, y;
};

/*  Given three colinear points p, q, r, the function checks
    if point q lies on line segment 'pr' */
bool onSegment(Point p, Point q, Point r) {
    if(q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
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

bool isIntersection(Point p1, Point q1, Point p2, Point q2) {
    /*  Find the four orientations needed for general and special cases */
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    /* General case */
    if(o1 != o2 && o3 != o4) return true;

    /* Special Cases */
    /* p1, q1 and p2 are colinear and p2 lies on segment p1q1 */
    if(o1 == 0 && onSegment(p1, p2, q1)) return true;

    /* p1, q1 and p2 are colinear and q2 lies on segment p1q1 */
    if(o2 == 0 && onSegment(p1, q2, q1)) return true;

    /* p2, q2 and p1 are colinear and p1 lies on segment p2q2 */
    if(o3 == 0 && onSegment(p2, p1, q2)) return true;

    /* p2, q2 and q1 are colinear and q1 lies on segment p2q2 */
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; /* Doesn't fall in any of the above cases */
}

int main() {
    /*
    struct Point p1 = {1, 1}, q1 = {10, 1};
    struct Point p2 = {1, 2}, q2 = {10, 2};

    isIntersection(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

    p1 = {10, 0}, q1 = {0, 10};
    p2 = {0, 0}, q2 = {10, 10};
    isIntersection(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

    p1 = {-5, -5}, q1 = {0, 0};
    p2 = {1, 1}, q2 = {10, 10};
    isIntersection(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";
    */

    struct Point p1, q1, p2, q2;

    scanf("%d %d", &p1.x, &p1.y);
    scanf("%d %d", &q1.x, &q1.y);
    scanf("%d %d", &p2.x, &p2.y);
    scanf("%d %d", &q2.x, &q2.y);

    if(isIntersection(p1, q1, p2, q2)) printf("Yes\n");
    else printf("No\n");

    return 0;
}
