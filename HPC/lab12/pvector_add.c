#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <limits.h>
#include <math.h>

int main() {
	int N = 100000;

	double arr1[N];
	double arr2[N];
	double arr_sum[N];

	for(int i=0; i<N; i++) {
		arr1[i] = rand()*00000.34;
		arr2[i] = rand()*00000.36;
	}
	
	double start_time = omp_get_wtime();
	//printf("start_time: %f\n", start_time);
	
	#pragma omp parallel for shared(arr1, arr2, arr_sum, N)
	for(int i=0; i < N; i++) 
		arr_sum[i] = arr1[i] + arr2[i];

	double end_time = omp_get_wtime();
	//printf("end_time: %f\n", end_time);

	printf("total_time: %f\n", end_time-start_time);

	return(end_time-start_time*10000);
}
	
