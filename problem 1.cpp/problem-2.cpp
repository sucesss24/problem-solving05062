#include <bits/stdc++.h>
using namespace std;
int flipSign(int a)
{
	int neg = 0;

	int tmp = a < 0 ? 1 : -1;
	while (a != 0)
	{
		neg += tmp;
		a += tmp;
	}
	return neg;
}


bool areDifferentSign(int a, int b)
{
	return ((a<0 && b> 0) || (a > 0 && b < 0));
}

int sub(int a, int b)
{
	
	return a + flipSign(b);
}


int mul(int a, int b)
{

	if (a < b)
		return mul(b, a);


	int sum = 0;
	for (int i = abs(b); i > 0; i--)
		sum += a;

	
	if (b < 0)
		sum = flipSign(sum);

	return sum;
}

int division(int a, int b)
{
	
	if (b == 0)
		throw(b);

	int quotient = 0, dividend;

	
	int divisor = flipSign(abs(b));

	
	for (dividend = abs(a); dividend >= abs(divisor);
								dividend += divisor)
		quotient++;

	
	if (areDifferentSign(a, b))
		quotient = flipSign(quotient);
	return quotient;
}


int main()
{
int a;
int b;
 cout<<"ENTER TWO NUMBER:";
    cin>>a>>b;
	cout << "Subtraction is " << sub(a, b) << endl;
	cout << "Product is " << mul(a, b) << endl;

	try
	{
		cout << "Division is " << division(a, b);
	}

	catch (int k)
	{
		cout << " Exception :- Divide by 0";
	}
	return 0;
}