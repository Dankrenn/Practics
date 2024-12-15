#include<stdio.h>
#include<math.h>
struct point {
	float x;
	float y;
	char name;
};
typedef struct point Point;

void put_point(Point z) {
	printf("point %c (%.1f, %.1f)", z.name, z.x, z.y);
}
float dist(Point z, Point w) {
	float dist = pow(pow((w.x - z.x), 2) + pow((w.y - z.y), 2), 0.5);
	printf("Distance = %f", dist);
}
void average(Point a, Point b) {
	Point c;
	c.x = (a.x + b.x) / 2;
	c.y = (a.y + b.y) / 2;
	printf("Average point: (%.1f %.1f)", c.x, c.y);
}
void which_quarter(Point z) {
	int quarter = 0;
	if (z.x > 0 && z.y > 0) quarter = 1;
	else if (z.x < 0 && z.y>0) quarter = 2;
	else if (z.x < 0 && z.y < 0) quarter = 3;
	else if (z.x > 0 && z.y < 0) quarter = 4;
	else quarter = 0;
	printf("Point %c belongs to %d quarter.", z.name, quarter);
}

void main() {
	Point b, a;
	a = (Point){ 1.f,2.f,'A' };
	b.name = 'B'; b.x = 5; b.y = -3;
	put_point(a);
	printf("\n");
	put_point(b);
	printf("\n");
	dist(a, b);
	printf("\n");
	average(a, b);
	printf("\n");
	which_quarter(a);

}