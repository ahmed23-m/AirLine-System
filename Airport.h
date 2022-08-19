#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
ref class Airport
{
public:
    void SetAirPortDetails(String^ code, String^ Name, String^ Address);
    String^ print();
    String^ Search(String^ Id);
    void Delete_airport(String^ ID);
};