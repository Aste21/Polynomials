#pragma once

#include <iostream>
#include <iomanip>
#include <map>
#include <cmath>

class Poly
{
	friend Poly operator+(const Poly &lhs, const Poly &rhs);
	friend Poly operator-(const Poly &lhs, const Poly &rhs);
	friend Poly operator*(const Poly &lhs, const Poly &rhs);
	friend std::ostream &operator<<(std::ostream &out, const Poly &toWrite);
	friend bool operator==(const Poly &lhs, const Poly &rhs);
	friend bool operator!=(const Poly &lhs, const Poly &rhs);
private:
	std::map<int, float> terms;
public:
	Poly();
	Poly(double x);
	Poly(std::map<int, float> newTerms);
	Poly(const Poly &source);
	Poly operator-() const;
	Poly &operator=(const Poly &rhs);
	Poly &operator+=(const Poly &rhs);
	Poly &operator-=(const Poly &rhs);
	float operator[](int index) const;
    float& operator[](int index);
	double operator()(double value) const;
	std::ostream printTerm(std::ostream &out, const Poly &toWrite, const std::pair<int, float> kv);
	void removeZeros();
};
