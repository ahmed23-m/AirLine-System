#include "Flight.h"
#include "Plane.h"
#include <io.h>

String^ Flight::print() {
	String^ Flights="";
	StreamReader^ Flights_File = File::OpenText("Data/Flights.txt");
	int i = 1;
	while (String^ str = Flights_File->ReadLine())
	{
		if (i == 7)
		{
			str += "\r\n\n";
			i = 0;
		}
		else if (i == 6)
		{
			str += "\r\t    ";
		}
		else if (i == 1)
		{
			str += "\r\t\t";
		}
		else if (i == 5)
		{
			str += "\r\t   ";
		}else
		{
			str += "\r\t";
		}
		Flights = Flights + str;
		i++;
	}
	Flights_File->Close();
	if (Flights == "") {
		return "NO Flights :(";
	}
	else {
		return Flights;
	}
}

void Flight::Add_Flight(String^ Departure, String^ Destination, String^ price, String^ Departure_Date, String^ plane) {
	Plane n;
	StreamWriter^ sw = gcnew StreamWriter(gcnew FileStream("Data/Flights.txt", FileMode::Append, FileAccess::Write, FileShare::None));
	Random^ RandId = gcnew Random();
	int^ x = RandId->Next(0, 10000);
	StreamWriter^ sd = gcnew StreamWriter(gcnew FileStream("Data/Flights_data/" + x->ToString() + ".txt", FileMode::Append, FileAccess::Write, FileShare::None));
	sw->Write("#" + x + "\n" + Departure + "\n" + Destination + "\n" + Departure_Date + "\n" + price + "\n" + plane + "\n"+n.GetN_O_S(plane));
	sw->Close();
	sd->Close();
};

String^ Flight::Search(String^ from, String^ to, String^ date) {

	int linenum = 0, nLine = 0;
	StreamReader^ din = File::OpenText("Data/Flights.txt");
	while (String^ line = din->ReadLine())
	{
		if (line == from)
		{
			linenum++;
			if (din->ReadLine() == to)
			{
				linenum++;
				if (din->ReadLine() == date)
				{
					StreamReader^ lin = File::OpenText("Data/Flights.txt");
					while (String^ line = lin->ReadLine())
					{
						if (nLine == linenum - 3)
						{
							for (int i = 0; i < 4; i++) {
								line += "\r\t" + lin->ReadLine();
							}
							return line;
						}
						nLine++;
					}
					lin->Close();
				}
			}
		}
		linenum++;
	}
	din->Close();
	return "We are unable to find recommendations for your search.\r\n\nPlease change your search criteria and resubmit the search.";
}

String^ Flight::Search(String^ F_N) {
	bool isfound = false;
	String^ info = "";
	StreamReader^ din = File::OpenText("Data/Flights.txt");
	while (String^ id = din->ReadLine())
	{
		if (id == "#" + F_N)
		{
			F_n = F_N;
			isfound = true;
			for (int i = 0; i < 6; i++)
			{
				id = din->ReadLine();
				info += (id + "\r\t     ");
				switch (i)
				{
				case 0:
					Departure = id;
					break;
				case 1:
					Destination = id;
					break;
				case 2:
					Date = id;
					break;
				case 3:
					Price = id;
					break;
				case 4:
					plane = id;
				case 5:
					AvailableTickets = id;
					break;
				}
			}
		}
	}
	din->Close();
	if (isfound == false) {
		return "Not Found :(";
	}
	else {
		return info;
	}
}

void Flight::Delete_flight(String^ F_N) {
	StreamReader^ din = File::OpenText("Data/Flights.txt");
	StreamWriter^ pin = gcnew StreamWriter(gcnew FileStream("Data/pin.txt", FileMode::Append, FileAccess::Write, FileShare::None));
	while (String^ id = din->ReadLine())
	{
		if (id == "#"+F_N)
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
	//--remove && rename File--//
	String^ str = "Data/Flights_data/" + F_N + ".txt";
	IntPtr p = Marshal::StringToHGlobalAnsi(str);
	const char* pAnsi = static_cast<const char*>(p.ToPointer());
	remove(pAnsi);
	Marshal::FreeHGlobal(p);
	remove("Data/Flights.txt");
	rename("Data/pin.txt", "Data/Flights.txt");
}

String^ Flight::GetF_n(){
	return F_n;
};
String^ Flight::GetDeparture(){
	return Departure;
};
String^ Flight::GetDestination(){
	return Destination;
};
String^ Flight::GetDate(){
	return Date;
};
int Flight::GetPrice(){
	int P = System::Convert::ToInt32(Price);
	return P;
};
int Flight::GetAvailableTickets() {
	//AvailableTickets = "100";///?
	int P = System::Convert::ToInt32(AvailableTickets);
	return P;
};

void Flight::IncreaseORDecrease(String^ F_N) {
	Plane n;
	int x = 0;
	StreamWriter^ pin = gcnew StreamWriter(gcnew FileStream("Data/pin.txt", FileMode::Append, FileAccess::Write, FileShare::None));
	StreamReader^ din = File::OpenText("Data/Flights_data/" + F_N + ".txt");
	while (String^ id = din->ReadLine())
	{
		x++;
	}
	din->Close();
	int p=n.GetN_O_S(plane);
	//
	StreamReader^ fin = File::OpenText("Data/Flights.txt");
	while (String^ id = fin->ReadLine())
	{
		if (id == "#" + F_N)
		{
			pin->Write(id + "\n");
			for (int i = 0; i < 5; i++) {
				pin->Write(fin->ReadLine()+"\n");
			}
			fin->ReadLine();
			pin->Write(System::Convert::ToString(p));
		}
		else {
			pin->Write(id+"\n");
		}
	}
	pin->Close();
	fin->Close();
	remove("Data/Flights.txt");
	rename("Data/pin.txt", "Data/Flights.txt");
}

String^ Flight::print(String^ F_N) {
	String^ info = "";
	StreamReader^ din = File::OpenText("Data/Flights_data/" + F_N + ".txt");
	while (String^ id = din->ReadLine())
	{
		info += id + "\r\n";
	}
	return info;
}