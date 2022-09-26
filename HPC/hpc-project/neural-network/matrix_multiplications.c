#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#define N 400

void multiply(double mat1[][N], double mat2[][N], double product[][N]) {
	#pragma omp parallel for shared(mat1, mat2, product)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			product[i][j] = 0;

			for (int k = 0; k < N; k++) {
				product[i][j] += mat1[i][k] * mat2[k][j];
			}
		}
	}
}

int main(void) {
    double mat1[N][N], mat2[N][N], mat3[N][N];

	double start_time = omp_get_wtime();
	#pragma omp parallel for shared(mat1, mat2)
    for (size_t i = 0; i < N; i++)
    {
        for (size_t j = 0; j < N; j++)
        {
            mat1[i][j] = rand()*0.1;
            mat2[i][j] = rand()*0.1;
        }
        
    }

	multiply(mat1, mat2, mat3);

    double end_time = omp_get_wtime();
	printf("\t%f\n", end_time-start_time);
	return(end_time-start_time);

	return 0;
}
