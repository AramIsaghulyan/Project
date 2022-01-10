//If we list all the natural numbers below 10 that are multiples of 3 or 5, 
//we get 3, 5, 6 and 9. The sum of these multiples is 23.
//Find the sum of all the multiples of 3 or 5 below 1000.

#include <iostream>
#include <algorithm>

int multiples (int *arr, int size);

int main ()
{
	const int size = 1000;
	int arr[size] {};
	for (int i = 0; i < size; ++i)
	{
		arr[i] = i + 1;
	}
	std::cout << multiples (arr,size);
	return 0;
}

int multiples (int *arr, int size)
{
	int sum = 0;
	for (int i = 0; i < size - 1; ++i)
	{
		if (arr[i] % 3 == 0 || arr[i] % 5 == 0)
		{
			sum = arr[i] + sum;			
		}
	}
	return sum;
}
