#include <cstdio>
#include <cstdlib>

#include <mkl.h>


int main(int argc, char *argv[]) {

	double fin, inicio = dsecnd(); //Inicialización falsa

	double A[9] = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };
	double B[3] = { 10.0, 11.0, 12.0 };
	double C[3];

	inicio = dsecnd(); //Inicio del cronometraje

	cblas_dgemv(CblasRowMajor, CblasTrans, 3, 3, 1.0, A, 3, B, 1, 0.0, C, 1); //C = A*B

	fin = dsecnd(); //Fin del cronometraje

	for (int i = 0; i < 3; i++)
	{
		printf("%lf\n", C[i]);
	}

	//Report del tiempo en microsegundos
	printf("Tiempo: %lf msec\n", (fin - inicio)*1.0e3);

	std::getchar();
	return 0;
}