#ifndef complex_H
#define complex_H

#include <bits/stdc++.h>
using namespace std;
class complex{
public:
	double e[2];

	complex() : e{0,0}{}
	complex(double e0, double e1) : e{e0,e1}{}

	double x() const {return e[0];}
	double y() const {return e[1];}

	complex operator-() const{return complex(-e[0],-e[1]);}
	double operator[](int i) const { return e[i]; }
    double& operator[](int i) { return e[i]; }

    complex& operator+=(const complex& v){
    		e[0] += v.e[0];
        	e[1] += v.e[1];
        	return *this;
    	}

    complex& operator*=(double t){
    		e[0] *= t;
        	e[1] *= t;
        	return *this;
    	}

    complex& operator/=(double t) {
        	return *this *= 1/t;
    	}

    double length() const {
        	return std::sqrt(length_squared());
    }

    double length_squared() const {
        	return e[0]*e[0] + e[1]*e[1];
    }

};

inline std::ostream& operator<<(std::ostream& out, const complex& v) {
    return out << v.e[0] << ' ' << v.e[1];
}

inline complex operator+(const complex& u, const complex& v) {
    return complex(u.e[0] + v.e[0], u.e[1] + v.e[1]);
}

inline complex operator-(const complex& u, const complex& v) {
    return complex(u.e[0] - v.e[0], u.e[1] - v.e[1]);
}

inline complex operator*(const complex& u, const complex& v) {
    return complex(u.e[0] * v.e[0] - u.e[1] * v.e[1],u.e[0] * v.e[1] + u.e[1] * v.e[0] );
}

inline complex operator*(double t, const complex& v) {
    return complex(t*v.e[0], t*v.e[1]);
}

inline complex operator*(const complex& v, double t) {
    return t * v;
}

inline complex operator/(const complex& v, double t) {
    return (1/t) * v;
}

#endif