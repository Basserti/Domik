/*
 * ExampleWindow.h
 *
 *  Created on: 25 ����. 2020 �.
 *      Author: ���
 */

#pragma once
#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_

#include "Window.h"
#include <GL/gl.h>
#include <GL/glu.h>

#include "Ground1.h"
#include "SimpleModel1.h"
#include "Texture.h"
#include "SnowMan.h"

class ExampleWindow: public Window{
protected:
	double _angle { 0. };
	double _camera_z { 0. };
	double z1 { -0.7 };
	double z2 { -0.05 };
	double z3 { 0.6 };
	double z_carrot { 0.65};
	double x1 {  1   };
	double x2 {  1   };
	double x3 {  1.2 };
	double y3 {  2.8 };
	double y4 {  2.8 };
	double y1 { -3   };
	double y2 {  3   };

	SimpleModel _cube = SimpleModel::create_cube();
	Ground _ground = Ground::create_ground();
	Texture _crate_texture;
	Texture _snowman_texture;
	Texture _tree_texture;
	Texture _carrot_texture;

public:
	ExampleWindow(	int width = DEFAULT_WIDTH,
					int height = DEFAULT_HEIGHT	);
	virtual ~ExampleWindow() = default;

	virtual void setup() override;
	virtual void render() override;
	virtual void do_logic() override;
};

#endif /* EXAMPLEWINDOW_H_ */
