#include <stdio.h>
#include <math.h>

int main(){
	double r, degree;
	char str[10];
	const double pi = acos(-1);
	while( ~scanf("%lf %lf %s", &r, &degree, str) ){
		r += 6440;
		if(str[0] == 'm'){
			degree /= 60; 
		}
		if(degree > 180){
			degree = 360 - degree;
		}
		double arc = (double)r * 2.0 * pi * degree/360;
		double chord = (double)r * 2 * sin(degree * pi/360.0);
		printf("%lf %lf\n", arc, chord);
	}
	return 0;
}
