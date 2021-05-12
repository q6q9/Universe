#include <stdio.h> 
#include <math.h> 
#include <locale.h> 

int main() {
	setlocale(LC_ALL, "Rus");
	double eps;
	printf("Введите эпсилон от 0 до 1\n");
	scanf_s("%lf", &eps);
	printf("%lf", eps);
	if ((eps > 0 && eps < 1)) {
		int i = 1;
		double s = (powl(-1, i)) / sqrt(i);
		double tek = s;
		double pred = 0;
		do {
			printf("sum = %f, i = %d, tek = %f\n", s, i, tek);
			pred = tek;
			i++;
			double h = ((-1) * (sqrt(i - 1))) / (sqrt(i));
			tek *= h;
			s += tek;
		} while ((fabs(pred) - fabs(tek)) >= eps);
		printf("Сумма = %f", s);
	}
	else {
		printf("Неверный эпсилон");
	}
	return 0;
}