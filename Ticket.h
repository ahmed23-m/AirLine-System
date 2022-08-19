#pragma once
#include "Luggage.h"
#include "Flight.h"
#include "Passenger.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
ref class Ticket :public Luggage, public Passenger
	{
	public:
		static String^ Tickets = "";
		void SetTickets(String^ B_D, String^ R_N, String^ S_N, String^ Expiry_Date);
		Random^ Randnum = gcnew Random();
		int^ T_N = Randnum->Next(0, 1000000);
		int^ G_N1 = Randnum->Next(1, 15);
		int^ G_N2 = Randnum->Next(1, 15);
		void BookTicket(String^ ID);
		void SetSeatnum(String^ S_N);
		String^ GetSeatnum();
		void SetTicketnum(String^ S_N);
		String^ GetTicketnum();
		void SetReservationNum(String^ R_N);
		String^ GetReservationNum();
		String^ SeatNum;
		String^ TicketNum;
		String^ ReservationNum;
		Flight f;
		DateTime^ dt = DateTime::Now;
		String^ BookDate = dt->ToString("ddd/MMMM/yy, hh:mm:ss tt");
		// Inherited via Passenger
		virtual void setPassenger(String^ FN, String^ LN, String^ id, String^ Cls, String^ phone, String^ age);
};


