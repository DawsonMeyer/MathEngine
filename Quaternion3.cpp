#include <iostream>
#include "Quaternion3.h"
#include <cmath>

namespace Engine {

	Quaternion3::Quaternion3() {};
	Quaternion3::Quaternion3(float s, Vector3 v) : s(s), v(v) {};

	Quaternion3::~Quaternion3() {};

	Quaternion3::Quaternion3(const Quaternion3& val){
		
		s = val.s;
		v = val.v;
	}

	Quaternion3& Quaternion3::operator=(const Quaternion3& val){
	
		s = val.s;
		v = val.v;

		return *this;
	}

	void Quaternion3::operator+=(const Quaternion3& q) {
	
		s += q.s;
		v += q.v;
	}
	
	Quaternion3 Quaternion3::operator+(const Quaternion3& q) {

		float scalar = s + q.s;
		Vector3 vec = v + q.v;

		return Quaternion3(scalar, vec);
	}

	void Quaternion3::operator-=(const Quaternion3& q) {

		s -= q.s;
		v -= q.v;
	}

	Quaternion3 Quaternion3::operator-(const Quaternion3& q) {

		float temp = s - q.s;
		Vector3 vec = v - q.v;

		return Quaternion3(temp, vec);
	}

	//scalar multiplication
	void Quaternion3::operator*=(const float scalar) {

		s *= scalar;
		v *= scalar;
	}

	Quaternion3 Quaternion3::operator*(const float scalar) {

		float temp = s * scalar;
		Vector3 vec = v * scalar;

		return Quaternion3(temp, vec);
	}
	
	//quaternion multiplication
	Quaternion3 Quaternion3::operator*(const Quaternion3& q) {

		float scalar = (s*q.s) - (v * q.v);
		Vector3 vec = (q.v*s) + (v * q.s) + (v % q.v);

		return Quaternion3(scalar, vec);
	}

	//normalization (magnitude of a quaternion)
	float Quaternion3::magnitude() {

		float scalar = s * s;
		float temp = v * v;

		return sqrt(scalar+temp);
	}

	void Quaternion3::norm() {

		if (magnitude() != 0)
		{
			float value = 1 / magnitude();

			s *= value;
			v *= value;
		}
	}

	//conjugate 
	Quaternion3 Quaternion3::conjugate() {

		float scalar = s;
		Vector3 vec = v * (-1);

		return Quaternion3(scalar, vec);
	}


	//inverse
	Quaternion3 Quaternion3::inverse() {

		float mag = magnitude();
		mag *= mag;
		mag = 1 / mag;

		Quaternion3 conjVal = conjugate();

		float scalar = conjVal.s * mag;
		Vector3 vec = conjVal.v * mag;
		
		return Quaternion3(scalar, vec);
	}

	//roatations of vectors
	void Quaternion3::convertToUnitNorm() {
		
		const float PI = 3.14159265358979323846;
		float radians = s * (PI/180);

		s = cosf(0.5 * radians);
		v = v * sinf(0.5 * radians); 
	}
	
	void Quaternion3::print() {

		std::cout << s << " " << std::endl;
		v.print();
	}

}