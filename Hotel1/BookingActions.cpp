#include "BookingActions.h"
#include "stdafx.h"
#include "Room.h"
#include "Client.h"
#include <iostream>

void addBookingManually()
{
	const bool showIDsBeforeMakingAChoice = false;
	std::string bookingInfo = "";
	std::string inputData;

	bookingInfo = std::to_string(Booking::generateBookingID()) + ';';
	std::cout << "\nWproawdz nastepujace parametry: ";
	if (showIDsBeforeMakingAChoice)
		Room::head->showAllRooms();
	std::cout << "\nID pokoju: ";
	std::cin >> inputData;
	bookingInfo += inputData + ';';
	if (showIDsBeforeMakingAChoice)
		Client::head->showAllClients();
	std::cout << "\nID klienta: ";
	std::cin >> inputData;
	bookingInfo += inputData + ';';
	std::cout << "\nPoczatek rezerwacji:\nDzien: ";
	std::cin >> inputData;
	bookingInfo += inputData + ';';
	std::cout << "\nMiesiac: ";
	std::cin >> inputData;
	bookingInfo += inputData + ';';
	std::cout << "\nRok: ";
	std::cin >> inputData;
	bookingInfo += inputData + ';';

	std::cout << "\Koniec rezerwacji:\nDzien: ";
	std::cin >> inputData;
	bookingInfo += inputData + ';';
	std::cout << "\nMiesiac: ";
	std::cin >> inputData;
	bookingInfo += inputData + ';';
	std::cout << "\nRok: ";
	std::cin >> inputData;
	bookingInfo += inputData + ';';

	Booking* newBooking = new Booking(bookingInfo);
	newBooking->addBooking();
	Booking::addElementToTxtFile(bookingInfo);
}

void deleteBooking()
{
	std::cout << "\n\n";
	Booking::showAllBookings();
	std::cout << "\nPodaj ID rezerwacji do usuniecia: ";
	int id;
	std::cin >> id;
	Booking::deleteBooking(id);
	std::cout << "\nElement Usunieto\n";
}

void showBookings()
{
	Booking::showAllBookings();
}

void showBookingsInAPeriodOfTime()
{
	Date beginDate, endDate;
	std::cout << "\nWpisz date poczatkowa:";
	beginDate.initDate();
	std::cout << "\nWpisz date koncowa:";
	endDate.initDate();

	Booking::showBookingsInAPeriodOfTime(beginDate, endDate);
}

void deallocateBookings()
{
	Booking::deallocateBookings();
}