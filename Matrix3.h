#ifndef Matrix3_H
#define Matrix3_H
#include "Vector3.h"

namespace Engine{

	class Matrix3 {
	private:

	public:
		float matrixData[9] = { 0.0f };

		Matrix3();
		Matrix3(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8);

		Matrix3& operator=(const Matrix3& m);

		~Matrix3();

		//addition of matrices
		Matrix3& operator+(const Matrix3& m);

		//scalar multiplication
		Matrix3& operator*(const float s)const;
		void operator*=(const float s);

		//multiplying matrices
		Matrix3 operator*(const Matrix3& mat)const;
		void operator*=(const Matrix3& mat);

		//set an identity matrix
		void setToIdentity();

		//transpose
		void transpose(const Matrix3& m);
		Matrix3 getTranspose()const;

		//vector transforms   transforming (roatating, scaling ect) a vector happens when you mutiply it by a matrix
		Vector3 operator*(const Vector3& v)const;
		Vector3 getTransform(const Vector3& v)const;

		//need to do inverse still
		void invert(const Matrix3& m);
		Matrix3 getInverse()const;
		void getInverseMatrix();

		void print();

	};
}

#endif
