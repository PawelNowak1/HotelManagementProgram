// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Reader.h"
#include "UserInput.h"

int main(int argc, char* argv[])
{
	std::string bookingsFile;
	std::string clientsFile;
	std::string roomsFile;
	if (argc == 4)
	{
		bookingsFile = argv[1];
		clientsFile = argv[2];
		roomsFile = argv[3];
	}
	else
	{
		bookingsFile = "bookings.txt";
		clientsFile = "clients.txt";
		roomsFile = "rooms.txt";
	}

	bool applicationStatus = true;
	
	readRoomsData(roomsFile);
	readClientsData(clientsFile);
	readBookingsData(bookingsFile);
	
	while (applicationStatus)
	{
		applicationStatus = getUserInput();
	}
	
    return 0;
}

