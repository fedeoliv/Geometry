#include <stdio.h>
#include <math.h>
#include <vector>

/*  Given n points in a plane find the diameter of the smallest circle that encloses all the points.
    A point lying on the circle is also considered to be inside it.

    Input: (1, 1), (1, 0), (0, 1), (0, 0)
    Output: 1.41 */

using namespace std;

struct point {
	int x, y;
};

int main() {
	int n;
	float max = 0;
	vector <point> points;
	point temp;

	scanf("%d", &n);

	for(int i = 0; i < n; ++i) {
		scanf("%d %d", &temp.x, &temp.y);
		points.push_back(temp);
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			float dist = (points[i].x - points[j].x)*(points[i].x - points[j].x) +
                         (points[i].y - points[j].y)*(points[i].y - points[j].y);

			if(max < dist) max = dist;
		}
	}

	max = sqrt(max);
	max = floor (max*100 + 0.5)/100;
	printf("%.2f", max);

	return 0;
}
