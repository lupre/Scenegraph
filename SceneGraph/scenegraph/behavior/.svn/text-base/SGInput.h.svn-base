#ifndef SGINPUT_H_
#define SGINPUT_H_
#include <list>

/** \define possible type for the union within the struct Input */
#define TYPE_UNSIGNED_CHAR	1
/** \define possible type for the union within the struct Input */
#define TYPE_INT 			2

using namespace std;

namespace sg
{

/**
 * This struct makes it possible that special keys, represented as int values, and 
 * normal keys, represented as char values, can be meintained within one structure.
 */
struct Input {
	int type; ///< determines the type the following union
	union {
		int iKey;
		unsigned char cKey;	
	}; ///< either special key or normal key
	/**
	 * The Operator (==) is overwritten for Input
	 */
	bool operator==(const Input& inp) const;
};

/**
 * This class implements a genereal container for keyboard input, delivered from GLUT 
 * callback functions. Through the struct Input both special and normal keys can be 
 * maintained at the same time.
 */
class SGInput
{
public:
	SGInput();
	virtual ~SGInput();
	
	/**
	 * adds a normal key to the list which contains all pressed keys
	 */
	void addKey(unsigned char);
	
	/**
	 * removes a normale key from the list which contains all pressed keys
	 */
	bool removeKey(unsigned char);
	
	/**
	 * adds a special key to the list which contains all pressed keys
	 */
	void addSpecialKey(int);
	
	/**
	 * removes a special key from the list which contains all pressed keys
	 */
	bool removeKey(int);
	
	/**
	 * checks if the given Input object is contain within the pressed key list
	 */
	bool contains(Input inp);
	
	/**
	 * returns the list with all pressed keys
	 */
	list<Input> getKeys();
	
private:
	list<Input> pressedKeys;///< list with all pressed keys
};



}

#endif /*SGINPUT_H_*/
