#pragma once
using namespace System;
ref class Luggage
{
public:
	void SetLuggage(String^ lug1, String^ lug2);
	int getlug();
	int getEx_lug();
	int getSum();
private:
static	int lug;
static	int Ex_lug;
};

