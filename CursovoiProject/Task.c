#include<stdio.h>
#include<math.h>
#include<float.h>
#include<locale.h>
double f(double x);
double derivative(double x);
void one();
void two();
void three();
void four();
void five();
int main() {
	setlocale(LC_ALL, "RUS");
	printf("Меню возможных операций.\n");
	printf("1) Значение функции в точке.\n");
	printf("2) Таблица - x->f(x) на интервале.\n");
	printf("3) Min/max - экстремумы на отрезке.\n");
	printf("4) Поиск x - найти x: f(x) = Y.\n");
	printf("5) Производная - f'(x) в точке.\n");
	printf("Введите номер операции: ");
	char z;
	scanf("%c", &z);
	switch (z) {
	case '1':
		one();
		break;
	case '2':
		two();
		break;
	case '3':
		three();
		break;
	case '4':
		four();
		break;
	case '5':
		five();
		break;
	default:
		printf("Операция невозможна!");
	}
	return 0;
}
double f(double x) {
	if (x < 0) {
		return pow(x, 2) + 1;
	}
	else if (x >= 3) {
		double sum = 0;
		for (int n = 0; n <= 13; n++) {
			double a = (pow(-1, n) * pow(x, 2 * n + 1));
			double b = (tgamma(2 * n + 1) * (n + 1));
			sum = sum + a / b;
		}
		return sum;
	}
	else {
		return ((exp(sin(x)) * log(1 + fabs(x))) / (sqrt(pow(x, 2) + 1))) + atan(pow(x, 3));
	}
}
double derivative(double x) {
	double h = 1e-6;
	return (f(x + h) - f(x - h)) / (2 * h);
}
void one() {
	double x;
	printf("Введите x: ");
	scanf("%lf", &x);
	printf("f(%lf)=%lf", x, f(x));
}
void two() {
	double start;
	double finish;
	double step;
	printf("Введите начало интервала: ");
	scanf("%lf", &start);
	printf("Введите конец интервала: ");
	scanf("%lf", &finish);
	printf("Введите шаг: ");
	scanf("%lf", &step);
	for (double x = start; x <= finish; x += step) {
		printf("f(%lf) = %lf\n", x, f(x));
	}
}
void three() {
	double start;
	double finish;
	double step;
	printf("Введите начало отрезка: ");
	scanf("%lf", &start);
	printf("Введите конец отрезка: ");
	scanf("%lf", &finish);
	printf("Введите шаг поиска: ");
	scanf("%lf", &step);
	double min_val;
	double max_val;
	double min_x;
	double max_x;
	min_val = DBL_MAX;
	max_val = -DBL_MAX;
	min_x = start;
	max_x = start;
	for (double x = start; x <= finish; x += step) {
		double fx = f(x);
		if (fx < min_val) {
			min_val = fx;
			min_x = x;
		}
		if (fx > max_val) {
			max_val = fx;
			max_x = x;
		}
	}
	printf("Минимум: f(%lf) = %lf\n", min_x, min_val);
	printf("Максимум: f(%lf) = %lf\n", max_x, max_val);
}
void four() {
	setlocale(LC_ALL, "RUS");
	double y, prec, start, finish;
	int found = 0;
	printf("Введите Y: ");
	scanf("%lf", &y);
	printf("Введите точность: ");
	scanf("%lf", &prec);
	printf("Введите начало интервала поиска: ");
	scanf("%lf", &start);
	printf("Введите конец интервала поиска: ");
	scanf("%lf", &finish);
	for (double x = start; x <= finish; x += prec) {
		if (fabs(f(x) - y) < prec) {
			printf("x = %.6lf, f(x) = %.6lf\n", x, f(x));
			found = 1;
		}
	}
}
void five() {
	double x;
	printf("Введите x: ");
	scanf("%lf", &x);
	printf("f'(%lf)=%f\n", x, derivative(x));
}