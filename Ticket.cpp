#include "Ticket.h"
#include<io.h>
void Ticket::SetTickets(String^ B_D, String^ R_N, String^ S_N, String^ Expiry_Date){
	Tickets += "\r\t\t\t\t\tB_D:" + B_D + "\r\n\t\t\t\t\tName:" + Passenger::FirstName + " " + Passenger::LastName + "\r\n\n\nT_N:" + T_N + "\r\nR_N:" + R_N + "\r\nS_N:" + S_N + "\r\nFrom/To\tFlight\tCL\tDate\t\t\tNVA\t\t\t\tLUG\tST\r\n" + f.GetDeparture() + "\t" + f.GetF_n() + "\t" +Passenger::Class + "\t" + f.GetDate() + "\t" + Expiry_Date + "\t" + Ticket::getSum() + "\tOK\r\ngate:" + G_N1 + "\r\n" + f.GetDestination() + "\r\ngate:" + G_N2 + "\r\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\r\n\n";

};

void Ticket::BookTicket(String^ ID) {
		StreamWriter^ UT = gcnew StreamWriter(gcnew FileStream(("Data/Users_data/" + ID + ".txt"), FileMode::Append, FileAccess::Write, FileShare::None));
		StreamWriter^ WordFile = gcnew StreamWriter(gcnew FileStream(("Data/Users_data/" + ID + ".docx"), FileMode::Append, FileAccess::Write, FileShare::None));
		UT->Write(Tickets);
		UT->Close();
		WordFile->Write(Tickets);
		WordFile->Close();
}

void Ticket::SetSeatnum(String^ S_N)
{
	SeatNum = S_N;
}

String^ Ticket::GetSeatnum()
{
	return SeatNum;
}
void Ticket::SetTicketnum(String^ S_N)
{
	TicketNum = S_N;
}

String^ Ticket::GetTicketnum()
{
	return TicketNum;
}
void Ticket::SetReservationNum(String^ R_N)
{
	ReservationNum = R_N;
}

String^ Ticket::GetReservationNum()
{
	return ReservationNum;
}
void Ticket::setPassenger(String^ FN, String^ LN, String^ id, String^ Cls, String^ phone, String^ age)
{
	Passenger::FirstName = FN;
	Passenger::LastName = LN;
	Passenger::ID = id;
	Passenger::Class = Cls;
	Passenger::Phone = phone;
	Passenger::Age = age;
}
