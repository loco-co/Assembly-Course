#include <stdio.h>
#include <math.h>

struct coord{ float x, y;};

float f_input() {
	float v;
	scanf("%f",&v);
	return v;
}

void printf_float(float v) {
    printf("%f\n",v);
}

struct coord getCoord() {
    struct coord p;
	p.x = f_input();
	p.y = f_input();
    return p;
}

float getLength(struct coord *p1, struct coord *p2) {
	float x_len = (p1->x - p2->x);	
	float y_len = (p1->y - p2->y);	
	return sqrt( x_len*x_len + y_len*y_len);
}

int main(void){
	struct coord p[3];
	p[0] = getCoord();
	p[1] = getCoord();
	p[2] = getCoord();
	
	float area = ( p[0].x*(p[1].y-p[2].y) + p[1].x*(p[2].y-p[0].y) + p[2].x*(p[0].y-p[1].y) ) / 2.0;
	if(area <0) area *= -1;
	printf_float(area);

	float perimeter = getLength(&p[0],&p[1]) +  getLength(&p[0],&p[2]) +  getLength(&p[1],&p[2]);
	printf_float(perimeter);

	return 0;
}
