#pragma once
#include "Date.h"
#include <string>

struct Booking
{
	static std::string file;
	const static int MAX_ID = 500;

	Booking* next;
	Booking* previous;

	int id;
	std::string bookingTxtInfo;
	int roomID;
	int clientID;
	Date bookedStartDate;
	Date bookedEndDate;

	Booking(std::string bookingInfo);
	Booking();

	static void showAllBookings();
	void showElement();
	static void showBookingsInAPeriodOfTime(Date begin, Date end);
	
	static void addElementToTxtFile(std::string info);
	void addBooking();
	void addElementToList(std::string info);

	static int generateBookingID();
	static void readListFromFile();

	static void deleteBooking(int ID);
	static void deallocateBookings();
};