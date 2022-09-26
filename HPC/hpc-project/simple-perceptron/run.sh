g++ -fopenmp -o main_parallel main_parallel.cpp
export OMP_NUM_THREADS=$1
./main_parallel
