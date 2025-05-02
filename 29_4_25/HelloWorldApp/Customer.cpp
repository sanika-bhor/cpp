#include "Customer.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

Customer::Customer() : customerId(0), name(""), email(""), phoneNumber(""), address("") {
}
Customer::Customer(int id, const std::string& n, const std::string& e, const std::string& p, const std::string& a)
	: customerId(id), name(n), email(e), phoneNumber(p), address(a) {
}
int Customer::getCustomerId() const { return customerId; }
std::string Customer::getName() const { return name; }
std::string Customer::getEmail() const { return email; }
std::string Customer::getPhoneNumber() const { return phoneNumber; }
std::string Customer::getAddress() const { return address; }
void Customer::setName(const std::string& n) { name = n; }
void Customer::setEmail(const std::string & e) { email = e; }
void Customer::setPhoneNumber(const std::string& p) { phoneNumber = p; }
void Customer::setAddress(const std::string& a) { address = a; }
void Customer::display() const {
	std::cout << "Customer ID: " << customerId << "\n"
		<< "Name: " << name << "\n"
		<< "Email: " << email << "\n"
		<< "Phone Number: " << phoneNumber << "\n"
		<< "Address: " << address << "\n";
}


void Customer::serialize(ofstream& outFile) {
	if (!outFile.is_open()) {
		std::cerr << "Error opening file for writing." << std::endl;
	}
	else
	{
		//cutomerId
		outFile.write(reinterpret_cast<char*>(&customerId), sizeof(customerId));

		//name
		size_t nameLength = name.size();
		outFile.write(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
		outFile.write(name.c_str(), nameLength);

		//email
		size_t emailLength=email.size();
		outFile.write(reinterpret_cast<char*>(&emailLength), sizeof(emailLength));
		outFile.write(email.c_str(), emailLength);

		//phoneNumber
		size_t phoneNumberLength = phoneNumber.size();
		outFile.write(reinterpret_cast<char*>(&phoneNumberLength), sizeof(phoneNumberLength));
		outFile.write(phoneNumber.c_str(), phoneNumberLength);

		//address
		size_t addressLength= address.size();
		outFile.write(reinterpret_cast<char*>(&addressLength), sizeof(addressLength));
		outFile.write(address.c_str(), addressLength);

		cout<<"Customer data serialized successfully." << endl;
		
	}
}
void  Customer::deserialize(ifstream& inFile)
{
	if (!inFile) {
		std::cerr << "Error opening file for reading." << std::endl;
	}

	int id;
	string name, email, phoneNumber, address;
	size_t nameLength, emailLength, phoneNumberLength, addressLength;
	
	//id
	inFile.read(reinterpret_cast<char*>(&id), sizeof(id));

	//name
	inFile.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
	name.resize(nameLength);
	inFile.read(&name[0], nameLength);

	//email
	inFile.read(reinterpret_cast<char*>(&emailLength), sizeof(emailLength));
	email.resize(emailLength);
	inFile.read(&email[0], emailLength);

	//phoneNumber
	inFile.read(reinterpret_cast<char*>(&phoneNumberLength), sizeof(phoneNumberLength));
	phoneNumber.resize(phoneNumberLength);
	inFile.read(&phoneNumber[0], phoneNumberLength);

	//address
	inFile.read(reinterpret_cast<char*>(&addressLength), sizeof(addressLength));
	address.resize(addressLength);
	inFile.read(&address[0], addressLength);

	customerId = id;
	this->name = name;
	this->email = email;
	this->phoneNumber = phoneNumber;
	this->address = address;
	cout << "Customer data deserialized successfully." << endl;
}