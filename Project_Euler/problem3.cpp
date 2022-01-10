//The prime factors of 13195 are 5, 7, 13 and 29.
//What is the largest prime factor of the number 600851475143 ?


#include <iostream>

int main() 
{
	unsigned long long factorNumber = 600851475143;
	bool isPrime = true;
	int lastPrime = 2;
		for (int i = lastPrime; i < factorNumber; i++) 
        {	
			isPrime = true;
				for (int j = 2; j < i; j++) 
                {
					if(i % j == 0)
					isPrime = false;
				}
				if(isPrime && (factorNumber % i == 0))
				{
					lastPrime = i;
					factorNumber = factorNumber / i;
				}
			}
	std::cout << factorNumber;
	return 0;
}