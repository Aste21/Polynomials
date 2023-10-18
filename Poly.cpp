#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <algorithm>
#include "Poly.h"

Poly::Poly()
{
}

Poly::Poly(int x)
{
	terms.insert(std::make_pair(0, x));
}

Poly::Poly(float x)
{
	terms.insert(std::make_pair(0, x));
}

Poly::Poly(double x)
{
	terms.insert(std::make_pair(0, x));
}

Poly::Poly(std::map<int, float> newTerms)
{
	terms = newTerms;
}

Poly::Poly(const Poly &source)
{
	terms = source.terms;
}

Poly operator+(const Poly &lhs, const Poly &rhs)
{
	Poly result(lhs.terms);
	for (auto &kv : rhs.terms)
	{
		if (lhs.terms.count(kv.first) != 0)
		{
			result.terms[kv.first] += kv.second;
		}
		result.terms[kv.first] = kv.second;
	}
	return Poly(lhs.terms);
}

Poly operator-(const Poly &lhs, const Poly &rhs)
{
	Poly result(lhs.terms);
	for (auto &kv : rhs.terms)
	{
		if (lhs.terms.count(kv.first) != 0)
		{
			result.terms[kv.first] -= kv.second;
		}
		result.terms[kv.first] = -kv.second;
	}
	return Poly(lhs.terms);
}

// Poly operator*(const Poly &lhs, const Poly &rhs)
// {
// }

std::ostream &operator<<(std::ostream &out, const Poly &toWrite)
{
    const int Precision = 3;
    out << std::setprecision(Precision);
    bool isFirst = true;

    for (auto it = toWrite.terms.rbegin(); it != toWrite.terms.rend(); ++it)
    {
        const auto &kv = *it;

        if (!isFirst)
        {
            if (kv.second > 0)
                out << " + ";
            else
                out << " - ";
        }
        
        if (fabs(kv.second) != 1)
            out << fabs(kv.second);

        if (kv.first > 0)
        {
            if (kv.first == 1)
                out << "x";
            else
                out << "x^" << kv.first;
        }

        isFirst = false;
    }
    return out;
}

Poly Poly::operator-() const
{
	Poly result = *this;
	for (auto &kv : result.terms)
	{
		result.terms[kv.first] = -result.terms[kv.first];
	}
	return result;
}

Poly &Poly::operator=(const Poly &rhs)
{
	terms = rhs.terms;
	return *this;
}

Poly &Poly::operator+=(const Poly &rhs)
{
	for (auto &kv : rhs.terms)
	{
		if (terms.count(kv.first) != 0)
		{
			terms[kv.first] += kv.second;
		}
		terms[kv.first] = kv.second;
	}
	return *this;
}

Poly &Poly::operator-=(const Poly &rhs)
{
	for (auto &kv : rhs.terms)
	{
		if (terms.count(kv.first) != 0)
		{
			terms[kv.first] -= kv.second;
		}
		terms[kv.first] = -kv.second;
	}
	return *this;
}

// Poly &Poly::operator*=(const Poly &rhs)
// {
// }

bool operator==(const Poly &lhs, const Poly &rhs)
{
	if (lhs.terms.size() != rhs.terms.size())
	{
		return false;
	}
	for (auto &kv : lhs.terms)
	{
		if (lhs.terms.find(kv.first) != rhs.terms.find(kv.first))
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
		return false;
	}
	for (auto &kv : lhs.terms)
	{
		if (lhs.terms.find(kv.first) != rhs.terms.find(kv.first))
		{
			return true;
		}
	}
	return false;
}

float Poly::operator[](int n) const
{
	auto it = terms.find(n);
	if (it != terms.end())
	{
		return it->second;
	}
	else
	{
		return 0.0; // If the key is not found, return a default value
	}
}

float &Poly::operator[](int n)
{
	if (terms.find(n) != terms.end())
	{
		return terms[n];
	}
	else
	{
		// If the term doesn't exist, return a pointer to a new term with a value of 0.0.
		terms[n] = 0.0;
		return terms[n];
	}
}

// float &Poly::operator[](int n)
// {
// 	if (n < 0)
// 	{
// 		throw std::invalid_argument("Degree must be non-negative");
// 	}
// 	if (terms.find(n) != terms.end())
// 	{
// 		return *(terms[n]);
// 	}
// 	else
// 	{
// 		// If the term doesn't exist, return a pointer to a new term with a value of 0.0.
// 		terms[n] = 0.0;
// 		return (terms[n]);
// 	}

// 	// auto it = terms.find(n);
// 	// if (it != terms.end())
// 	// {
// 	// 	return *(it->second);
// 	// }

// 	// // Handle the case when the key is not found, by inserting a default pair
// 	// terms[n] = 0.0;
// 	// return *terms.find(n);
// }

double Poly::operator()(double y) const
{
	double result = 0;
	for (auto &kv : terms)
	{
		result += pow(y, kv.first) * kv.second;
	}
	return result;
}
