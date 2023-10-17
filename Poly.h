#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

// ALL ,,x" ARE TO BE NAMED

#pragma once

class Term
{
	friend bool compareTerms(const Term& term1, const Term& term2);
	friend class Poly;

private:
	

public:
	// think if its possible for these to be private
	double coefficient;
	int power;
	Term();
	Term(double coefficient);
	Term(double coefficient, int power);
};

class Poly
{
	friend Poly operator+(const Poly &lhs, const Poly &rhs);
	friend Poly operator-(const Poly &lhs, const Poly &rhs);
	friend Poly operator*(const Poly &lhs, const Poly &rhs);
	friend std::ostream &operator<<(std::ostream &out, const Poly &toWrite);
	friend bool operator==(const Poly &lhs, const Poly &rhs);
	friend bool operator!=(const Poly &lhs, const Poly &rhs);
	friend void copyTerms(Poly &lhs, const Poly &rhs);
private:
	std::vector<Term> terms;
public:
	Poly();
	Poly(float x);
	Poly(std::vector<Term> newTerms);
	Poly(const Poly &source);
	Poly operator-() const;
	Poly &operator=(const Poly &rhs);
	Poly &operator+=(const Poly &rhs);
	Poly &operator-=(const Poly &rhs);
	Poly &operator*=(const Poly &rhs);
	double operator[](int n) const;
    Term& operator[](int n);
	double operator()(double x) const;
	void sortPoly();
	void deleteEmpty();
};