#pragma once
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
ref class Reservation
{
public:
	String^ print(String^ ID);
	String^ print();
	void DELETE_RESERVATION(String^ ID,String^ R_N,String^ T_N,String^F_N);
	void Delete_reservation(String^ F_N);
	void Delete_Reservation(String^ R_N);
	void Delete_Reservation(String^ ID, String^ T_N);
	bool CheckFlightNumber(String^ ID, String^ F_N, String^ T_N);
	String^ search(String^ R_N);
	String^ search(String^ ID, String^ T_N);
private:
	String^ S_N;
};

