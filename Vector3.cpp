#include "Vector3.h"
#include <iostream>
#include <math.h>
#include "Quaternion3.h"

namespace Engine{
	//constructor definitions
	Vector3::Vector3() : x(0.0), y(0.0), z(0.0) {};
	Vector3::Vector3(float uX, float uY, float uZ) : x(uX), y(uY), z(uZ){}

	Vector3::~Vector3(){}

	//copy constructor
	Vector3::Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {};
	
	Vector3& Vector3::operator=(const Vector3& v) {
		x = v.x;
		y = v.y;
		z = v.z;

		return *this;
	}

	//for addition of vectors
	void Vector3::operator+=(const Vector3& v) {
		x+=v.x;
		y+=v.y;
		z+=v.z;
	}

	Vector3 Vector3::operator+(const Vector3& v) const {
		return Vector3(x + v.x, y + v.y, z + v.z);
	}
	
	//subtraction
	void Vector3::operator-=(const Vector3& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}

	Vector3 Vector3::operator-(const Vector3& v)const {
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	//scalar mult/div
	void Vector3::operator*=(const float s) {
		x *= s;
		y *= s;
		z *= s;
	}

	Vector3 Vector3::operator*(const float s)const {
		return Vector3(x*s, y*s, z*s);
	}

	void Vector3::operator/=(const float s) {
		x /= s;
		y /= s;
		z /= s;
	}
	Vector3 Vector3::operator/(const float s)const {
		return Vector3(x / s, y / s, z / s);
	}

	//dot product
	float Vector3::operator*(const Vector3& v)const {
		return(x*v.x + y*v.y + z*v.z);
	}

	//cross product
	Vector3 Vector3::operator%(const Vector3& v)const {
		return Vector3(
		y*v.z - z * v.y,
		z*v.x - x * v.z,
		x*v.y - y * v.x
		);
	}

	//magnitude
	float Vector3::magnitude() {
		return sqrt(x*x + y*y + z*z);
	}

	//normalize (turn into unit vector)
	void Vector3::normalize() {
		float mag = this->magnitude();

		if (mag > 0.0)
		{
			float oneOverMag = 1.0 / mag;
			
			x = x * oneOverMag;
			y = y * oneOverMag;
			z = z * oneOverMag;
		}
	}

	Vector3 Vector3::rotateVec(float angle, Vector3& vec) {

		//make into pure quaternion
		Quaternion3 p(0, *this);

		//find unit vector
		vec.normalize();

		//real quaternion needs to be unit norm
		Quaternion3 q(angle, vec);
		q.convertToUnitNorm();

		//insverse quaternion
		Quaternion3 qInv = q.inverse();

		//rotate
		Quaternion3 pRotated = q * p * qInv;

		return pRotated.v;
	}

	//print
	void Vector3::print() {
		std::cout << x << " " << y << " " << z << std::endl;
	}
}
