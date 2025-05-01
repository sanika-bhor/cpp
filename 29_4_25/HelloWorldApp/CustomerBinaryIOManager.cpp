#include "CustomerBinaryIOManager.h"
#include "Customer.h"
#include <fstream>
#include <iostream>
using namespace std;

void CustomerBinaryIOManager::saveCustomers( const std::vector<Customer>& customers)
{
	string fileName = "customers.dat";
	
	ofstream outFile(fileName, ios::binary);
	if (!outFile) {
		std::cerr << "Error opening file for writing." << std::endl;

	}
	else
	{
		size_t size = customers.size();
		outFile.write(reinterpret_cast<char*>(&size), sizeof(size));
		for (auto& customer : customers) {
			customer.serialize(outFile);
		}
	}
	
}

vector<Customer> CustomerBinaryIOManager::loadCustomers()
{
	string fileName = "customers.dat";
	ifstream inFile(fileName, ios::binary);

	if(!inFile) {
		std::cerr << "Error opening file for reading." << std::endl;
		return {};
	}

	size_t size;
	inFile.read(reinterpret_cast<char*>(&size), sizeof(size));
	vector<Customer> customers(size);

	for(auto& customer : customers) {
		customer.deserialize(inFile);
	}

	inFile.close();
	return customers;
}

void displayCustomer(const std::vector<Customer>& cutomers) {}
void addCustomer(std::vector<Customer>& cutomers, const Customer& customer) {}
void removeCustomer(std::vector<Customer>& cutomers, int cutomerId) {}
void updateCustomer(std::vector<Customer>& cutomers, const Customer& updatedcutomer) {}