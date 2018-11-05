#pragma once
#include <string>
#include "Booking.h"

struct Room
{ 
	static Room* head;
	static std::string file;
	const static int MAX_ID = 1000;

	Room* next;
	Room* previous;
	Booking* bookingsHead;

	int id;
	std::string roomTxtInfo;
	std::string roomNumber;
	std::string roomDesribtion;
	double price;
	int numberOfSleeps;


	Room(std::string roomInfo);
	Room();

	void showAvaiableRooms(Date begin, Date end);
	void showRoomBookings(int ID);
	void showElement();
	void showAllRooms();

	void addElementToTxtFile(std::string info);
	void addElement();
	Room* addElement(Room* current, std::string info);

	static Room* getRoom(int roomId);
	static void readListFromFile(); 
	int generateID();
	static void deallocateRooms();
	void deleteElement(int ID);
};