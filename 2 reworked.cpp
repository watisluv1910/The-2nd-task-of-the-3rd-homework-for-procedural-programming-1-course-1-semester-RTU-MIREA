#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <stdio.h> // for printf

using namespace std;

// Tasks:
// проработать алгоритм с отрицательными процентами * done
// проверка вводимых данных через while
// доработать r начальное значение
// доработать step начальное значение

void f2rew() { 
	double Sum, years, fractional_percent, monthly_payment, error = 0.1, monthly_payment_guess, step;
	cout << "Введите величину суммы Sum:\n";
	cin >> Sum;
	cout << "Введите величину месячных выплат m:\n";
	cin >> monthly_payment;
	cout << "Введите количество лет n:\n";
	cin >> years;
	int x = monthly_payment, deg_of_err = -8;
	while (x > 0)
	{
		deg_of_err += 1; // degree of e in error
		x /= 10;
	}
	error = pow(10, (deg_of_err)); // margin of error (depends on number of digits of m)
	if (monthly_payment > Sum) // checking the availability to pay arrears before interest will be accrued
	{
		cout << "Кредит выплачен первым платежом (т.к. проценты начисляются после 1го месяца, а m > Sum).\nОпределить процент, под который выдан кредит, невозможно.\n";
	}
	else if (Sum / (years * 12) == monthly_payment) // condition for percentage == 0
	{
		cout << "Кредит выдан под нулевой процент.\n";
	}
	else if (Sum / (years * 12) > monthly_payment) // condition for percentage < 0
	{
		int iteration = 0;
		double fractional_percent = (monthly_payment * years * 12 - Sum) / Sum;
		printf("\nОтрицательный результат: Cумма величиной %.2lf, которая гасится месячными выплатами величиной %.2lf в течение %.2lf лет, выдана под процент %lf.\n\n", Sum, monthly_payment, years, fractional_percent * 100);
	}
	else // condition for percentage > 0
	{
		int iter = 0;
		step = 1;
		fractional_percent = 1;
		monthly_payment_guess = Sum * fractional_percent * pow((1 + fractional_percent), years) / (12 * (pow((1 + fractional_percent), years) - 1));
		while (fabs(monthly_payment_guess - monthly_payment) >= error)
		{
			iter += 1;
			printf("m_guess = %lf\t\t r = %lf\t\t iter = %d\t\t\n", monthly_payment_guess, fractional_percent, iter);
			if (monthly_payment_guess > monthly_payment)
			{
				fractional_percent -= step;
				step /= 2;
			}
			if (2 * monthly_payment_guess < monthly_payment)
			{
				step *= 2;
			}
			fractional_percent += step;
			monthly_payment_guess = Sum * fractional_percent * pow((1 + fractional_percent), years) / (12 * (pow((1 + fractional_percent), years) - 1));
		}
		printf("\nm_guess = %lf\t\t r = %lf\t\t iter = %d\t\t\n", monthly_payment_guess, fractional_percent, iter);
		printf("\nПоложительный результат: Cумма величиной %.2lf, которая гасится месячными выплатами величиной %.2lf в течение %.2lf лет, выдана под процент %lf (с погрешностью +- %lf).\n\n", Sum, monthly_payment, years, fractional_percent * 100, error);
	}
}

int main() {
	int counter;
	setlocale(LC_ALL, "Russian");
	cout << "Номер задачи не превышает 2.\n" << "Чтобы закончить работу, введите 0.\n";
	cout << "Введите номер задачи: \n";
	cin >> counter;
	while (counter > 0)
	{
		switch (counter)
		{
		case 1:
			cout << "Для просмотра 1й и последующих задач из ДЗ №3 пройдите по пути:\nD:/Microsoft VS source/C++/Home Tasks/1 курс/ДЗ №4 на 5ю неделю/4.\n";
			break;
		case 2:
			f2rew();
			break;
		default:
			cout << "Номер задачи не превышает 2.\n" << "Чтобы закончить работу, введите 0.\n";
			break;
		}
		cout << "Введите номер следующей задачи: \n";
		cin >> counter;
	}
}