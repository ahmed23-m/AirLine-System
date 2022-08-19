#pragma once
#include <string>//--To Convert System::String to const char*--//
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Runtime::InteropServices;
ref class Flight
{
public:
    void  Delete_flight(String^ F_N);
    String^ Search(String^ F_N);
    String^ Search(String^ from, String^ to, String^ date);
    String^ print();
    void Add_Flight(String^ Departure, String^ Destination, String^ price, String^ Departure_Date, String^ plane );
    String^ GetF_n();
    String^ GetDeparture();
    String^ GetDestination();
    String^ GetDate();
    String^ print(String^ F_N);
    void Flight::IncreaseORDecrease(String^ F_N);
    int GetAvailableTickets();
    int GetPrice();
private:
   static String^ F_n;
   static String^ Departure;
   static String^ Destination;
   static String^ Date;
   static String^ Price;
   static String^ AvailableTickets;
   static String^ plane;

};