#include <stdlib.h>
#include <stdio.h>

int main() {
	#pragma omp parallel
	{
		printf("Hello");
		printf("World");
	}
	printf("\n");
	return(0);
}
