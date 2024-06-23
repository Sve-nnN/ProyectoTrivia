#pragma once
#include "Form1.h"
#include "Sound.h"
namespace savingTheFarm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FrmMenu
	/// </summary>
	public ref class FrmMenu : public System::Windows::Forms::Form
	{
	public:
		FrmMenu(void)
		{
			InitializeComponent();

			/* Inicializamos las variables gráficas
			 * que nos permitirá crear gráficos donde
			 * le asignemos.
			*/
			gMenu = PnlMenu->CreateGraphics();

			/* Creamos un espacio que nos proporciona métodos para poder
			 * configurar nuestro bufer gráfico. Con el método allocate creo
			 * un contenedor bufer de gráficos con las dimensiones de nuestros paneles
			*/
			bfSpace = BufferedGraphicsManager::Current;
			bfMenu = bfSpace->Allocate(gMenu, PnlMenu->ClientRectangle);

			/* Inicializamos los mapas de bits con las rutas de la imagen */
			bmpMenu = gcnew Bitmap("assets/1.png");
			bmpTitulo = gcnew Bitmap("assets/titulo.png");
			bmpCopyright = gcnew Bitmap("assets/copyright.png");

			/* Inicializamos los string para definir las rutas por defecto */
			pathSprite_Jugar = "assets/jugaron.png";
			pathSprite_Instrucciones = "assets/instruccionesoff.png";
			pathSprite_Creditos = "assets/creditosoff.png";
			sonido = gcnew SoundPlayer("assets/music/titlescreen.wav");
			sonido->Play();
			/* Inicializamos la clase que guarda los sonidos */
			//soundtrack = gcnew Soundtrack();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FrmMenu()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ PnlMenu;
	private: System::Windows::Forms::Timer^ Loop;
	private: System::ComponentModel::IContainer^ components;
	private:
		Graphics^ gMenu;
		BufferedGraphicsContext^ bfSpace;
		BufferedGraphics^ bfMenu;

		Bitmap^ bmpTitulo;
		Bitmap^ bmpMenu;
		Bitmap^ bmpCopyright;
		Soundtrack^ soundtrack;
		Media::SoundPlayer^ sonido;
		String^ pathSprite_Jugar;
		String^ pathSprite_Instrucciones;
		String^ pathSprite_Creditos;

		int posXTitulo = -725;
		int posYTitulo = -50;
		bool playAnimation_Title = true;
		bool playAnimationVertical_Title = false;
		bool playAnimationHorizontal_Title = true;

		int indexButtons_Menu = 1;
		bool viewScreenMenu = true;
		bool viewScreenInstructions = false;
		bool viewScreenCredits = false;

		int posYCredits_G = -250;
		int posYCredits_J = -230;
		int posYCredits_D = 680;

		int posXInstr_W = -210;
		int posXInstr_Q = -85;
		int posXInstr_E = -180;

		int ventaja;
		int dificultad;
		int indexButtons_Play = 1;
		bool viewScreenPlayGame = false;
		bool viewChooseVentaja = true;
		bool viewChooseDifficulty = false;

		bool Animacion_Titulo() {
			bfMenu->Graphics->DrawImage(bmpTitulo, posXTitulo, posYTitulo, 900, 500);

			if (posXTitulo == 185) {
				playAnimationHorizontal_Title = false;
				playAnimation_Title = playAnimationHorizontal_Title;
			}

			if (posYTitulo == -420) {
				playAnimationVertical_Title = false;
				playAnimation_Title = playAnimationVertical_Title;
			}

			if (playAnimationHorizontal_Title)
				posXTitulo += 10;

			if (playAnimationVertical_Title)
				posYTitulo -= 40;

			return playAnimation_Title;
		}

		void Cargar_Botones() {
			Bitmap^ bmpBtnJugar = gcnew Bitmap(pathSprite_Jugar);
			Bitmap^ bmpBtnInstrucciones = gcnew Bitmap(pathSprite_Instrucciones);
			Bitmap^ bmpBtnCreditos = gcnew Bitmap(pathSprite_Creditos);

			bfMenu->Graphics->DrawImage(bmpBtnJugar, 530, 405, 190, 65);
			bfMenu->Graphics->DrawImage(bmpBtnInstrucciones, 417, 485, 410, 65);
			bfMenu->Graphics->DrawImage(bmpBtnCreditos, 484, 562, 280, 60);

			delete bmpBtnJugar;
			delete bmpBtnInstrucciones;
			delete bmpBtnCreditos;
		}

		void Transicion_Pantallas() {
			playAnimationVertical_Title = true;
			viewScreenMenu = false;
			if (indexButtons_Menu == 1) viewScreenPlayGame = true;
			if (indexButtons_Menu == 2) viewScreenInstructions = true;
			if (indexButtons_Menu == 3) viewScreenCredits = true;
		}

		void ScreenChooseVentaja() {
			Bitmap^ bmpVentajas = gcnew Bitmap("assets/images/ventajas.png");
			Bitmap^ bmpCubeta = gcnew Bitmap("assets/images/cubeta.png");
			Bitmap^ bmpMedicina = gcnew Bitmap("assets/images/medicina.png");
			Bitmap^ bmpx3_C = gcnew Bitmap("assets/images/x3.png");
			Bitmap^ bmpx3_M = gcnew Bitmap("assets/images/x3.png");

			bfMenu->Graphics->DrawImage(bmpVentajas, 480, 50, 300, 60);
			bfMenu->Graphics->DrawImage(bmpCubeta, 210, 250, 120, 130);
			bfMenu->Graphics->DrawImage(bmpx3_C, 350, 300, 80, 60);
			bfMenu->Graphics->DrawImage(bmpMedicina, 840, 250, 120, 130);
			bfMenu->Graphics->DrawImage(bmpx3_M, 980, 300, 80, 60);

			delete bmpVentajas;
			delete bmpCubeta;
			delete bmpMedicina;
			delete bmpx3_C;
			delete bmpx3_M;
		}

		void Load_ScreenPlayGame() {
			Bitmap^ bmpInstrucc = gcnew Bitmap("assets/2.png");
			bfMenu->Graphics->Clear(Color::White);
			bfMenu->Graphics->DrawImage(bmpInstrucc, 0, 0, 1281, 683);
			delete bmpInstrucc;
		}

		void Load_ScreenInstructions() {
			Bitmap^ bmpWASD = gcnew Bitmap("assets/wasd.png");
			Bitmap^ bmpQ = gcnew Bitmap("assets/q.png");
			Bitmap^ bmpEnter = gcnew Bitmap("assets/enter2.png");
			Bitmap^ bmpDescriptionWASD = gcnew Bitmap("assets/descriptionwasd.png");
			Bitmap^ bmpDescriptionQ = gcnew Bitmap("assets/descriptionq.png");
			Bitmap^ bmpDescriptionEnter = gcnew Bitmap("assets/descriptionenter.png");

			bfMenu->Graphics->DrawImage(bmpWASD, posXInstr_W, 85, 210, 150);
			bfMenu->Graphics->DrawImage(bmpQ, posXInstr_Q, 310, 80, 80);
			bfMenu->Graphics->DrawImage(bmpEnter, posXInstr_E, 475, 175, 85);

			if (posXInstr_W <= 120) posXInstr_W += 20;
			else bfMenu->Graphics->DrawImage(bmpDescriptionWASD, 445, 145, 680, 30);

			if (posXInstr_Q <= 185) posXInstr_Q += 20;
			else bfMenu->Graphics->DrawImage(bmpDescriptionQ, 445, 330, 440, 30);

			if (posXInstr_E <= 140) posXInstr_E += 20;
			else bfMenu->Graphics->DrawImage(bmpDescriptionEnter, 445, 500, 420, 30);

			delete bmpWASD;
			delete bmpQ;
			delete bmpEnter;
			delete bmpDescriptionWASD;
			delete bmpDescriptionQ;
			delete bmpDescriptionEnter;
		}

		void Load_ScreenCredits() {
			Bitmap^ bmpProfile1 = gcnew Bitmap("assets/giovany.png");
			Bitmap^ bmpProfile2 = gcnew Bitmap("assets/thimoty.png");
			Bitmap^ bmpProfile3 = gcnew Bitmap("assets/juan.png");

			Bitmap^ bmpName1 = gcnew Bitmap("assets/nombre_giovani.png");  
			Bitmap^ bmpName2 = gcnew Bitmap("assets/nombre_thimoty.png");
			Bitmap^ bmpName3 = gcnew Bitmap("assets/nombre_juan.png");

			bfMenu->Graphics->DrawImage(bmpProfile1, 150, posYCredits_G, 250, 250);
			bfMenu->Graphics->DrawImage(bmpProfile2, 510, posYCredits_D, 230, 230);
			bfMenu->Graphics->DrawImage(bmpProfile3, 880, posYCredits_J, 230, 230);

			if (posYCredits_G <= 55) posYCredits_G += 15;
			else bfMenu->Graphics->DrawImage(bmpName1, 132, 330, 275, 50);

			if (posYCredits_J <= 75) posYCredits_J += 15;
			else bfMenu->Graphics->DrawImage(bmpName3, 875, 330, 245, 50);

			if (posYCredits_D >= 370) posYCredits_D -= 15;
			else bfMenu->Graphics->DrawImage(bmpName2, 505, 610, 275, 50);

			delete bmpProfile1;
			delete bmpProfile2;
			delete bmpProfile3;
			delete bmpName1;
			delete bmpName2;
			delete bmpName3;
		}

		void Reiniciar_Menu() {
			indexButtons_Play = 1;
			indexButtons_Menu = 1;

			posXTitulo = -725;
			posYTitulo = -50;

			viewScreenMenu = true;
			viewScreenPlayGame = false;
			viewScreenInstructions = false;
			viewScreenCredits = false;

			viewChooseVentaja = true;
			viewChooseDifficulty = false;

			playAnimationVertical_Title = false;
			playAnimationHorizontal_Title = true;
			playAnimation_Title = true;

			posYCredits_G = -250;
			posYCredits_J = -230;
			posYCredits_D = 680;

			posXInstr_W = -210;
			posXInstr_Q = -85;
			posXInstr_E = -180;

			ventaja = 1;
			dificultad = 1;
		}

		void Habilitar_BtnJugar() {
			pathSprite_Jugar = "assets/jugaron.png";
			pathSprite_Instrucciones = "assets/instruccionesoff.png";
			pathSprite_Creditos = "assets/creditosoff.png";
		}

		void Habilitar_BtnInstrucciones() {
			pathSprite_Jugar = "assets/jugaroff.png";
			pathSprite_Instrucciones = "assets/instruccioneson.png";
			pathSprite_Creditos = "assets/creditosoff.png";
		}

		void Habilitar_BtnCreditos() {
			pathSprite_Jugar = "assets/jugaroff.png";
			pathSprite_Instrucciones = "assets/instruccionesoff.png";
			pathSprite_Creditos = "assets/creditoson.png";
		}

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>

#pragma region Windows Form Designer generated code
/// <summary>
/// Método necesario para admitir el Diseñador. No se puede modificar
/// el contenido de este método con el editor de código.
/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->PnlMenu = (gcnew System::Windows::Forms::Panel());
			this->Loop = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// PnlMenu
			// 
			this->PnlMenu->BackColor = System::Drawing::Color::Transparent;
			this->PnlMenu->Location = System::Drawing::Point(0, 0);
			this->PnlMenu->Name = L"PnlMenu";
			this->PnlMenu->Size = System::Drawing::Size(1280, 682);
			this->PnlMenu->TabIndex = 0;
			// 
			// Loop
			// 
			this->Loop->Enabled = true;
			this->Loop->Interval = 33;
			this->Loop->Tick += gcnew System::EventHandler(this, &FrmMenu::Loop_Tick);
			// 
			// FrmMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1280, 682);
			this->Controls->Add(this->PnlMenu);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"FrmMenu";
			this->Text = L"FrmMenu";
			this->Load += gcnew System::EventHandler(this, &FrmMenu::FrmMenu_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FrmMenu::FrmMenu_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion

#pragma region Events
	private: System::Void Loop_Tick(System::Object^ sender, System::EventArgs^ e) {
		bfMenu->Graphics->Clear(Color::White);
		bfMenu->Graphics->DrawImage(bmpMenu, 0, 0, 1281, 683);

		if (!Animacion_Titulo() &&
			!viewScreenPlayGame &&
			!viewScreenInstructions &&
			!viewScreenCredits) {
			Cargar_Botones();
			bfMenu->Graphics->DrawImage(bmpCopyright, 7, 660, 380, 15);
		}

		/* Visualización de distintas pantallas en el menú */
		if (viewScreenPlayGame)
			Load_ScreenPlayGame();

		if (viewScreenInstructions)
			Load_ScreenInstructions();

		if (viewScreenCredits)
			Load_ScreenCredits();

		bfMenu->Render(gMenu);
	}

	private: System::Void FrmMenu_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (viewScreenMenu) {
			if (e->KeyCode == Keys::Space)
				posXTitulo = 185;

			if (posXTitulo != 185) return;

			if (e->KeyCode == Keys::Up && indexButtons_Menu > 1) {
				indexButtons_Menu--;
				//soundtrack->Play_ChooseButton();
			}

			if (e->KeyCode == Keys::Down && indexButtons_Menu < 3) {
				indexButtons_Menu++;
			//	soundtrack->Play_ChooseButton();
			}

			switch (indexButtons_Menu) {
			case 1: Habilitar_BtnJugar(); break;
			case 2: Habilitar_BtnInstrucciones(); break;
			case 3: Habilitar_BtnCreditos(); break;
			}

			if (e->KeyCode == Keys::Enter) {
				Transicion_Pantallas();
				//	soundtrack->Play_Enter();
				return;
			}

			if (e->KeyCode == Keys::Escape)
				Application::Exit();
		}

		if (viewScreenPlayGame) {
			if (e->KeyCode == Keys::Left && indexButtons_Play > 1) {
				indexButtons_Play--;
				//	soundtrack->Play_ChooseButton();
			}

			if (e->KeyCode == Keys::Right && indexButtons_Play < 2) {
				indexButtons_Play++;
				//	soundtrack->Play_ChooseButton();
			}

			viewChooseDifficulty = true;
			if (e->KeyCode == Keys::Enter && viewChooseDifficulty) {
				dificultad = indexButtons_Play;
			//	soundtrack->Play_Enter();
				//soundtrack->Stop_TitleScreen();

			//	Loop->Enabled = false;
				FrmMenu::Visible = false;

				CppCLRWinFormsProject::Form1^ frmBackground = gcnew CppCLRWinFormsProject::Form1();
				frmBackground->ShowDialog();
				sonido->Stop();
				Reiniciar_Menu();
				//	soundtrack->Play_TitleScreen();
			//	Loop->Enabled = true;
				FrmMenu::Visible = true;
				Application::Exit();
			}
		}

		if (e->KeyCode == Keys::Escape &&
			(viewScreenPlayGame || viewScreenInstructions || viewScreenCredits)) {
			Reiniciar_Menu();
			//soundtrack->Play_Back();
		}

		bfMenu->Render(gMenu);
	}
#pragma endregion
	private: System::Void FrmMenu_Load(System::Object^ sender, System::EventArgs^ e) {
		//soundtrack->Play_TitleScreen();
	}
	};
}
