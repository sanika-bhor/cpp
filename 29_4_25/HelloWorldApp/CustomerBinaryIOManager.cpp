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
	for(auto& customer : cutomers) {
		customer.display();
	}

}


void CustomerBinaryIOManager::addCustomer(std::vector<Customer>& cutomers, const Customer& customer) {
	cutomers.push_back(customer);
	cout << "Customer added successfully." << endl;
}
void CustomerBinaryIOManager::removeCustomer(std::vector<Customer>& cutomers, int cutomerId) {

	auto it = remove_if(cutomers.begin(), cutomers.end(), [cutomerId](const Customer& customer) {
		return customer.getCustomerId() == cutomerId;
	});

	if (it != cutomers.end()) {
		cutomers.erase(it, cutomers.end());
		cout << "Customer removed successfully." << endl;
	}
	else {
		cout << "Customer not found." << endl;
	}
}
void CustomerBinaryIOManager::updateCustomer(std::vector<Customer>& cutomers, const Customer& updatedcutomer) {

	auto it = find_if(cutomers.begin(), cutomers.end(), [updatedcutomer](const Customer& customer) {
		return customer.getCustomerId() == updatedcutomer.getCustomerId();
	});

	if (it != cutomers.end()) {
		*it = updatedcutomer;
		cout << "Customer updated successfully." << endl;
	}
	else {
		cout << "Customer not found." << endl;
	}
}