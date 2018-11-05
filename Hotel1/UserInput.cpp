#include "stdafx.h"
#include "UserInput.h"
#include <iostream>
#include <string>
#include "RoomActions.h"
#include "BookingActions.h"
#include "ClientActions.h"

int displayText()
{
	std::cout << "\nPROGRAM DO ZARZADZANIA HOTELEM\n";
	std::cout << "------------------------------\n";
	std::cout << "Wybierz opcje:\n";
	std::cout << "1. Dodaj pokoj\n";
	std::cout << "2. Dodaj rezerwacje\n";
	std::cout << "3. Dodanie Klienta\n";

	std::cout << "4. Usun pokoj\n";
	std::cout << "5. Usun rezerwacje\n";
	std::cout << "6. Usun Klineta\n";

	std::cout << "7. Wyswietlanie wszystkich pokoi\n";
	std::cout << "8. Wyswietlanie wszystkich rezerwacji\n";
	std::cout << "9. Wyswietlanie wszystkich klientow\n";

	std::cout << "10. Wyswietlanie wolnych pokoi w danym terminie\n";
	std::cout << "11. Wyswietlanie dokonanych rezerwacji danego pokoju\n";
	std::cout << "12. Wyswietlanie rezerwacji wszystkich pokoi w danym terminie\n"; 
	
	std::cout << "13. Wyjscie\n"; 
	int choice;
	std::cin >> choice;
	return choice;
}

bool handleUserChoice(int choice)
{
	enum Options
	{
		addRoom = 1, addBooking, addClient,  
		delRoom, delBooking, delClient, 
		showAllRooms, showAllBookings, showClients, 
		showAccessibleRooms, showRoomBooking, showAllBookingsInAPeriodOfTime,
		exit
	};

	Options options;

	switch (choice)
	{
	case addBooking:
		addBookingManually(); break; 
	case addClient:
		addClientManually(); break;
	case addRoom:
		addRoomManually(); break;

	case delBooking:
		deleteBooking(); break;
	case delClient:
		deleteClient(); break;
	case delRoom:
		deleteRoom(); break;

	case showClients:
		showAllClients(); break;
	case showAllBookings:
		showBookings(); break;
	case showAllRooms:
		showRooms(); break;

	case showAllBookingsInAPeriodOfTime:
		showBookingsInAPeriodOfTime(); break;
	case showAccessibleRooms:
		showAvaiableRooms(); break;
	case showRoomBooking:
		showRoomBookings(); break;
	
	case exit:
	{
		deallocateBookings();
		deallocateRooms();
		deallocateClients();
		return false;
	}
	}
	return true;
}

bool getUserInput()
{
	int choice;
	choice = displayText();
	return handleUserChoice(choice);
}
