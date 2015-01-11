#include <bits/stdc++.h>

/* Check whether two line segments intersect. */
struct point {
    int x, y;
};

struct line {
    point s, e;
};

double res(point a, point b, point c) {
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}

bool isMiddle(int a, int b, int c) {
    int t;
    if(a > b) {
        t = a;
        a = b;
        b = t;
    }

    if(a <= c && c <= b) return true;
    return false;
}

/* Checking the case where the line segments lie within the same line. */
bool isIntersection(line a, line b) {
    if((res(a.s, a.e, b.s) * res(a.s, a.e, b.e) < 0) &&
        (res(b.s, b.e, a.s) * res(b.s, b.e, a.e) < 0)) return true;

    if(res(a.s, a.e, b.s) == 0 && isMiddle(a.s.x, a.e.x, b.s.x) && isMiddle(a.s.y, a.e.y, b.s.y)) return true;
    if(res(a.s, a.e, b.e) == 0 && isMiddle(a.s.x, a.e.x, b.e.x) && isMiddle(a.s.y, a.e.y, b.e.y)) return true;
    if(res(b.s, b.e, a.s) == 0 && isMiddle(b.s.x, b.e.x, a.s.x) && isMiddle(b.s.y, b.e.y, a.s.y)) return true;
    if(res(b.s, b.e, a.e) == 0 && isMiddle(b.s.x, b.e.x, a.e.x) && isMiddle(b.s.y, b.e.y, a.e.y)) return true;

    return false;
}

/*
    If we don't need to consider if they are in the same line, we can change by:

    bool isIntersection(point a, point b, point c, point d) {
        return (res(a,b,c)*res(a,b,d) < 0 &&
            res(c,d,b)*res(c,d,a) < 0);
    }
*/

int main() {
    //line a={{1,0},{3,0}};
    //line b = {{2,0}, {4,0}};

    line a, b;

    scanf("%d %d", &a.s.x, &a.s.y);
    scanf("%d %d", &a.e.x, &a.e.y);
    scanf("%d %d", &b.s.x, &b.s.y);
    scanf("%d %d", &b.e.x, &b.e.y);

    if(isIntersection(a, b)) printf("Yes\n");
    else printf("No\n");
}
