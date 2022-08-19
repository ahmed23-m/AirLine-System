#include "Seat.h"
#include <io.h>

void Seat::BookSeat(String^ F_N,String^ S_N,String^ T_N){
	StreamWriter^ sd = gcnew StreamWriter(gcnew FileStream("Data/Flights_data/" + F_N + ".txt", FileMode::Append, FileAccess::Write, FileShare::None));
	sd->Write("#" + S_N + "\t->\t" + T_N + "\t" + Passenger::ID + "\t" + Passenger::FirstName + " " + Passenger::LastName + "\t" + Passenger::Class + "\t" + 5 + "\t" + Passenger::Phone + "\t" + Passenger::Age + "\n");
	sd->Close();
}

