#pragma once
#include <msclr/marshal_cppstd.h>
#include <random>
#include <unordered_set>
namespace Stringtask {
	std::vector<std::vector<std::string>> new_workers; std::vector<bool> f; int count_add_rows;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Add_player
	/// </summary>
	public ref class Add_player : public System::Windows::Forms::Form
	{
	public:
		Add_player(void)
		{
			InitializeComponent();
			for (int i = 0; i < 7; i++) {
				f.push_back(true);
			}
			count_add_rows = 1;
			Field_workers_add->ColumnCount = 7; Field_workers_add->RowCount = count_add_rows;
			Field_workers_add->Columns[0]->Name = "ID"; Field_workers_add->Columns[0]->Width = 45;
			Field_workers_add->Columns[1]->Name = "Фамилия"; Field_workers_add->Columns[1]->Width = 95;
			Field_workers_add->Columns[2]->Name = "Имя"; Field_workers_add->Columns[2]->Width = 95;
			Field_workers_add->Columns[3]->Name = "Команда"; Field_workers_add->Columns[3]->Width = 95;
			Field_workers_add->Columns[4]->Name = "Голлы"; Field_workers_add->Columns[4]->Width = 95;
			Field_workers_add->Columns[5]->Name = "Пассы"; Field_workers_add->Columns[5]->Width = 95;
			Field_workers_add->Columns[6]->Name = "Штрафное"; Field_workers_add->Columns[6]->Width = 95;
			
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Add_player()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ surname_tb;
	private: System::Windows::Forms::TextBox^ monday_tb;
	private: System::Windows::Forms::TextBox^ tuesday_tb;
	private: System::Windows::Forms::TextBox^ wednesday_tb;
	private: System::Windows::Forms::TextBox^ thursady_tb;
	private: System::Windows::Forms::TextBox^ sunday_tb;
	private: System::Windows::Forms::Button^ add_button;
	private: System::Windows::Forms::Button^ cancel_button;
	private: System::Windows::Forms::Button^ ready_button;

	private: System::Windows::Forms::Label^ sur_l;
	private: System::Windows::Forms::Label^ mon_l;
	private: System::Windows::Forms::Label^ tue_l;
	private: System::Windows::Forms::Label^ wed_l;
	private: System::Windows::Forms::Label^ thu_l;

	private: System::Windows::Forms::Label^ sat_l;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::DataGridView^ Field_workers_add;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ surname_colmn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ monday_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ tuesday_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ wednesday_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ thursday_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ friday_column;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->surname_tb = (gcnew System::Windows::Forms::TextBox());
			this->monday_tb = (gcnew System::Windows::Forms::TextBox());
			this->tuesday_tb = (gcnew System::Windows::Forms::TextBox());
			this->wednesday_tb = (gcnew System::Windows::Forms::TextBox());
			this->thursady_tb = (gcnew System::Windows::Forms::TextBox());
			this->sunday_tb = (gcnew System::Windows::Forms::TextBox());
			this->add_button = (gcnew System::Windows::Forms::Button());
			this->cancel_button = (gcnew System::Windows::Forms::Button());
			this->ready_button = (gcnew System::Windows::Forms::Button());
			this->sur_l = (gcnew System::Windows::Forms::Label());
			this->mon_l = (gcnew System::Windows::Forms::Label());
			this->tue_l = (gcnew System::Windows::Forms::Label());
			this->wed_l = (gcnew System::Windows::Forms::Label());
			this->thu_l = (gcnew System::Windows::Forms::Label());
			this->sat_l = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Field_workers_add = (gcnew System::Windows::Forms::DataGridView());
			this->ID_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->surname_colmn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->monday_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tuesday_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->wednesday_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->thursday_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->friday_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Field_workers_add))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(7, 69);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(80, 21);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Фамилия";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(7, 121);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 21);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Имя";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(7, 174);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(76, 21);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Команда";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(7, 228);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(47, 21);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Голы";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(7, 282);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(86, 21);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Передачи";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(7, 336);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(91, 21);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Штрафное";
			// 
			// surname_tb
			// 
			this->surname_tb->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->surname_tb->Location = System::Drawing::Point(128, 69);
			this->surname_tb->Margin = System::Windows::Forms::Padding(2);
			this->surname_tb->Name = L"surname_tb";
			this->surname_tb->Size = System::Drawing::Size(219, 29);
			this->surname_tb->TabIndex = 7;
			this->surname_tb->TextChanged += gcnew System::EventHandler(this, &Add_player::surname_tb_TextChanged);
			// 
			// monday_tb
			// 
			this->monday_tb->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->monday_tb->Location = System::Drawing::Point(128, 121);
			this->monday_tb->Margin = System::Windows::Forms::Padding(2);
			this->monday_tb->Name = L"monday_tb";
			this->monday_tb->Size = System::Drawing::Size(219, 29);
			this->monday_tb->TabIndex = 8;
			this->monday_tb->TextChanged += gcnew System::EventHandler(this, &Add_player::monday_tb_TextChanged);
			// 
			// tuesday_tb
			// 
			this->tuesday_tb->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tuesday_tb->Location = System::Drawing::Point(128, 174);
			this->tuesday_tb->Margin = System::Windows::Forms::Padding(2);
			this->tuesday_tb->Name = L"tuesday_tb";
			this->tuesday_tb->Size = System::Drawing::Size(219, 29);
			this->tuesday_tb->TabIndex = 9;
			this->tuesday_tb->TextChanged += gcnew System::EventHandler(this, &Add_player::tuesday_tb_TextChanged);
			// 
			// wednesday_tb
			// 
			this->wednesday_tb->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->wednesday_tb->Location = System::Drawing::Point(128, 228);
			this->wednesday_tb->Margin = System::Windows::Forms::Padding(2);
			this->wednesday_tb->Name = L"wednesday_tb";
			this->wednesday_tb->Size = System::Drawing::Size(219, 29);
			this->wednesday_tb->TabIndex = 10;
			this->wednesday_tb->TextChanged += gcnew System::EventHandler(this, &Add_player::wednesday_tb_TextChanged);
			// 
			// thursady_tb
			// 
			this->thursady_tb->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->thursady_tb->Location = System::Drawing::Point(128, 282);
			this->thursady_tb->Margin = System::Windows::Forms::Padding(2);
			this->thursady_tb->Name = L"thursady_tb";
			this->thursady_tb->Size = System::Drawing::Size(219, 29);
			this->thursady_tb->TabIndex = 11;
			this->thursady_tb->TextChanged += gcnew System::EventHandler(this, &Add_player::thursady_tb_TextChanged);
			// 
			// sunday_tb
			// 
			this->sunday_tb->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sunday_tb->Location = System::Drawing::Point(128, 336);
			this->sunday_tb->Margin = System::Windows::Forms::Padding(2);
			this->sunday_tb->Name = L"sunday_tb";
			this->sunday_tb->Size = System::Drawing::Size(219, 29);
			this->sunday_tb->TabIndex = 13;
			this->sunday_tb->TextChanged += gcnew System::EventHandler(this, &Add_player::sunday_tb_TextChanged);
			// 
			// add_button
			// 
			this->add_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->add_button->Location = System::Drawing::Point(11, 395);
			this->add_button->Margin = System::Windows::Forms::Padding(2);
			this->add_button->Name = L"add_button";
			this->add_button->Size = System::Drawing::Size(122, 31);
			this->add_button->TabIndex = 14;
			this->add_button->Text = L"Добавить";
			this->add_button->UseVisualStyleBackColor = true;
			this->add_button->Click += gcnew System::EventHandler(this, &Add_player::add_button_Click);
			// 
			// cancel_button
			// 
			this->cancel_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cancel_button->Location = System::Drawing::Point(902, 530);
			this->cancel_button->Margin = System::Windows::Forms::Padding(2);
			this->cancel_button->Name = L"cancel_button";
			this->cancel_button->Size = System::Drawing::Size(122, 31);
			this->cancel_button->TabIndex = 15;
			this->cancel_button->Text = L"Отменить";
			this->cancel_button->UseVisualStyleBackColor = true;
			this->cancel_button->Click += gcnew System::EventHandler(this, &Add_player::cancel_button_Click);
			// 
			// ready_button
			// 
			this->ready_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ready_button->Location = System::Drawing::Point(11, 530);
			this->ready_button->Margin = System::Windows::Forms::Padding(2);
			this->ready_button->Name = L"ready_button";
			this->ready_button->Size = System::Drawing::Size(122, 31);
			this->ready_button->TabIndex = 16;
			this->ready_button->Text = L"Готово";
			this->ready_button->UseVisualStyleBackColor = true;
			this->ready_button->Click += gcnew System::EventHandler(this, &Add_player::ready_button_Click);
			// 
			// sur_l
			// 
			this->sur_l->AutoSize = true;
			this->sur_l->ForeColor = System::Drawing::Color::IndianRed;
			this->sur_l->Location = System::Drawing::Point(31, 103);
			this->sur_l->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->sur_l->Name = L"sur_l";
			this->sur_l->Size = System::Drawing::Size(0, 13);
			this->sur_l->TabIndex = 18;
			// 
			// mon_l
			// 
			this->mon_l->AutoSize = true;
			this->mon_l->ForeColor = System::Drawing::Color::IndianRed;
			this->mon_l->Location = System::Drawing::Point(31, 155);
			this->mon_l->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->mon_l->Name = L"mon_l";
			this->mon_l->Size = System::Drawing::Size(0, 13);
			this->mon_l->TabIndex = 19;
			// 
			// tue_l
			// 
			this->tue_l->AutoSize = true;
			this->tue_l->ForeColor = System::Drawing::Color::IndianRed;
			this->tue_l->Location = System::Drawing::Point(31, 208);
			this->tue_l->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->tue_l->Name = L"tue_l";
			this->tue_l->Size = System::Drawing::Size(0, 13);
			this->tue_l->TabIndex = 20;
			// 
			// wed_l
			// 
			this->wed_l->AutoSize = true;
			this->wed_l->ForeColor = System::Drawing::Color::IndianRed;
			this->wed_l->Location = System::Drawing::Point(32, 263);
			this->wed_l->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->wed_l->Name = L"wed_l";
			this->wed_l->Size = System::Drawing::Size(0, 13);
			this->wed_l->TabIndex = 21;
			// 
			// thu_l
			// 
			this->thu_l->AutoSize = true;
			this->thu_l->ForeColor = System::Drawing::Color::IndianRed;
			this->thu_l->Location = System::Drawing::Point(32, 317);
			this->thu_l->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->thu_l->Name = L"thu_l";
			this->thu_l->Size = System::Drawing::Size(0, 13);
			this->thu_l->TabIndex = 22;
			// 
			// sat_l
			// 
			this->sat_l->AutoSize = true;
			this->sat_l->ForeColor = System::Drawing::Color::IndianRed;
			this->sat_l->Location = System::Drawing::Point(32, 372);
			this->sat_l->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->sat_l->Name = L"sat_l";
			this->sat_l->Size = System::Drawing::Size(0, 13);
			this->sat_l->TabIndex = 24;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(225, 395);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(122, 31);
			this->button1->TabIndex = 25;
			this->button1->Text = L"Удалить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Add_player::button1_Click);
			// 
			// Field_workers_add
			// 
			this->Field_workers_add->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->Field_workers_add->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->Field_workers_add->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->Field_workers_add->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->ID_column,
					this->surname_colmn, this->monday_column, this->tuesday_column, this->wednesday_column, this->thursday_column, this->friday_column
			});
			this->Field_workers_add->Location = System::Drawing::Point(364, 10);
			this->Field_workers_add->Margin = System::Windows::Forms::Padding(2);
			this->Field_workers_add->Name = L"Field_workers_add";
			this->Field_workers_add->ReadOnly = true;
			this->Field_workers_add->RowHeadersWidth = 51;
			this->Field_workers_add->RowTemplate->Height = 24;
			this->Field_workers_add->Size = System::Drawing::Size(662, 478);
			this->Field_workers_add->TabIndex = 27;
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
			this->surname_colmn->Width = 94;
			// 
			// monday_column
			// 
			this->monday_column->HeaderText = L"Имя";
			this->monday_column->MinimumWidth = 6;
			this->monday_column->Name = L"monday_column";
			this->monday_column->ReadOnly = true;
			this->monday_column->Width = 94;
			// 
			// tuesday_column
			// 
			this->tuesday_column->HeaderText = L"Команда";
			this->tuesday_column->MinimumWidth = 6;
			this->tuesday_column->Name = L"tuesday_column";
			this->tuesday_column->ReadOnly = true;
			this->tuesday_column->Width = 94;
			// 
			// wednesday_column
			// 
			this->wednesday_column->HeaderText = L"Голы";
			this->wednesday_column->MinimumWidth = 6;
			this->wednesday_column->Name = L"wednesday_column";
			this->wednesday_column->ReadOnly = true;
			this->wednesday_column->Width = 94;
			// 
			// thursday_column
			// 
			this->thursday_column->HeaderText = L"Пассы";
			this->thursday_column->MinimumWidth = 6;
			this->thursday_column->Name = L"thursday_column";
			this->thursday_column->ReadOnly = true;
			this->thursday_column->Width = 94;
			// 
			// friday_column
			// 
			this->friday_column->HeaderText = L"Штрафное";
			this->friday_column->MinimumWidth = 6;
			this->friday_column->Name = L"friday_column";
			this->friday_column->ReadOnly = true;
			this->friday_column->Width = 94;
			// 
			// Add_player
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1035, 572);
			this->Controls->Add(this->Field_workers_add);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->sat_l);
			this->Controls->Add(this->thu_l);
			this->Controls->Add(this->wed_l);
			this->Controls->Add(this->tue_l);
			this->Controls->Add(this->mon_l);
			this->Controls->Add(this->sur_l);
			this->Controls->Add(this->ready_button);
			this->Controls->Add(this->cancel_button);
			this->Controls->Add(this->add_button);
			this->Controls->Add(this->thursady_tb);
			this->Controls->Add(this->wednesday_tb);
			this->Controls->Add(this->tuesday_tb);
			this->Controls->Add(this->monday_tb);
			this->Controls->Add(this->sunday_tb);
			this->Controls->Add(this->surname_tb);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Add_player";
			this->Text = L"Add_player";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Field_workers_add))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private:
	void remove_entries(std::vector<std::vector<std::string>>& vec, const std::vector<std::string>& ids) {
		std::vector<std::vector<std::string>> new_vec;
		bool f = false;
		for (int i = 0; i < vec.size(); i++) {
			for (int j = 0; j < ids.size(); j++) {
				if (vec[i][0] == ids[j]) {
					f = true;
					break;
				}
			}
			if (!f) {
				new_vec.push_back(vec[i]);
			}
			else {
				f = false;
			}
		}
		vec = new_vec;
	}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (Field_workers_add->SelectedRows->Count > 0) {
		std::vector<std::string> ids;
		String^ buf1;
		std::string str;

		while (Field_workers_add->SelectedRows->Count > 0) {
			buf1 = Convert::ToString(Field_workers_add->SelectedRows[0]->Cells[0]->Value);
			for each (char c in buf1) str += c;
			ids.push_back(str);
			str = "";
			Field_workers_add->Rows->RemoveAt(Field_workers_add->SelectedRows[0]->Index);
			count_add_rows--;
		}
		remove_entries(new_workers, ids);
	}
}

private: int generate_random_id() {
	std::random_device rd;	
	std::mt19937 gen(rd()); 
	std::uniform_int_distribution<> dis(100000, 999999);
	return dis(gen);
}

private: std::unordered_set<int> load_existing_ids(const std::string& filename) {
	std::unordered_set<int> ids;
	std::ifstream file(filename);
	int id;
	std::string buf_str;

	while (file >> buf_str) {
		id = std::stoi(buf_str);
		ids.insert(id);
		for (int i = 0; i < 6; ++i) {
			file >> buf_str;  
		}
	}

	file.close();
	return ids;
}

private: bool validate_team_input(const std::string& team) {
	std::string lower_team = team;
	std::transform(lower_team.begin(), lower_team.end(), lower_team.begin(), ::tolower);
	return (lower_team == "spartak" || lower_team == "dynamo");
}

private: System::String^ capitalize_team_name(System::String^ team) {
	team = team->ToLower();
	team = team->Substring(0, 1)->ToUpper() + team->Substring(1);
	return team;
}

private: System::Void add_button_Click(System::Object^ sender, System::EventArgs^ e) {
	if (surname_tb->Text == "" || monday_tb->Text == "" || tuesday_tb->Text == "" || wednesday_tb->Text == "" || thursady_tb->Text == "" || sunday_tb->Text == "") {
		MessageBox::Show("Заполните все поля");
		return;
	}
	if (!(f[0] && f[1] && f[2] && f[3] && f[4] && f[5] && f[6])) {
		MessageBox::Show("Неправильный ввод!");
		return;
	}

	String^ team_input = tuesday_tb->Text;
	std::string team_str;
	for each (char c in team_input) team_str += c;

	if (!validate_team_input(team_str)) {
		MessageBox::Show("Неправильная команда! Допускаются только 'Spartak' и 'Dynamo' в любом регистре.");
		return;
	}

	team_input = capitalize_team_name(team_input);

	std::unordered_set<int> existing_spartak_ids = load_existing_ids("spartakInput.txt");
	std::unordered_set<int> existing_dynamo_ids = load_existing_ids("dynamoInput.txt");
	std::unordered_set<int> existing_ids = existing_spartak_ids;
	existing_ids.insert(existing_dynamo_ids.begin(), existing_dynamo_ids.end());

	int random_id = generate_random_id();
	while (existing_ids.find(random_id) != existing_ids.end()) {
		random_id = generate_random_id();
	}

	std::vector<std::string> worker;
	std::string str;

	worker.push_back(std::to_string(random_id));

	String^ buf;
	buf = surname_tb->Text;
	for each (char c in buf) str += c;
	worker.push_back(str); str = "";

	buf = monday_tb->Text;
	for each (char c in buf) str += c;
	worker.push_back(str); str = "";

	buf = team_input;
	for each (char c in buf) str += c;
	worker.push_back(str); str = "";

	buf = wednesday_tb->Text;
	for each (char c in buf) str += c;
	worker.push_back(str); str = "";

	buf = thursady_tb->Text;
	for each (char c in buf) str += c;
	worker.push_back(str); str = "";

	buf = sunday_tb->Text;
	for each (char c in buf) str += c;
	worker.push_back(str); str = "";
	new_workers.push_back(worker);

	surname_tb->Text = "";
	monday_tb->Text = "";
	tuesday_tb->Text = "";
	wednesday_tb->Text = "";
	thursady_tb->Text = "";
	sunday_tb->Text = "";
	count_add_rows += 1;
	Field_workers_add->RowCount = count_add_rows;
	for (int i = 0; i < worker.size(); i++) {
		buf = gcnew String(worker[i].c_str());
		this->Field_workers_add->Rows[count_add_rows - 2]->Cells[i]->Value = buf;
	}
}

	private: System::Void cancel_button_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void ready_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (new_workers.empty()) {
			MessageBox::Show("Нет новых сотрудников для добавления.");
			return;
		}

		std::ofstream spartakFile("spartakInput.txt", std::ios::app);
		std::ofstream dynamoFile("dynamoInput.txt", std::ios::app);

		for (const auto& worker : new_workers) {
			std::string team = worker[3];
			std::string team_lower = team; 

			std::transform(team_lower.begin(), team_lower.end(), team_lower.begin(), ::tolower);

			std::ofstream* targetFile = nullptr;

			if (team_lower == "spartak") {
				targetFile = &spartakFile;
			}
			else if (team_lower == "dynamo") {
				targetFile = &dynamoFile;
			}

			if (targetFile) {
				for (const auto& field : worker) {
					*targetFile << field << " ";
				}
				*targetFile << "\n";
			}
		}

		spartakFile.close();
		dynamoFile.close();

		MessageBox::Show("Данные успешно добавлены.");
		this->Close();
	}


	private: bool validate_team_input(String^ team) {
		String^ lower_team = team->ToLower();
		return (lower_team == "spartak" || lower_team == "dynamo");
	}

	private: System::Void surname_tb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	validate_text_input(surname_tb, sur_l, L"Неверный ввод! Допускаются символы от a до z и от A до Z.", 0, true);
	}

	private: System::Void monday_tb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		validate_text_input(monday_tb, mon_l, L"Неверный ввод! Допускаются символы от a до z и от A до Z.", 1, true);
	}

	private: System::Void tuesday_tb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		validate_text_input(tuesday_tb, tue_l, L"Неверный ввод! Допускаются символы от a до z и от A до Z.", 2, true);
	}

	private: System::Void wednesday_tb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		validate_text_input(wednesday_tb, wed_l, L"Неверный ввод! Допускаются символы от 0 до 9.", 3, false);
	}

	private: System::Void thursady_tb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		validate_text_input(thursady_tb, thu_l, L"Неверный ввод! Допускаются символы от 0 до 9.", 4, false);
	}

	private: System::Void sunday_tb_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		validate_text_input(sunday_tb, sat_l, L"Неверный ввод! Допускаются символы от 0 до 9.", 6, false);
	}

	private: void validate_text_input(System::Windows::Forms::TextBox^ tb, System::Windows::Forms::Label^ lbl, String^ errorMsg, int index, bool isAlpha) {
		lbl->Text = "";
		String^ str_buf = tb->Text;
		f[index] = true; 

		for each (char c in str_buf) {
			if (isAlpha) {
				if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))) {
					f[index] = false;
					lbl->Text = errorMsg;
					break;
				}
			}
			else {
				if (!(c >= '0' && c <= '9')) {
					f[index] = false;
					lbl->Text = errorMsg;
					break;
				}
			}
		}
	}

};
}
