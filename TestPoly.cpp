#include "Poly.h" // Defines class Poly
#include <iostream>

using namespace std;

void display(const Poly &p1, const Poly &p2);
void test(const Poly &p1, const Poly &p2);
void testAddition(const Poly &p1, const Poly &p2);
void testSubtraction(const Poly &p1, const Poly &p2);
void testMultiplication(const Poly &p1, const Poly &p2);
void testNegation(const Poly &p1, const Poly &p2);
void testValue(const Poly &p1, const Poly &p2);

int main()
{
	Poly p1;   // Declare object representing polynomial p1
	p1[3] = 2; // Specify coefficients of p1 = 2x^3 + 3.6x + 7
	p1[1] = 3.6;
	p1[0] = 7;

	Poly p2 = 5; // Declare object representing polynomial p2 = 5
	p2[4] = 1;	 // Specify additional coefficients of p2 = x^4 - 6x^2 + 3x + 5
	p2[2] = -6;
	p2[1] = 3;

	display(p1, p2);
	test(p1, p2);
}

void display(const Poly &p1, const Poly &p2)
{
	cout << "Polynomial p1: " << p1 << endl;
	cout << "Polynomial p2: " << p2 << endl;
}

void test(const Poly &p1, const Poly &p2)
{
	testAddition(p1, p2);
	testSubtraction(p1, p2);
	testMultiplication(p1, p2);
	testNegation(p1, p2);
	testValue(p1, p2);
}

void testAddition(const Poly &p1, const Poly &p2)
{
	Poly p = (p1 + p2);
	cout << "Sum of polynomials p1 and p2: " << p << endl;

	p = p1 + 3.1;
	cout << "Sum of polynomial p1 and 3.1: " << p << endl;

	p = 3.1 + p1;
	cout << "Sum of 3.1 and polynomial p1: " << p << endl;
}

void testSubtraction(const Poly &p1, const Poly &p2)
{
	cout << "Difference of polynomials p1 and p2: " << p1 - p2 << endl;
	cout << "Difference of polynomials p1 and p1: " << p1 - p1 << endl; // Should display 0 (not 0x^3 + 0x + 0)
	cout << "Difference of polynomial p1 and 7.2: " << p1 - 7.2 << endl;
	cout << "Difference of 7.2 and polynomial p1: " << 7.2 - p1 << endl;
}

void testMultiplication(const Poly &p1, const Poly &p2)
{
	cout << "Product of polynomials p1 and p2: " << p1 * p2 << endl;
	cout << "2 multiplied by polynomial p1: " << 2 * p1 << endl;
	cout << "Polynomial p1 multiplied by 2: " << p1 * 2 << endl;
}

void testNegation(const Poly &p1, const Poly &p2)
{
	cout << "Negation of polynomial p1: " << -p1 << endl;
	cout << "Negation of polynomial p2: " << -p2 << endl;
}

void testValue(const Poly &p1, const Poly &p2)
{
	cout << "Value of polynomial p1 at point 1.5: " << p1(1.5) << endl;
	cout << "Value of polynomial p2 at point 2.3: " << p2(2.3) << endl;
}



