#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "IPersistCustomerManager.h"

class CustomerBinaryIOManager: public IPersistCustomerManager
{
public:

	
	void saveCustomers(const std::vector<Customer>& cutomers) override;
	std::vector<Customer> loadCustomers() override;
	void displayCustomer(const std::vector<Customer>& cutomers) override;
	void addCustomer(std::vector<Customer>& cutomers, const Customer& customer) override;
	void removeCustomer(std::vector<Customer>& cutomers, int cutomerId) override;
	void updateCustomer(std::vector<Customer>& cutomers, const Customer& updatedcutomer) override;
};

