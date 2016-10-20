#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

bool isNotEven(int x)
{
	if (x % 2 != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isNotDiv2or3(int x)
{
	if ((x % 2 != 0) && (x % 3 != 0))
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool isPrime(int x)
{
	int Sqt = sqrt(x);
	for (int i = 2; i < Sqt; i++)
	{
		if (x%i == 0)
		{
			return false;
		}
	}
	return true;
}

void updateTopk(int topk[], int k, int x)
{
	if (x > topk[0]) 
	{
		int i = 0;
			while (x > topk[i] && i < k)
			{
				topk[i] = topk[i + 1];
				i++;
			}
			topk[i - 1] = x;
	}

}

int  main()
{
	ifstream file("C:/Users/Christopher/Documents/Freshmen Year/ComputerScience/input.txt");
	int x = 0;
	int counter = -1;
	int odd_counter = 0;
	int twoThreeCounter = 0;
	int P_counter = -1;
	int k = 10;
	int topK [10];
	int topKprimes[10];
	while (x != -1)
	{
		file >> x;
		if (isNotEven(x))
		{
			odd_counter++;
		}
		if (isNotDiv2or3(x))
		{
			twoThreeCounter++;
		}
		if (isPrime(x))
		{
			P_counter++;
			updateTopk(topKprimes, k, x);
		}
		updateTopk(topK, k, x);
		counter++;
	}
	cout << "Numbers read in = " << counter << endl;
	cout << "Numbers not even = " << odd_counter << endl;
	cout << "Numbers not divisible by 2 or 3  = " << twoThreeCounter << endl;
	cout << "Prime numbers = " << P_counter << endl;
	cout << "The top 10 = " << endl;
	for (int i = 0; i < k; i++)
	{
		cout << topK[i] << endl;
	}
	cout << "The top 10 Primes = " << endl;
	for (int i = 0; i < k; i++)
	{
		cout << topKprimes[i] << endl;
	}
}