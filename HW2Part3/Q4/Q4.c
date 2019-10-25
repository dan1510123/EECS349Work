#include <stdio.h>

int proc1(int* x, int y, int z);
int main(void) {
	int x = 7;
	int y = 100;
	int z = 0;
	
	int arr[100];
	
	while(z < y) {
		arr[z] = z + 1;
		z++;
	}
	
	printf("%d", proc1(arr, y, x));
	return 0;
}

int proc1(int * x, int y, int z) {
	int a = 0;
	int b = 0;
	int c = 0;
	int d;
	
	while(c < y) {
		d = 1;
		while(d < z) {
			while(x[a] == 0) {
				a = (a + 1) % y;
			}
			d++;
			a = (a + 1) % y;
		}
		while(x[a] == 0) {
			a = (a + 1) % y;
		}
		b = x[a];
		x[a] = 0;
		c++;
	}
	
	return b;
}
