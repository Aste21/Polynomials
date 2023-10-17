#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Poly.h"

Term::Term()
	: coefficient{0}, power{0} {}

Term::Term(double coefficient)
	: coefficient{coefficient}, power{0} {}

Term::Term(double coefficient, int power)
	: coefficient{coefficient}, power{power} {}

void copyTerms(std::vector<Term>  &lhs, const std::vector<Term>  &rhs)
{
	for (int i = 0; i < rhs.size(); i++)
	{
		lhs.push_back(Term(rhs[i].coefficient, rhs[i].power));
	}
}

Poly::Poly(float x)
{
	if (x != 0)
	{
		terms.push_back(Term(x, 0));
	}
}

Poly::Poly(std::vector<Term> newTerms)
{
	copyTerms(terms, newTerms);
}

Poly::Poly(const Poly &source)
{
	copyTerms(terms, source.terms);
}

Poly operator+(const Poly &lhs, const Poly &rhs)
{
	
}

Poly operator-(const Poly &lhs, const Poly &rhs)
{

}

Poly operator*(const Poly &lhs, const Poly &rhs)
{

}

std::ostream &operator<<(std::ostream &out, const Poly &toWrite)
{

}

Poly Poly::operator-() const
{
	std::vector<Term> newTerms;
}

Poly &Poly::operator=(const Poly &rhs)
{
	copyTerms(terms, rhs.terms);
	return *this;
}

Poly &Poly::operator+=(const Poly &rhs)
{

}

Poly &Poly::operator-=(const Poly &rhs)
{

}

Poly &Poly::operator*=(const Poly &rhs)
{
}

bool operator==(const Poly &lhs, const Poly &rhs)
{
	if (lhs.terms.size() != rhs.terms.size())
	{
		return false;
	}
	for (int i = 0; i < lhs.terms.size(); i++)
	{
		if (lhs.terms[i].power != rhs.terms[i].power || lhs.terms[i].coefficient != rhs.terms[i].coefficient)
		{
			return false;
		}
	}
	return true;
}

bool operator!=(const Poly &lhs, const Poly &rhs)
{
	if (lhs.terms.size() != rhs.terms.size())
	{
		return true;
	}
	for (int i = 0; i < lhs.terms.size(); i++)
	{
		if (lhs.terms[i].power != rhs.terms[i].power || lhs.terms[i].coefficient != rhs.terms[i].coefficient)
		{
			return true;
		}
	}
	return false;
}

double Poly::operator[](int n) const
{
	if (terms.size() == 0)
	{
		return 0;
	}

	return terms[n].coefficient;
}

Term &Poly::operator[](int n)
{
	if (n < 0)
	{
		throw std::invalid_argument("Degree must be non-negative");
	}

	for (int i = 0; i < terms.size(); i++)
	{
		if (terms[i].power == n)
		{
			return terms[i];
		}
	}
	terms.push_back(Term(0));
	return terms[terms.size() - 1];
}

double Poly::operator()(double y) const
{
	double result = 0;
	for (int i = 0; i < terms.size(); i++)
	{
		result += pow(y, terms[i].power) * terms[i].coefficient;
	}
	return result;
}

void Poly::deleteEmpty()
{
	for (int i = 0; i < terms.size(); i++)
	{
		if (terms[i].coefficient == 0)
		{
			terms.erase(terms.begin() + i);
			i -= 1;
		}
	}
}

bool compareTerms(const Term &term1, const Term &term2)
{
	return term1.power > term2.power;
}

void Poly::sortPoly()
{
	std::sort(terms.begin(), terms.end(), compareTerms);
}