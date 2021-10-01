#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

void f2rew() { // сделать красивый вывод через printf
	double S, n, r, m, k = 0.1, m_guess, shag, count = 0; // разобраться с зависимостью k от m

	cout << "Введите S:\n";
	cin >> S;
	cout << "Введите m:\n";
	cin >> m;
	cout << "Введите n:\n";
	cin >> n;
	/*float x = m;
	while (x > 0)
	{
		count += 1;
		x /= 10;
	}
	k = pow(10, (count - 5));*/
	if (S / (n * 12) == m)
	{
		cout << "Кредит выдан под нулевой процент.\n";
	}
	else if (S / (n * 12) > m)
	{
		int iter = 0;
		shag = 1; // доработать шаг начальное значение
		r = 1; // доработать r начальное значение
		m_guess = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
		while (fabs(m_guess - m) >= k)
		{
			iter += 1;
			cout << "m_guess = " << m_guess << " r =" << r << " iter = " << iter << endl;
			if (m_guess > m)
			{
				r -= shag;
				shag /= 2;
			}
			if (2 * m_guess < m)
			{
				shag *= 2;
			}
			r += shag;
			m_guess = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
		}
		//cout << "Отрицательный результат: Cумма величиной " << S << ", которая гасится месячными выплатами величиной " << m << " в течение " << n << " лет, выдана под процент " << r * 100 << " (с точностью до" << k << ").\n" << endl;
		printf("\nm_guess = %lf\t r = %lf\t iter = %d\t\n", m_guess, r, iter);
		printf("\nПоложительный результат: Cумма величиной %.2lf, которая гасится месячными выплатами величиной %.2lf в течение %.2lf лет, выдана под процент %.5lf (с погрешностью +- %.2lf).\n\n", S, m, n, r * 100, k);
	}
	else
	{
		int iter = 0;
		shag = 1;
		r = 1;
		m_guess = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
		while (fabs(m_guess - m) >= k)
		{
			iter += 1;
			printf("m_guess = %lf\t r = %lf\t iter = %d\t\n", m_guess, r, iter);
			//cout << "m_guess = " << setw(8) << m_guess << setw(10) << " r = " << setw(15) << r << setw(10) << " iter = " << setw(5) << iter << setw(10) << endl;
			if (m_guess > m)
			{
				r -= shag;
				shag /= 2;
			}
			if (2 * m_guess < m)
			{
				shag *= 2;
			}
			r += shag;
			m_guess = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
		}

		//cout << "m_guess = " << m_guess << setw(10) << " r = " << r << setw(10) << " iter = " << iter << setw(10) << endl << endl;
		//cout << "Положительный результат: Cумма величиной "<< S << ", которая гасится месячными выплатами величиной " << m << " в течение " << n  << " лет, выдана под процент " << r * 100 << " (с погрешностью +- " << k << ").\n" << endl;
		printf("\nm_guess = %lf\t r = %lf\t iter = %d\t\n", m_guess, r, iter);
		printf("\nПоложительный результат: Cумма величиной %.2lf, которая гасится месячными выплатами величиной %.2lf в течение %.2lf лет, выдана под процент %.5lf (с погрешностью +- %.2lf).\n\n", S, m, n, r * 100, k);
	}
}

int main() {
	int counter;
	setlocale(LC_ALL, "Russian");
	cout << "Номер задачи не превышает 5.\n" << "Чтобы закончить работу, введите 0.\n";
	cout << "Введите номер задачи: \n";
	cin >> counter;
	while (counter > 0)
	{
		switch (counter)
		{
		case 1:
			//f1();
			break;
		case 2:
			f2rew();
			break;
		case 3:
			//f3();
			break;
		case 4:
			//f4();
			break;
		case 5:
			//f5();
			break;
		default:
			cout << "Номер задачи не превышает 5.\n" << "Чтобы закончить работу, введите 0.\n";
			break;
		}
		cout << "Введите номер следующей задачи: \n";
		cin >> counter;
	}
}