#include "stdafx.h"
#include "Booking.h"
#include "Room.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

std::string Booking::file = "";

int getRoomIDFromTxt(std::string bookingInfo)
{
	int dataSeperator = bookingInfo.find(';');
	int idBooking = std::stoi(bookingInfo.substr(0, dataSeperator));
	bookingInfo.erase(0, dataSeperator + 1);
	dataSeperator = bookingInfo.find(';');
	int roomId = std::stoi(bookingInfo.substr(0, dataSeperator));
	return roomId;
}

void Booking::showBookingsInAPeriodOfTime(Date begin, Date end)
{
	Room* current = Room::head->next;
	while (current != nullptr)
	{
		Booking* currentBooking = current->bookingsHead->next;
		while (currentBooking != nullptr)
		{
			if (Date::areDatesColliding(begin, end, currentBooking->bookedStartDate, currentBooking->bookedEndDate))
				currentBooking->showElement();
			currentBooking = currentBooking->next;
		}
		current = current->next;
	}
}

int Booking::generateBookingID()
{
	srand(time(NULL));
	Room* current = Room::head->next;

	int i = rand() % Booking::MAX_ID + 1;;
	while (current != nullptr)
	{
		Booking* currentBooking = current->bookingsHead->next;
		while (currentBooking != nullptr)
		{
			if (current->id == i)
			{
				current = Room::head;
				i = rand() % Room::MAX_ID + 1;
				break;
			}
			currentBooking = currentBooking->next;
		}
		current = current->next;
	}
	return i;
}

void Booking::addElementToTxtFile(std::string info)
{
	std::ofstream fileOut;
	fileOut.open(Booking::file, std::ios::app);
	fileOut << "\n" + info;
	fileOut.close();
}

void Booking::addBooking()
{
	int roomID = getRoomIDFromTxt(this->bookingTxtInfo);
	Room* room = Room::getRoom(roomID);
	Booking* current = room->bookingsHead->next;
	if (current != nullptr)
		current = current->next;
	this->next = nullptr;
	this->previous = current;
	current->next = this;
}

void updateBookingFile()
{
	std::ofstream fileOut;
	bool firstLine = true;
	fileOut.open(Booking::file, std::ios::trunc);
	Room* current = Room::head->next;

	while (current != nullptr)
	{
		Booking* currentBooking = current->bookingsHead->next;
		while (currentBooking != nullptr)
		{
			if (firstLine)
			{
				fileOut << currentBooking->bookingTxtInfo;
				firstLine = false;
			}
			else
				fileOut << "\n" << currentBooking->bookingTxtInfo;

			currentBooking = currentBooking->next;
		}
		current = current->next;
	}
}

void Booking::deleteBooking(int ID)
{
	Room* current = Room::head->next;

	while (current != nullptr)
	{
		Booking* toRemove = current->bookingsHead->next;
		while (toRemove != nullptr)
		{
			if (toRemove->id == ID)
			{
				toRemove->previous->next = toRemove->next;
				if (toRemove->next != nullptr)
					toRemove->next->previous = toRemove->previous;
				delete toRemove;
				break;
			}
			toRemove = toRemove->next;
		}
		current = current->next;
	}
	updateBookingFile();
}

void Booking::showAllBookings()
{
	Room* current = Room::head->next;

	while (current != nullptr)
	{
		Booking* currentBooking = current->bookingsHead->next;
		while (currentBooking != nullptr)
		{
			currentBooking->showElement();
			currentBooking = currentBooking->next;
		}
		current = current->next;
	}
}

void Booking::readListFromFile()
{
	std::ifstream fileIn;
	fileIn.open(file, std::ios::in);
	std::string info = "";

	Room* current;

	while (!fileIn.eof())
	{
		std::getline(fileIn, info);
		int roomId = getRoomIDFromTxt(info);
		current = Room::getRoom(roomId);
		current->bookingsHead->addElementToList(info);
	}
	fileIn.close();
}

void Booking::addElementToList(std::string info)
{
	Booking* newBooking = new Booking(info);
	Booking* current = this;
	while (current->next != nullptr)
		current = current->next;
	newBooking->next = nullptr;
	newBooking->previous = current;
	current->next = newBooking;
}


Booking::Booking(std::string bookingInfo)
{
	bookingTxtInfo = bookingInfo;
	int dataSeperator = bookingInfo.find(';');
	id = std::stoi(bookingInfo.substr(0, dataSeperator));

	bookingInfo.erase(0, dataSeperator + 1);
	dataSeperator = bookingInfo.find(';');
	roomID = std::stoi(bookingInfo.substr(0, dataSeperator));

	bookingInfo.erase(0, dataSeperator + 1);
	dataSeperator = bookingInfo.find(';');
	clientID = std::stoi(bookingInfo.substr(0, dataSeperator));

	bookingInfo.erase(0, dataSeperator + 1);
	dataSeperator = bookingInfo.find(';');
	bookedStartDate.day = std::stoi(bookingInfo.substr(0, dataSeperator));

	bookingInfo.erase(0, dataSeperator + 1);
	dataSeperator = bookingInfo.find(';');
	bookedStartDate.month = std::stoi(bookingInfo.substr(0, dataSeperator));

	bookingInfo.erase(0, dataSeperator + 1);
	dataSeperator = bookingInfo.find(';');
	bookedStartDate.year = std::stoi(bookingInfo.substr(0, dataSeperator));

	bookingInfo.erase(0, dataSeperator + 1);
	dataSeperator = bookingInfo.find(';');
	bookedEndDate.day = std::stoi(bookingInfo.substr(0, dataSeperator));

	bookingInfo.erase(0, dataSeperator + 1);
	dataSeperator = bookingInfo.find(';');
	bookedEndDate.month = std::stoi(bookingInfo.substr(0, dataSeperator));

	bookingInfo.erase(0, dataSeperator + 1);
	dataSeperator = bookingInfo.find(';');
	bookedEndDate.year = std::stoi(bookingInfo.substr(0, dataSeperator));
}

Booking::Booking()
{
	next = nullptr;
	previous = nullptr;
}


void Booking::showElement()
{
	std::cout << "\nID rezerwacji:            " << id;
	std::cout << "\nID pokoju:                " << roomID;
	std::cout << "\nID klienta:               " << clientID;
	std::cout << "\nData poczatku rezerwacji: " << bookedStartDate.day << "-" << bookedStartDate.month << "-" << bookedStartDate.year;
	std::cout << "\nData konca rezerwacji:    " << bookedEndDate.day << "-" << bookedEndDate.month << "-" << bookedEndDate.year << std::endl;
}

void Booking::deallocateBookings()
{
	Room* current = Room::head;

	while (current != nullptr)
	{
		Booking* currentBooking = current->bookingsHead;
		while (currentBooking != nullptr)
		{
			Booking* next = currentBooking->next;
			delete currentBooking;
			currentBooking = next;
		}
		current = current->next;
	} 
}