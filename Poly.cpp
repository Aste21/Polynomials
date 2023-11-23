#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <algorithm>
#include "Poly.h"
#include <vector>

Poly::Poly(double x)
{
	terms.insert(std::make_pair(0, x));
}

Poly::Poly(std::map<int, double> newTerms)
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
		else
		{
			result.terms[kv.first] = kv.second;
		}
	}
	return result;
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
		else
		{
			result.terms[kv.first] = -kv.second;
		}
	}
	result.removeZeros();
	return result;
}

Poly operator*(const Poly &lhs, const Poly &rhs)
{
	Poly result;
	for (auto &rkv : rhs.terms)
	{
		for (auto &lkv : lhs.terms)
		{
			result[rkv.first+lkv.first] += rkv.second*lkv.second;
		}
	}
	result.removeZeros();
	return result;
}

std::ostream &operator<<(std::ostream &out, const Poly &toWrite)
{
	if (toWrite.terms.size() == 0)
	{
		out << 0;
	}
	else
	{
		const int Precision = 3;
		out << std::setprecision(Precision);
		bool isFirst = true;

		for (auto it = toWrite.terms.rbegin(); it != toWrite.terms.rend(); ++it)
		{
			const auto &kv = *it;

			if (kv.second > 0)
			{
				if (!isFirst)
				{
					out << " + ";
				}
			}
			else
			{
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
	this->removeZeros();
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
	this->removeZeros();
	return *this;
}

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

double Poly::operator[](int index) const
{
	auto it = terms.find(index);
	if (it != terms.end())
	{
		return it->second;
	}
	else
	{
		return 0.0; // If the key is not found, return a default value
	}
}

double &Poly::operator[](int index)
{
	if (terms.find(index) != terms.end())
	{
		return terms[index];
	}
	else
	{
		// If the term doesn't exist, return a pointer to a new term with a value of 0.0.
		terms[index] = 0.0;
		return terms[index];
	}
}

double Poly::operator()(double value) const
{
	double result = 0;
	for (auto &kv : terms)
	{
		result += pow(value, kv.first) * kv.second;
	}
	return result;
}

void Poly::removeZeros()
{
	std::vector<int> whatToErase;
	for (auto &kv : terms)
	{
		if (terms[kv.first] == 0)
		{
			whatToErase.push_back(kv.first);
		}
	}
	for (size_t i = 0; i < whatToErase.size(); i++)
	{
		terms.erase(whatToErase[i]);
	}
}
