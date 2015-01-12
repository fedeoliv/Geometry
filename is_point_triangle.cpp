#include <stdio.h>
#include <stdlib.h>

/*  Given three corner points of a triangle, and one more point P.
    Write a function to check whether P lies within the triangle or not.

    Let the coordinates of three corners be (x1, y1), (x2, y2) and (x3, y3)
    and coordinates of the given point P be (x, y).

    1) Calculate area of the given triangle. Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2.
    2) Calculate area of the triangle PAB. We can use the same formula for this. Let this area be A1.
    3) Calculate area of the triangle PBC. Let this area be A2.
    4) Calculate area of the triangle PAC. Let this area be A3.
    5) If P lies inside the triangle, then A1 + A2 + A3 must be equal to A.*/

/* Function to calculate area of triangle formed by (x1, y1), (x2, y2) and (x3, y3) */
float area(int x1, int y1, int x2, int y2, int x3, int y3) {
    return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

/* A function to check whether point P(x, y) lies inside the triangle formed
   by A(x1, y1), B(x2, y2) and C(x3, y3) */
bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) {
   float A = area(x1, y1, x2, y2, x3, y3);  /* Calculate area of triangle ABC */
   float A1 = area(x, y, x2, y2, x3, y3);   /* Calculate area of triangle PBC */
   float A2 = area(x1, y1, x, y, x3, y3);   /* Calculate area of triangle PAC */
   float A3 = area(x1, y1, x2, y2, x, y);   /* Calculate area of triangle PAB */

   /* Check if sum of A1, A2 and A3 is same as A */
   return (A == A1 + A2 + A3);
}

int main() {
    /* Let us check whether the point P(10, 15) lies inside the triangle
      formed by A(0, 0), B(20, 0) and C(10, 30) */
    /* isInside(0, 0, 20, 0, 10, 30, 10, 15) */
    int x1, y1, x2, y2, x3, y3, x, y;

    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &x2, &y2);
    scanf("%d %d", &x3, &y3);
    scanf("%d %d", &x, &y);

    if(isInside(x1, y1, x2, y2, x3, y3, x, y)) printf("Yes\n");
    else printf("No\n");

    return 0;
}
