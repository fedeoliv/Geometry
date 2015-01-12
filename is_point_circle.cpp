#include <bits/stdc++.h>
using namespace std;

/* Check whether a given point lies inside a circle or not. */

void isInside(double x1, double y1, double x2, double y2, double x3, double y3, int x, int y) {
    double m1, m2, c1, c2, r;

    m1 = (y1 - y2) / (x1 - x2);
    m2 = (y3 - y2) / (x3 - x2);

    c1 = ((m1 * m2 * (y3 - y1)) + (m1 * (x2 + x3)) - (m2 * (x1 + x2))) / (2* (m1 - m2));
    c2 = ((((x1 + x2) / 2) - c1) / (-1 * m1)) + ((y1 + y2) / 2);
    r = sqrt(((x3 - c1) * (x3 - c1)) + ((y3 - c2) * (y3 - c2)));

    printf("Center of the circle: (%.1lf, %.1lf)\n", c1, c2);
    printf("Radius: %.5lf\n", r);

    double s = ((x - c1) * (x - c1)) + ((y - c2) * (y - c1)) - (r * r);

    if(s < 0) printf("Inside\n");
    else if(s > 0) printf("Outside\n");
    else printf("On the cicle\n");
}

int main() {
    /*  (2, 5), (10, 8), (3, 6)
        point 1 2 */
    int x, y;
    double x1, x2, y1, y2, x3, y3;

    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);
    scanf("%lf %lf", &x3, &y3);
    scanf("%d %d", &x, &y);

    isInside(x1, y1, x2, y2, x3, y3, x, y);
    return 0;
}
