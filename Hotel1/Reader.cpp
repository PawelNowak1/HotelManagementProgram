#include "stdafx.h"
#include "Reader.h"
#include "Room.h"
#include "Client.h"
#include "Booking.h"

void readRoomsData(const std::string roomsFile)
{
	Room* roomHead = new Room;
	Room::head = roomHead;
	Room::file = roomsFile;
	Room::readListFromFile();
}

void readClientsData(const std::string clientsFile)
{
	Client* clientHead = new Client;
	Client::head = clientHead;
	Client::file = clientsFile;
	Client::readListFromFile();
}

void readBookingsData(const std::string bookingsFile)
{
	Booking::file = bookingsFile;
	Booking::readListFromFile();
}
