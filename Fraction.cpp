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
#include <iostream>
#include <cstring>
#include "Fraction.h"
using namespace std;
namespace sict {
	Fraction::Fraction() {
		nom = 0;
		dom = 0;
	}
	Fraction::Fraction(int noms, int doms) {
		if (noms >= 0 && doms > 0) {
			nom = noms;
			dom = doms;
			reduce();
		}
		else {
			*this = Fraction();
		}
	}
	int Fraction::max() const {
		if (nom > dom) {
			return nom;
		}
		else {
			return dom;
		}
	}
	int Fraction::min() const {
		if (nom < dom) {
			return nom;
		}
		else {
			return dom;
		}
	}
	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}
	void Fraction::reduce() {
		int divide = gcd();
		this->nom /= divide;
		this->dom /= divide;
	}
	void Fraction::display() const {
		if (nom >= 0 && dom > 0 && dom != 1) {
			cout << nom << "/" << dom;
		}
		else if(dom == 1){
			cout << nom;
		}
		else if (isEmpty()) {
			cout << "no fraction stored";
		}
	}
	bool Fraction::isEmpty() const {
		if (nom == 0 && dom == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	Fraction Fraction::operator+(const Fraction& rhs) const{
		int fracAddNum;
		int fracAddDom;

		if (this->isEmpty() || rhs.isEmpty()) {
			return Fraction();
		}
		else {
			fracAddNum =(this->nom * rhs.dom) + (this->dom * rhs.nom);
			fracAddDom = (this->dom * rhs.dom);
			Fraction fracAdd = Fraction(fracAddNum,fracAddDom);
			return fracAdd;
		}
	}
	Fraction Fraction::operator*(const Fraction& rhs) const {
		int fracMulNum;
		int fracMulDom;

		if (this->isEmpty() || rhs.isEmpty()) {
			return Fraction();
		}
		else {
			fracMulNum = (this->nom * rhs.nom);
			fracMulDom = (this->dom * rhs.dom);
			Fraction fracAdd = Fraction(fracMulNum, fracMulDom);
			return fracAdd;
		}
	}
	bool Fraction::operator==(const Fraction& rhs) const {
		if (rhs.isEmpty() || this->isEmpty()) {
			return false;
		}else if(*this == rhs){
			return true;
		}
		else {
			return false;
		}
	}
	bool Fraction::operator!=(const Fraction& rhs) const {
		if (this->isEmpty() || rhs.isEmpty()) {
			return false;
		}
		else if(!(*this == rhs)){
			return true;
		}
		else {
			return false;
		}
	}
	Fraction& Fraction::operator+=(const Fraction& rhs)  {
		if (this->isEmpty() || rhs.isEmpty()) {
			*this = Fraction();
			return *this;
		}
		else{
			*this = *this + rhs;
			this->reduce();
			return *this;
		}
	}
}
