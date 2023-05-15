#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <msclr/marshal.h>
#include <msclr/marshal_cppstd.h>
#include <fstream>

namespace TrabajoMatemáticaComputacional {

	using namespace System;
	using namespace std;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Media;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: 
		SoundPlayer^ music;
	public:
		MyForm(void)
		{
			InitializeComponent();
			music = gcnew SoundPlayer("music.wav");
			//
			//TODO: agregar código de constructor aquí
			//
		}

		bool es_primo(int n) {
			if (n < 2) return false;
			for (int i = 2; i * i <= n; i++) {
				if (n % i == 0) return false;
			}
			return true;
		}

		int mcd(int a, int b) {
			int r;
			while (b > 0) {
				r = a % b;
				a = b;
				b = r;
			}
			return a;
		}

		int encontrarE(int phi) {
			int e = 2;
			while (e < phi) {
				if (mcd(e, phi) == 1) {
					break;
				}
				e++;
			}
			return e;
		}

		int encontrarD(int e, int phi) {
			int k = 1;
			int d;
			while (true) {
				d = (1 + k * phi) / e;
				if ((d * e) % phi == 1) {
					break;
				}
				k++;
			}
			return d;
		}
		
		vector<int> encriptarRSA(string mensaje, int p, int q) {
			int n = p * q;
			int phi = (p - 1) * (q - 1);
			int e = encontrarE(phi);
			int d = encontrarD(e, phi);

			std::vector<int> mensajeEncriptado;

			for (char c : mensaje) {
				int m = int(c);
				int cEncriptado = 1;
				for (int i = 0; i < e; i++) {
					cEncriptado = (cEncriptado * m) % n;
				}
				mensajeEncriptado.push_back(cEncriptado);
			}
			std::cout << "n = " << n << endl;
			TxtN->Text = Convert::ToString(n);
			cout << "phi = " << phi << endl;
			TxtPhi->Text = Convert::ToString(phi);
			cout << "d = " << d << endl;
			TxtD->Text = Convert::ToString(d);
			cout << "e = " << e << endl;
			TxtE->Text = Convert::ToString(e);

			return mensajeEncriptado;
		}

		void imprimirMensajeEncriptado(vector<int> mensajeEncriptado) {
			cout << "Mensaje encriptado: ";
			for (int valorEncriptado : mensajeEncriptado) {
				cout << valorEncriptado << " ";
			}
			cout << endl;
		}

		string desencriptarRSA(vector<int> mensajeEncriptado, int n, int d) {
			vector<int> mensajeDesencriptado;

			for (int i = 0; i < mensajeEncriptado.size(); i++) {
				int valorEncriptado = mensajeEncriptado[i];
				int valorDesencriptado = 1;

				for (int j = 0; j < d; j++) {
					valorDesencriptado = (valorDesencriptado * valorEncriptado) % n;
				}

				mensajeDesencriptado.push_back(valorDesencriptado);
			}

			string mensajeDesencriptadoStr;
			for (int i = 0; i < mensajeDesencriptado.size(); i++) {
				mensajeDesencriptadoStr += char(mensajeDesencriptado[i]);
			}

			return mensajeDesencriptadoStr;
		}


		void imprimirMensajeDesencriptado(string mensajeDesencriptado) {
			cout << "Mensaje desencriptado: ";
			for (char letra : mensajeDesencriptado) {
				cout << letra;
			}
			cout << endl;
		}

		vector<int> strToVector(string mensajeEncriptadoStr) {
			vector<int> mensajeEncriptado;
			string numStr;
			for (int i = 0; i < mensajeEncriptadoStr.size(); i++) {
				if (isdigit(mensajeEncriptadoStr[i])) {
					numStr += mensajeEncriptadoStr[i];
				}
				else if (!numStr.empty()) {
					mensajeEncriptado.push_back(stoi(numStr));
					numStr = "";
				}
			}
			if (!numStr.empty()) {
				mensajeEncriptado.push_back(stoi(numStr));
			}
			return mensajeEncriptado;
		}



	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ TxtP;
	private: System::Windows::Forms::TextBox^ TxtQ;
	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ TxtMsg;
private: System::Windows::Forms::TextBox^ TxtEncriptado;
private: System::Windows::Forms::TextBox^ TxtN;
private: System::Windows::Forms::TextBox^ TxtD;
private: System::Windows::Forms::TextBox^ TxtPhi;
private: System::Windows::Forms::TextBox^ TxtE;







	private: System::Windows::Forms::Button^ button1;
private: System::Windows::Forms::TextBox^ TxtEncriptado2;
private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::Button^ BtnDesencriptar;
private: System::Windows::Forms::Label^ label10;
private: System::Windows::Forms::TextBox^ TxtDesencriptado;
private: System::Windows::Forms::Button^ button2;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->TxtP = (gcnew System::Windows::Forms::TextBox());
			this->TxtQ = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->TxtMsg = (gcnew System::Windows::Forms::TextBox());
			this->TxtEncriptado = (gcnew System::Windows::Forms::TextBox());
			this->TxtN = (gcnew System::Windows::Forms::TextBox());
			this->TxtD = (gcnew System::Windows::Forms::TextBox());
			this->TxtPhi = (gcnew System::Windows::Forms::TextBox());
			this->TxtE = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->TxtEncriptado2 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->BtnDesencriptar = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->TxtDesencriptado = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// TxtP
			// 
			this->TxtP->Location = System::Drawing::Point(217, 71);
			this->TxtP->Name = L"TxtP";
			this->TxtP->Size = System::Drawing::Size(226, 20);
			this->TxtP->TabIndex = 0;
			// 
			// TxtQ
			// 
			this->TxtQ->Location = System::Drawing::Point(217, 108);
			this->TxtQ->Name = L"TxtQ";
			this->TxtQ->Size = System::Drawing::Size(226, 20);
			this->TxtQ->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(61, 71);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Ingresar P";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(61, 108);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Ingresar Q";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(61, 147);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(132, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Ingresar mensaje";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(61, 293);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(150, 20);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Mensaje Encriptado";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(61, 333);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(83, 20);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Valor de N";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(61, 365);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(84, 20);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Valor de D";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(61, 402);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(94, 20);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Valor de Phi";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(61, 437);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(83, 20);
			this->label8->TabIndex = 9;
			this->label8->Text = L"Valor de E";
			// 
			// TxtMsg
			// 
			this->TxtMsg->Location = System::Drawing::Point(217, 147);
			this->TxtMsg->Name = L"TxtMsg";
			this->TxtMsg->Size = System::Drawing::Size(226, 20);
			this->TxtMsg->TabIndex = 10;
			// 
			// TxtEncriptado
			// 
			this->TxtEncriptado->Location = System::Drawing::Point(217, 293);
			this->TxtEncriptado->Name = L"TxtEncriptado";
			this->TxtEncriptado->Size = System::Drawing::Size(226, 20);
			this->TxtEncriptado->TabIndex = 11;
			// 
			// TxtN
			// 
			this->TxtN->Location = System::Drawing::Point(217, 333);
			this->TxtN->Name = L"TxtN";
			this->TxtN->Size = System::Drawing::Size(226, 20);
			this->TxtN->TabIndex = 12;
			// 
			// TxtD
			// 
			this->TxtD->Location = System::Drawing::Point(217, 365);
			this->TxtD->Name = L"TxtD";
			this->TxtD->Size = System::Drawing::Size(226, 20);
			this->TxtD->TabIndex = 13;
			// 
			// TxtPhi
			// 
			this->TxtPhi->Location = System::Drawing::Point(217, 402);
			this->TxtPhi->Name = L"TxtPhi";
			this->TxtPhi->Size = System::Drawing::Size(226, 20);
			this->TxtPhi->TabIndex = 14;
			// 
			// TxtE
			// 
			this->TxtE->Location = System::Drawing::Point(217, 437);
			this->TxtE->Name = L"TxtE";
			this->TxtE->Size = System::Drawing::Size(226, 20);
			this->TxtE->TabIndex = 15;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(113, 207);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(137, 59);
			this->button1->TabIndex = 16;
			this->button1->Text = L"Encriptar";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// TxtEncriptado2
			// 
			this->TxtEncriptado2->Location = System::Drawing::Point(740, 71);
			this->TxtEncriptado2->Name = L"TxtEncriptado2";
			this->TxtEncriptado2->Size = System::Drawing::Size(287, 20);
			this->TxtEncriptado2->TabIndex = 17;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(521, 71);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(213, 20);
			this->label9->TabIndex = 18;
			this->label9->Text = L"Ingresar Mensaje Encriptado";
			// 
			// BtnDesencriptar
			// 
			this->BtnDesencriptar->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BtnDesencriptar->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->BtnDesencriptar->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->BtnDesencriptar->Location = System::Drawing::Point(757, 124);
			this->BtnDesencriptar->Name = L"BtnDesencriptar";
			this->BtnDesencriptar->Size = System::Drawing::Size(143, 73);
			this->BtnDesencriptar->TabIndex = 19;
			this->BtnDesencriptar->Text = L"Desencriptar";
			this->BtnDesencriptar->UseVisualStyleBackColor = false;
			this->BtnDesencriptar->Click += gcnew System::EventHandler(this, &MyForm::BtnDesencriptar_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(521, 246);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(156, 20);
			this->label10->TabIndex = 20;
			this->label10->Text = L"Texto Desencriptado";
			// 
			// TxtDesencriptado
			// 
			this->TxtDesencriptado->Location = System::Drawing::Point(740, 246);
			this->TxtDesencriptado->Name = L"TxtDesencriptado";
			this->TxtDesencriptado->Size = System::Drawing::Size(287, 20);
			this->TxtDesencriptado->TabIndex = 21;
			this->TxtDesencriptado->TextChanged += gcnew System::EventHandler(this, &MyForm::TxtDesencriptado_TextChanged);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button2->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(306, 207);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(137, 59);
			this->button2->TabIndex = 22;
			this->button2->Text = L"LeerTxt";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Highlight;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1129, 646);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->TxtDesencriptado);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->BtnDesencriptar);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->TxtEncriptado2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->TxtE);
			this->Controls->Add(this->TxtPhi);
			this->Controls->Add(this->TxtD);
			this->Controls->Add(this->TxtN);
			this->Controls->Add(this->TxtEncriptado);
			this->Controls->Add(this->TxtMsg);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->TxtQ);
			this->Controls->Add(this->TxtP);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		music->Play();
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		string mensaje = msclr::interop::marshal_as<string>(TxtMsg->Text);
		int p = stoi(msclr::interop::marshal_as<string>(TxtP->Text));
		int q = stoi(msclr::interop::marshal_as<string>(TxtQ->Text));

		vector<int> mensajeEncriptado = encriptarRSA(mensaje, p, q);
		imprimirMensajeEncriptado(mensajeEncriptado);

		string mensajeEncriptadoStr;
		for (int valorEncriptado : mensajeEncriptado) {
			mensajeEncriptadoStr += to_string(valorEncriptado) + " ";
		}
		TxtEncriptado->Text = gcnew String(mensajeEncriptadoStr.c_str());
}
private: System::Void TxtDesencriptado_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void BtnDesencriptar_Click(System::Object^ sender, System::EventArgs^ e) {
	// Leer el valor encriptado desde el cuadro de texto
	String^ valorEncriptado = TxtEncriptado->Text;
	std::string valorEncriptadoStr = msclr::interop::marshal_as<std::string>(valorEncriptado);

	// Agregar un espacio al final para asegurar que el último bloque se decodifique correctamente
	valorEncriptadoStr += " ";

	// Convertir la cadena encriptada a un vector de enteros
	std::vector<int> mensajeEncriptado = strToVector(valorEncriptadoStr);

	// Convertir los valores de texto de N y D a enteros
	int n = System::Convert::ToInt32(TxtN->Text);
	int d = System::Convert::ToInt32(TxtD->Text);

	// Desencriptar el mensaje utilizando RSA
	std::string mensajeDesencriptado = desencriptarRSA(mensajeEncriptado, n, d);

	// Mostrar el mensaje desencriptado en el cuadro de texto correspondiente
	String^ mensajeDesencriptadoManaged = gcnew String(mensajeDesencriptado.c_str());
	TxtDesencriptado->Text = mensajeDesencriptadoManaged;
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	// Abrir archivo
	std::ifstream archivo("archivo.txt");

	// Leer archivo línea por línea y concatenar las líneas en una cadena
	std::string linea;
	std::string contenido;
	while (std::getline(archivo, linea)) {
		contenido += linea + "\r\n";
	}

	// Cerrar archivo
	archivo.close();

	// Convertir la cadena a una cadena de sistema y mostrarla en la caja de texto
	String^ netString = gcnew String(contenido.c_str());
	TxtMsg->Text = netString;
}
};
}