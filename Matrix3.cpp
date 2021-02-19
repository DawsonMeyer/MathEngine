#include "Matrix3.h"
#include "Vector3.h"
#include <iostream>

namespace Engine {

	Matrix3::Matrix3() {
	
		/*  called column-major
		0	3	6
		1	4	7
		2	5	8
		*/

		//initialize the matrix
		for (int i = 0; i < 9; i++)
			matrixData[i] = 0.0f;
		
		//make it identity matrix
		matrixData[0] = matrixData[4] = matrixData[8] = 1.0f;
	};

	Matrix3::Matrix3(float m0, float m3, float m6, float m1, float m4, float m7, float m2, float m5, float m8) {

		matrixData[0] = m0;
		matrixData[3] = m3;
		matrixData[6] = m6;
		matrixData[1] = m1;
		matrixData[4] = m4;
		matrixData[7] = m7;
		matrixData[2] = m2;
		matrixData[5] = m5;
		matrixData[8] = m8;
	};

	Matrix3& Matrix3::operator=(const Matrix3& m) {
	
		for (int i = 0; i < 9; i++)
			matrixData[i] = m.matrixData[i];

		return *this;
	};

	Matrix3::~Matrix3() {}; 

	Matrix3& Matrix3::operator+(const Matrix3& m) {

		for (int i = 0; i < 9; i++)
			matrixData[i] += m.matrixData[i];
		
		return *this;
	};

	//multiplication by scalar
	Matrix3& Matrix3::operator*(const float s)const {
	
		Matrix3 n;

		for (int i = 0; i < 9; i++)
			n.matrixData[i] = matrixData[i] * s;

		return n;
	};

	void Matrix3::operator*=(const float s) {

		for (int i = 0; i < 9; i++)
			matrixData[i] *= s;
	};

	//multiplication by matrix
	Matrix3 Matrix3::operator*(const Matrix3& mat)const{

		return Matrix3(
			matrixData[0] * mat.matrixData[0] + matrixData[3] * mat.matrixData[1] + matrixData[6] * mat.matrixData[2],
			matrixData[0] * mat.matrixData[3] + matrixData[3] * mat.matrixData[4] + matrixData[6] * mat.matrixData[5],
			matrixData[0] * mat.matrixData[6] + matrixData[3] * mat.matrixData[7] + matrixData[6] * mat.matrixData[8],

			matrixData[1] * mat.matrixData[0] + matrixData[4] * mat.matrixData[1] + matrixData[7] * mat.matrixData[2],
			matrixData[1] * mat.matrixData[3] + matrixData[4] * mat.matrixData[4] + matrixData[7] * mat.matrixData[5],
			matrixData[1] * mat.matrixData[6] + matrixData[4] * mat.matrixData[7] + matrixData[7] * mat.matrixData[8],

			matrixData[2] * mat.matrixData[0] + matrixData[5] * mat.matrixData[1] + matrixData[8] * mat.matrixData[2],
			matrixData[2] * mat.matrixData[3] + matrixData[5] * mat.matrixData[4] + matrixData[8] * mat.matrixData[5],
			matrixData[2] * mat.matrixData[6] + matrixData[5] * mat.matrixData[7] + matrixData[8] * mat.matrixData[8]
		);

	};

	void Matrix3::operator*=(const Matrix3& mat) {

		float p1;
		float p2;
		float p3;

		p1 = matrixData[0] * mat.matrixData[0] + matrixData[3] * mat.matrixData[1] + matrixData[6] * mat.matrixData[2];
		p2 = matrixData[0] * mat.matrixData[3] + matrixData[3] * mat.matrixData[4] + matrixData[6] * mat.matrixData[5];
		p3 = matrixData[0] * mat.matrixData[6] + matrixData[3] * mat.matrixData[7] + matrixData[6] * mat.matrixData[8];

		matrixData[0] = p1;
		matrixData[3] = p2;
		matrixData[6] = p3;

		p1 = matrixData[1] * mat.matrixData[0] + matrixData[4] * mat.matrixData[1] + matrixData[7] * mat.matrixData[2];
		p2 = matrixData[1] * mat.matrixData[3] + matrixData[4] * mat.matrixData[4] + matrixData[7] * mat.matrixData[5];
		p3 = matrixData[1] * mat.matrixData[6] + matrixData[4] * mat.matrixData[7] + matrixData[7] * mat.matrixData[8];

		matrixData[1] = p1;
		matrixData[4] = p2;
		matrixData[7] = p3;

		p1 = matrixData[2] * mat.matrixData[0] + matrixData[5] * mat.matrixData[1] + matrixData[8] * mat.matrixData[2];
		p2 = matrixData[2] * mat.matrixData[3] + matrixData[5] * mat.matrixData[4] + matrixData[8] * mat.matrixData[5];
		p3 = matrixData[2] * mat.matrixData[6] + matrixData[5] * mat.matrixData[7] + matrixData[8] * mat.matrixData[8];

		matrixData[2] = p1;
		matrixData[5] = p2;
		matrixData[8] = p3;
	
	};

	//set to Identity
	void Matrix3::setToIdentity() {

		for (int i = 0; i < 9; i++)
			matrixData[i] = 0.0f;

		matrixData[0] = matrixData[4] = matrixData[8] = 1.0f;
	};

	//transpose the matrix (sets the matrix as the transpose of the given one)
	void Matrix3::transpose(const Matrix3& m) {
	/*
	changes a matrix from column-major to row major and viceversa
		0 3 6		0 1 2
		1 4 7   ->  3 4 5
		2 5 8		6 7 8
	*/
		matrixData[0] = m.matrixData[0];
		matrixData[1] = m.matrixData[3];
		matrixData[2] = m.matrixData[6];
		matrixData[3] = m.matrixData[1];
		matrixData[4] = m.matrixData[4];
		matrixData[5] = m.matrixData[7];
		matrixData[6] = m.matrixData[2];
		matrixData[7] = m.matrixData[5];
		matrixData[8] = m.matrixData[8];

	};

	Matrix3 Matrix3::getTranspose()const {
		Matrix3 m;
		m.transpose(*this);
		return m;
	};

	//transform
	Vector3 Matrix3::operator*(const Vector3& v) const{
		
		return Vector3(
			v.x*matrixData[0] + v.y*matrixData[3] + v.z*matrixData[6],
			v.x*matrixData[1] + v.y*matrixData[4] + v.z*matrixData[7],
			v.x*matrixData[2] + v.y*matrixData[5] + v.z*matrixData[8]
		);
	};

	Vector3 Matrix3::getTransform(const Vector3& v)const {

		return (*this)*v;
	};


	//invert matrices
	void Matrix3::invert(const Matrix3& m) {

		//find determinant
		float d1 = ((m.matrixData[4] * m.matrixData[8]) - (m.matrixData[5] * m.matrixData[7]));
		float d2 = ((m.matrixData[1] * m.matrixData[8]) - (m.matrixData[7] * m.matrixData[2]));
		float d3 = ((m.matrixData[1] * m.matrixData[5]) - (m.matrixData[4] * m.matrixData[2]));

		float det = (m.matrixData[0] * d1 - m.matrixData[3] * d2 + m.matrixData[6] * d3);
	
		if (det == 0.0f)
		{
			std::cout << "This matrix has no inverse" << std::endl;
			return;
		}

		float inverseDet = 1.0f / det;

		//invert and multiply by the inverseDet for each position
		float p0 = ((m.matrixData[4] * matrixData[8]) - (matrixData[5] * matrixData[7])) * inverseDet;
		float p3 = ((m.matrixData[3] * matrixData[8]) - (matrixData[5] * matrixData[6])) * inverseDet;
		float p6 = ((m.matrixData[3] * matrixData[7]) - (matrixData[4] * matrixData[6])) * inverseDet;
		float p1 = ((m.matrixData[1] * matrixData[8]) - (matrixData[2] * matrixData[7])) * inverseDet;
		float p4 = ((m.matrixData[0] * matrixData[8]) - (matrixData[6] * matrixData[2])) * inverseDet;
		float p7 = ((m.matrixData[0] * matrixData[7]) - (matrixData[1] * matrixData[6])) * inverseDet;
		float p2 = ((m.matrixData[1] * matrixData[5]) - (matrixData[2] * matrixData[4])) * inverseDet;
		float p5 = ((m.matrixData[0] * matrixData[5]) - (matrixData[2] * matrixData[3])) * inverseDet;
		float p8 = ((m.matrixData[0] * matrixData[4]) - (matrixData[1] * matrixData[3])) * inverseDet;


		matrixData[0] = p0;
		matrixData[1] = p1;
		matrixData[2] = p2;
		matrixData[3] = p3;
		matrixData[4] = p4;
		matrixData[5] = p5;
		matrixData[6] = p6;
		matrixData[7] = p7;
		matrixData[8] = p8;

	};
	
	Matrix3 Matrix3::getInverse()const {
	
		Matrix3 res;
		res.invert(*this);
		return res;
	};
	
	void Matrix3::getInverseMatrix() {
	
		invert(*this);
	};


	void Matrix3::print() {
	
		std::cout << matrixData[0] << " " << matrixData[3] << " " << matrixData[6] << std::endl;
		std::cout << matrixData[1] << " " << matrixData[4] << " " << matrixData[7] << std::endl;
		std::cout << matrixData[2] << " " << matrixData[5] << " " << matrixData[8] << std::endl << std::endl;
	};

}
