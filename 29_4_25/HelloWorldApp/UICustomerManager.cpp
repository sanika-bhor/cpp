
#include "UICustomerManager.h"


#include <iostream>
#include <string>
#include "Customer.h"

using namespace std;


void UICustomerManager::displayWelcomeMessage() {
	std::cout << "Welcome to Transflower Store!" << std::endl;
}
void UICustomerManager::displayGoodbyeMessage() {
	std::cout << "Thank you for visiting Transflower Store!" << std::endl;
}
void UICustomerManager::displayErrorMessage(const std::string& message) {
	std::cout << "Error: " << message << std::endl;
}
void UICustomerManager::displaySuccessMessage(const std::string& message) {
	std::cout << "Success: " << message << std::endl;
}
void UICustomerManager::displayCustomerDetails(const Customer& customer) {
	customer.display();
}
void UICustomerManager::displayCustomers( CustomerBinaryIOManager& iomgr,vector<Customer> customers) {
	iomgr.displayCustomer(customers);
}
void UICustomerManager::displayCustomerNotFound() {
	std::cout << "customer not found!" << std::endl;
}
void UICustomerManager::displayCustomerAdded() {
	std::cout << "Customer added successfully!" << std::endl;
}
void UICustomerManager::displayMenu() {
	std::cout << "1. Add Customer" << std::endl;
	std::cout << "2. Update Customer" << std::endl;
	std::cout << "3. Remove Customer" << std::endl;
	std::cout << "4. Display Customer" << std::endl;
	std::cout << "5. Save To File" << std::endl;
	std::cout << "6. display file data" << std::endl;
	std::cout << "7. Exit" << std::endl;
}
void UICustomerManager::getCustomerDetails(int& id, string& name, string& email, string& phoneNo, string& Address) {
	std::cout << "Enter Customer ID: ";
	std::cin >> id;
	std::cout << "Enter Customer Name: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "Enter Customer Email: ";
	std::getline(std::cin, email);
	std::cout << "Enter Phone Number: ";
	std::getline(std::cin, phoneNo);
	std::cout << "Enter Address: ";
	std::cin >> Address;

}
void UICustomerManager::getCustomerId(int& customerId) {
	std::cout << "Enter Customer ID: ";
	std::cin >> customerId;
}
void UICustomerManager::getCustomerName(string& title) {
	std::cout << "Enter Product Name: ";
	std::cin.ignore();
	std::getline(std::cin, title);
}
void UICustomerManager::handleUserInput(CustomerBinaryIOManager& ioMgr) {
	int choice;
	vector<Customer> customers = ioMgr.loadCustomers();
	do {
		displayMenu();
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		switch (choice) {
		case 1: {
			int custId;
			string name, email, phno, address;
			getCustomerDetails(custId, name, email, phno, address);
			Customer customer(custId, name, email, phno, address);
			ioMgr.addCustomer(customers, customer);
			displayCustomerAdded();
			break;
		}
		case 2: {
			int custId;
			string name, email, phno, address;
			getCustomerDetails(custId, name, email, phno, address);
			Customer customer(custId, name, email, phno, address);
			ioMgr.updateCustomer(customers, customer);
			break;
		}
		case 3: {
			int id;
			getCustomerId(id);
			ioMgr.removeCustomer(customers, id);
			break;
		}
		case 4:
			ioMgr.displayCustomer(customers);
			break;
		case 5: {
			ioMgr.saveCustomers(customers);
			break;
		}

		case 6: {
			vector<Customer> filecustomers = ioMgr.loadCustomers();
			for (auto& cust : filecustomers) {
				cust.display();
			}
			break;
		}
		case 7:
			std::cout << "Exiting..." << std::endl;
			break;
		default:
			std::cout << "Invalid choice! Please try again." << std::endl;
		}
	} while (choice != 7);



	}


