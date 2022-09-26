#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#define N 500  // dimensions of the matrix

void add(double A[][N], double B[][N], double C[][N])
{
	int i, j;

	#pragma omp parallel for shared(A, B, C)
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			C[i][j] = A[i][j] + B[i][j];
}

int main()
{
	double A[N][N], B[N][N], C[N][N];

	// #pragma omp parallel for shared(A, B)
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            A[i][j] = rand()*99.0;
            B[i][j] = rand()*99.0;
        }
        
    }
    
	double start_time = omp_get_wtime();
	add(A, B, C);

    double end_time = omp_get_wtime();
	printf("\t%f\n", end_time-start_time);
	return(end_time-start_time);

    // printf("A = \n");
    // for (int i = 0; i < N; i++)
	// {
	// 	for (int j = 0; j < N; j++)
	// 	printf("%f ", A[i][j]);
	// 	printf("\n");
	// }
	// printf("B = \n");
    // for (int i = 0; i < N; i++)
	// {
	// 	for (int j = 0; j < N; j++)
	// 	printf("%f ", B[i][j]);
	// 	printf("\n");
	// }
	// printf("C = \n");
	// for (int i = 0; i < N; i++)
	// {
	// 	for (int j = 0; j < N; j++)
	// 	printf("%f ", C[i][j]);
	// 	printf("\n");
	// }

	return 0;
}
