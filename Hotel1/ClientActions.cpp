#include "ClientActions.h"
#include "stdafx.h"
#include "Client.h"
#include <iostream>
#include <string>


void deleteClient()
{
	std::cout << "\n\n";
	Client::head->showAllClients();
	std::cout << "\nPodaj ID klienta do usuniecia: ";
	int id;
	std::cin >> id;
	Client::head->deleteElement(id);

	std::cout << "\nElement Usunieto\n";
}

void addClientManually()
{
	std::string clientInfo = "";
	std::string inputData;

	clientInfo = std::to_string(Client::head->generateID()) + ';';
	std::cout << "\nWproawdz nastepujace parametry: ";
	std::cout << "\nImie:               ";
	std::cin >> inputData;
	clientInfo += inputData + ';';
	std::cout << "\nNazwisko:           ";
	std::cin >> inputData;
	clientInfo += inputData + ';';
	std::cout << "\nAdres zamieszkania: ";
	std::cin.ignore();
	std::getline(std::cin, inputData);
	clientInfo += inputData + ';';
	std::cout << "\nTelefon:            ";
	std::cin >> inputData;
	clientInfo += inputData + ';';

	Client* newClient = new Client(clientInfo);
	newClient->addElement();
	newClient->addElementToTxtFile(clientInfo);
}

void showAllClients()
{
	Client::head->showAllClients();
}

void deallocateClients()
{
	Client::deallocateClients();
}
