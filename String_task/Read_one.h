#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
 
std::vector<std::vector<std::string>> workers_1; // ID Surname All_prod Day_prod
std::vector<std::string> most_prod;

namespace Stringtask {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Read_one
	/// </summary>
	public ref class Read_one : public System::Windows::Forms::Form
	{
	public:
		Read_one(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			int all_prod; int today_prod;
			int all_prod_max = 0;
			std::string day_m_p;
			std::ifstream file("input.txt");
			std::string buf_str;
			while (file >> buf_str) {
				std::vector<std::string> buf;
				buf.push_back(buf_str);

				all_prod = 0; today_prod = 0;
				for (int i = 0; i < 7; i++) {
					if (i == 0) {
						file >> buf_str;
						buf.push_back(buf_str);
					}
					else {
						file >> buf_str;
						all_prod += stoi(buf_str);
						if (stoi(buf_str) > today_prod) {
							today_prod = stoi(buf_str);
							switch (i - 1) {
							case 0: day_m_p = "Пн"; break;
							case 1: day_m_p = "Вт"; break;
							case 2: day_m_p = "Ср"; break;
							case 3: day_m_p = "ЧТ"; break;
							case 4: day_m_p = "Пт"; break;
							case 5: day_m_p = "Сб"; break;
							}
						}
					}
				}
				
				buf.push_back(std::to_string(all_prod));
				buf.push_back(day_m_p);
				if (all_prod > all_prod_max) {
					all_prod_max = all_prod;
					most_prod = buf;
				}

				workers_1.push_back(buf);
			}

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Read_one()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::CheckBox^ check_id;
	private: System::Windows::Forms::CheckBox^ check_surname;
	protected:

	protected:

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::TextBox^ get_info;

	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;







	private: System::Windows::Forms::Button^ button1;





	private: System::Windows::Forms::Button^ most_prod_button;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ id_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ surname_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ all_prod_column;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ most_prod_day_columnus;


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
			this->check_id = (gcnew System::Windows::Forms::CheckBox());
			this->check_surname = (gcnew System::Windows::Forms::CheckBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->id_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->surname_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->all_prod_column = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->most_prod_day_columnus = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->get_info = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->most_prod_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// check_id
			// 
			this->check_id->AutoSize = true;
			this->check_id->Location = System::Drawing::Point(6, 21);
			this->check_id->Name = L"check_id";
			this->check_id->Size = System::Drawing::Size(112, 20);
			this->check_id->TabIndex = 0;
			this->check_id->Text = L"Чтение по ID";
			this->check_id->UseVisualStyleBackColor = true;
			// 
			// check_surname
			// 
			this->check_surname->AutoSize = true;
			this->check_surname->Location = System::Drawing::Point(6, 47);
			this->check_surname->Name = L"check_surname";
			this->check_surname->Size = System::Drawing::Size(159, 20);
			this->check_surname->TabIndex = 1;
			this->check_surname->Text = L"Чтение по фамилии";
			this->check_surname->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->id_column,
					this->surname_column, this->all_prod_column, this->most_prod_day_columnus
			});
			this->dataGridView1->Location = System::Drawing::Point(6, 21);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(805, 203);
			this->dataGridView1->TabIndex = 2;
			// 
			// id_column
			// 
			this->id_column->HeaderText = L"ID";
			this->id_column->MinimumWidth = 6;
			this->id_column->Name = L"id_column";
			this->id_column->ReadOnly = true;
			this->id_column->Width = 125;
			// 
			// surname_column
			// 
			this->surname_column->HeaderText = L"Фамилия";
			this->surname_column->MinimumWidth = 6;
			this->surname_column->Name = L"surname_column";
			this->surname_column->ReadOnly = true;
			this->surname_column->Width = 125;
			// 
			// all_prod_column
			// 
			this->all_prod_column->HeaderText = L"Общее кол-во изделий";
			this->all_prod_column->MinimumWidth = 6;
			this->all_prod_column->Name = L"all_prod_column";
			this->all_prod_column->ReadOnly = true;
			this->all_prod_column->Width = 125;
			// 
			// most_prod_day_columnus
			// 
			this->most_prod_day_columnus->HeaderText = L"Самый продуктивный день";
			this->most_prod_day_columnus->MinimumWidth = 6;
			this->most_prod_day_columnus->Name = L"most_prod_day_columnus";
			this->most_prod_day_columnus->ReadOnly = true;
			this->most_prod_day_columnus->Width = 125;
			// 
			// get_info
			// 
			this->get_info->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->get_info->Location = System::Drawing::Point(183, 21);
			this->get_info->Multiline = true;
			this->get_info->Name = L"get_info";
			this->get_info->Size = System::Drawing::Size(622, 48);
			this->get_info->TabIndex = 3;
			this->get_info->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->dataGridView1);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(817, 230);
			this->groupBox1->TabIndex = 4;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Таблица";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->check_id);
			this->groupBox2->Controls->Add(this->get_info);
			this->groupBox2->Controls->Add(this->check_surname);
			this->groupBox2->Location = System::Drawing::Point(12, 248);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(811, 80);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Чтение";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(672, 391);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(145, 39);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Выполнить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Read_one::button1_Click);
			// 
			// most_prod_button
			// 
			this->most_prod_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->most_prod_button->Location = System::Drawing::Point(18, 391);
			this->most_prod_button->Name = L"most_prod_button";
			this->most_prod_button->Size = System::Drawing::Size(250, 39);
			this->most_prod_button->TabIndex = 6;
			this->most_prod_button->Text = L"Самый продуктивный";
			this->most_prod_button->UseVisualStyleBackColor = true;
			this->most_prod_button->Click += gcnew System::EventHandler(this, &Read_one::most_prod_button_Click);
			// 
			// Read_one
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(841, 442);
			this->Controls->Add(this->most_prod_button);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Read_one";
			this->Text = L"Прочитать одного";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion


private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if ((check_id->Checked || check_surname->Checked) && ((!check_id->Checked && check_surname->Checked) || (check_id->Checked && !check_surname->Checked))){
		std::vector<std::string> worke; bool f = false;
		if (check_id->Checked) {
			String^ buf = get_info->Text;
			std::string buf_str;
			for each (char c in buf) {
				buf_str += c;
			}

			dataGridView1->RowCount = 2;
			for (std::vector<std::string> worker : workers_1) {
				if (worker[0] == buf_str) {
					this->dataGridView1->Rows[0]->Cells[0]->Value = gcnew String(worker[0].c_str());
					this->dataGridView1->Rows[0]->Cells[1]->Value = gcnew String(worker[1].c_str());
					this->dataGridView1->Rows[0]->Cells[2]->Value = gcnew String(worker[2].c_str());
					this->dataGridView1->Rows[0]->Cells[3]->Value = gcnew String(worker[3].c_str());

					f = true;
					break;
				}
			}
			if (!f) MessageBox::Show("Рабочего с таким ID не существует!");
		}
		else {
			String^ buf = get_info->Text;
			std::string buf_str;
			for each (char c in buf) {
				buf_str += c;
			}
			int count_row = 1;
			dataGridView1->RowCount = count_row;
			for (std::vector<std::string> worker : workers_1) {
				if (worker[1] == buf_str) {
					count_row++;
					dataGridView1->RowCount = count_row;
					this->dataGridView1->Rows[count_row-2]->Cells[0]->Value = gcnew String(worker[0].c_str());
					this->dataGridView1->Rows[count_row-2]->Cells[1]->Value = gcnew String(worker[1].c_str());
					this->dataGridView1->Rows[count_row-2]->Cells[2]->Value = gcnew String(worker[2].c_str());
					this->dataGridView1->Rows[count_row-2]->Cells[3]->Value = gcnew String(worker[3].c_str());
					f = true;
				}
			}
		}

	}
	else {
		MessageBox::Show("Выберете по какому полю хотите считать!");
	}
}
	private: System::Void most_prod_button_Click(System::Object^ sender, System::EventArgs^ e) {
		dataGridView1->RowCount = 2;
		this->dataGridView1->Rows[0]->Cells[0]->Value = gcnew String(most_prod[0].c_str());
		this->dataGridView1->Rows[0]->Cells[1]->Value = gcnew String(most_prod[1].c_str());
		this->dataGridView1->Rows[0]->Cells[2]->Value = gcnew String(most_prod[2].c_str());
		this->dataGridView1->Rows[0]->Cells[3]->Value = gcnew String(most_prod[3].c_str());
	}
};
}
