#ifndef QUATERNION3_H
#define QUATERNION3_H

#include "Vector3.h"

namespace Engine {
	class Quaternion3 {

	private:


	public:
		float s;
		Vector3 v;

		Quaternion3();
		Quaternion3(float s, Vector3 v);

		~Quaternion3();

		Quaternion3(const Quaternion3& val);

		Quaternion3& operator=(const Quaternion3& val);

		//adding and subracting quaternions together
		void operator+=(const Quaternion3& q);
		Quaternion3 operator+(const Quaternion3& q);

		void operator-=(const Quaternion3& q);
		Quaternion3 operator-(const Quaternion3& q);

		//scalar multiplication
		void operator*=(const float scalar);
		Quaternion3 operator*(const float scalar);

		//dot product
		Quaternion3 operator*(const Quaternion3& q);

		//normalization
		float magnitude();
		void norm();

		//conjugate
		Quaternion3 conjugate();

		//inverse
		Quaternion3 inverse();

		//rotations
		//need function for convert to unit Norm for rotations of vectors
		void convertToUnitNorm();

		void print();
	};

}

#endif