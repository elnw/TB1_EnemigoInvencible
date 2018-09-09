#pragma once
#include "CPersonaje.h"
#include "CEnemigo.h"


namespace TB1_EnemigoInvencible {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FormPrincipal
	/// </summary>
	public ref class FormPrincipal : public System::Windows::Forms::Form
	{
	public:
		FormPrincipal(void)
		{

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^  components;
	protected:
	private: System::Windows::Forms::Timer^  timer;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>

		Bitmap^ bmpMapa = gcnew Bitmap("mapa.jpg");
		Bitmap^ bmpPersonaje = gcnew Bitmap("demo.png");
		Bitmap^ bmpEnemigo = gcnew Bitmap("demon.png");
		CPersonaje *objPersonaje;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ProgressBar^  pbPersonaje;

	private: System::Windows::Forms::ProgressBar^  pbEnemigo;
	private: System::Windows::Forms::Label^  lblColision;

			 CEnemigo *objEnemigo;

			 int vida_enemigo;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pbPersonaje = (gcnew System::Windows::Forms::ProgressBar());
			this->pbEnemigo = (gcnew System::Windows::Forms::ProgressBar());
			this->lblColision = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Interval = 20;
			this->timer->Tick += gcnew System::EventHandler(this, &FormPrincipal::timer_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(12, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(52, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"LuisVives";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(12, 381);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Jailly";
			// 
			// pbPersonaje
			// 
			this->pbPersonaje->Location = System::Drawing::Point(70, 12);
			this->pbPersonaje->Name = L"pbPersonaje";
			this->pbPersonaje->Size = System::Drawing::Size(132, 16);
			this->pbPersonaje->TabIndex = 2;
			this->pbPersonaje->Value = 50;
			// 
			// pbEnemigo
			// 
			this->pbEnemigo->Location = System::Drawing::Point(47, 381);
			this->pbEnemigo->Name = L"pbEnemigo";
			this->pbEnemigo->Size = System::Drawing::Size(488, 16);
			this->pbEnemigo->TabIndex = 3;
			this->pbEnemigo->Value = 50;
			// 
			// lblColision
			// 
			this->lblColision->AutoSize = true;
			this->lblColision->Location = System::Drawing::Point(458, 12);
			this->lblColision->Name = L"lblColision";
			this->lblColision->Size = System::Drawing::Size(35, 13);
			this->lblColision->TabIndex = 4;
			this->lblColision->Text = L"label3";
			// 
			// FormPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(567, 409);
			this->Controls->Add(this->lblColision);
			this->Controls->Add(this->pbEnemigo);
			this->Controls->Add(this->pbPersonaje);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"FormPrincipal";
			this->Text = L"FormPrincipal";
			this->Load += gcnew System::EventHandler(this, &FormPrincipal::FormPrincipal_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormPrincipal::PresionarTecla);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &FormPrincipal::SoltarTecla);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics ^g = this->CreateGraphics();
		BufferedGraphicsContext ^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics ^buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);

		System::Drawing::Rectangle elmapa = System::Drawing::Rectangle(0, 0, 960, 640);
		buffer->Graphics->DrawImage(bmpMapa, 0, 0, elmapa, GraphicsUnit::Pixel);
		bmpPersonaje->MakeTransparent();
		bmpEnemigo->MakeTransparent();
		objPersonaje->Mover(buffer, bmpPersonaje);
		objEnemigo->Mover(buffer, bmpEnemigo,objPersonaje->x, objPersonaje->y,objPersonaje->Ancho, objPersonaje->Largo);



		buffer->Render(g);
		delete buffer, g, espacio;
	}
	private: System::Void FormPrincipal_Load(System::Object^  sender, System::EventArgs^  e) {

		objPersonaje = new CPersonaje();
		objEnemigo = new CEnemigo();

		pbEnemigo->Value = 100;
		pbPersonaje->Value = 100;
		vida_enemigo = objEnemigo->Vida;
	}
	private: System::Void PresionarTecla(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyCode)
		{
		case Keys::Left:
			objPersonaje->Direccion = Direcciones::Izquierda;


			break;
		case Keys::Right:
			objPersonaje->Direccion = Direcciones::Derecha;

			break;
		case Keys::Up:
			objPersonaje->Direccion = Direcciones::Arriba;


			break;
		case Keys::Down:
			objPersonaje->Direccion = Direcciones::Abajo;

			break;
		case Keys::A: {
			auto Dano = objPersonaje->AtaqueDebil(objEnemigo->X, objEnemigo->Y, objEnemigo->Ancho, objEnemigo->Largo);
			if(Dano !=0)

				lblColision->Text = "COLISON!!";
			else
				lblColision->Text = "No hay colision!!";
			objEnemigo->Vida -= Dano;
			pbEnemigo->Value = (objEnemigo->Vida / vida_enemigo) * 100;
		}
			
			break;
		}
	}
	private: System::Void SoltarTecla(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		objPersonaje->Direccion = Direcciones::Ninguna;
		
	}
};
}
