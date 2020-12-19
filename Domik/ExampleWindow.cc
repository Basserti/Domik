/*
 * ExampleWindow.cc
 *
 *  Created on: 25 ����. 2020 �.
 *      Author: ���
 */

#include "ExampleWindow.h"

#include <cmath>

static constexpr double Pi = acos(-1.);

double coeff=0.2;
double coeff2=0.2;
double coeff3=0.1;
double coeff4=-0.1;

ExampleWindow::ExampleWindow(int width, int height)
: Window(width,height),
_crate_texture("wall_tex.png"),
_snowman_texture("snowman_tex.png"),
_tree_texture("tree_tex.png"),
_carrot_texture("carrot_tex.png")
{
	// TODO Auto-generated constructor stub

}

void ExampleWindow::setup() {

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_TEXTURE);

	// ����� ���� ������� ������ �����
	glClearColor(0.2f, 0.35f, 0.45f, 1.0f);

	glMatrixMode(GL_PROJECTION); // ����� ���������� ������� ��������
	gluPerspective(45., double (width())/double (height()),
			0.1, 60.0);
	glMatrixMode(GL_MODELVIEW); // ����� ���������� ������� ������-����
}

void ExampleWindow::render() {
	// ������� ������ �����
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity(); // ������ ������� ������� �� ���������

	gluLookAt(
			3., 15, 5,
			0.0, 0.0, 0.0,
			0., 0., 1.);

	//glRotated(_angle, 0., 0., 1.);

	glEnable(GL_TEXTURE_2D);
	_crate_texture.bind();
	glPushMatrix();
		glRotated(0., 0., 0., 1.);
		glTranslated(-6.,0.,0.);
			_cube.draw();
	glPopMatrix();

	glPushMatrix();
		glRotated(35., 0., 0., 1.);
		glTranslated(-6.,0.,0.);
			_cube.draw();
	glPopMatrix();

	glPushMatrix();
		glRotated(70., 0., 0., 1.);
		glTranslated(-6.,0.,0.);
			_cube.draw();
	glPopMatrix();

	glPushMatrix();
		glRotated(105., 0., 0., 1.);
		glTranslated(-6.,0.,0.);
			_cube.draw();
	glPopMatrix();

	glPushMatrix();
		glRotated(145., 0., 0., 1.);
		glTranslated(-6.,0.,0.);
			_cube.draw();
	glPopMatrix();
	glPushMatrix();
		glRotated(180., 0., 0., 1.);
		glTranslated(-6.,0.,0.);
			_cube.draw();
	glPopMatrix();

	_ground.draw();

	_carrot_texture.bind();
	glPushMatrix();
		glRotated(90., 0., 0., 1.);
		glTranslated(2.,0.,-1.);
		glScalef(1, 1, 2);
		   draw_cylinder(12);
	glPopMatrix();

	_tree_texture.bind();
	glPushMatrix();
		glRotated(90., 0., 0., 1.);
		glTranslated(2.,0.,0.);
			draw_cone(18);
	glPopMatrix();

	glPushMatrix();
		glRotated(90., 0., 0., 1.);
		glTranslated(2.,0.,0.6);
			draw_cone(18);
	glPopMatrix();

	glPushMatrix();
		glRotated(90., 0., 0., 1.);
		glTranslated(2.,0.,1.2);
			draw_cone(18);
	glPopMatrix();

	_snowman_texture.bind();
	glPushMatrix();
		glRotated(90., 0., 0., 1.);
		glTranslated(x1,y1,z1);
		glScalef(1.5, 1.5, 1.5);
		draw_sphere_smooth(180,60);
	glPopMatrix();

	glPushMatrix();
		glRotated(90., 0., 0., 1.);
		glTranslated(x1,y1,z2);
		glScalef(1.25, 1.25, 1.25);
		draw_sphere_smooth(180,60);
	glPopMatrix();

	glPushMatrix();
		glRotated(90., 0., 0., 1.);
		glTranslated(x1,y1,z3);
		draw_sphere_smooth(180,60);
	glPopMatrix();

	glPushMatrix();
			glRotated(90., 0., 0., 1.);
			glTranslated(x2,y2,z1);
			glScalef(1.5, 1.5, 1.5);
			draw_sphere_smooth(180,60);
	glPopMatrix();

	glPushMatrix();
			glRotated(90., 0., 0., 1.);
			glTranslated(x2,y2,z2);
			glScalef(1.25, 1.25, 1.25);
			draw_sphere_smooth(180,60);
	glPopMatrix();

	glPushMatrix();
			glRotated(90., 0., 0., 1.);
			glTranslated(x2,y2,z3);
			draw_sphere_smooth(180,60);
	glPopMatrix();

	_carrot_texture.bind();
	glPushMatrix();
		glTranslated(-y1-0.2,x3,z_carrot);
		glRotated(-90., 0., 1., 0.);
		//glRotated(-180., 1., 0., 1.);
		glScalef(0.5, 0.5, 0.5);
			draw_pyramid(18);
	glPopMatrix();

	glPushMatrix();
		glTranslated(-y2+0.2,x3,z_carrot);
		glRotated(90., 0., 1., 0.);
		//glRotated(180., 0., 1., 1.);
		glScalef(0.5, 0.5, 0.5);
			draw_pyramid(18);
	glPopMatrix();

}
void ExampleWindow::do_logic() {
	_angle += 1.;
	if (_angle>=360.)
		_angle-=360.;

	x1 += coeff2;
	x2 += coeff2;
	x3 += coeff2;
	if (x1<=-4 || x1>=4){
			coeff2*=-1;}

	y1 += coeff3;
	if (y1<=-3 || y1>=-2){
				coeff3*=-1;}
	y2 += coeff4;
		if (y2<=2 || y2>=3){
					coeff4*=-1;}

	z1 += coeff;
	z2 += coeff;
	z3 += coeff;
	z_carrot += coeff;
	if (z1<=-0.6 || z1>=0.3){
		coeff*=-1;
	}
	//_camera_z = sin(_angle / 180. * Pi) * 10.;
}
