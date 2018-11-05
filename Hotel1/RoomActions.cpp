#include "RoomActions.h"
#include "stdafx.h"
#include "Room.h"
#include <string>
#include <iostream>

void showRooms()
{
	Room::head->showAllRooms();
}

void showAvaiableRooms()
{
	Date beginDate, endDate;
	std::cout << "\nWpisz date poczatkowa:";
	beginDate.initDate();
	std::cout << "\nWpisz date koncowa:";
	endDate.initDate();
	
	Room::head->showAvaiableRooms(beginDate, endDate);
}

void showRoomBookings()
{
	Room::head->showAllRooms();
	std::cout << "\nPodaj ID pokoju, ktorego chcesz zobaczyc rezerwacje: ";
	int id;
	std::cin >> id;
	Room::head->showRoomBookings(id);
}

void deallocateRooms()
{
	Room::deallocateRooms();
}

void addRoomManually()
{
	std::string roomInfo = "";
	std::string inputData;

	roomInfo = std::to_string(Room::head->generateID()) + ';';
	std::cout << "\nWproawdz nastepujace parametry: ";
	std::cout << "\nCena:                   ";
	std::cin >> inputData;
	roomInfo += inputData + ';';
	std::cout << "\nPokoj nr:               ";
	std::cin >> inputData;
	roomInfo += inputData + ';';
	std::cout << "\nOpis pokoju:            ";
	std::cin.ignore();
	std::getline(std::cin, inputData);
	roomInfo += inputData + ';';
	std::cout << "\nIlosc miejsc do spania: ";
	std::cin >> inputData;
	roomInfo += inputData + ';';

	Room* newRoom = new Room(roomInfo);
	newRoom->addElement();
	newRoom->addElementToTxtFile(roomInfo);
}

void deleteRoom()
{
	std::cout << "\n\n";
	Room::head->showAllRooms();
	std::cout << "\nPodaj ID pokoju do usuniecia: ";
	int id;
	std::cin >> id;
	Room::head->deleteElement(id);
	std::cout << "\nElement Usunieto\n";
}
