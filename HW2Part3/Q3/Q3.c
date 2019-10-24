#include <stdio.h>

int main(void) {
	int a = 100;
	while(a < 1000) {
		int b = a / 100;
		int c = ((-100 * b) + a) / 10;
		int d = a - 2*(a / 10 * 5);
		
		if(a == b * b * b + c * c * c +  d * d * d) {
			printf("%d ", a);
		}
		a = a + 1;
	}
	return 0;
}


