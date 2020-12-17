/*
 * Texture.h
 *
 *  Created on: 25 ����. 2020 �.
 *      Author: ���
 */

#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <GL/gl.h>
#include <GL/glu.h>

class Texture {
protected:
	GLuint _tex;

public:
	Texture(const char * filename);
	virtual ~Texture();

	void bind();
};

#endif /* TEXTURE_H_ */
