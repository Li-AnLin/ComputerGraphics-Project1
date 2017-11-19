#include "robot.h"

using namespace Rbt;
void Robot::drawRobot(int timeCount)
{
	//drawSphere(1.0, 40, 50);
	switch (anim)
	{
	case Anim::Walk:
		Walk(timeCount);
		break;
	case Anim::Idle:
		Idle();
		break;
	case Anim::Run:
		Run(timeCount);
		break;
	case Anim::Explosion:
		Explosion(timeCount);
		break;
	case Anim::Jump:
		Jump(timeCount);
		break;
	default:
		Idle();
		break;
	}
}

void Rbt::Robot::setAnim(Animator anim)
{
	this->anim = anim;
}

Animator Rbt::Robot::getAnim()
{
	return anim;
}

void Robot::drawBox(float size, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	glColor4f(r, g, b, a);
	glBegin(GL_QUADS);
	//front
	glNormal3f(0, 0, 1);
	glVertex3f(-size, size, size);
	glVertex3f(-size, -size, size);
	glVertex3f(size, -size, size);
	glVertex3f(size, size, size);
	//left
	glNormal3f(-1, 0, 0);
	glVertex3f(-size, size, -size);
	glVertex3f(-size, -size, -size);
	glVertex3f(-size, -size, size);
	glVertex3f(-size, size, size);
	//rught
	glNormal3f(1, 0, 0);
	glVertex3f(size, size, size);
	glVertex3f(size, -size, size);
	glVertex3f(size, -size, -size);
	glVertex3f(size, size, -size);
	//back
	glNormal3f(0, 0, -1);
	glVertex3f(size, size, -size);
	glVertex3f(size, -size, -size);
	glVertex3f(-size, -size, -size);
	glVertex3f(-size, size, -size);
	//top
	glNormal3f(0, 1, 0);
	glVertex3f(-size, size, -size);
	glVertex3f(-size, size, size);
	glVertex3f(size, size, size);
	glVertex3f(size, size, -size);
	//down
	glNormal3f(0, -1, 0);
	glVertex3f(size, -size, size);
	glVertex3f(-size, -size, size);
	glVertex3f(-size, -size, -size);
	glVertex3f(size, -size, -size);

	glEnd();

}

void Robot::drawCuboid(float length, float width, float height, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
	glColor4f(r, g, b, a);
	glBegin(GL_QUADS);

	float l = length / 2, w = width / 2, h = height;

	//front
	glNormal3f(0, 0, 1);
	glNormal3f(0, 0, 1);
	glVertex3f(-l, h, w);
	glVertex3f(-l, 0, w);
	glVertex3f(l, 0, w);
	glVertex3f(l, h, w);
	//left
	glNormal3f(-1, 0, 0);
	glVertex3f(-l, h, -w);
	glVertex3f(-l, 0, -w);
	glVertex3f(-l, 0, w);
	glVertex3f(-l, h, w);
	//rught
	glNormal3f(1, 0, 0);
	glVertex3f(l, h, w);
	glVertex3f(l, 0, w);
	glVertex3f(l, 0, -w);
	glVertex3f(l, h, -w);
	//back
	glNormal3f(0, 0, -1);
	glVertex3f(l, h, -w);
	glVertex3f(l, 0, -w);
	glVertex3f(-l, 0, -w);
	glVertex3f(-l, h, -w);
	//top
	glNormal3f(0, 1, 0);
	glVertex3f(-l, h, -w);
	glVertex3f(-l, h, w);
	glVertex3f(l, h, w);
	glVertex3f(l, h, -w);
	//down
	glNormal3f(0, -1, 0);
	glVertex3f(l, 0, w);
	glVertex3f(-l, 0, w);
	glVertex3f(-l, 0, -w);
	glVertex3f(l, 0, -w);

	glEnd();
}

void Rbt::Robot::drawSphere(float radius, int slices, int stacks)
{
	glutSolidSphere(radius, slices, stacks);
}

void Rbt::Robot::torso()
{
	glScalef(0.6, 0.6, 0.6);
	//torso
	glTranslatef(0, 0, 0);

	//anim
	switch (anim)
	{
	case Anim::Jump:
		if (timeCount < 20)
			glRotatef(45, 1, 0, 0);
		else if (45 - timeCount + 20 > 0)
		{
			glRotatef(45 - timeCount + 20, 1, 0, 0);
			glTranslatef(0, 0.1 * timeCount, 0);
		}
		else if(45 - timeCount - 20 > -180)
			glTranslatef(0, 0.1 * timeCount, 0);
		else if(timeCount < 205 * 2)
			glTranslatef(0, 0.1 * (205 - (timeCount-205)), 0);
		break;
	default:
		break;
	}

	drawCuboid(5, 3, 8, 1.0, 0.96, 0.49, 1.0);

	//head
	glPushMatrix();
	head();
	glPopMatrix();

	//left upper arm
	glPushMatrix();
	leftUpperArm();
	glPopMatrix();

	//right upper arm
	glPushMatrix();
	rightUpperArm();
	glPopMatrix();

	//left upper leg
	glPushMatrix();
	leftUpperLeg();
	glPopMatrix();

	//right upper leg
	glPushMatrix();
	rightUpperLeg();
	glPopMatrix();
}

void Rbt::Robot::head()
{
	//head
	glTranslatef(0, 8 + 1, 0);

	//anim
	switch (anim)
	{
	case Anim::Explosion:
		glTranslatef(0, 0.1 * timeCount, 0);
		glRotatef(timeCount * 2, 0, 1, 1);
		break;
	default:
		break;
	}

	drawBox(1, 0.5, 1, 0.5, 1);
}

#pragma region Arm
void Rbt::Robot::leftUpperArm()
{
	glTranslatef(5 / 2.0, 7, 0);
	//anim
	float speed = 10.0, angle = 45.0;
	switch (anim)
	{
	case Anim::Walk:
		glRotatef(15, 0, 0, 1);
		glRotatef(-sinf(this->timeCount / speed) * angle, 1, 0, 0);
		break;
	case Anim::Run:
		glRotatef(15, 0, 0, 1);
		glRotatef(-sinf(this->timeCount / speed * 1.5) * angle, 1, 0, 0);
		break;
	case Anim::Explosion:
		glTranslatef(0.1 * timeCount, 0.1 * timeCount, 0);
		glRotatef(-0.1 * timeCount, 0, 1, 0);
		break;
	case Anim::Jump:
		if (timeCount < 20)
		{
			glRotatef(15, 0, 0, 1);
			glRotatef(45, 1, 0, 0);
		}
		else if(45 - timeCount - 20 > -180)
		{
			glRotatef(45 - timeCount - 10, 1, 0, 0);
		}
		else if (timeCount - 205 < 90)
		{
			glRotatef(-180, 1, 0, 0);
			glRotatef(timeCount - 205, 0, 0, 1);
		}
		else
			glRotatef(90, 0, 0, 1);
		break;
	default:
		glRotatef(15, 0, 0, 1);
		break;
	}

	drawBox(0.5, 0, 1, 0, 1);	//關節

	//left upper arm
	glPushMatrix();
	{
		glTranslatef(0, -0.5 / 2.0, 0);

		//anim
		switch (anim)
		{
		case Anim::Explosion:
			glTranslatef(0.1 * timeCount, 0, 0);
			break;
		default:
			break;
		}

		drawCuboid(2, 2, -4, 1, 0, 0, 1);

		//left lower arm
		glPushMatrix();
		{
			leftLowerArm();
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void Rbt::Robot::rightUpperArm()
{
	glTranslatef(-5/2.0, 7, 0);

	//anim
	float speed = 10.0, angle = 45.0;
	switch (anim)
	{
	case Anim::Walk:
		glRotatef(-15, 0, 0, 1);
		glRotatef(sinf(this->timeCount / speed) * angle, 1, 0, 0);
		break;
	case Anim::Run:
		glRotatef(-15, 0, 0, 1);
		glRotatef(sinf(this->timeCount / speed * 1.5) * angle, 1, 0, 0);
		break;
	case Anim::Explosion:
		glTranslatef(-0.1 * timeCount, 0.1 * timeCount, 0);
		glRotatef(-0.1 * timeCount, 0, 1, 0);
		break;
	case Anim::Jump:
		if (timeCount < 20)
		{
			glRotatef(-15, 0, 0, 1);
			glRotatef(45, 1, 0, 0);
		}
		else if(45 - timeCount - 20 > -180)
		{
			glRotatef(45 - timeCount - 10, 1, 0, 0);
		}
		else if(-timeCount + 205 > -90)
		{
			glRotatef(-180, 1, 0, 0);
			glRotatef(-timeCount+205, 0, 0, 1);
		}
		else
			glRotatef(-90, 0, 0, 1);
		break;
	default:
		glRotatef(-15, 0, 0, 1);
		break;
	}

	drawBox(0.5, 0, 1, 0, 1);	//關節
	
	//right upper arm
	glPushMatrix();
	{
		glTranslatef(0, -0.5 / 2.0, 0);
		//anim
		switch (anim)
		{
		case Anim::Explosion:
			glTranslatef(-0.1 * timeCount, 0, 0);
			break;
		default:
			break;
		}
		drawCuboid(2, 2, -4, 1, 0, 0, 1);
		
		//right lower arm
		glPushMatrix();
		{
			rightLowerArm();
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void Rbt::Robot::leftLowerArm()
{
	glTranslatef(0, -4, 0);

	//anim
	switch (anim)
	{
	case Anim::Run:
		glRotatef(-90, 1, 0, 0);
		break;
	case Anim::Explosion:
		glTranslatef(0,-0.1 * timeCount, -0.1 * timeCount);
		glRotatef(timeCount * 2, 0, 1, 1);
		break;
	default:
		break;
	}

	drawBox(0.5, 0, 1, 0, 1);	//關節

	glPushMatrix();
	{
		glTranslatef(0, -0.5, 0);
		//anim
		switch (anim)
		{
		case Anim::Explosion:
			glTranslatef(-0.1 * timeCount, 0, 0);
			glRotatef(timeCount * 2, 0, 0, 1);
			break;
		default:
			break;
		}

		drawCuboid(1.5, 1.5, -3, 0.5, 0, 0.5, 1);
	}
	glPopMatrix();
}

void Rbt::Robot::rightLowerArm()
{
	glTranslatef(0, -4, 0);

	//anim
	switch (anim)
	{
	case Anim::Run:
		glRotatef(-90, 1, 0, 0);
		break;
	case Anim::Explosion:
		glTranslatef(0, -0.1 * timeCount, -0.1 * timeCount);
		glRotatef(timeCount * 2, 0, 1, 1);
		break;
	default:
		break;
	}

	drawBox(0.5, 0, 1, 0, 1);	//關節

	glPushMatrix();
	{
		glTranslatef(0, -0.5, 0);
		//anim
		switch (anim)
		{
		case Anim::Explosion:
			glTranslatef(0.1 * timeCount, 0, 0.1 * timeCount);
			glRotatef(timeCount * 2, 0, 0, 1);
			break;
		default:
			break;
		}

		drawCuboid(1.5, 1.5, -3, 0.5, 0, 0.5, 1);
	}
	glPopMatrix();
}
#pragma endregion

#pragma region Leg
void Rbt::Robot::leftUpperLeg()
{
	glTranslatef(5/4.0, 0, 0);
	//anim
	float speed = 10.0, angle = 45.0;
	switch (anim)
	{
	case Anim::Walk:
		glRotatef(sinf(this->timeCount / speed) * angle, 1, 0, 0);
		break;
	case Anim::Run:
		glRotatef(sinf(this->timeCount / speed * 1.5) * angle, 1, 0, 0);
		break;
	case Anim::Explosion:
		glTranslatef(0.1 * timeCount, -0.1 * timeCount, -0.1 * timeCount);
		glRotatef(timeCount * 2, 0, 1, 1);
		break;
	case Anim::Jump:
		if (timeCount < 20)
			glRotatef(-90, 1, 0, 0);
		else if (-90 + timeCount - 20 < 0)
			glRotatef(-90 + timeCount - 20, 1, 0, 0);
		break;
	default:
		break;
	}

	drawBox(0.5, 0, 1, 0, 1);	//關節

	//left upper leg
	glPushMatrix();
	{
		glTranslatef(0, -0.5 / 2.0, 0);
		//anim
		switch (anim)
		{
		case Anim::Explosion:
			glTranslatef(0.1 * timeCount, -0.1 * timeCount, -0.1 * timeCount);
			glRotatef(-timeCount * 2, 0,1, 1);
			break;
		default:
			break;
		}

		drawCuboid(2, 2, -4, 1, 0, 0, 1);

		//left lower leg
		glPushMatrix();
		{
			leftLowerLeg();
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void Rbt::Robot::rightUpperLeg()
{
	glTranslatef(-5 / 4.0, 0, 0);

	float speed = 10.0, angle = 45.0;
	switch (anim)
	{
	case Anim::Walk:
		glRotatef(-sinf(this->timeCount / speed) * angle, 1, 0, 0);
		break;
	case Anim::Run:
		glRotatef(-sinf(this->timeCount / speed * 1.5) * angle, 1, 0, 0);
		break;
	case Anim::Explosion:
		glTranslatef(-0.1 * timeCount, -0.1 * timeCount, 0);
		glRotatef(timeCount * 2, 0, 1, 1);
		break;
	case Anim::Jump:
		if (timeCount < 20)
			glRotatef(-90, 1, 0, 0);
		else if (-90 + timeCount - 20 < 0)
			glRotatef(-90 + timeCount - 20, 1, 0, 0);
		break;
	default:
		break;
	}

	drawBox(0.5, 0, 1, 0, 1);	//關節

	//right upper leg
	glPushMatrix();
	{
		glTranslatef(0, -0.5 / 2.0, 0);
		//anim
		switch (anim)
		{
		case Anim::Explosion:
			glTranslatef(-0.1 * timeCount, -0.1 * timeCount, -0.1 * timeCount);
			glRotatef(-timeCount * 2, 0, 1, 1);
			break;
		default:
			break;
		}
		drawCuboid(2, 2, -4, 1, 0, 0, 1);

		//right lower leg
		glPushMatrix();
		{
			rightLowerLeg();
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void Rbt::Robot::leftLowerLeg()
{
	glTranslatef(0, -4, 0);

	//anim
	float speed = 10.0, angle = 15.0;
	switch (anim)
	{
	case Anim::Run:
		glRotatef(sinf(this->timeCount / speed) * angle, 1, 0, 0);
		break;
	case Anim::Explosion:
		glTranslatef(0.1 * timeCount, -0.1 * timeCount, -0.1 * timeCount);
		glRotatef(timeCount * 2, 0, 1, 1);
		break;
	case Anim::Jump:
		if (timeCount < 20)
			glRotatef(90, 1, 0, 0);
		else if (90 - timeCount + 20 > 0)
			glRotatef(90 - timeCount + 20, 1, 0, 0);
		break;
	default:
		break;
	}

	drawBox(0.5, 0, 1, 0, 1);	//關節

	glPushMatrix();
	{
		glTranslatef(0, -0.5, 0);
		//anim
		switch (anim)
		{
		case Anim::Explosion:
			glTranslatef(0.1 * timeCount, -0.1 * timeCount, 0);
			break;
		default:
			break;
		}
		drawCuboid(1.5, 1.5, -3, 0.5, 0, 0.5, 1);

		//left feet
		glPushMatrix();
		{
			leftFeet();
		}
		glPopMatrix();
	}
	glPopMatrix();
}

void Rbt::Robot::rightLowerLeg()
{
	glTranslatef(0, -4, 0);

	//anim
	float speed = 10.0, angle = 15.0;
	switch (anim)
	{
	case Anim::Run:
		glRotatef(-sinf(this->timeCount / speed) * angle, 1, 0, 0);
		break;
	case Anim::Explosion:
		glTranslatef(-0.1 * timeCount, -0.1 * timeCount, -0.1 * timeCount);
		glRotatef(timeCount * 2, 0,1,1 );
		break;
	case Anim::Jump:
		if (timeCount < 20)
			glRotatef(90, 1, 0, 0);
		else if (90 - timeCount + 20 > 0)
			glRotatef(90 - timeCount + 20, 1, 0, 0);
		break;
	default:
		break;
	}

	drawBox(0.5, 0, 1, 0, 1);	//關節

	glPushMatrix();
	{
		//right lower leg
		glTranslatef(0, -0.5, 0);
		//anim
		switch (anim)
		{
		case Anim::Explosion:
			glTranslatef(-0.1 * timeCount, -0.1 * timeCount, 0);
			break;
		default:
			break;
		}
		drawCuboid(1.5, 1.5, -3, 0.5, 0, 0.5, 1);

		//right feet
		glPushMatrix();
		{
			rightFeet();
		}
		glPopMatrix();
	}
	glPopMatrix();
}
#pragma endregion

#pragma region Feet

void Rbt::Robot::leftFeet()
{
	glTranslatef(0, -3, 0);
	//anim
	switch (anim)
	{
	case Anim::Jump:
		if (timeCount < 20)
			glRotatef(-30, 1, 0, 0);
		else if (-30 + timeCount - 20 < 0)
			glRotatef(-30 + timeCount - 20, 1, 0, 0);
		break;
	default:
		break;
	}	
	drawBox(0.5, 0, 1, 0, 1);	//關節

	glPushMatrix();
	{
		glTranslatef(0, -0.5, 1);
		drawCuboid(2, 3, -1, 0, 0, 1, 1);
	}
	glPopMatrix();
}

void Rbt::Robot::rightFeet()
{
	glTranslatef(0, -3, 0);
	//anim
	switch (anim)
	{
	case Anim::Jump:
		if (timeCount < 20)
			glRotatef(-30, 1, 0, 0);
		else if (-30 + timeCount - 20 < 0)
			glRotatef(-30 + timeCount - 20, 1, 0, 0);
		break;
	default:
		break;
	}
	drawBox(0.5, 0, 1, 0, 1);	//關節

	glPushMatrix();
	{
		glTranslatef(0, -0.5, 1);
		drawCuboid(2, 3, -1, 0, 0, 1, 1);
	}
	glPopMatrix();
}
#pragma endregion

#pragma region Anim

void Rbt::Robot::Idle()
{
	this->timeCount = 0;
	torso();
}

void Rbt::Robot::Walk(int timeCount)
{
	this->timeCount = timeCount;

	torso();
}

void Rbt::Robot::Run(int timeCount)
{
	this->timeCount = timeCount;

	torso();
}

void Rbt::Robot::Explosion(int timeCount)
{
	this->timeCount = timeCount;

	torso();
}

void Rbt::Robot::Jump(int timeCount)
{
	this->timeCount = timeCount;

	torso();
}

#pragma endregion
