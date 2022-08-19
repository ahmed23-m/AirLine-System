#include "Reservation.h"
#include "Passenger.h"
#include "Ticket.h"
#include <io.h>
#include <string>//--To Convert System::String to const char*--//
using namespace::System;//
using namespace System::Runtime::InteropServices;//

bool Reservation::CheckFlightNumber(String^ ID, String^ F_N, String^ T_N) {
	bool isfound = false;
	Ticket t;
	StreamReader^ acc = File::OpenText(("Data/Users_data/" + ID + ".txt"));
	while (String^ id = acc->ReadLine())
	{
		if (id == "T_N:" + T_N)//
		{
			acc->ReadLine();
			S_N = acc->ReadLine();
			//split sn
			array<String^>^ StringArray = S_N->Split(':');
			t.SetSeatnum(StringArray[1]);//
			S_N = StringArray[1];
			break;
		}
	}
	StreamReader^ din = File::OpenText("Data/Flights.txt");
	while (String^ str = din->ReadLine()) {
		if (str == "#" + F_N)
		{
			isfound = true;
			break;
		}
		//isfound = false;
	}
	isfound = true;/////
	din->Close();
	if (isfound) {
		StreamReader^ fin = File::OpenText("Data/Flights_data/" + F_N + ".txt");
		isfound = false; 
		
		while (String^ str = fin->ReadLine()) {
			array<String^>^ StringArray = str->Split('-');
			if (StringArray[0] == "#"+t.GetSeatnum())
			{
				return true;
			}
		}
		fin->Close();
	}
	else
	{
		return false;
	}
}
void Reservation::DELETE_RESERVATION(String^ ID, String^ R_N, String^ T_N, String^ F_N)
{
	//----- Delete From User File -----//
	{
		int nline = 0;
		int linenum = 0;
		StreamReader^ din2 = File::OpenText("Data/Users_data/" + ID + ".txt");
		StreamWriter^ pin2 = gcnew StreamWriter(gcnew FileStream("Data/Users_data/temp.txt", FileMode::Append, FileAccess::Write, FileShare::None));
		while (String^ line = din2->ReadLine())
		{
			if (line == "T_N:" + T_N)
			{
				break;
			}
			linenum++;
		}
		din2->Close();
		StreamReader^ din3 = File::OpenText("Data/Users_data/" + ID + ".txt");
		while (String^ line = din3->ReadLine())
		{
			if (nline == linenum - 4)
			{
				for (int i = 0; i < linenum + 9; i++)
				{
					din3->ReadLine();
				}
			}
			else
			{
				pin2->Write(line + "\n");
			}
			nline++;
		}
		din3->Close();
		pin2->Close();
		//--remove && rename File--//
		String^ str = "Data/Users_data/" + ID + ".txt";
		IntPtr p = Marshal::StringToHGlobalAnsi(str);
		const char* pAnsi = static_cast<const char*>(p.ToPointer());
		Marshal::FreeHGlobal(p);
		rename("Data/Users_data/temp.txt", pAnsi);
		remove(pAnsi);
	}
	//----- Delete From Flights File -----//
	{
		StreamReader^ Gin = File::OpenText("Data/Flights_data/" + F_N + ".txt");
		StreamWriter^ Pin = gcnew StreamWriter(gcnew FileStream("Data/Flights_data/pin.txt", FileMode::Append, FileAccess::Write, FileShare::None));
		while (String^ line = Gin->ReadLine())
		{
			array<String^>^ StringArray = line->Split('-');
			if (StringArray[0] ==  "#"+S_N)
			{

			}
			else {
				Pin->Write(line + "\n");
			}
		}
		Gin->Close();
		Pin->Close();
		//--remove && rename File--//
		String^ str2 = "Data/Flights_data/" + F_N + ".txt";
		IntPtr p2 = Marshal::StringToHGlobalAnsi(str2);
		const char* pAnsi2 = static_cast<const char*>(p2.ToPointer());
		remove(pAnsi2);
		Marshal::FreeHGlobal(p2);
		rename("Data/Flights_data/pin.txt", pAnsi2);
	}
}
//----------------------------------------------------------------------------//
void Reservation::Delete_reservation(String^ F_N) {
	StreamReader^ Gin = File::OpenText("Data/Flights_data/" + F_N + ".txt");
	StreamWriter^ pin = gcnew StreamWriter(gcnew FileStream("Data/Users_data/pin.txt", FileMode::Append, FileAccess::Write, FileShare::None));
	while (String^ str = Gin->ReadLine()) {
		if (str == S_N)
		{
			continue;
		}
		else
		{
			pin->Write(Gin->ReadLine() + "\n");
		}
	}
	Gin->Close();
	pin->Close();
	//--remove && rename File--//
	String^ str = "Data/Flights_data/" + F_N + ".txt";
	IntPtr p = Marshal::StringToHGlobalAnsi(str);
	const char* pAnsi = static_cast<const char*>(p.ToPointer());
	Marshal::FreeHGlobal(p);
	remove(pAnsi);
	rename("Data/Users_data/pin.txt", pAnsi);
}
void Reservation::Delete_Reservation(String^ ID, String^ T_N) {
	StreamReader^ din = File::OpenText(("Data/Users_data/" + ID + ".txt"));
	StreamWriter^ pin = gcnew StreamWriter(gcnew FileStream("Data/Users_data/pin.txt", FileMode::Append, FileAccess::Write, FileShare::None));
	unsigned int lnum = 0;
	unsigned int lnum2 = 0;
	while (String^ id = din->ReadLine())
	{
		if (id == "T_N:"+T_N)
		{
			din->Close();
			StreamReader^ fin = File::OpenText(("Data/Users_data/" + ID + ".txt"));
			while (String^ id = fin->ReadLine()) {
				if (lnum2 == (lnum - 5))
				{
					for (int i = 0; i < 15; i++)
					{
						fin->ReadLine();
					}
				}
				else
				{
					pin->Write(id + "\n");
				}
				lnum2++;
			}	
			fin->Close();
			break;
		}
		lnum++;
	}
	pin->Close();
	//--remove && rename File--//
	String^ str = "Data/Users_data/" + ID + ".txt";
	IntPtr p = Marshal::StringToHGlobalAnsi(str);
	const char* pAnsi = static_cast<const char*>(p.ToPointer());
	Marshal::FreeHGlobal(p);
	remove(pAnsi);
	rename("Data/Users_data/pin.txt", pAnsi);
}
void Reservation::Delete_Reservation(String^ R_N) {
	StreamReader^ din = File::OpenText("Data/Reservations.txt");
	StreamWriter^ pin = gcnew StreamWriter(gcnew FileStream("Data/pin.txt", FileMode::Append, FileAccess::Write, FileShare::None));
	while (String^ id = din->ReadLine())
	{
		if (id == R_N)
		{
			for (int i = 0; i < 6; i++)
			{
				din->ReadLine();
			}
		}
		else
		{
			pin->Write(id + "\n");
		}
	}
	pin->Close();
	din->Close();
	remove("Data/Reservations.txt");
	rename("Data/pin.txt", "Data/Reservations.txt");
}
String^ Reservation::search(String^ ID, String^ T_N) {
	StreamReader^ din = File::OpenText(("Data/Users_data/" + ID + ".txt"));
	String^ info = "";
	bool isfound = false;
	unsigned int lnum = 0;
	unsigned int lnum2 = 0;
	while (String^ id = din->ReadLine())
	{
		if (id == "T_N:" + T_N)
		{
			isfound = true;
			din->Close();
			StreamReader^ fin = File::OpenText(("Data/Users_data/" + ID + ".txt"));
			while (String^ id = fin->ReadLine()) {
				if ((lnum2)== (lnum - 5))
				{
					for (int i = 0; i < 12; i++)
					{
						info += fin->ReadLine() + "\r\n";
					}
					fin->Close();
					break;
				}
				lnum2++;
			}
			break;
		}
		lnum++;
	}
	if (isfound == false) {
		return "Not Found :(";
	}
	return info;
}

String^ Reservation::search(String^ R_N) {
	bool isfound = false;
	String^ info = "";
	StreamReader^ din = File::OpenText("Data/Reservations.txt");
	while (String^ id = din->ReadLine())
	{
		if (id == "#" + R_N)
		{
			isfound = true;
			for (int i = 0; i < 6; i++)
			{
				info += (din->ReadLine() + "\r\t  ");
			}
		}
	}
	din->Close();
	if (isfound == false) {
		return "Not Found :(";
	}
	return info;
}



String^ Reservation::print() {
	String^ Reservations = "";
	StreamReader^ din = File::OpenText("Data/Reservations.txt");
	int i = 1;
	while (String^ str = din->ReadLine())
	{
		if (i == 1 )
		{
			str += "\r\t";
		}
		if (i == 7)
		{
			str += "\r\n\n";
			i = 0;
		}
		else
		{
			str += "\t";
		}
		Reservations = Reservations + str;
		i++;
	}
	din->Close();
	if (Reservations == "") {
		return "NO Reservations :(";
	}
	else {
		return Reservations;
	}
}

String^ Reservation::print(String^ ID) {
	String^ Reservations="";
	String^ Path = "Data/Users_data/" + ID + ".txt";
	if (File::Exists(Path))
	{
		StreamReader^ din = File::OpenText(Path);
		while (String^ str = din->ReadLine())
		{
			Reservations += str + "\r\n";
		}
			din->Close();
		if (Reservations == "") {
			return "NO TICKETS :(";
		}
		else {
			return Reservations;
		}
	}
	else
	{
		return "NO TICKETS :(";
	}
}