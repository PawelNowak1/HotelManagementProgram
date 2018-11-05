#include "stdafx.h"
#include "Client.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

Client* Client::head = nullptr;
std::string Client::file = "";

Client * Client::getClient(int roomId)
{
	Client* current = Client::head->next;
	while (current != nullptr)
	{
		if (current->id == roomId)
			return current;
		current = current->next;
	}
	std::cout << "\nBRAK ELEMENTU O PODANYM ID!!!\n";
	return nullptr;
}

void updateTxtFil()
{
	std::ofstream fileOut;
	fileOut.open(Client::file, std::ios::trunc);
	Client* current = Client::head->next;

	while (current->next != nullptr)
	{
		fileOut << current->clientTxtInfo << "\n";
		current = current->next;
	}
	fileOut << current->clientTxtInfo;
	fileOut.close();
}

void Client::deleteElement(int ID)
{
	Client* toRemove = getClient(ID);

	toRemove->previous->next = toRemove->next;
	toRemove->next->previous = toRemove->previous;
	delete toRemove;
	updateTxtFil();
}

void Client::addElementToTxtFile(std::string info)
{
	std::ofstream fileOut;
	fileOut.open(Client::file, std::ios::app);
	fileOut << "\n" + info;
	fileOut.close();
}

int Client::generateID()
{
	srand(time(NULL));
	Client* current = Client::head->next;

	int i = rand() % Client::MAX_ID + 1;;
	while (current != nullptr)
	{
		if (current->id == i)
		{
			current = Client::head->next;
			i = rand() % Client::MAX_ID + 1;
		}
		current = current->next;
	}
	return i;
}

void Client::showAllClients()
{
	Client* current = head->next;

	while (current != nullptr)
	{
		current->showElement();
		current = current->next;
	}
}

void Client::addElement()
{
	Client* current = head->next;

	while (current->next != nullptr)
		current = current->next;
	this->next = nullptr;
	this->previous = current;
	current->next = this;
}

Client * Client::addElement(Client * current, std::string info)
{
	Client* newClient = new Client(info);
	newClient->next = nullptr;
	newClient->previous = current;
	current->next = newClient;
	current = newClient;
	return newClient;
}

Client::Client(std::string clientInfo)
{
	this->clientTxtInfo = clientInfo;
	int dataSeperator = clientInfo.find(';');
	this->id = std::stoi(clientInfo.substr(0, dataSeperator));

	clientInfo.erase(0, dataSeperator + 1);
	dataSeperator = clientInfo.find(';');
	this->firstName = clientInfo.substr(0, dataSeperator);

	clientInfo.erase(0, dataSeperator + 1);
	dataSeperator = clientInfo.find(';');
	this->lastName = clientInfo.substr(0, dataSeperator);

	clientInfo.erase(0, dataSeperator + 1);
	dataSeperator = clientInfo.find(';');
	this->residence = clientInfo.substr(0, dataSeperator);

	clientInfo.erase(0, dataSeperator + 1);
	dataSeperator = clientInfo.find(';');
	this->phoneNumber = clientInfo.substr(0, dataSeperator);
}

Client::Client(){}

void Client::deallocateClients()
{
	Client* current = head;
	while (current != nullptr)
	{
		Client* next = current->next;
		delete current;
		current = next;
	}
}

void Client::readListFromFile()
{
	std::ifstream fileIn;
	fileIn.open(file, std::ios::in);
	std::string info = "";

	head->previous = nullptr;
	head->next = nullptr;

	Client* current = head;

	while (!fileIn.eof())
	{
		std::getline(fileIn, info);
		current = current->addElement(current, info);
	}
	fileIn.close();
}

void Client::showElement()
{
	std::cout << "\nId:                 " << this->id;
	std::cout << "\nImie:               " << this->firstName;
	std::cout << "\nNazwisko:           " << this->lastName;
	std::cout << "\nAdres zamieszkania: " << this->residence;
	std::cout << "\nNumer:              " << this->phoneNumber << std::endl;
}