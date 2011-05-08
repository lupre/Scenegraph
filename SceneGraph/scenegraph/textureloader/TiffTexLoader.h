#ifndef TIFFTEXLOADER_H_
#define TIFFTEXLOADER_H_

namespace sg
{

class TiffTexLoader
{
public:
	TiffTexLoader();
	virtual ~TiffTexLoader();
	int* loadTexture();
};

}

#endif /*TIFFTEXLOADER_H_*/
