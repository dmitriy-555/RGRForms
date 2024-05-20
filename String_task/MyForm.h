#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Add_player.h"


namespace Stringtask {
	int count_rows; std::vector<std::vector<std::string>> workers;
	std::vector<std::vector<std::string>> dynamo;
	std::vector<std::vector<std::string>> spartak;
	bool isDynamo = 0, isSpartak = 0;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			count_rows = 0;
			std::ifstream file("spartakInput.txt");
			if (!file) {
				MessageBox::Show("Error opening spartakInput.txt");
				return;
			}
			std::string buf_str;
			int all_prod_int = 0;
			while (file >> buf_str) {
				std::vector<std::string> buf;
				buf.push_back(buf_str);
				for (int i = 0; i < 6; i++) {
					file >> buf_str;
					buf.push_back(buf_str);
					if (i > 2 && i < 5) all_prod_int += stoi(buf_str);
				}
				buf_str = std::to_string(all_prod_int);
				buf.push_back(buf_str);
				spartak.push_back(buf);
				count_rows++;
				all_prod_int = 0;
			}
				

			file.close();
			file.open("dynamoInput.txt");
			if (!file) {
				MessageBox::Show("Error opening dynamoInput.txt");
				return;
			}
			buf_str = "";
			all_prod_int = 0;
			while (file >> buf_str) {
				std::vector<std::string> buf;
				buf.push_back(buf_str);
				for (int i = 0; i < 6; i++) {
					file >> buf_str;
					buf.push_back(buf_str);
					if (i > 2 && i < 5) all_prod_int += stoi(buf_str);
				}
				buf_str = std::to_string(all_prod_int);
				buf.push_back(buf_str);
				dynamo.push_back(buf);
				count_rows++;
				all_prod_int = 0;
			}
			file.close();
			workers.insert(workers.end(), spartak.begin(), spartak.end());
			workers.insert(workers.end(), dynamo.begin(), dynamo.end());
			
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ Field_workers;
	private: System::Windows::Forms::GroupBox^ players_list;
	private: System::Windows::Forms::GroupBox^ modes;
	private: System::Windows::Forms::Button^ read_all;
	private: System::Windows::Forms::Button^ add_worker;
	private: System::Windows::Forms::Button^ delete_worker;
	private: System::Windows::Forms::Button^ show_dynamo_button;
	private: System::Windows::Forms::Button^ show_spartak_button;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ surname_tb;
	private: System::Windows::Forms::TextBox^ id_tb;
	private: System::Windows::Forms::Button^ most_prod_button;









	private: System::Windows::Forms::Label^ id_l;
	private: System::Windows::Forms::Label^ sur_l;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ surname_colmn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ name_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ team_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ goals_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ passes_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ pentalty_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ total_prod;
	//private: System::Windows::Forms::CheckBox^ checkBox1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Field_workers = (gcnew System::Windows::Forms::DataGridView());
			this->ID_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->surname_colmn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->team_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->goals_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->passes_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pentalty_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->total_prod = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->players_list = (gcnew System::Windows::Forms::GroupBox());
			this->modes = (gcnew System::Windows::Forms::GroupBox());
			this->most_prod_button = (gcnew System::Windows::Forms::Button());
			this->add_worker = (gcnew System::Windows::Forms::Button());
			this->delete_worker = (gcnew System::Windows::Forms::Button());
			this->show_dynamo_button = (gcnew System::Windows::Forms::Button());
			this->show_spartak_button = (gcnew System::Windows::Forms::Button());
			this->read_all = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->sur_l = (gcnew System::Windows::Forms::Label());
			this->id_l = (gcnew System::Windows::Forms::Label());
			this->surname_tb = (gcnew System::Windows::Forms::TextBox());
			this->id_tb = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Field_workers))->BeginInit();
			this->players_list->SuspendLayout();
			this->modes->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// Field_workers
			// 
			this->Field_workers->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Field_workers->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Field_workers->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Field_workers->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->ID_column,
					this->surname_colmn, this->name_column, this->team_column, this->goals_column, this->passes_column, this->pentalty_column, this->total_prod
			});
			this->Field_workers->Location = System::Drawing::Point(2, 22);
			this->Field_workers->Margin = System::Windows::Forms::Padding(2);
			this->Field_workers->Name = L"Field_workers";
			this->Field_workers->ReadOnly = true;
			this->Field_workers->RowHeadersWidth = 51;
			this->Field_workers->RowTemplate->Height = 24;
			this->Field_workers->Size = System::Drawing::Size(736, 478);
			this->Field_workers->TabIndex = 0;
			// 
			// ID_column
			// 
			this->ID_column->HeaderText = L"ID";
			this->ID_column->MinimumWidth = 6;
			this->ID_column->Name = L"ID_column";
			this->ID_column->ReadOnly = true;
			this->ID_column->Width = 45;
			// 
			// surname_colmn
			// 
			this->surname_colmn->HeaderText = L"Фамилия";
			this->surname_colmn->MinimumWidth = 6;
			this->surname_colmn->Name = L"surname_colmn";
			this->surname_colmn->ReadOnly = true;
			this->surname_colmn->Width = 91;
			// 
			// name_column
			// 
			this->name_column->HeaderText = L"Имя";
			this->name_column->MinimumWidth = 6;
			this->name_column->Name = L"name_column";
			this->name_column->ReadOnly = true;
			this->name_column->Width = 91;
			// 
			// team_column
			// 
			this->team_column->HeaderText = L"Команда";
			this->team_column->MinimumWidth = 6;
			this->team_column->Name = L"team_column";
			this->team_column->ReadOnly = true;
			this->team_column->Width = 91;
			// 
			// goals_column
			// 
			this->goals_column->HeaderText = L"Голы";
			this->goals_column->MinimumWidth = 6;
			this->goals_column->Name = L"goals_column";
			this->goals_column->ReadOnly = true;
			this->goals_column->Width = 91;
			// 
			// passes_column
			// 
			this->passes_column->HeaderText = L"Пассы";
			this->passes_column->MinimumWidth = 6;
			this->passes_column->Name = L"passes_column";
			this->passes_column->ReadOnly = true;
			this->passes_column->Width = 91;
			// 
			// pentalty_column
			// 
			this->pentalty_column->HeaderText = L"Штрафное";
			this->pentalty_column->MinimumWidth = 6;
			this->pentalty_column->Name = L"pentalty_column";
			this->pentalty_column->ReadOnly = true;
			this->pentalty_column->Width = 91;
			// 
			// total_prod
			// 
			this->total_prod->HeaderText = L"Общий счёт";
			this->total_prod->MinimumWidth = 6;
			this->total_prod->Name = L"total_prod";
			this->total_prod->ReadOnly = true;
			this->total_prod->Width = 91;
			// 
			// players_list
			// 
			this->players_list->Controls->Add(this->Field_workers);
			this->players_list->Location = System::Drawing::Point(272, 19);
			this->players_list->Margin = System::Windows::Forms::Padding(2);
			this->players_list->Name = L"players_list";
			this->players_list->Padding = System::Windows::Forms::Padding(2);
			this->players_list->Size = System::Drawing::Size(740, 505);
			this->players_list->TabIndex = 1;
			this->players_list->TabStop = false;
			this->players_list->Text = L"Список игроков";
			// 
			// modes
			// 
			this->modes->Controls->Add(this->most_prod_button);
			this->modes->Controls->Add(this->add_worker);
			this->modes->Controls->Add(this->delete_worker);
			this->modes->Location = System::Drawing::Point(6, 19);
			this->modes->Margin = System::Windows::Forms::Padding(2);
			this->modes->Name = L"modes";
			this->modes->Padding = System::Windows::Forms::Padding(2);
			this->modes->Size = System::Drawing::Size(253, 162);
			this->modes->TabIndex = 2;
			this->modes->TabStop = false;
			this->modes->Text = L"Действия";
			// 
			// most_prod_button
			// 
			this->most_prod_button->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->most_prod_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->most_prod_button->Location = System::Drawing::Point(26, 68);
			this->most_prod_button->Margin = System::Windows::Forms::Padding(2);
			this->most_prod_button->Name = L"most_prod_button";
			this->most_prod_button->Size = System::Drawing::Size(200, 29);
			this->most_prod_button->TabIndex = 9;
			this->most_prod_button->Text = L"Лучшие";
			this->most_prod_button->UseVisualStyleBackColor = true;
			this->most_prod_button->Click += gcnew System::EventHandler(this, &MyForm::most_prod_button_Click);
			// 
			// add_worker
			// 
			this->add_worker->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->add_worker->Location = System::Drawing::Point(26, 22);
			this->add_worker->Margin = System::Windows::Forms::Padding(2);
			this->add_worker->Name = L"add_worker";
			this->add_worker->Size = System::Drawing::Size(200, 29);
			this->add_worker->TabIndex = 7;
			this->add_worker->Text = L"Добавить";
			this->add_worker->UseVisualStyleBackColor = true;
			this->add_worker->Click += gcnew System::EventHandler(this, &MyForm::add_worker_Click);
			// 
			// delete_worker
			// 
			this->delete_worker->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->delete_worker->Location = System::Drawing::Point(26, 116);
			this->delete_worker->Margin = System::Windows::Forms::Padding(2);
			this->delete_worker->Name = L"delete_worker";
			this->delete_worker->Size = System::Drawing::Size(200, 28);
			this->delete_worker->TabIndex = 6;
			this->delete_worker->Text = L"Удалить";
			this->delete_worker->UseVisualStyleBackColor = true;
			this->delete_worker->Click += gcnew System::EventHandler(this, &MyForm::delete_worker_Click);
			// 
			// show_dynamo_button
			// 
			this->show_dynamo_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->show_dynamo_button->Location = System::Drawing::Point(3, 178);
			this->show_dynamo_button->Margin = System::Windows::Forms::Padding(2);
			this->show_dynamo_button->Name = L"show_dynamo_button";
			this->show_dynamo_button->Size = System::Drawing::Size(242, 28);
			this->show_dynamo_button->TabIndex = 0;
			this->show_dynamo_button->Text = L"Показать Dynamo";
			this->show_dynamo_button->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->show_dynamo_button->UseVisualStyleBackColor = true;
			this->show_dynamo_button->Click += gcnew System::EventHandler(this, &MyForm::show_dynamo_button_Click);
			// 
			// show_spartak_button
			// 
			this->show_spartak_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->show_spartak_button->Location = System::Drawing::Point(3, 146);
			this->show_spartak_button->Margin = System::Windows::Forms::Padding(2);
			this->show_spartak_button->Name = L"show_spartak_button";
			this->show_spartak_button->Size = System::Drawing::Size(242, 28);
			this->show_spartak_button->TabIndex = 0;
			this->show_spartak_button->Text = L"Показать Spartak";
			this->show_spartak_button->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->show_spartak_button->UseVisualStyleBackColor = true;
			this->show_spartak_button->Click += gcnew System::EventHandler(this, &MyForm::show_spartak_button_Click);
			// 
			// read_all
			// 
			this->read_all->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->read_all->Location = System::Drawing::Point(3, 210);
			this->read_all->Margin = System::Windows::Forms::Padding(2);
			this->read_all->Name = L"read_all";
			this->read_all->Size = System::Drawing::Size(242, 28);
			this->read_all->TabIndex = 0;
			this->read_all->Text = L"Прочитать всех/Обновить";
			this->read_all->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->read_all->UseVisualStyleBackColor = true;
			this->read_all->Click += gcnew System::EventHandler(this, &MyForm::read_all_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->sur_l);
			this->groupBox1->Controls->Add(this->id_l);
			this->groupBox1->Controls->Add(this->show_spartak_button);
			this->groupBox1->Controls->Add(this->show_dynamo_button);
			this->groupBox1->Controls->Add(this->read_all);
			this->groupBox1->Controls->Add(this->surname_tb);
			this->groupBox1->Controls->Add(this->id_tb);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(6, 190);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(253, 321);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Поиск";
			// 
			// sur_l
			// 
			this->sur_l->AutoSize = true;
			this->sur_l->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sur_l->ForeColor = System::Drawing::Color::IndianRed;
			this->sur_l->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->sur_l->Location = System::Drawing::Point(8, 114);
			this->sur_l->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->sur_l->Name = L"sur_l";
			this->sur_l->Size = System::Drawing::Size(0, 13);
			this->sur_l->TabIndex = 5;
			// 
			// id_l
			// 
			this->id_l->AutoSize = true;
			this->id_l->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->id_l->ForeColor = System::Drawing::Color::IndianRed;
			this->id_l->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->id_l->Location = System::Drawing::Point(8, 56);
			this->id_l->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->id_l->Name = L"id_l";
			this->id_l->Size = System::Drawing::Size(0, 13);
			this->id_l->TabIndex = 4;
			// 
			// surname_tb
			// 
			this->surname_tb->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->surname_tb->Location = System::Drawing::Point(77, 85);
			this->surname_tb->Margin = System::Windows::Forms::Padding(2);
			this->surname_tb->Name = L"surname_tb";
			this->surname_tb->Size = System::Drawing::Size(135, 26);
			this->surname_tb->TabIndex = 3;
			this->surname_tb->TextChanged += gcnew System::EventHandler(this, &MyForm::surname_tb_TextChanged);
			// 
			// id_tb
			// 
			this->id_tb->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->id_tb->Location = System::Drawing::Point(77, 27);
			this->id_tb->Margin = System::Windows::Forms::Padding(2);
			this->id_tb->Name = L"id_tb";
			this->id_tb->Size = System::Drawing::Size(135, 26);
			this->id_tb->TabIndex = 2;
			this->id_tb->TextChanged += gcnew System::EventHandler(this, &MyForm::id_tb_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(7, 88);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(68, 19);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Фамилия";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(52, 30);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(23, 19);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ID";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::HighlightText;
			this->ClientSize = System::Drawing::Size(1017, 555);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->modes);
			this->Controls->Add(this->players_list);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"Игроки";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Field_workers))->EndInit();
			this->players_list->ResumeLayout(false);
			this->modes->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void read_all_Click(System::Object^ sender, System::EventArgs^ e) {
		isDynamo = 0;
		isSpartak = 0;
		Field_workers->Columns->Clear();
		Field_workers->ColumnCount = 8; Field_workers->RowCount = count_rows;
		Field_workers->Columns[0]->Name = "ID"; Field_workers->Columns[0]->Width = 45;
		Field_workers->Columns[1]->Name = "Фамилия"; Field_workers->Columns[1]->Width = 91;
		Field_workers->Columns[2]->Name = "Имя"; Field_workers->Columns[2]->Width = 91;
		Field_workers->Columns[3]->Name = "Команда"; Field_workers->Columns[3]->Width = 91;
		Field_workers->Columns[4]->Name = "Голы"; Field_workers->Columns[4]->Width = 91;
		Field_workers->Columns[5]->Name = "Пассы"; Field_workers->Columns[5]->Width = 91;
		Field_workers->Columns[6]->Name = "Штрафное"; Field_workers->Columns[6]->Width = 91;
		Field_workers->Columns[7]->Name = "Общий счёт"; Field_workers->Columns[7]->Width = 91;
		


		for (int i = 0; i < count_rows; i++) {
			for (int j = 0; j < 8; j++) {
				String^ buf = gcnew String(workers[i][j].c_str());
				this->Field_workers->Rows[i]->Cells[j]->Value = buf;
			}
		}
	}

	private: System::Void add_worker_Click(System::Object^ sender, System::EventArgs^ e) {
		Add_player^ form = gcnew Add_player;
		form->ShowDialog();
		count_rows = 0;
		workers.clear();
		workers.shrink_to_fit();
		dynamo.clear();
		dynamo.shrink_to_fit();
		spartak.clear();
		spartak.shrink_to_fit();
		std::ifstream file("spartakInput.txt");
		if (!file) {
			MessageBox::Show("Error opening spartakInput.txt");
			return;
		}
		std::string buf_str;
		int all_prod_int = 0;
		while (file >> buf_str) {
			std::vector<std::string> buf;
			buf.push_back(buf_str);
			for (int i = 0; i < 6; i++) {
				file >> buf_str;
				buf.push_back(buf_str);
				if (i > 2 && i < 5) all_prod_int += stoi(buf_str);
			}
			buf_str = std::to_string(all_prod_int);
			buf.push_back(buf_str);
			spartak.push_back(buf);
			count_rows++;
			all_prod_int = 0;
		}


		file.close();
		file.open("dynamoInput.txt");
		if (!file) {
			MessageBox::Show("Error opening dynamoInput.txt");
			return;
		}
		buf_str = "";
		all_prod_int = 0;
		while (file >> buf_str) {
			std::vector<std::string> buf;
			buf.push_back(buf_str);
			for (int i = 0; i < 6; i++) {
				file >> buf_str;
				buf.push_back(buf_str);
				if (i > 2 && i < 5) all_prod_int += stoi(buf_str);
			}
			buf_str = std::to_string(all_prod_int);
			buf.push_back(buf_str);
			dynamo.push_back(buf);
			count_rows++;
			all_prod_int = 0;
		}
		file.close();
		workers.insert(workers.end(), spartak.begin(), spartak.end());
		workers.insert(workers.end(), dynamo.begin(), dynamo.end());
	}

	private: System::Void close_button_Click(System::Object^ sender, System::EventArgs^ e) {
		//std::ofstream file("input.txt");
		//for (std::vector<std::string> worker : workers) {
			//for (int i = 0; i < 7; i ++) {
				//file << worker[i] + " ";
			//} file << std::endl;
		//}
		Application::Exit();
	}

	private: System::Void id_tb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		std::string str = "";
		id_l->Text = "";
		for each (char c in id_tb->Text) {
			if (!(c >= '0' && c <= '9')) {
				id_l->Text = "Неверный ввод!\nДопускаются символы от 0 до 9";
				return;
			}
			str += c;
		}
		if (id_tb->Text != "") {
		int row = 1;
		Field_workers->Columns->Clear();
		Field_workers->ColumnCount = 8; Field_workers->RowCount = row;
		Field_workers->Columns[0]->Name = "ID"; Field_workers->Columns[0]->Width = 45;
		Field_workers->Columns[1]->Name = "Фамилия"; Field_workers->Columns[1]->Width = 91;
		Field_workers->Columns[2]->Name = "Имя"; Field_workers->Columns[2]->Width = 91;
		Field_workers->Columns[3]->Name = "Команда"; Field_workers->Columns[3]->Width = 91;
		Field_workers->Columns[4]->Name = "Голы"; Field_workers->Columns[4]->Width = 91;
		Field_workers->Columns[5]->Name = "Пассы"; Field_workers->Columns[5]->Width = 91;
		Field_workers->Columns[6]->Name = "Штрафное"; Field_workers->Columns[6]->Width = 91;
		Field_workers->Columns[7]->Name = "Общий счёт"; Field_workers->Columns[7]->Width = 91;
			for (std::vector<std::string> worker : workers) {
				if (worker[0].find(str) != std::string::npos) {
					row += 1;
					Field_workers->RowCount = row;
					for (int i = 0; i < 8; i++) {
						String^ buf = gcnew String(worker[i].c_str());
						this->Field_workers->Rows[row - 2]->Cells[i]->Value = buf;
					}
				}
			}
		}
			
	}

	private: System::Void surname_tb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		std::string str = "";
		sur_l->Text = "";
		for each (char c in surname_tb->Text) {
			if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
				sur_l->Text = "Неверный ввод!\nДопускаются символы от a до z и от A до Z";
				return;	
			}
			str += std::tolower(c);
		}
		if (surname_tb->Text != "") {
			int row = 1;
			Field_workers->Columns->Clear();
			Field_workers->ColumnCount = 8; Field_workers->RowCount = row;
			Field_workers->Columns[0]->Name = "ID"; Field_workers->Columns[0]->Width = 45;
			Field_workers->Columns[1]->Name = "Фамилия"; Field_workers->Columns[1]->Width = 91;
			Field_workers->Columns[2]->Name = "Имя"; Field_workers->Columns[2]->Width = 91;
			Field_workers->Columns[3]->Name = "Команда"; Field_workers->Columns[3]->Width = 91;
			Field_workers->Columns[4]->Name = "Голы"; Field_workers->Columns[4]->Width = 91;
			Field_workers->Columns[5]->Name = "Пассы"; Field_workers->Columns[5]->Width = 91;
			Field_workers->Columns[6]->Name = "Штрафное"; Field_workers->Columns[6]->Width = 91;
			Field_workers->Columns[7]->Name = "Общий счёт"; Field_workers->Columns[7]->Width = 91;
			std::string ch_str;
			for (std::vector<std::string> worker : workers) {
				ch_str = "";

				for (char c : worker[1]) ch_str += std::tolower(c);
				if (ch_str.find(str) != std::string::npos) {
					row += 1;
					Field_workers->RowCount = row;
					for (int i = 0; i < 8; i++) {
						String^ buf = gcnew String(worker[i].c_str());
						this->Field_workers->Rows[row - 2]->Cells[i]->Value = buf;
					}
				}
			}
		}
		

	}

	private: 
		static bool CompareWorkers(std::vector<std::string> a, std::vector<std::string> b) {
			return stoi(a[7]) > stoi(b[7]);
		}
		
		System::Void most_prod_button_Click(System::Object^ sender, System::EventArgs^ e) {
		int row = 1;
		Field_workers->Columns->Clear();
		Field_workers->ColumnCount = 8; Field_workers->RowCount = row;
		Field_workers->Columns[0]->Name = "ID"; Field_workers->Columns[0]->Width = 45;
		Field_workers->Columns[1]->Name = "Фамилия"; Field_workers->Columns[1]->Width = 91;
		Field_workers->Columns[2]->Name = "Имя"; Field_workers->Columns[2]->Width = 91;
		Field_workers->Columns[3]->Name = "Команда"; Field_workers->Columns[3]->Width = 91;
		Field_workers->Columns[4]->Name = "Голы"; Field_workers->Columns[4]->Width = 91;
		Field_workers->Columns[5]->Name = "Пассы"; Field_workers->Columns[5]->Width = 91;
		Field_workers->Columns[6]->Name = "Штрафное"; Field_workers->Columns[6]->Width = 91;
		Field_workers->Columns[7]->Name = "Общий счёт"; Field_workers->Columns[7]->Width = 91;


		if (isSpartak) {
			std::vector< std::vector<std::string>> players = spartak;
			std::sort(players.begin(), players.end(), CompareWorkers);
			for (int i = 0; i < players.size(); i++) {
				row += 1;
				Field_workers->RowCount = row;
				for (int j = 0; j < 8; j++) {
					String^ buf = gcnew String(players[i][j].c_str());
					this->Field_workers->Rows[i]->Cells[j]->Value = buf;
				}
			}
		}
		else if (isDynamo) {
			std::vector< std::vector<std::string>> players = dynamo;
			std::sort(players.begin(), players.end(), CompareWorkers);
			for (int i = 0; i < players.size(); i++) {
				row += 1;
				Field_workers->RowCount = row;
				for (int j = 0; j < 8; j++) {
					String^ buf = gcnew String(players[i][j].c_str());
					this->Field_workers->Rows[i]->Cells[j]->Value = buf;
				}
			}
		}
		else {
			std::vector< std::vector<std::string>> players = workers;
			std::sort(players.begin(), players.end(), CompareWorkers);
			for (int i = 0; i < players.size(); i++) {
				row += 1;
				Field_workers->RowCount = row;
				for (int j = 0; j < 8; j++) {
					String^ buf = gcnew String(players[i][j].c_str());
					this->Field_workers->Rows[i]->Cells[j]->Value = buf;
				}
			}
		}
	}

private: System::Void show_spartak_button_Click(System::Object^ sender, System::EventArgs^ e) {
	isSpartak = 1;
	isDynamo = 0;
	Field_workers->Columns->Clear();
	Field_workers->ColumnCount = 8;
	int count_rows = 0;

	Field_workers->Columns[0]->Name = "ID"; Field_workers->Columns[0]->Width = 45;
	Field_workers->Columns[1]->Name = "Фамилия"; Field_workers->Columns[1]->Width = 91;
	Field_workers->Columns[2]->Name = "Имя"; Field_workers->Columns[2]->Width = 91;
	Field_workers->Columns[3]->Name = "Команда"; Field_workers->Columns[3]->Width = 91;
	Field_workers->Columns[4]->Name = "Голы"; Field_workers->Columns[4]->Width = 91;
	Field_workers->Columns[5]->Name = "Пассы"; Field_workers->Columns[5]->Width = 91;
	Field_workers->Columns[6]->Name = "Штрафное"; Field_workers->Columns[6]->Width = 91;
	Field_workers->Columns[7]->Name = "Общий счёт"; Field_workers->Columns[7]->Width = 91;

	for (std::vector<std::string> player : spartak) {
		Field_workers->RowCount++;
		for (int j = 0; j < 8; j++) {
			String^ buf = gcnew String(player[j].c_str());
			this->Field_workers->Rows[count_rows]->Cells[j]->Value = buf;
		}
		count_rows++;
	}
}

private: System::Void show_dynamo_button_Click(System::Object^ sender, System::EventArgs^ e) {
	isDynamo = 1;
	isSpartak = 0;
	Field_workers->Columns->Clear();
	Field_workers->ColumnCount = 8;
	int count_rows = 0;

	Field_workers->Columns[0]->Name = "ID"; Field_workers->Columns[0]->Width = 45;
	Field_workers->Columns[1]->Name = "Фамилия"; Field_workers->Columns[1]->Width = 91;
	Field_workers->Columns[2]->Name = "Имя"; Field_workers->Columns[2]->Width = 91;
	Field_workers->Columns[3]->Name = "Команда"; Field_workers->Columns[3]->Width = 91;
	Field_workers->Columns[4]->Name = "Голы"; Field_workers->Columns[4]->Width = 91;
	Field_workers->Columns[5]->Name = "Пассы"; Field_workers->Columns[5]->Width = 91;
	Field_workers->Columns[6]->Name = "Штрафное"; Field_workers->Columns[6]->Width = 91;
	Field_workers->Columns[7]->Name = "Общий счёт"; Field_workers->Columns[7]->Width = 91;

	for (std::vector<std::string> player : dynamo) {
		Field_workers->RowCount++;
		for (int j = 0; j < 8; j++) {
			String^ buf = gcnew String(player[j].c_str());
			this->Field_workers->Rows[count_rows]->Cells[j]->Value = buf;
		}
		count_rows++;
	}
}

private:
	void remove_entries(std::vector<std::vector<std::string>>& vec, const std::vector<std::string>& ids) {
		std::vector<std::vector<std::string>> new_vec;
		for (const auto& worker : vec) {
			if (std::find(ids.begin(), ids.end(), worker[0]) == ids.end()) {
				new_vec.push_back(worker);
			}
			else {
				count_rows--;
			}
		}
		vec = new_vec;
	}

	void write_to_file(const std::string& filename, const std::vector<std::vector<std::string>>& vec) {
		std::ofstream file(filename);
		for (int i = 0; i < vec.size(); i++) { 
			for (int j = 0; j < vec[i].size() - 1; j++) {
				file << vec[i][j];
				if (j < vec[i].size() - 1) file << " "; // Добавляем пробел, если это не последний элемент строки
			}
			file << "\n";
		}
		file.close();
	}

private: System::Void delete_worker_Click(System::Object^ sender, System::EventArgs^ e) {
	if (Field_workers->SelectedRows->Count > 0) {
		std::vector<std::string> ids;
		std::string str;
		String^ buf;

		while (Field_workers->SelectedRows->Count > 0) {
			buf = Convert::ToString(Field_workers->SelectedRows[0]->Cells[0]->Value);
			for each (char c in buf) str += c;
			ids.push_back(str);	
			str = "";
			Field_workers->Rows->RemoveAt(Field_workers->SelectedRows[0]->Index);
		}

		remove_entries(workers, ids);
		remove_entries(dynamo, ids);
		remove_entries(spartak, ids);

		write_to_file("dynamoInput.txt", dynamo);
		write_to_file("spartakInput.txt", spartak);
	}
}
};
}
