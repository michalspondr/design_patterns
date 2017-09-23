#include <iostream>
#include <string>
#include <memory>

#include "abstract_factory.h"

using namespace pattern;


// Product (created by factories) definitions
class Product {
        protected:
        std::string name;
        int price;

        public:
        Product() = default;
        Product(const std::string& _name, const int _price) : name{_name}, price{_price} {}

        friend std::ostream& operator<< (std::ostream& stream, const Product& _product);
};
// print content of Product
std::ostream& operator<< (std::ostream& stream, const Product& _product) {
        stream << _product.name << " " << _product.price;
}

class Car : public Product {
        public:
        Car(const std::string& _name = "car", const int _price = 500000) : Product(_name, _price) {}
};

class Bike : public Product {
        public:
        Bike(const std::string& _name = "bike", const int _price = 10000) : Product(_name, _price) {}
};


// Factory definitions
template <typename T>
class Factory : public AbstractFactory<T> {
        public:
        virtual std::unique_ptr<T> createProduct() {
                return std::make_unique<T>();
        }

        virtual std::unique_ptr<T> createProduct(const std::string& s, const int i) {
                return std::make_unique<T>(s, i);
        }
};

int main() {
        // new factories for Products
        Factory<Product> pf;
        Factory<Car> carFactory;
        Factory<Bike> bikeFactory;
        
        // factory generates a product
        std::unique_ptr<Product> product = pf.createProduct("thing", 11);
        std::cout << *product << std::endl;
        
        product = carFactory.createProduct();
        std::cout << *product << std::endl;
        
        product = bikeFactory.createProduct();
        std::cout << *product << std::endl;

        return 0;
}
