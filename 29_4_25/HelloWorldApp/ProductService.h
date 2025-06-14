#ifndef  __PRODUCTSERVICE_H
#define __PRODUCTSERVICE_H

#include <iostream>
#include <string>
 #include "Product.h"
#include "ProductRepository.h"	
 
#include "IService.h"
// Forward declaration of ProductRepository
class ProductRepository;

using namespace std;
#pragma once
class ProductService:IService {

private:
	ProductRepository& repo; 

public:
	ProductService(ProductRepository& r);
	void applyDiscount(int productId, double discount) override;
	void calculateTotalPrice(int productId) override;
	void searchProductByTitle(const std::string& title) override;
	void saveProducts() override;
};


#endif // ! __PRODUCTSERVICE_H