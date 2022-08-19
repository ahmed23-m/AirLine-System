#pragma once
#include "Ticket.h"
using namespace System;
using namespace System::IO;
ref class Seat	:public Ticket
{
public:
	void BookSeat(String^ F_N,String^ S_N,String^ T_N);
};

