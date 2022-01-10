//A palindromic number reads the same both ways. The largest palindrome made 
//from the product of two 2-digit numbers is 9009 = 91 × 99.
//Find the largest palindrome made from the product of two 3-digit numbers.


#include <iostream>

int main ()
{
    const int size = 999;
	int arr1[size] {};
    int arr2[size] {};
    int resulte = 0;
	for (int i = 100; i < size; ++i)
	{
		arr1[i] = i + 1;
        arr2[i] = i + 1;
	}
    for (int i = 100; i < 900; ++i)
    {
        for (int j = 100; j < 900; ++j)
        {
            resulte = arr1[i] * arr2[j];
            int sum = 0;
            int tmp = resulte;
            int mod;
            while (tmp != 0)
            {
                mod = tmp % 10;
                sum = (sum * 10) + mod;
                tmp = tmp / 10;
            }
            if (sum == resulte)
            {
                std::cout << arr1[i] << " * " << arr2[j] << " = " << sum <<std::endl;
            }
        }
    }
}