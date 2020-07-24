#pragma once
#include<iostream>
#include<cstdlib>
#include<string.h>
#include<cmath>
#include<ctime>
#include<vector>
#include "Neuron.h"
#include"Layer.h"
#include"Pattern.h"
#include<sstream>
#include<fstream>
#include<atlstr.h>
#include<Windows.h>

namespace HasanFlow {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm için özet
	/// </summary>
	
	std::vector<Layer*> layers;
	std::vector<Pattern*> models;
	std::vector<Pattern*> test_models;
	Pattern* pat;
	Layer* layer;
	float** TEMP_W_MATRÝX_1;
	float** TEMP_W_MATRÝX_2;
	float** TEMP_INPUT_MATRIX;
	long float** TEMP_OUTPUT_MATRIX;
	float net, fnet, signalhl, norm, x, y, sum = 0, ort, SS, temphl, signalol, tempol, errorsum = 0, hata = 0;
	int LMethodIndex,startx,starty,inputindex,HiddenLayer,InputLayerNumber,LayerID,LayerNeuron,AFIndex,cycle = 0,OutputLayerNumber,RateCount = 0,MAX_EPOCH;
	float LC,alfa,error;
	bool isclick,normalize = false;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			setCombo();
			//
			//TODO: Oluþturucu kodunu buraya ekle
			//
		}

	protected:
		/// <summary>
		///Kullanýlan tüm kaynaklarý temizleyin.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;




	private: System::Windows::Forms::TextBox^ textBox1;



	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::ComboBox^ comboBox1;

	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Button^ button2;


	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;

	private: System::Windows::Forms::Button^ button3;


	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ processToolStripMenuItem;


	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Button^ button4;



	private: System::Windows::Forms::ToolStripMenuItem^ tRAINToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ tESTToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog2;

	protected:

	private:
		/// <summary>
		///Gerekli tasarýmcý deðiþkeni.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasarýmcý desteði için gerekli metot - bu metodun 
		///içeriðini kod düzenleyici ile deðiþtirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tRAINToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tESTToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 83);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 25);
			this->label3->TabIndex = 2;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(8, 66);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(85, 25);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Layer ID";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(8, 123);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(174, 25);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Layer Neuron Size";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(8, 179);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(177, 25);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Activation Function";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(216, 120);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(120, 30);
			this->textBox1->TabIndex = 10;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->numericUpDown1);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->groupBox1->Location = System::Drawing::Point(26, 31);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(351, 330);
			this->groupBox1->TabIndex = 16;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Set Layer Properties";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(216, 179);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(126, 33);
			this->comboBox1->TabIndex = 19;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->button1->Location = System::Drawing::Point(104, 248);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(119, 39);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Set";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(216, 66);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 30);
			this->numericUpDown1->TabIndex = 17;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 68);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(178, 25);
			this->label1->TabIndex = 21;
			this->label1->Text = L"Input Layer Neuron";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(216, 68);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(120, 30);
			this->textBox2->TabIndex = 22;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->groupBox2->Location = System::Drawing::Point(26, 401);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(351, 204);
			this->groupBox2->TabIndex = 17;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Set Start Properties";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(104, 139);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(119, 40);
			this->button2->TabIndex = 25;
			this->button2->Text = L"Set";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->textBox3);
			this->groupBox3->Controls->Add(this->label7);
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Controls->Add(this->textBox6);
			this->groupBox3->Controls->Add(this->label11);
			this->groupBox3->Controls->Add(this->textBox5);
			this->groupBox3->Controls->Add(this->textBox4);
			this->groupBox3->Controls->Add(this->comboBox2);
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Controls->Add(this->label9);
			this->groupBox3->Controls->Add(this->label8);
			this->groupBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->groupBox3->Location = System::Drawing::Point(460, 31);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(309, 304);
			this->groupBox3->TabIndex = 18;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Learn Panel";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(154, 208);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(125, 30);
			this->textBox3->TabIndex = 13;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(15, 211);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(111, 25);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Max Epoch";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(176, 261);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 37);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Set";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(154, 158);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(122, 30);
			this->textBox6->TabIndex = 8;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(15, 158);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(119, 25);
			this->label11->TabIndex = 7;
			this->label11->Text = L"Learn Const";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(154, 114);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(121, 30);
			this->textBox5->TabIndex = 6;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(154, 75);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(121, 30);
			this->textBox4->TabIndex = 5;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(154, 28);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 33);
			this->comboBox2->TabIndex = 4;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(15, 114);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(97, 25);
			this->label10->TabIndex = 2;
			this->label10->Text = L"Max Error";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label9->Location = System::Drawing::Point(15, 75);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(120, 21);
			this->label9->TabIndex = 1;
			this->label9->Text = L"Moment Coeff";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->label8->Location = System::Drawing::Point(15, 39);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(126, 19);
			this->label8->TabIndex = 0;
			this->label8->Text = L"Learning Method";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(877, 431);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(54, 17);
			this->label12->TabIndex = 19;
			this->label12->Text = L"label12";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(877, 477);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(54, 17);
			this->label13->TabIndex = 20;
			this->label13->Text = L"label13";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(877, 520);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(54, 17);
			this->label14->TabIndex = 21;
			this->label14->Text = L"label14";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->processToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1493, 28);
			this->menuStrip1->TabIndex = 24;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->tRAINToolStripMenuItem,
					this->tESTToolStripMenuItem
			});
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(72, 24);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// tRAINToolStripMenuItem
			// 
			this->tRAINToolStripMenuItem->Name = L"tRAINToolStripMenuItem";
			this->tRAINToolStripMenuItem->Size = System::Drawing::Size(134, 26);
			this->tRAINToolStripMenuItem->Text = L"TRAIN";
			this->tRAINToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::tRAINToolStripMenuItem_Click);
			// 
			// tESTToolStripMenuItem
			// 
			this->tESTToolStripMenuItem->Name = L"tESTToolStripMenuItem";
			this->tESTToolStripMenuItem->Size = System::Drawing::Size(134, 26);
			this->tESTToolStripMenuItem->Text = L"TEST";
			this->tESTToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::tESTToolStripMenuItem_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button4);
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->groupBox4->Location = System::Drawing::Point(463, 341);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(276, 110);
			this->groupBox4->TabIndex = 26;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Input Dataset Panel";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(62, 47);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(172, 38);
			this->button4->TabIndex = 2;
			this->button4->Text = L"Read Inputs";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->button5);
			this->groupBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(162)));
			this->groupBox5->Location = System::Drawing::Point(463, 501);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(276, 104);
			this->groupBox5->TabIndex = 27;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Test Dataset Panel";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(62, 41);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(172, 38);
			this->button5->TabIndex = 0;
			this->button5->Text = L"Read Test Datas";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(792, 31);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Color = System::Drawing::Color::Blue;
			series1->Legend = L"Legend1";
			series1->Name = L"ERGRAPH";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(666, 368);
			this->chart1->TabIndex = 28;
			this->chart1->Text = L"chart1";
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1493, 645);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"HasanFlow";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		int a;
		
		void setCombo()
		{
			comboBox1->Items->Add("Unipolar Sigmoid");
			comboBox1->Items->Add("Bipolar Sigmoid");
			comboBox1->Items->Add("ReLU");
			comboBox1->Items->Add("SoftMAX");
			comboBox1->Items->Add("Binary Step");
			comboBox2->Items->Add("SDG");
			comboBox2->Items->Add("Momentum");
			
		}
		float s_sapma(float* a, int argc)
		{
			int ort, sum = 0, ortsum = 0;
			for (int i = 0; i < argc; i++)
			{
				sum += a[i];
			}
			ort = sum / argc;
			for (int i = 0; i < argc; i++)
			{
				ortsum += (a[i] - ort) * (a[i] - ort);
			}
			ortsum = ortsum / (argc);
			return sqrt(ortsum);

		}
		float RateCalc(float r1, float r2)
		{
			return (r2 * 100) / r1;
		}
#pragma endregion
	
		
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		LMethodIndex = comboBox2->SelectedIndex;
		
		FLOAT::TryParse(textBox5->Text, error);
		FLOAT::TryParse(textBox4->Text, alfa);
		FLOAT::TryParse(textBox6->Text, LC);
		MAX_EPOCH = (int)System::Convert::ToInt32(textBox3->Text);

		
	}	
		System::Drawing::Pen^ pen;
		System::Drawing::Graphics^ g;
private: System::Void pictureBox1_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	
	if(isclick)
	{
		g->DrawLine(pen, startx, starty, e->X, e->Y);
		startx = e->X;
		starty = e->Y;
	}
		
}
private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	isclick = false;
}
private: System::Void pictureBox1_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	
	
}

private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Input Dizisini Veriniz");
	inputindex = 0;
	std::ifstream dosya;
	int col = 0, pos, startpos = 0;
	std::string line;
	String^ vs;

	char discrim = ' ';
	CString s;
	LPCTSTR input;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		s = openFileDialog1->FileName;
		input = (LPCTSTR)s;
		dosya.open(input, std::ios::in);
		while (!dosya.eof())//yeni yontem
		{
			pat = new Pattern(InputLayerNumber);
			pat->setBias(1.0f);
			models.push_back(pat);

			getline(dosya, line);//tum satýrý okuyor
			pos = line.find(discrim);
			while (true)
			{
				if (col == InputLayerNumber)
				{
					pos = line.length();
					models[inputindex]->setClassID((int)atoi(line.substr(startpos, pos - startpos).c_str()));
					//MessageBox::Show(models[inputindex]->getClassID().ToString());
					startpos = 0;
					col = 0;
					inputindex++;
					break;
				}
				models[inputindex]->setElem(col, (float)atof(line.substr(startpos, pos - startpos).c_str()));
				//MessageBox::Show(models[inputindex]->getElem(col).ToString());
				startpos = pos + 1;
				pos = line.find(discrim, startpos);
				col++;

			}
		}

		dosya.close();
		//MessageBox::Show(models[inputindex]->getClassID().ToString());
	}

}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	
	InputLayerNumber = (int)System::Convert::ToInt32(textBox2->Text->ToString());
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	
	LayerID = (int)System::Convert::ToInt32(numericUpDown1->Text->ToString());
	LayerNeuron = (int)System::Convert::ToInt32(textBox1->Text->ToString());
	AFIndex = comboBox1->SelectedIndex;
	
		if (LayerID == 1)
		{
			layer = new Layer(LayerNeuron,AFIndex,InputLayerNumber);
			layers.push_back(layer);

		}
		else if(LayerID > 1)
		{
			layer = new Layer(LayerNeuron, AFIndex, layers[LayerID - 2]->getSize()); 
			layers.push_back(layer);
		}
	

}
private: System::Void nORMALIZEToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void tRAINToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	OutputLayerNumber = layers[layers.size() - 1]->getSize();
	float** desiredArr = new float* [OutputLayerNumber];
	for (int i = 0; i < OutputLayerNumber; i++)
	{
		desiredArr[i] = new float[1];
	}
	float sumWeights = 0;
	float* SOutput = new float[OutputLayerNumber];

	sum = 0;
	float* temp = new float[models.size()];
	normalize = true;
	for (int i = 0; i < InputLayerNumber; i++)
	{
		for (int j = 0; j < models.size(); j++)
		{
			temp[j] = models[j]->getElem(i);
			sum += models[j]->getElem(i);
		}
		ort = sum / models.size();
		SS = s_sapma(temp, models.size());
		if (SS == 0)
			SS = 0.1f;
		for (int k = 0; k < models.size(); k++)
		{
			models[k]->setNormElem(i, (models[k]->getElem(i) - ort) / SS);
		}
		sum = 0;//traine basýnca calýsacak
	}	
	if (LMethodIndex == 0)
	{
		while (true)
		{
			for (int val = 0; val < models.size(); val++)
			{
				//beklenen vektor setleme
				for (int k = 0; k < OutputLayerNumber; k++)//scbak
				{
					if (models[val]->getClassID() == k)
					{
						desiredArr[k][0] = 1.0f;
					}
					else if (models[val]->getClassID() != k)
					{
						desiredArr[k][0] = -1.0f;
					}
				}
				//dinamik dizi olusmasý
				TEMP_W_MATRÝX_1 = new float* [layers[0]->getSize()];
				for (int i = 0; i < layers[0]->getSize(); i++)
				{
					TEMP_W_MATRÝX_1[i] = new float[InputLayerNumber + 1];
				}
				//aðýrlýklarý matrise alma L0xIL boyutunda
				for (int row = 0; row < layers[0]->getSize(); row++)
				{
					for (int col = 0; col < InputLayerNumber + 1; col++)
					{
						TEMP_W_MATRÝX_1[row][col] = layers[0]->getNeuron(row)->getWeightElem(col);
						//System::Diagnostics::Debug::Write(layers[0]->getNeuron(row)->getWeightElem(col) + " ");
					}
				}
				//girdi katmanýndaki giriþlerin alýnmasý matris oluþturma
				TEMP_INPUT_MATRIX = new float* [InputLayerNumber + 1];
				for (int row = 0; row < InputLayerNumber + 1; row++)
				{
					TEMP_INPUT_MATRIX[row] = new float[1];
				}

				//matrise atama
				for (int row = 0; row < InputLayerNumber; row++)
				{
					TEMP_INPUT_MATRIX[row][0] = models[val]->getNormElem(row);
					//System::Diagnostics::Debug::Write(models[val]->getNormElem(row) + " ");
				}TEMP_INPUT_MATRIX[InputLayerNumber][0] = models[val]->getBias();

				//dinamik cýkýs matrisi olusturulmasý
				TEMP_OUTPUT_MATRIX = new long float* [layers[0]->getSize()];
				for (int i = 0; i < layers[0]->getSize(); i++)
				{
					TEMP_OUTPUT_MATRIX[i] = new long float[1];
				}
				for (int i = 0; i < layers[0]->getSize(); i++)
				{
					TEMP_OUTPUT_MATRIX[i][0] = 0.0f;
				}

				//matris carpýmý ve L0 cýkýslarýn alýnmasý
				for (int i = 0; i < layers[0]->getSize(); i++)
				{
					for (int j = 0; j < 1; j++)
					{
						for (int k = 0; k < InputLayerNumber + 1; k++)
						{
							TEMP_OUTPUT_MATRIX[i][j] += TEMP_W_MATRÝX_1[i][k] * TEMP_INPUT_MATRIX[k][j];
						}
						//System::Diagnostics::Debug::Write(TEMP_OUTPUT_MATRIX[i][0] + " ");//sorun burda
					}
				}
				float res;
				//o katmandaki her noronun cýkýsýnýn AF dan geçirilmesi ve setlenmesi
				for (int i = 0; i < layers[0]->getSize(); i++)
				{
					res = layers[0]->getNeuron(i)->ActivationFunc(TEMP_OUTPUT_MATRIX[i][0], layers[0]->getNeuron(i)->getActivationFunctionIndex(), false);
					layers[0]->getNeuron(i)->setOutput(res);
					//System::Diagnostics::Debug::Write(layers[0]->getNeuron(i)->GetOutput()+ " ");//0 cýkýyo hep
				}
				delete[] TEMP_INPUT_MATRIX;
				delete[] TEMP_OUTPUT_MATRIX;
				delete[] TEMP_W_MATRÝX_1;

				for (int lay = 1; lay < layers.size(); lay++)//katmanlar bitene kadar
				{
					//dinamik dizi olusturma
					TEMP_W_MATRÝX_2 = new float* [layers[lay]->getSize()];
					for (int i = 0; i < layers[lay]->getSize(); i++)
					{
						TEMP_W_MATRÝX_2[i] = new float[layers[lay - 1]->getSize() + 1];
					}
					//aðýrlýk matrisi atama
					for (int row = 0; row < layers[lay]->getSize(); row++)
					{
						for (int col = 0; col < layers[lay - 1]->getSize() + 1; col++)
						{
							TEMP_W_MATRÝX_2[row][col] = layers[lay]->getNeuron(row)->getWeightElem(col);
						}
					}
					//girdi dizisinin oluþturulmasý
					TEMP_INPUT_MATRIX = new float* [layers[lay - 1]->getSize() + 1];
					for (int i = 0; i < layers[lay - 1]->getSize() + 1; i++)
					{
						TEMP_INPUT_MATRIX[i] = new float[1];
					}
					//girdi dizisinin setlenmesi
					for (int row = 0; row < layers[lay - 1]->getSize(); row++)
					{
						TEMP_INPUT_MATRIX[row][0] = layers[lay - 1]->getNeuron(row)->GetOutput();
					}TEMP_INPUT_MATRIX[layers[lay - 1]->getSize()][0] = 1.0f;

					//dinamik cýkýs matrisi olusturulmasý
					TEMP_OUTPUT_MATRIX = new long float* [layers[lay]->getSize()];
					for (int i = 0; i < layers[lay]->getSize(); i++)
					{
						TEMP_OUTPUT_MATRIX[i] = new long float[1];
					}
					//dizi elemanlarý 0 a eþitlemek lazým += dediðimiz için
					for (int i = 0; i < layers[lay]->getSize(); i++)
					{
						TEMP_OUTPUT_MATRIX[i][0] = 0.0f;
					}
					//matris carpýmý ve Llay cýkýslarýn alýnmasý
					for (int i = 0; i < layers[lay]->getSize(); i++)
					{
						for (int j = 0; j < 1; j++)
						{
							for (int k = 0; k < layers[lay - 1]->getSize() + 1; k++)
							{
								TEMP_OUTPUT_MATRIX[i][j] += TEMP_W_MATRÝX_2[i][k] * TEMP_INPUT_MATRIX[k][j];
							}
						}
					}
					//çýkýþ katmanlarýnýn AF dan geçirilerek setlenmesi
					for (int i = 0; i < OutputLayerNumber; i++)
					{
						temp[i] = TEMP_OUTPUT_MATRIX[i][0];
					}
					for (int i = 0; i < layers[lay]->getSize(); i++)
					{
						//son katmanda softmax olur
						if (lay == layers.size() - 1)
						{
							//eðer softmax demisse
							if (layers[lay]->getNeuron(i)->getActivationFunctionIndex() == 3)
								layers[lay]->getNeuron(i)->setOutput(layers[lay]->getNeuron(i)->SoftMAX_Function(temp, OutputLayerNumber, TEMP_OUTPUT_MATRIX[i][0]));
							else
								layers[lay]->getNeuron(i)->setOutput(layers[lay]->getNeuron(i)->ActivationFunc(TEMP_OUTPUT_MATRIX[i][0], layers[lay]->getNeuron(i)->getActivationFunctionIndex(), false));
						}
						else
							layers[lay]->getNeuron(i)->setOutput(layers[lay]->getNeuron(i)->ActivationFunc(TEMP_OUTPUT_MATRIX[i][0], layers[lay]->getNeuron(i)->getActivationFunctionIndex(), false));
					}
					delete[] TEMP_INPUT_MATRIX;
					delete[] TEMP_OUTPUT_MATRIX;
					delete[] TEMP_W_MATRÝX_2;
				}

				//2.Yontem en son ara katman arkasý çýkýþ elemaný katýlarak diðerleri normal
				//TESTÝ GEÇTÝ
				//cýkýs katmaný
				for (int lay = layers.size() - 1; lay > 0; lay--)
				{
					if (lay == layers.size() - 2)
						continue;
					//M(dk-ok)olur sondaysa
					for (int k = 0; k < layers[lay]->getSize(); k++)
					{
						if (lay == layers.size() - 1)
						{
							if (layers[lay]->getNeuron(k)->getActivationFunctionIndex() == 3)
							{
								signalol = LC * (desiredArr[k][0] - layers[lay]->getNeuron(k)->GetOutput()) * layers[lay]->getNeuron(k)->GetOutput() * (1 - layers[lay]->getNeuron(k)->GetOutput());
							}
							//M*(dk-ok)*f'(net)
							//root mean squarized
							else
							{
								signalol = LC * (desiredArr[k][0] - layers[lay]->getNeuron(k)->GetOutput()) * layers[lay]->getNeuron(k)->ActivationFunc
								(layers[lay]->getNeuron(k)->GetOutput(), layers[lay]->getNeuron(k)->getActivationFunctionIndex(), true);
							}
							hata += (desiredArr[k][0] - layers[lay]->getNeuron(k)->GetOutput()) * (desiredArr[k][0] - layers[lay]->getNeuron(k)->GetOutput());
						}
						else if (lay != layers.size() - 1)
						{
							signalol = LC * layers[lay]->getNeuron(k)->ActivationFunc(layers[lay]->getNeuron(k)->GetOutput(), layers[lay]->getNeuron(k)->getActivationFunctionIndex(), true);
						}
						for (int j = 0; j < layers[lay - 1]->getSize(); j++)
						{
							//aðýrlýk matrisine gerek yok
							layers[lay]->getNeuron(k)->setWeightElem(j, layers[lay]->getNeuron(k)->getWeightElem(j) + (signalol * layers[lay - 1]->getNeuron(j)->GetOutput()));
							//aðýrlýðý yaz
						}
						layers[lay]->getNeuron(k)->setWeightElem(layers[lay - 1]->getSize(), signalol + layers[lay]->getNeuron(k)->getWeightElem(layers[lay - 1]->getSize()));

					}
					errorsum += hata;
					hata = 0;

				}//lay sonu
				//giris katmaný weight güncelleme
				for (int k = 0; k < layers[0]->getSize(); k++)
				{
					signalol = LC * layers[0]->getNeuron(k)->ActivationFunc(layers[0]->getNeuron(k)->GetOutput(), layers[0]->getNeuron(k)->getActivationFunctionIndex(), true);
					for (int j = 0; j < InputLayerNumber + 1; j++)
					{
						layers[0]->getNeuron(k)->setWeightElem(j, layers[0]->getNeuron(k)->getWeightElem(j) + (signalol * models[val]->getNormElem(j)));
					}
				}
				//en son ara katmana ulaþma
				int index = layers.size() - 1;
				int index_2 = index - 1;
				//önceki giriþleri elde etmek için (2.for için)
				TEMP_INPUT_MATRIX = new float* [layers[index_2 - 1]->getSize() + 1];
				for (int row = 0; row < layers[index_2 - 1]->getSize() + 1; row++)
				{
					TEMP_INPUT_MATRIX[row] = new float[1];
				}
				for (int i = 0; i < layers[index_2 - 1]->getSize(); i++)
				{
					TEMP_INPUT_MATRIX[i][0] = layers[index_2 - 1]->getNeuron(i)->GetOutput();
				}
				TEMP_INPUT_MATRIX[layers[index_2 - 1]->getSize()][0] = 1.0f;


				for (int j = 0; j < layers[index_2]->getSize(); j++)
				{
					for (int i = 0; i < layers[index_2 - 1]->getSize() + 1; i++)
					{
						for (int k = 0; k < OutputLayerNumber; k++)
						{
							if (layers[index]->getNeuron(k)->getActivationFunctionIndex() == 3)
							{
								sumWeights += (desiredArr[k][0] - layers[index]->getNeuron(k)->GetOutput()) * layers[index]->getNeuron(k)->GetOutput() * (1 - layers[index]->getNeuron(k)->GetOutput()) * layers[index]->getNeuron(k)->getWeightElem(j);
							}
							else
							{
								sumWeights += (desiredArr[k][0] - layers[index]->getNeuron(k)->GetOutput()) * layers[index]->getNeuron(k)->ActivationFunc(layers[index]->getNeuron(k)->GetOutput(),
									layers[index]->getNeuron(k)->getActivationFunctionIndex(), true) * layers[index]->getNeuron(k)->getWeightElem(j);
							}

						}
						//Veights[j][i] += LC * ptron.ActivationFunc(hloa[j][0], HLAFIndex, true) * VecX[i][0] * sumWeights;
						layers[index_2]->getNeuron(j)->setWeightElem(i, layers[index_2]->getNeuron(j)->getWeightElem(i) + LC * layers[index_2]->getNeuron(j)->ActivationFunc(layers[index_2]->getNeuron(j)->GetOutput(),
							layers[index_2]->getNeuron(j)->getActivationFunctionIndex(), true) * TEMP_INPUT_MATRIX[i][0] * sumWeights);
						sumWeights = 0;
					}
				}//2.yontem sonu

			}
			errorsum = sqrt(errorsum) / (OutputLayerNumber * models.size());
			if (errorsum < error || cycle == MAX_EPOCH)
				break;
			label12->Text = "Hata: " + errorsum.ToString();
			label13->Text = "Cycle: " + cycle.ToString();
			label12->Refresh();
			label13->Refresh();
			this->chart1->Series["ERGRAPH"]->Points->AddXY(cycle, errorsum);
			errorsum = 0;
			cycle++;
			/*if (cycle % 200 == 0)
				WriteWeights();*/

		}
	}
	else if (LMethodIndex == 1)
	{
	while (true)
	{
		for (int val = 0; val < models.size(); val++)
		{
			//beklenen vektor setleme
			for (int k = 0; k < OutputLayerNumber; k++)//scbak
			{
				if (models[val]->getClassID() == k)
				{
					desiredArr[k][0] = 1.0f;
				}
				else if (models[val]->getClassID() != k)
				{
					desiredArr[k][0] = -1.0f;
				}
			}
			//dinamik dizi olusmasý
			TEMP_W_MATRÝX_1 = new float* [layers[0]->getSize()];
			for (int i = 0; i < layers[0]->getSize(); i++)
			{
				TEMP_W_MATRÝX_1[i] = new float[InputLayerNumber + 1];
			}
			//aðýrlýklarý matrise alma L0xIL boyutunda
			for (int row = 0; row < layers[0]->getSize(); row++)
			{
				for (int col = 0; col < InputLayerNumber + 1; col++)
				{
					TEMP_W_MATRÝX_1[row][col] = layers[0]->getNeuron(row)->getWeightElem(col);
					//System::Diagnostics::Debug::Write(layers[0]->getNeuron(row)->getWeightElem(col) + " ");
				}
			}
			//girdi katmanýndaki giriþlerin alýnmasý matris oluþturma
			TEMP_INPUT_MATRIX = new float* [InputLayerNumber + 1];
			for (int row = 0; row < InputLayerNumber + 1; row++)
			{
				TEMP_INPUT_MATRIX[row] = new float[1];
			}

			//matrise atama
			for (int row = 0; row < InputLayerNumber; row++)
			{
				TEMP_INPUT_MATRIX[row][0] = models[val]->getNormElem(row);
				//System::Diagnostics::Debug::Write(models[val]->getNormElem(row) + " ");
			}TEMP_INPUT_MATRIX[InputLayerNumber][0] = models[val]->getBias();

			//dinamik cýkýs matrisi olusturulmasý
			TEMP_OUTPUT_MATRIX = new long float* [layers[0]->getSize()];
			for (int i = 0; i < layers[0]->getSize(); i++)
			{
				TEMP_OUTPUT_MATRIX[i] = new long float[1];
			}
			for (int i = 0; i < layers[0]->getSize(); i++)
			{
				TEMP_OUTPUT_MATRIX[i][0] = 0.0f;
			}

			//matris carpýmý ve L0 cýkýslarýn alýnmasý
			for (int i = 0; i < layers[0]->getSize(); i++)
			{
				for (int j = 0; j < 1; j++)
				{
					for (int k = 0; k < InputLayerNumber + 1; k++)
					{
						TEMP_OUTPUT_MATRIX[i][j] += TEMP_W_MATRÝX_1[i][k] * TEMP_INPUT_MATRIX[k][j];
					}
					//System::Diagnostics::Debug::Write(TEMP_OUTPUT_MATRIX[i][0] + " ");//sorun burda
				}
			}
			float res;
			//o katmandaki her noronun cýkýsýnýn AF dan geçirilmesi ve setlenmesi
			for (int i = 0; i < layers[0]->getSize(); i++)
			{
				res = layers[0]->getNeuron(i)->ActivationFunc(TEMP_OUTPUT_MATRIX[i][0], layers[0]->getNeuron(i)->getActivationFunctionIndex(), false);
				layers[0]->getNeuron(i)->setOutput(res);
				//System::Diagnostics::Debug::Write(layers[0]->getNeuron(i)->GetOutput()+ " ");//0 cýkýyo hep
			}
			delete[] TEMP_INPUT_MATRIX;
			delete[] TEMP_OUTPUT_MATRIX;
			delete[] TEMP_W_MATRÝX_1;

			for (int lay = 1; lay < layers.size(); lay++)//katmanlar bitene kadar
			{
				//dinamik dizi olusturma
				TEMP_W_MATRÝX_2 = new float* [layers[lay]->getSize()];
				for (int i = 0; i < layers[lay]->getSize(); i++)
				{
					TEMP_W_MATRÝX_2[i] = new float[layers[lay - 1]->getSize() + 1];
				}
				//aðýrlýk matrisi atama
				for (int row = 0; row < layers[lay]->getSize(); row++)
				{
					for (int col = 0; col < layers[lay - 1]->getSize() + 1; col++)
					{
						TEMP_W_MATRÝX_2[row][col] = layers[lay]->getNeuron(row)->getWeightElem(col);
					}
				}
				//girdi dizisinin oluþturulmasý
				TEMP_INPUT_MATRIX = new float* [layers[lay - 1]->getSize() + 1];
				for (int i = 0; i < layers[lay - 1]->getSize() + 1; i++)
				{
					TEMP_INPUT_MATRIX[i] = new float[1];
				}
				//girdi dizisinin setlenmesi
				for (int row = 0; row < layers[lay - 1]->getSize(); row++)
				{
					TEMP_INPUT_MATRIX[row][0] = layers[lay - 1]->getNeuron(row)->GetOutput();
				}TEMP_INPUT_MATRIX[layers[lay - 1]->getSize()][0] = 1.0f;

				//dinamik cýkýs matrisi olusturulmasý
				TEMP_OUTPUT_MATRIX = new long float* [layers[lay]->getSize()];
				for (int i = 0; i < layers[lay]->getSize(); i++)
				{
					TEMP_OUTPUT_MATRIX[i] = new long float[1];
				}
				//dizi elemanlarý 0 a eþitlemek lazým += dediðimiz için
				for (int i = 0; i < layers[lay]->getSize(); i++)
				{
					TEMP_OUTPUT_MATRIX[i][0] = 0.0f;
				}
				//matris carpýmý ve Llay cýkýslarýn alýnmasý
				for (int i = 0; i < layers[lay]->getSize(); i++)
				{
					for (int j = 0; j < 1; j++)
					{
						for (int k = 0; k < layers[lay - 1]->getSize() + 1; k++)
						{
							TEMP_OUTPUT_MATRIX[i][j] += TEMP_W_MATRÝX_2[i][k] * TEMP_INPUT_MATRIX[k][j];
						}
					}
				}
				//çýkýþ katmanlarýnýn AF dan geçirilerek setlenmesi
				for (int i = 0; i < OutputLayerNumber; i++)
				{
					temp[i] = TEMP_OUTPUT_MATRIX[i][0];
				}
				for (int i = 0; i < layers[lay]->getSize(); i++)
				{
					//son katmanda softmax olur
					if (lay == layers.size() - 1)
					{
						//eðer softmax demisse
						if (layers[lay]->getNeuron(i)->getActivationFunctionIndex() == 3)
							layers[lay]->getNeuron(i)->setOutput(layers[lay]->getNeuron(i)->SoftMAX_Function(temp, OutputLayerNumber, TEMP_OUTPUT_MATRIX[i][0]));
						else
							layers[lay]->getNeuron(i)->setOutput(layers[lay]->getNeuron(i)->ActivationFunc(TEMP_OUTPUT_MATRIX[i][0], layers[lay]->getNeuron(i)->getActivationFunctionIndex(), false));
					}
					else
						layers[lay]->getNeuron(i)->setOutput(layers[lay]->getNeuron(i)->ActivationFunc(TEMP_OUTPUT_MATRIX[i][0], layers[lay]->getNeuron(i)->getActivationFunctionIndex(), false));
				}
				delete[] TEMP_INPUT_MATRIX;
				delete[] TEMP_OUTPUT_MATRIX;
				delete[] TEMP_W_MATRÝX_2;
			}

			//2.Yontem en son ara katman arkasý çýkýþ elemaný katýlarak diðerleri normal
			//TESTÝ GEÇTÝ
			//cýkýs katmaný
			for (int lay = layers.size() - 1; lay > 0; lay--)
			{
				if (lay == layers.size() - 2)
					continue;
				//M(dk-ok)olur sondaysa
				for (int k = 0; k < layers[lay]->getSize(); k++)
				{
					//tempW[k][j] = alfa * signalol * hloa[j][0];
					if (lay == layers.size() - 1)
					{
						if (layers[lay]->getNeuron(k)->getActivationFunctionIndex() == 3)
						{
							signalol = LC * (desiredArr[k][0] - layers[lay]->getNeuron(k)->GetOutput()) * layers[lay]->getNeuron(k)->GetOutput() * (1 - layers[lay]->getNeuron(k)->GetOutput());
						}
						//M*(dk-ok)*f'(net)
						//root mean squarized
						else
						{
							signalol = LC * (desiredArr[k][0] - layers[lay]->getNeuron(k)->GetOutput()) * layers[lay]->getNeuron(k)->ActivationFunc
							(layers[lay]->getNeuron(k)->GetOutput(), layers[lay]->getNeuron(k)->getActivationFunctionIndex(), true);
						}
						hata += (desiredArr[k][0] - layers[lay]->getNeuron(k)->GetOutput()) * (desiredArr[k][0] - layers[lay]->getNeuron(k)->GetOutput());
					}
					else if (lay != layers.size() - 1)
					{
						signalol = LC * layers[lay]->getNeuron(k)->ActivationFunc(layers[lay]->getNeuron(k)->GetOutput(), layers[lay]->getNeuron(k)->getActivationFunctionIndex(), true);
					}
					for (int j = 0; j < layers[lay - 1]->getSize(); j++)
					{
						//aðýrlýk matrisine gerek yok
						layers[lay]->getNeuron(k)->setWeightElem(j, layers[lay]->getNeuron(k)->getWeightElem(j) + (signalol * layers[lay - 1]->getNeuron(j)->GetOutput()*alfa)+(alfa* layers[lay]->getNeuron(k)->getTempWeightElem(j)));
						//aðýrlýðý yaz
						//tempW[k][j] = alfa * signalol * hloa[j][0];
						layers[lay]->getNeuron(k)->setTempWeightElem(j, (alfa* signalol* layers[lay - 1]->getNeuron(j)->GetOutput())+ layers[lay]->getNeuron(k)->getTempWeightElem(j));
					}
					layers[lay]->getNeuron(k)->setWeightElem(layers[lay - 1]->getSize(), signalol + layers[lay]->getNeuron(k)->getWeightElem(layers[lay - 1]->getSize()));
					layers[lay]->getNeuron(k)->setTempWeightElem(layers[lay - 1]->getSize(), (alfa* signalol)+ layers[lay]->getNeuron(k)->getTempWeightElem(layers[lay - 1]->getSize()));
				}
				errorsum += hata;
				hata = 0;

			}//lay sonu
			//giris katmaný weight güncelleme
			for (int k = 0; k < layers[0]->getSize(); k++)
			{
				signalol = LC * layers[0]->getNeuron(k)->ActivationFunc(layers[0]->getNeuron(k)->GetOutput(), layers[0]->getNeuron(k)->getActivationFunctionIndex(), true);
				for (int j = 0; j < InputLayerNumber + 1; j++)
				{
					layers[0]->getNeuron(k)->setWeightElem(j, layers[0]->getNeuron(k)->getWeightElem(j) + (signalol * models[val]->getNormElem(j) * alfa) + (alfa * layers[0]->getNeuron(k)->getTempWeightElem(j)));
					layers[0]->getNeuron(k)->setTempWeightElem(j, (alfa* signalol* models[val]->getNormElem(j)) + layers[0]->getNeuron(k)->getTempWeightElem(j));
				}
			}

			//en son ara katmana ulaþma
			int index = layers.size() - 1;
			int index_2 = index - 1;
			//önceki giriþleri elde etmek için (2.for için)
			TEMP_INPUT_MATRIX = new float* [layers[index_2 - 1]->getSize() + 1];
			for (int row = 0; row < layers[index_2 - 1]->getSize() + 1; row++)
			{
				TEMP_INPUT_MATRIX[row] = new float[1];
			}
			for (int i = 0; i < layers[index_2 - 1]->getSize(); i++)
			{
				TEMP_INPUT_MATRIX[i][0] = layers[index_2 - 1]->getNeuron(i)->GetOutput();
			}
			TEMP_INPUT_MATRIX[layers[index_2 - 1]->getSize()][0] = 1.0f;


			for (int j = 0; j < layers[index_2]->getSize(); j++)
			{
				for (int i = 0; i < layers[index_2 - 1]->getSize() + 1; i++)
				{
					for (int k = 0; k < OutputLayerNumber; k++)
					{
						if (layers[index]->getNeuron(k)->getActivationFunctionIndex() == 3)
						{
							sumWeights += (desiredArr[k][0] - layers[index]->getNeuron(k)->GetOutput()) * layers[index]->getNeuron(k)->GetOutput() * (1 - layers[index]->getNeuron(k)->GetOutput()) * layers[index]->getNeuron(k)->getWeightElem(j);
						}
						else
						{
							sumWeights += (desiredArr[k][0] - layers[index]->getNeuron(k)->GetOutput()) * layers[index]->getNeuron(k)->ActivationFunc(layers[index]->getNeuron(k)->GetOutput(),
								layers[index]->getNeuron(k)->getActivationFunctionIndex(), true) * layers[index]->getNeuron(k)->getWeightElem(j);
						}

					}
					//Veights[j][i] += LC * ptron.ActivationFunc(hloa[j][0], HLAFIndex, true) * VecX[i][0] * sumWeights;
					layers[index_2]->getNeuron(j)->setWeightElem(i, layers[index_2]->getNeuron(j)->getWeightElem(i) + alfa*LC * layers[index_2]->getNeuron(j)->ActivationFunc(layers[index_2]->getNeuron(j)->GetOutput(),
						layers[index_2]->getNeuron(j)->getActivationFunctionIndex(), true) * TEMP_INPUT_MATRIX[i][0] * sumWeights+(alfa* layers[index_2]->getNeuron(j)->getTempWeightElem(i)));
					//temp eleman eþitleme
					layers[index_2]->getNeuron(j)->setTempWeightElem(i, layers[index_2]->getNeuron(j)->getTempWeightElem(i) + alfa * LC * layers[index_2]->getNeuron(j)->ActivationFunc(layers[index_2]->getNeuron(j)->GetOutput(),
						layers[index_2]->getNeuron(j)->getActivationFunctionIndex(), true) * TEMP_INPUT_MATRIX[i][0] * sumWeights);
					sumWeights = 0;
				}
			}//2.yontem sonu

		}
		errorsum = sqrt(errorsum) / (OutputLayerNumber * models.size());
		if (errorsum < error || cycle == MAX_EPOCH)
			break;
		label12->Text = "Hata: " + errorsum.ToString();
		label13->Text = "Cycle: " + cycle.ToString();
		label12->Refresh();
		label13->Refresh();
		this->chart1->Series["ERGRAPH"]->Points->AddXY(cycle, errorsum);
		errorsum = 0;
		cycle++;
		/*if (cycle % 200 == 0)
			WriteWeights();*/

	}
	}

	
	label13->Text = "Cycle: " + cycle.ToString();
	label12->Text = "Hata: " + errorsum.ToString();
	hata = 0;
	errorsum = 0;
	cycle = 0;
	

}
private: System::Void tESTToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	
	float* result = new float[test_models.size()];
	float* temp = new float[layers[layers.size() - 1]->getSize()];
	for (int val = 0; val < test_models.size(); val++)
	{
		//dinamik dizi olusmasý
		TEMP_W_MATRÝX_1 = new float* [layers[0]->getSize()];
		for (int i = 0; i < layers[0]->getSize(); i++)
		{
			TEMP_W_MATRÝX_1[i] = new float[InputLayerNumber + 1];
		}
		//aðýrlýklarý matrise alma L0xIL boyutunda
		for (int row = 0; row < layers[0]->getSize(); row++)
		{
			for (int col = 0; col < InputLayerNumber + 1; col++)
			{
				TEMP_W_MATRÝX_1[row][col] = layers[0]->getNeuron(row)->getWeightElem(col);
			}
		}
		//girdi katmanýndaki giriþlerin alýnmasý matris oluþturma
		TEMP_INPUT_MATRIX = new float* [InputLayerNumber + 1];
		for (int row = 0; row < InputLayerNumber + 1; row++)
		{
			TEMP_INPUT_MATRIX[row] = new float[1];
		}
		//matrise atama
		for (int row = 0; row < InputLayerNumber; row++)
		{
			TEMP_INPUT_MATRIX[row][0] = models[val]->getNormElem(row);
		}
		TEMP_INPUT_MATRIX[InputLayerNumber][0] = models[val]->getBias();

		//dinamik cýkýs matrisi olusturulmasý
		TEMP_OUTPUT_MATRIX = new long float* [layers[0]->getSize()];
		for (int i = 0; i < layers[0]->getSize(); i++)
		{
			TEMP_OUTPUT_MATRIX[i] = new long float[1];
		}

		for (int i = 0; i < layers[0]->getSize(); i++)
		{
			TEMP_OUTPUT_MATRIX[i][0] = 0.0f;
		}

		//matris carpýmý ve L0 cýkýslarýn alýnmasý
		for (int i = 0; i < layers[0]->getSize(); i++)
		{
			for (int j = 0; j < 1; j++)
			{
				for (int k = 0; k < InputLayerNumber + 1; k++)
				{
					TEMP_OUTPUT_MATRIX[i][j] += TEMP_W_MATRÝX_1[i][k] * TEMP_INPUT_MATRIX[k][j];
				}
			}
		}
		//o katmandaki her noronun cýkýsýnýn AF dan geçirilmesi ve setlenmesi
		for (int i = 0; i < layers[0]->getSize(); i++)
		{
			layers[0]->getNeuron(i)->setOutput(layers[0]->getNeuron(i)->ActivationFunc(TEMP_OUTPUT_MATRIX[i][0], layers[0]->getNeuron(i)->getActivationFunctionIndex(), false));
		}
		delete[] TEMP_INPUT_MATRIX;
		delete[] TEMP_OUTPUT_MATRIX;

		for (int lay = 1; lay < layers.size(); lay++)//katmanlar bitene kadar
		{
			//dinamik dizi olusturma
			TEMP_W_MATRÝX_2 = new float* [layers[lay]->getSize()];
			for (int i = 0; i < layers[lay]->getSize(); i++)
			{
				TEMP_W_MATRÝX_2[i] = new float[layers[lay - 1]->getSize() + 1];
			}
			//aðýrlýk matrisi atama
			for (int row = 0; row < layers[lay]->getSize(); row++)
			{
				for (int col = 0; col < layers[lay - 1]->getSize() + 1; col++)
				{
					TEMP_W_MATRÝX_2[row][col] = layers[lay]->getNeuron(row)->getWeightElem(col);
				}
			}
			//girdi dizisinin oluþturulmasý
			TEMP_INPUT_MATRIX = new float* [layers[lay - 1]->getSize() + 1];
			for (int i = 0; i < layers[lay - 1]->getSize() + 1; i++)
			{
				TEMP_INPUT_MATRIX[i] = new float[1];
			}
			//girdi dizisinin setlenmesi
			for (int row = 0; row < layers[lay - 1]->getSize(); row++)
			{
				TEMP_INPUT_MATRIX[row][0] = layers[lay - 1]->getNeuron(row)->GetOutput();
			}
			TEMP_INPUT_MATRIX[layers[lay - 1]->getSize()][0] = 1.0f;

			//dinamik cýkýs matrisi olusturulmasý
			TEMP_OUTPUT_MATRIX = new long float* [layers[lay]->getSize()];
			for (int i = 0; i < layers[lay]->getSize(); i++)
			{
				TEMP_OUTPUT_MATRIX[i] = new long float[1];
			}
			for (int i = 0; i < layers[lay]->getSize(); i++)
			{
				TEMP_OUTPUT_MATRIX[i][0] = 0.0f;
			}
			//matris carpýmý ve Llay cýkýslarýn alýnmasý
			for (int i = 0; i < layers[lay]->getSize(); i++)
			{
				for (int j = 0; j < 1; j++)
				{
					for (int k = 0; k < layers[lay - 1]->getSize() + 1; k++)
					{
						TEMP_OUTPUT_MATRIX[i][j] += TEMP_W_MATRÝX_2[i][k] * TEMP_INPUT_MATRIX[k][j];
					}
				}
			}
			//çýkýþ katmanlarýnýn AF dan geçirilerek setlenmesi
			/*for (int i = 0; i < layers[lay]->getSize(); i++)
			{
				layers[lay]->getNeuron(i)->setOutput(layers[lay]->getNeuron(i)->ActivationFunc(TEMP_OUTPUT_MATRIX[i][0], layers[lay]->getNeuron(i)->getActivationFunctionIndex(), false));
			}*/
			for (int i = 0; i < layers[lay]->getSize(); i++)
			{
				//son katmanda softmax olur
				if (lay == layers.size() - 1)
				{
					//eðer softmax demisse
					if (layers[lay]->getNeuron(i)->getActivationFunctionIndex() == 3)
					{
						for (int i = 0; i < OutputLayerNumber; i++)
						{
							temp[i] = TEMP_OUTPUT_MATRIX[i][0];
						}
						layers[lay]->getNeuron(i)->setOutput(layers[lay]->getNeuron(i)->SoftMAX_Function(temp, OutputLayerNumber, TEMP_OUTPUT_MATRIX[i][0]));
					}
					else
						layers[lay]->getNeuron(i)->setOutput(layers[lay]->getNeuron(i)->ActivationFunc(TEMP_OUTPUT_MATRIX[i][0], layers[lay]->getNeuron(i)->getActivationFunctionIndex(), false));
				}
				else
					layers[lay]->getNeuron(i)->setOutput(layers[lay]->getNeuron(i)->ActivationFunc(TEMP_OUTPUT_MATRIX[i][0], layers[lay]->getNeuron(i)->getActivationFunctionIndex(), false));
			}
			delete[] TEMP_INPUT_MATRIX;
			delete[] TEMP_OUTPUT_MATRIX;
			delete[] TEMP_W_MATRÝX_2;
		}
		float max = layers[layers.size() - 1]->getNeuron(0)->GetOutput();
		int index = 0;
		for (int i = 0; i < OutputLayerNumber; i++)
		{
			if (layers[layers.size() - 1]->getNeuron(i)->GetOutput() > max)
			{
				max = layers[layers.size() - 1]->getNeuron(i)->GetOutput();
				index = i;
			}
		}
		result[val] = index;
	}
	for (int i = 0; i < test_models.size(); i++)
	{
		if (result[i] == test_models[i]->getClassID())
			RateCount++;
	}
	label14->Text = "Test Doðruluk Oraný = %" + RateCalc((float)test_models.size(), (float)RateCount).ToString();

}

private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Test Dizisini Veriniz");
	//inputindex = (int)System::Convert::ToInt32(numericUpDown1->Text) - 1;
	inputindex = 0;
	std::ifstream dosya;
	int col = 0, pos, startpos = 0;
	std::string line;
	String^ vs;

	char discrim = ' ';
	CString s;
	LPCTSTR input;
	if (openFileDialog2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		s = openFileDialog2->FileName;
		input = (LPCTSTR)s;
		dosya.open(input, std::ios::in);

		while (!dosya.eof())
		{
			pat = new Pattern(InputLayerNumber);//test modellerinde yok bu
			pat->setBias(1.0f);
			test_models.push_back(pat);

			getline(dosya, line);//tum satýrý okuyor
			pos = line.find(discrim);
			/*while (pos != std::string::npos)
			{
				test_models[inputindex]->setElem(col, (float)atof(line.substr(startpos, pos - startpos).c_str()));
				//MessageBox::Show(models[inputindex]->getElem(col).ToString());
				startpos = pos + 1;
				pos = line.find(discrim, startpos);
				col++;
			}*/
			while (true)
			{
				if (col == InputLayerNumber)
				{
					pos = line.length();
					test_models[inputindex]->setClassID((int)atoi(line.substr(startpos, pos - startpos).c_str()));
					//MessageBox::Show(models[inputindex]->getClassID().ToString());
					startpos = 0;
					col = 0;
					inputindex++;
					break;
				}
				test_models[inputindex]->setElem(col, (float)atof(line.substr(startpos, pos - startpos).c_str()));
				//MessageBox::Show(models[inputindex]->getElem(col).ToString());
				startpos = pos + 1;
				pos = line.find(discrim, startpos);
				col++;

			}
		}
		dosya.close();
		//MessageBox::Show(models[inputindex]->getClassID().ToString());
	}

}
};
}
