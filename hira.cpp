
#include <iostream>
#include<cmath>
using namespace std;

int main()
{
	int choice = 0;
	char Qn;
	int lenght, next, a, b, i,iterations,n,reversed,isprime,sum;
	do
	{
		cout << "Please Enter QN:1,2, 3, 4, 5, 6, 7\t";
		cin >> Qn;
		switch (Qn)
		{
		
		case '1':
			// put code for q3
			
			lenght = 0;
			a = 0;
			b = 0;
			cout << "enter the length of the series" << endl;
			cin >> lenght;
			a = 0; a = 1;
			cout << "generated series" << endl;
			for (i = 0; i < lenght;++i)
			{
				if (i % 2 == 0)
				{
					next = a - b;
					cout << "next" << " ";
					a = b;
					b = next;
				}
				else
				{
					int next = a + b;
					cout << a + b;
					cout << " " << next << endl;
					a = b;
					b = next;

				}
			}

			break;

		case '2':
			// code to be executed if
			// expression is equal to constant2;

		   iterations = 0;
			cout << "enter a integer" << endl;
			cin >> n;
			while (n >3 && iterations < 40){
				cout << n << "";
				if (n<10 && n % 2 == 0){
					n = n * 5;

				}
				else if (n>10 && n % 2 == 0){
					n = n / 2;

				}
				else {
					n = (n * 3) + 1;

				}
				iterations++;
			}
			cout << n;
			cout << endl;
			
			break;

		case '3':
			// put code for q3
		{
			int n;
			cout << "enter an integer" << endl;
			cin >> n;
			for (int i = 1; i <= n; ++i){
			cout << "divisors of" << i << endl;
			int count = 0;
			for (int j = 1; j <= 1; ++j){
			if (i%j == 0){
			cout << j << " ";
			count++;
			}
			}
			cout << "(" << ((count % 2 == 0) ? "even" : "odd") << ")" << endl;
			
			}
			break;

		case '4':
			// code to be executed if
			// expression is equal to constant2;
			
			bool isPrime(int num)
			
				if (num <= 1)
				{
					return false;
				}

				for (int i = 2; i <= sqrt(num); i++)
				{
					if (num % i == 0)
					{
						return false;
					}
					else
					{
						return true;
					}
				}
			
		
		
			
				


			break;

		case '7':
			// code to be executed if
			// expression is equal to constant2;
			break;

		default:
			cout << "Wrong Input \n";

		}
		cout << "\nPress 1 if you want to ReRun this programe\n Press any other key to exit";
		cin >> choice;
	} while (choice == 1);

	system("pause");

	return 0;
}