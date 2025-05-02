#pragma once
#include <iostream>
#include <string>
#include "Customer.h"
#include "CustomerBinaryIOManager.h"

class UICustomerManager
{

public:

	void displayWelcomeMessage();
	void displayGoodbyeMessage();
	void displayErrorMessage(const std::string& message);
	void displaySuccessMessage(const std::string& message);
	void displayCustomerDetails(const Customer& customer);
	void displayCustomers(CustomerBinaryIOManager& repo, vector<Customer> customers);
	void displayCustomerNotFound();
	void displayCustomerAdded();
	void displayMenu();
	void getCustomerDetails(int& id, string& name, string& email, string& phoneNo, string& Address);
	void getCustomerId(int& customerId);
	void getCustomerName(string& name);
	void handleUserInput(CustomerBinaryIOManager& mgr);
};
