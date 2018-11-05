#pragma once
#include <string>

struct Client
{
	static Client* head;
	static std::string file;
	const static int MAX_ID = 1000;

	Client* next;
	Client* previous;

	int id;
	std::string clientTxtInfo;
	std::string firstName;
	std::string lastName;
	std::string residence;
	std::string phoneNumber;


	Client(std::string clientInfo);
	Client();

	void addElement();
	Client* addElement(Client* current, std::string info); 
	void addElementToTxtFile(std::string info);
	void showElement();
	void showAllClients();

	Client * getClient(int roomId);
	int generateID();
	static void readListFromFile();
	void deleteElement(int id);
	static void deallocateClients();
};