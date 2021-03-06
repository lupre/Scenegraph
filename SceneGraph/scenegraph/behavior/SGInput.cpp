#include "SGInput.h"

#include <iostream>

using namespace std;

namespace sg
{

SGInput::SGInput()
{
}

SGInput::~SGInput()
{
}

void SGInput::addKey(unsigned char key) {
	Input inpData;
	inpData.type = TYPE_UNSIGNED_CHAR;
	inpData.iKey = key; 
	pressedKeys.push_back(inpData);	
}

void SGInput::addSpecialKey(int key) {
	Input inpData;
	inpData.type = TYPE_INT;
	inpData.iKey = key;
	pressedKeys.push_back(inpData);	
}

bool SGInput::removeKey(unsigned char key) {
	Input inpData;
	inpData.type = TYPE_UNSIGNED_CHAR;
	inpData.cKey = key;
	pressedKeys.remove(inpData);
	
	return true;	
}

bool SGInput::removeKey(int key) {
	Input inpData;
	inpData.type = TYPE_INT;
	inpData.iKey = key;
	pressedKeys.remove(inpData);	
    
    // TODO: return false added to suppress compiler-warning. 
    return false;
}

bool SGInput::contains(Input inp) {
	list<Input>::iterator iter = pressedKeys.begin();
	
	while( iter != pressedKeys.end() ) {
		if( (*iter) == inp ) {
			return true;	
		} 
		iter++;	
	}
	
	return false;
}

list<Input> SGInput::getKeys() {
	return pressedKeys;	
}

bool Input::operator==(const Input& inp) const {
	if(type == inp.type) {
		if(type == TYPE_INT) {
			return (iKey == inp.iKey);	
		}
		else if( type == TYPE_UNSIGNED_CHAR ) {
			return (cKey == inp.cKey);	
		}
		else {
			return false;	
		}
	}
	else {
		return false;	
	}	
}	

}
