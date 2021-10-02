#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <stdio.h> // for printf

using namespace std;

// Tasks:
// проработать алгоритм с отрицательными процентами 
// проверка вводимых данных через while

void f2rew() { 
	double S, n, r, m, error = 0.1, m_guess, step;
	cout << "Введите величину суммы S:\n";
	cin >> S;
	cout << "Введите величину месячных выплат m:\n";
	cin >> m;
	cout << "Введите количество лет n:\n";
	cin >> n;
	int x = m, deg_of_err = -8;
	while (x > 0)
	{
		deg_of_err += 1; // degree of e in error
		x /= 10;
	}
	error = pow(10, (deg_of_err)); // margin of error (depends on number of digits of m)
	if (m > S) // checking the availability to pay arrears before interest will be accrued
	{
		cout << "Кредит выплачен первым платежом (т.к. проценты начисляются после 1го месяца, а m > S).\nОпределить процент, под который выдана ссуда, невозможно.\n";
	}
	else if (S / (n * 12) == m) // condition for percentage == 0
	{
		cout << "Кредит выдан под нулевой процент.\n";
	}
	else if (S / (n * 12) > m) // condition for percentage < 0
	{
		int iter = 0;
		step = 1; // доработать шаг начальное значение
		r = 1; // доработать r начальное значение
		m_guess = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
		while (fabs(m_guess - m) >= error)
		{
			iter += 1;
			printf("m_guess = %lf\t\t r = %lf\t\t iter = %d\t\t\n", m_guess, r, iter);
			if (m_guess > m)
			{
				r-= step;
				step /= 2;
			}
			if (2 * m_guess < m)
			{
				step *= 2;
			}
			r += step;
			m_guess = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
		}
		//cout << "Отрицательный результат: Cумма величиной " << S << ", которая гасится месячными выплатами величиной " << m << " в течение " << n << " лет, выдана под процент " << r * 100 << " (с точностью до" << error << ").\n" << endl;
		printf("\nm_guess = %lf\t\t r = %lf\t\t iter = %d\t\t\n", m_guess, r, iter);
		printf("\nОтрицательный результат: Cумма величиной %.2lf, которая гасится месячными выплатами величиной %.2lf в течение %.2lf лет, выдана под процент %lf (с погрешностью +- %lf).\n\n", S, m, n, r * 100, error);
	}
	else // condition for percentage > 0
	{
		int iter = 0;
		step = 1;
		r = 1;
		m_guess = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
		while (fabs(m_guess - m) >= error)
		{
			iter += 1;
			printf("m_guess = %lf\t\t r = %lf\t\t iter = %d\t\t\n", m_guess, r, iter);
			//cout << "m_guess = " << setw(8) << m_guess << setw(10) << " r = " << setw(15) << r << setw(10) << " iter = " << setw(5) << iter << setw(10) << endl;
			if (m_guess > m)
			{
				r -= step;
				step /= 2;
			}
			if (2 * m_guess < m)
			{
				step *= 2;
			}
			r += step;
			m_guess = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
		}
		//cout << "\nm_guess = " << m_guess << "\t\t" << " r = " << r << "\t\t" << " iter = " << iter << "\t\t" << endl << endl;
		//cout << "Положительный результат: Cумма величиной "<< S << ", которая гасится месячными выплатами величиной " << m << " в течение " << n  << " лет, выдана под процент " << r * 100 << " (с погрешностью +- " << error << ").\n" << endl;
		printf("\nm_guess = %lf\t\t r = %lf\t\t iter = %d\t\t\n", m_guess, r, iter);
		printf("\nПоложительный результат: Cумма величиной %.2lf, которая гасится месячными выплатами величиной %.2lf в течение %.2lf лет, выдана под процент %lf (с погрешностью +- %lf).\n\n", S, m, n, r * 100, error);
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