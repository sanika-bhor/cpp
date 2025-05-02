#pragma once
#include <iostream>
#include <string>
#include "Product.h"
#include "ProductRepository.h"	


using namespace std;
#pragma once
class IService {


public:
	virtual ~IService() { }
	virtual void applyDiscount(int productId, double discount)=0;
	virtual void calculateTotalPrice(int productId)=0;
	virtual void searchProductByTitle(const std::string& title)=0;
	virtual void saveProducts()=0;
};


