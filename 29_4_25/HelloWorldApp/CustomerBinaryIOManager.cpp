#include "CustomerBinaryIOManager.h"
#include "Customer.h"
#include <fstream>
#include <iostream>
using namespace std;

void CustomerBinaryIOManager::saveCustomers(  std::vector<Customer>& customers)
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
		for ( auto& customer : customers) {
			customer.serialize(outFile);
		}
		cout << "data saved successfully"<<endl; 
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

void CustomerBinaryIOManager::displayCustomer(const std::vector<Customer>& cutomers) {


}


void CustomerBinaryIOManager::addCustomer(std::vector<Customer>& cutomers, const Customer& customer) {}
void CustomerBinaryIOManager::removeCustomer(std::vector<Customer>& cutomers, int cutomerId) {}
void CustomerBinaryIOManager::updateCustomer(std::vector<Customer>& cutomers, const Customer& updatedcutomer) {}