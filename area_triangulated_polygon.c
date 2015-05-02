#include <stdbool.h>
#include <math.h>
#define MAXPOLY		200	    /* maximum number of points in a polygon */
#define DIMENSION	2	    /* dimension of points */
#define X 0	                /* x-coordinate index */
#define	Y 1	                /* y-coordinate index */
#define EPSILON	0.000001	/* a quantity small enough to be zero */


/*	Triangulate a polygon and compute the area of a polygon.
    Input:  6           Output: Area = 27.5
            7 0
            6 2
            9 5
            3 5
            0 3
            1 1*/


typedef double point[DIMENSION];
typedef point triangle[3];	        /* triangle datatype */

typedef struct {
	int n;			    /* number of triangles in triangulation */
	int t[MAXPOLY][3];	/* indicies of vertices in triangulation */
} triangulation;

typedef struct {
	int n;			    /* number of points in polygon */
	point p[MAXPOLY];	/* array of points in polygon */
} polygon;

void copy_point(point a, point b) {
	int i;
	for (i = 0; i < DIMENSION; i++) b[i] = a[i];
}

double signed_triangle_area(point a, point b, point c) {
	return( (a[X]*b[Y] - a[Y]*b[X] + a[Y]*c[X]
		- a[X]*c[Y] + b[X]*c[Y] - c[X]*b[Y]) / 2.0 );
}

double triangle_area(point a, point b, point c) {
	return(fabs(signed_triangle_area(a,b,c)));
}

bool cw(point a, point b, point c) {
	double signed_triangle_area();
	return (signed_triangle_area(a,b,c) < - EPSILON);
}

bool point_in_triangle(point p, triangle t) {
	int i;
	bool cw();

	for (i = 0; i < 3; i++)
		if (cw(t[i], t[(i+1)%3], p)) return false;
	return true;
}

bool ear_Q(int i, int j, int k, polygon *p) {
	triangle t;			/* coordinates for points i,j,k */
	int m;				/* counter */
	bool cw();

	copy_point(p->p[i], t[0]);
	copy_point(p->p[j], t[1]);
	copy_point(p->p[k], t[2]);

	if (cw(t[0],t[1],t[2])) return false;

	for (m = 0; m < p->n; m++) {
		if ((m!=i) && (m!=j) && (m!=k))
			if (point_in_triangle(p->p[m],t)) return false;
	}

	return true;
}

triangulate(polygon *p, triangulation *t) {
	int l[MAXPOLY], r[MAXPOLY];	        /* left/right neighbor indices */
	int i;				                /* counter */

	for (i = 0; i < p->n; i++) {	        /* initialization */
		l[i] = ((i-1) + p->n) % p->n;
		r[i] = ((i+1) + p->n) % p->n;
	}

	t->n = 0;
	i = p->n-1;

	while (t->n < (p->n-2)) {
		i = r[i];
		if (ear_Q(l[i],i,r[i],p)) {
			add_triangle(t, l[i], i, r[i], p);
			l[r[i]] = l[i];
			r[l[i]] = r[i];
		}
	}
}

add_triangle(triangulation *t, int i, int j, int k, polygon *p) {
	int n = t->n;	    /* number of triangles in t */

	t->t[n][0] = i;
	t->t[n][1] = j;
	t->t[n][2] = k;
	t->n = n + 1;
}

double area_triangulation(polygon *p) {
	triangulation t;                /* output triangulation */
	double total = 0.0;		        /* total area so far */
    int i;                         /* counter */
	double triangle_area();

	triangulate(p,&t);
	for (i = 0; i < t.n; i++)
        total += triangle_area(p->p[t.t[i][0]], p->p[t.t[i][1]], p->p[t.t[i][2]]);
	return total;
}

double area(polygon *p) {
	double total = 0.0;		/* total area so far */
	int i, j;			    /* counters */

	for (i = 0; i < p->n; i++) {
		j = (i+1) % p->n;
		total += (p->p[i][X]*p->p[j][Y]) - (p->p[j][X]*p->p[i][Y]);
	}

	return(total / 2.0);
}

print_triangulation(triangulation *t) {
	int i, j;			    /* counters */

	for (i = 0; i < t->n; i++) {
		for (j = 0; j < 3; j++)
            printf("%d ", t->t[i][j]);
		printf("\n");
	}
}

int main() {
	polygon p;			    /* input polygon */
	triangulation t;		/* output triangulation */
	int i;

	scanf("%d", &p.n);

	for (i = 0; i < p.n; i++)
		scanf("%lf %lf", &p.p[i][X], &p.p[i][Y]);

	triangulate(&p,&t);
	print_triangulation(&t);

	printf("Area via triangulation = %f\n", area_triangulation(&p));
	printf("Area slick = %f\n", area(&p));

    return 0;
}
