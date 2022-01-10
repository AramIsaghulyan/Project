//The sum of the squares of the first ten natural numbers is,
//The square of the sum of the first ten natural numbers is,
//Hence the difference between the sum of the squares of the 
//first ten natural numbers and the square of the sum is
//Find the difference between the sum of the squares of the first 
//one hundred natural numbers and the square of the sum.

#include <iostream>
#include <cmath>

int main()
{
    const int size = 100;
	int arr[size] {};
    int pow_resulte1 = 0;
    int pow_resulte2 = 0;
    int resulte = 0;
    int sum1 = 0;
    int sum2 = 0;
	for (int i = 0; i < size; ++i)
	{
		arr[i] = i + 1;
	}    
    for (int i = 0; i < size; ++i)
    {
        pow_resulte1 = pow(arr[i],2);
        sum1 = pow_resulte1 + sum1;
    }
    std::cout << "The sum of the squares of the first ten natural numbers is: "  << sum1 << std::endl;
    for (int j = 0; j < size; ++j)
    {
        sum2 = arr[j] + sum2;
    }
    pow_resulte2 = pow(sum2,2);
    std::cout << "The square of the sum of the first ten natural numbers is: " << pow_resulte2 << std::endl;
    resulte = pow_resulte2 - sum1;
    std::cout << "Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is: " <<
    pow_resulte2 << " - " << sum1 << " = " << resulte;
}