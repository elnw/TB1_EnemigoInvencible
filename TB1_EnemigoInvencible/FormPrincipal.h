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
		Bitmap^ bmpPersonaje = gcnew Bitmap("personaje.jpg");
		CPersonaje *objPersonaje;
		CEnemigo *objEnemigo;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Tick += gcnew System::EventHandler(this, &FormPrincipal::timer_Tick);
			// 
			// FormPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(567, 409);
			this->Name = L"FormPrincipal";
			this->Text = L"FormPrincipal";
			this->Load += gcnew System::EventHandler(this, &FormPrincipal::FormPrincipal_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormPrincipal::PresionarTecla);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics ^g = this->CreateGraphics();
		BufferedGraphicsContext ^espacio = BufferedGraphicsManager::Current;
		BufferedGraphics ^buffer = espacio->Allocate(g, this->ClientRectangle);

		System::Drawing::Rectangle elmapa = System::Drawing::Rectangle(0, 0, 960, 640);
		buffer->Graphics->DrawImage(bmpMapa, 0, 0, elmapa, GraphicsUnit::Pixel);
		objPersonaje->Mover(buffer, bmpPersonaje);




		buffer->Render(g);
		delete buffer, g, espacio;
	}
	private: System::Void FormPrincipal_Load(System::Object^  sender, System::EventArgs^  e) {

		objPersonaje = new CPersonaje();
		objEnemigo = new CEnemigo();
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




		}
	}
	};
}
