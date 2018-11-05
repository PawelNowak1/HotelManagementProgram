#include "stdafx.h"
#include "Room.h"
#include <iostream>
#include <fstream>
#include "Booking.h"
#include <stdlib.h>
#include <time.h>


Room* Room::head = nullptr;
std::string Room::file = "";

Room::Room(std::string roomInfo)
{
	this->roomTxtInfo = roomInfo;
	int dataSeperator = roomInfo.find(';');
	id = std::stoi(roomInfo.substr(0, dataSeperator));

	roomInfo.erase(0, dataSeperator + 1);
	dataSeperator = roomInfo.find(';');
	this->price = std::stod(roomInfo.substr(0, dataSeperator));

	roomInfo.erase(0, dataSeperator + 1);
	dataSeperator = roomInfo.find(';');
	this->roomNumber = roomInfo.substr(0, dataSeperator);

	roomInfo.erase(0, dataSeperator + 1);
	dataSeperator = roomInfo.find(';');
	this->roomDesribtion = roomInfo.substr(0, dataSeperator);

	roomInfo.erase(0, dataSeperator + 1);
	dataSeperator = roomInfo.find(';');
	this->numberOfSleeps = std::stoi(roomInfo.substr(0, dataSeperator));

	bookingsHead = new Booking();
	bookingsHead->next = nullptr;
	bookingsHead->previous = nullptr;
}

Room::Room()
{
	this->bookingsHead = nullptr;
}

void Room::showAllRooms()
{
	Room* current = head->next;

	while (current != nullptr)
	{
		current->showElement();
		current = current->next;
	}
}

Room * Room::getRoom(int roomId)
{
	Room* current = head->next;
	while (current != nullptr)
	{
		if (current->id == roomId)
			return current;
		current = current->next;
	}
	std::cout << "\nBRAK ELEMENTU O PODANYM ID!!!\n";
	return nullptr;
}

void Room::readListFromFile()
{
	std::ifstream fileIn;
	fileIn.open(file, std::ios::in);
	std::string info = "";

	head->previous = nullptr;
	head->next = nullptr;

	Room* current = head;

	while (!fileIn.eof())
	{
		std::getline(fileIn, info);
		current = current->addElement(current, info);
	}
	fileIn.close();
}

int Room::generateID()
{
	srand(time(NULL));
	Room* current = Room::head->next;

	int i = rand() % Room::MAX_ID + 1;;
	while (current != nullptr)
	{
		if (current->id == i)
		{
			current = Room::head;
			i = rand() % Room::MAX_ID + 1;
		}
		current = current->next;
	}
	return i;
}

void Room::showAvaiableRooms(Date begin, Date end)
{
	Room* current = head->next;

	while (current != nullptr)
	{
		bool isRoomAvaiable = true;
		Booking* currentBooking = current->bookingsHead->next;
		while (currentBooking != nullptr)
		{
			if (Date::areDatesColliding(begin, end, currentBooking->bookedStartDate, currentBooking->bookedEndDate))
			{
				isRoomAvaiable = false;
				break;
			}
			currentBooking = currentBooking->next;
		}
		if (isRoomAvaiable)
			current->showElement();
		current = current->next;
	}
}
void Room::showRoomBookings(int ID)
{
	std::cout << "\nRezerwacje pokoju:\n";
	Room* room = getRoom(ID);
	room->showElement();
	Booking* current = room->bookingsHead->next;
	while (current != nullptr)
	{
		current->showElement();
		current = current->next;
	}
}

void Room::addElementToTxtFile(std::string info)
{
	std::ofstream fileOut;
	fileOut.open(Room::file, std::ios::app);
	fileOut << "\n" + info;
	fileOut.close();
}

void updateTxtFile()
{
	std::ofstream fileOut;
	fileOut.open(Room::file, std::ios::trunc);
	Room* current = Room::head->next;

	while (current->next != nullptr)
	{
		fileOut << current->roomTxtInfo << "\n";
		current = current->next;
	}
	fileOut << current->roomTxtInfo;
	fileOut.close();
}

void Room::deleteElement(int ID)
{
	Room* toRemove = getRoom(ID);

	toRemove->previous->next = toRemove->next;
	if(toRemove->next != nullptr)
		toRemove->next->previous = toRemove->previous;
	delete toRemove;
	updateTxtFile();
}

void Room::showElement()
{
	std::cout << "\nId:                     " << this->id;
	std::cout << "\nPokoj nr:               " << this->roomNumber;
	std::cout << "\nCena:                   " << this->price << " zl";
	std::cout << "\nOpis pokoju:            " << this->roomDesribtion;
	std::cout << "\nIlosc miejsc do spania: " << this->numberOfSleeps << std::endl;

}

void Room::addElement()
{
	Room* current = head->next;

	while (current->next != nullptr)
		current = current->next;
	this->next = nullptr;
	this->previous = current;
	current->next = this;
}

Room* Room::addElement(Room* current, std::string info)
{
	Room* newRoom = new Room(info);
	newRoom->next = nullptr;
	newRoom->previous = current;
	current->next = newRoom;
	current = newRoom;
	return newRoom;
}


void Room::deallocateRooms()
{
	Room* current = head;
	while (current != nullptr)
	{
		Room* next = current->next;
		delete current;
		current = next;
	}
}