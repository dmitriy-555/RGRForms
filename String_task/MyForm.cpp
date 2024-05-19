#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]

int main(array<String^>^ arg) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Stringtask::MyForm form;
	Application::Run(% form);	

}