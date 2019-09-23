/***********************************************************
// OOP244 Workshop 5: Member Operator Overloads
// File Fraction.cpp
// Version 1.0
// Date June. 13, 2019
// Author Nilan Patel
// Student Number: <038 908 117>
// Section SEE
// Description
//
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
//
///////////////////////////////////////////////////////////
***********************************************************/
#ifndef SICT_FRACTION_H
#define SICT_FRACTION_H
namespace sict {
	class Fraction {
		int nom;
		int dom;
		int max() const;
		int min() const;
		void reduce();
		int gcd() const;
	public:
		Fraction();
		Fraction(int nom, int dem);
		bool isEmpty() const;
		void display() const;
		Fraction operator+(const Fraction& rhs) const;
		Fraction operator*(const Fraction& rhs) const;
		bool operator==(const Fraction& rhs) const;
		bool operator!=(const Fraction& rhs) const;
		Fraction& operator+=(const Fraction& rhs);
	};
}
#endif