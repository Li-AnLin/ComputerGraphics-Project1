#pragma once

#include <Windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "camera\GLCamera.h"
#include "robot.h"

xform xf;
GLCamera camera;

float fov = 0.7f;

point center = { 0,0,0 };
//變數
int count;

static const Mouse::button physical_to_logical_map[] = {
	Mouse::NONE, Mouse::ROTATE, Mouse::MOVEXY, Mouse::MOVEZ,
	Mouse::MOVEZ, Mouse::MOVEXY, Mouse::MOVEXY, Mouse::MOVEXY,
};

Mouse::button Mouse_State = Mouse::ROTATE;

namespace project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Rbt;
	using namespace Anim;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm
		: public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: HKOGLPanel::HKOGLPanelControl^  hkoglPanelControl1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::CheckBox^  checkBox_Axis;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::Timer^  timer1;


	private: System::Windows::Forms::Button^  Walk;
	private: System::Windows::Forms::Button^  Idle;
	private: System::Windows::Forms::Button^  Run;
	private: System::Windows::Forms::Button^  Explosion;
	private: System::Windows::Forms::CheckBox^  Light;
	private: System::Windows::Forms::Button^  Jump;


	protected:

	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>

		Robot *robot = new Robot();

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			HKOGLPanel::HKCOGLPanelCameraSetting^  hkcoglPanelCameraSetting2 = (gcnew HKOGLPanel::HKCOGLPanelCameraSetting());
			HKOGLPanel::HKCOGLPanelPixelFormat^  hkcoglPanelPixelFormat2 = (gcnew HKOGLPanel::HKCOGLPanelPixelFormat());
			this->hkoglPanelControl1 = (gcnew HKOGLPanel::HKOGLPanelControl());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->checkBox_Axis = (gcnew System::Windows::Forms::CheckBox());
			this->Light = (gcnew System::Windows::Forms::CheckBox());
			this->Walk = (gcnew System::Windows::Forms::Button());
			this->Idle = (gcnew System::Windows::Forms::Button());
			this->Run = (gcnew System::Windows::Forms::Button());
			this->Explosion = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->Jump = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// hkoglPanelControl1
			// 
			hkcoglPanelCameraSetting2->Far = 1000;
			hkcoglPanelCameraSetting2->Fov = 45;
			hkcoglPanelCameraSetting2->Near = -1000;
			hkcoglPanelCameraSetting2->Type = HKOGLPanel::HKCOGLPanelCameraSetting::CAMERATYPE::ORTHOGRAPHIC;
			this->hkoglPanelControl1->Camera_Setting = hkcoglPanelCameraSetting2;
			this->hkoglPanelControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->hkoglPanelControl1->Location = System::Drawing::Point(194, 78);
			this->hkoglPanelControl1->Margin = System::Windows::Forms::Padding(4);
			this->hkoglPanelControl1->Name = L"hkoglPanelControl1";
			hkcoglPanelPixelFormat2->Accumu_Buffer_Bits = HKOGLPanel::HKCOGLPanelPixelFormat::PIXELBITS::BITS_0;
			hkcoglPanelPixelFormat2->Alpha_Buffer_Bits = HKOGLPanel::HKCOGLPanelPixelFormat::PIXELBITS::BITS_0;
			hkcoglPanelPixelFormat2->Stencil_Buffer_Bits = HKOGLPanel::HKCOGLPanelPixelFormat::PIXELBITS::BITS_0;
			this->hkoglPanelControl1->Pixel_Format = hkcoglPanelPixelFormat2;
			this->hkoglPanelControl1->Size = System::Drawing::Size(770, 508);
			this->hkoglPanelControl1->TabIndex = 0;
			this->hkoglPanelControl1->Load += gcnew System::EventHandler(this, &MyForm::hkoglPanelControl1_Load_1);
			this->hkoglPanelControl1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::hkoglPanelControl1_Paint);
			this->hkoglPanelControl1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::hkoglPanelControl1_MouseDown);
			this->hkoglPanelControl1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::hkoglPanelControl1_MouseMove);
			this->hkoglPanelControl1->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::hkoglPanelControl1_MouseWheel);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				19.69697F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				80.30303F)));
			this->tableLayoutPanel1->Controls->Add(this->hkoglPanelControl1, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel1, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 12.71186F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 87.28814F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(968, 590);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->checkBox_Axis);
			this->flowLayoutPanel1->Controls->Add(this->Light);
			this->flowLayoutPanel1->Controls->Add(this->Walk);
			this->flowLayoutPanel1->Controls->Add(this->Idle);
			this->flowLayoutPanel1->Controls->Add(this->Run);
			this->flowLayoutPanel1->Controls->Add(this->Explosion);
			this->flowLayoutPanel1->Controls->Add(this->Jump);
			this->flowLayoutPanel1->Location = System::Drawing::Point(4, 78);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(157, 508);
			this->flowLayoutPanel1->TabIndex = 1;
			// 
			// checkBox_Axis
			// 
			this->checkBox_Axis->AutoSize = true;
			this->checkBox_Axis->Checked = true;
			this->checkBox_Axis->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox_Axis->Location = System::Drawing::Point(4, 4);
			this->checkBox_Axis->Margin = System::Windows::Forms::Padding(4);
			this->checkBox_Axis->Name = L"checkBox_Axis";
			this->checkBox_Axis->Size = System::Drawing::Size(55, 19);
			this->checkBox_Axis->TabIndex = 0;
			this->checkBox_Axis->Text = L"Axis";
			this->checkBox_Axis->UseVisualStyleBackColor = true;
			// 
			// Light
			// 
			this->Light->AutoSize = true;
			this->Light->Location = System::Drawing::Point(66, 3);
			this->Light->Name = L"Light";
			this->Light->Size = System::Drawing::Size(60, 19);
			this->Light->TabIndex = 6;
			this->Light->Text = L"Light";
			this->Light->UseVisualStyleBackColor = true;
			// 
			// Walk
			// 
			this->Walk->Location = System::Drawing::Point(3, 30);
			this->Walk->Name = L"Walk";
			this->Walk->Size = System::Drawing::Size(85, 40);
			this->Walk->TabIndex = 1;
			this->Walk->Text = L"Walk";
			this->Walk->UseVisualStyleBackColor = true;
			this->Walk->Click += gcnew System::EventHandler(this, &MyForm::Walk_Click);
			// 
			// Idle
			// 
			this->Idle->Location = System::Drawing::Point(3, 76);
			this->Idle->Name = L"Idle";
			this->Idle->Size = System::Drawing::Size(85, 40);
			this->Idle->TabIndex = 3;
			this->Idle->Text = L"Idle";
			this->Idle->UseVisualStyleBackColor = true;
			this->Idle->Click += gcnew System::EventHandler(this, &MyForm::Idle_Click);
			// 
			// Run
			// 
			this->Run->Location = System::Drawing::Point(3, 122);
			this->Run->Name = L"Run";
			this->Run->Size = System::Drawing::Size(85, 40);
			this->Run->TabIndex = 4;
			this->Run->Text = L"Run";
			this->Run->UseVisualStyleBackColor = true;
			this->Run->Click += gcnew System::EventHandler(this, &MyForm::Run_Click);
			// 
			// Explosion
			// 
			this->Explosion->Location = System::Drawing::Point(3, 168);
			this->Explosion->Name = L"Explosion";
			this->Explosion->Size = System::Drawing::Size(85, 40);
			this->Explosion->TabIndex = 5;
			this->Explosion->Text = L"Explosion";
			this->Explosion->UseVisualStyleBackColor = true;
			this->Explosion->Click += gcnew System::EventHandler(this, &MyForm::Explosion_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// Jump
			// 
			this->Jump->Location = System::Drawing::Point(3, 214);
			this->Jump->Name = L"Jump";
			this->Jump->Size = System::Drawing::Size(85, 40);
			this->Jump->TabIndex = 7;
			this->Jump->Text = L"Jump";
			this->Jump->UseVisualStyleBackColor = true;
			this->Jump->Click += gcnew System::EventHandler(this, &MyForm::Jump_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(968, 590);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void hkoglPanelControl1_Load(System::Object^  sender, System::EventArgs^  e) {
		//初始
		count = 0;
	}
	private: System::Void hkoglPanelControl1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		glEnable(GL_COLOR_MATERIAL); //允許使用glColor
		glClearColor(0.0, 0.0, 0.0, 1.0); //畫面背景顏色
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //清除顏色及深度的buffer

		//設定camera-----
		camera.setupGL(xf * center, 1000.0);
		camera.set_fov(fov);
		glTranslatef(0, -1, -30);
		//---------------
		glMatrixMode(GL_MODELVIEW);
		glMultMatrixd((double *)xf); //設定model view
		//打光
		if (Light->Checked)
		{
			GLfloat diffuse0[] = { 1.0,1.0,1.0,1.0 };
			GLfloat ambient0[] = { 0,0,0,1.0 };
			GLfloat specular0[] = { 1.0,1.0,1.0,1.0 };
			GLfloat light0_pos[] = { -10.0,-5.0,5.0,1.0 };
			GLfloat spot_direction[] = { 1.0,1.0,-1.0 };
			GLint spot_exponent = 30, spot_cutoff = 180;
			GLfloat constant = 1.0, linear = 0, quadratic = 0;
			//GLfloat a = 0.8;

			glEnable(GL_LIGHTING);
			glEnable(GL_LIGHT0);

			glLightfv(GL_LIGHT0, GL_POSITION, light0_pos);
			glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0);
			glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0);
			glLightfv(GL_LIGHT0, GL_SPECULAR, specular0);

			glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);
			glLighti(GL_LIGHT0, GL_SPOT_EXPONENT, spot_exponent);
			glLighti(GL_LIGHT0, GL_SPOT_CUTOFF, spot_cutoff);

			glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, constant);
			glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, linear);
			glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, quadratic);
		}
		else
			glDisable(GL_LIGHTING); //關燈

		glEnable(GL_DEPTH_TEST); //開深度測試
		glDisable(GL_CULL_FACE);

		//---------------
		//material
		GLfloat diffuse[] = { 0.2,0.2,0.2,1.0 };
		GLfloat ambient[] = { 1.0,0.8,0.8,1.0 };
		GLfloat specular[] = { 1.0,1.0,1.0,1.0 };
		GLfloat shine = 128;

		glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
		glMaterialf(GL_FRONT, GL_SHININESS, shine);
		//---------------
		glPushMatrix();
		robot->drawRobot(count);
		glPopMatrix();
		glPushMatrix();
		//--------------------------
		if (checkBox_Axis->Checked)
		{
			glDisable(GL_LIGHTING); //關燈
			int length = 1000;
			glBegin(GL_LINES);
			glLineWidth(10.0);
			glColor4f(1.0, 0.0, 0.0, 1.0);
			glVertex3f(0, 0, 0);
			glVertex3f(length, 0, 0);

			glColor4f(0.0, 1.0, 0.0, 1.0);
			glVertex3f(0, 0, 0);
			glVertex3f(0, length, 0);

			glColor4f(0.0, 0.0, 1.0, 1.0);
			glVertex3f(0, 0, 0);
			glVertex3f(0, 0, length);
			glEnd();
		}
		//---------------------------

		glPopMatrix();

	}
	private: System::Void hkoglPanelControl1_Load_1(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void hkoglPanelControl1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left ||
			e->Button == System::Windows::Forms::MouseButtons::Middle)
		{
			Mouse_State = Mouse::NONE;
			camera.mouse(e->X, e->Y, Mouse_State,
				xf * center,
				1.0, xf);
		}
	}
	private: System::Void hkoglPanelControl1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			Mouse_State = Mouse::ROTATE;
			camera.mouse(e->X, e->Y, Mouse_State,
				xf * center,
				1.0, xf);
		}
		if (e->Button == System::Windows::Forms::MouseButtons::Middle)
		{
			Mouse_State = Mouse::MOVEXY;
			camera.mouse(e->X, e->Y, Mouse_State,
				xf * center,
				1.0, xf);
		}
	}
	private: System::Void hkoglPanelControl1_MouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		if (e->Delta < 0)
		{
			Mouse_State = Mouse::WHEELDOWN;
			camera.mouse(e->X, e->Y, Mouse_State,
				xf * center,
				1.0, xf);
		}
		else
		{
			Mouse_State = Mouse::WHEELUP;
			camera.mouse(e->X, e->Y, Mouse_State,
				xf * center,
				1.0, xf);
		}
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		//控制速度 每n秒更新一次
		count++;
		hkoglPanelControl1->Invalidate();
	}

#pragma region Animator
	private: System::Void Walk_Click(System::Object^  sender, System::EventArgs^  e) {
		count = 0;
		robot->setAnim(Animator::Walk);
	}

	private: System::Void Idle_Click(System::Object^  sender, System::EventArgs^  e) {
		count = 0;
		robot->setAnim(Animator::Idle);
	}

	private: System::Void Run_Click(System::Object^  sender, System::EventArgs^  e) {
		count = 0;
		robot->setAnim(Animator::Run);
	}

	private: System::Void Explosion_Click(System::Object^  sender, System::EventArgs^  e) {
		count = 0;
		robot->setAnim(Animator::Explosion);
	}

	private: System::Void Jump_Click(System::Object^  sender, System::EventArgs^  e) {
		count = 0;
		robot->setAnim(Animator::Jump);
	}
#pragma endregion
};
}
