#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
#include "ProductRepository.h"
#include "ProductService.h"
#include "ProductsController.h"
#include  "IPersistManager.h"
#include "ProductTextIOManager.h"
#include "ProductBinaryIOManger.h"
#include "ProductJSONIOManager.h"
#include "UIManager.h"
#include "Customer.h"
#include "CustomerBinaryIOManager.h"
#include "UICustomerManager.h"


using namespace std;
int main()
{

	std::cout << "Welcome to Transflower Store!\n";
	std::vector<Customer> customers;
	IPersistCustomerManager* ptrMgr = new CustomerBinaryIOManager();


	//Set up User Interface
	/*	UIManager uiManager;
		ProductRepository repo;
		ProductService service(repo); //service
		ProductsController controller(repo, service); //controller
	*/

		UICustomerManager uiManager;
		CustomerBinaryIOManager iomgr;


	// Display the menu and handle user input
	//Console Menu Driven  User ineraction

		uiManager.displayWelcomeMessage(); // Display welcome message
		uiManager.handleUserInput(iomgr); // Handle user input through the UIManager
	

	//shot syntax;

	/* customers = {
					Customer(1,"Sanika","sanika@gmail.com","5555","pune"),
					Customer(2,"sarthak","sarthak@gmail.com","9999","pune"),
					Customer(3,"kajal","kajal@gmail.com","8888","pune")
	 };

	CustomerBinaryIOManager mgr;
	mgr.saveCustomers(customers);


	auto loadedProducts = mgr.loadCustomers();

	cout << "data loading..." << endl;
	for ( auto& p : loadedProducts) {
		p.display();
	}
	*/
	return 0;
}


/*
	/*
	cout <<endl<< "Adding a new product...\n";

	controller.addProduct(5, "Tulip", "Spring Flower", "Flower", 8, 15.99);
	controller.displayProducts(); // Display all products after adding a new one

	cout << "Updating product at index 1...\n";

	controller.updateProduct(1, new Product(2, "Lily", "Summer Flower", "Flower", 12, 25.99)); // Update product at index 1
	controller.displayProducts(); // Display all products after update

	// Cleanup
	for (int i = 0; i < 100; i++) {
		delete repo.getProduct(i); // Delete each product in the repository
	}

	// Load products from file

	ProductIOManager::saveProductsToFile(filename, products);
	*/


/*
	service.applyDiscount(1, 10); // Apply 10% discount to product with ID 1
	service.calculateTotalPrice(1); // Calculate total price for product with ID 1
	service.searchProductByTitle("Rose"); // Search for product by title

	*/
