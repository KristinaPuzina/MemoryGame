#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main()
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	MemorySimulator::MyForm form;
	Application::Run(% form);
}