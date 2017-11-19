#pragma once

#ifndef _ROBOT
#define _ROBOT

#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <math.h>

#include "..\freeglut-3.0.0\include\GL\glut.h"

namespace Anim
{
	enum Animator
	{
		Walk = 1,
		Idle = 2,
		Run = 3,
		Explosion = 4,
		Jump = 5
	};
}

namespace Rbt {

	using namespace Anim;

	class Robot
	{
	public:
		Robot()
		{
			anim = Animator::Idle;
		}
		void drawRobot(int timeCount);
		void setAnim(Animator anim);
		Animator getAnim();
	private:
		void drawBox(float size, GLfloat r, GLfloat g, GLfloat b, GLfloat a);
		void drawCuboid(float length, float width, float height, GLfloat r, GLfloat g, GLfloat b, GLfloat a);
		void drawSphere(float radius, int slices, int stacks);

		void torso();
		void head();
		void leftUpperArm();
		void rightUpperArm();
		void leftUpperLeg();
		void rightUpperLeg();
		void leftLowerArm();
		void rightLowerArm();
		void leftLowerLeg();
		void rightLowerLeg();
		void leftFeet();
		void rightFeet();

		//anim
		void Idle();
		void Walk(int timeCount);
		void Run(int timeCount);
		void Explosion(int timeCount);
		void Jump(int timeCount);

		Animator anim = Animator::Idle;

		int timeCount;
	};
}

#endif