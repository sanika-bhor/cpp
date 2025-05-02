#pragma once
#include <iostream>
#include <string>
#include "product.h"

using namespace std;
class IRepository {
public:
	virtual ~IRepository() {} 
	virtual void addProduct(Product* product)=0;
	virtual Product* getProduct(int index) const = 0;
	virtual Product* findProductById(int id) const = 0;
	virtual Product* findProductByTitle(const std::string& title) const = 0;
	virtual void removeProduct(int index) = 0;
	virtual void updateProduct(int index, Product* product) = 0;
	virtual void displayProducts() const = 0;
	virtual void saveProducts() = 0;
};
