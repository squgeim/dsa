#include<stdio.h>
#include<math.h>

int main(int argc, char **argv) {
	double power;
	int modulo,
		sum,
		i,
		modulo_quotient;

	power = pow(2,1000);
	
	sum = 0;
	while (power > 0) {
		modulo = (int) fmod(power, 10);
		power /= 10;
		sum += modulo;
	}

	printf("%d", sum);
	

	return 0;
}
