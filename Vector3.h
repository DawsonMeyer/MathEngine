#ifndef VECTOR3_H
#define VECTOR3_H

namespace Engine
{
	class Vector3
	{

	private:

	public:
		//three dimensions public for ease of use
		float x;
		float y;
		float z;

		Vector3();
		Vector3(float uX, float uY, float uZ);

		~Vector3();

		//Copy Constructors
		Vector3(const Vector3& v);
		Vector3& operator=(const Vector3& v);
	
		//for additions
		void operator+=(const Vector3& v);
		Vector3 operator+(const Vector3& v)const;

		//subtractions
		void operator-=(const Vector3& v);
		Vector3 operator-(const Vector3& v)const;

		//scalar multiplication/division
		void operator*=(const float s);
		Vector3 operator*(const float s)const;
		
		void operator/=(const float s);
		Vector3 operator/(const float s)const;

		//dot product
		float operator*(const Vector3& v)const;

		//cross product
		Vector3 operator%(const Vector3& v)const;

		//magnitude
		float magnitude();

		//normalize
		void normalize();

		Vector3 rotateVec(float angle, Vector3& vec);

		//for printing
		void print();
	};
}
#endif