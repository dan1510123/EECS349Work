#include <stdio.h>

int main(void) {
	int arr[8] = {12, 15, 221, 3, 432, 54, 16, 67};
	
	int max = 0;
	int x = 0;
	
	while(x < 8) {
		if(arr[x] >= max) {
			max = arr[x];
		}
		x++;
	}
	
	printf("%d", max);
}
