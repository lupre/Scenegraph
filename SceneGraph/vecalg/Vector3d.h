/**
 * Simple representation of 3-dimensional vector. The element's type is double.
 */
#ifndef VECTOR3D_H_
#define VECTOR3D_H_

class Vector3d
{
public:
	/**
	 * Constructor initializes the members x, y and z to the given values in the 
	 * given order.
	 */
	Vector3d(double, double, double);
	
	/**
	 * The members are initialized with the value 0.
	 */
	Vector3d();
	
	/** Simple destructor */
	virtual ~Vector3d();

	double x; ///< x value of the vector
	double y; ///< y value of the vector
	double z; ///< z value of the vector
};

#endif /*VECTOR3D_H_*/
