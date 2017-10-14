#ifndef _CAR_
#define _CAR_

#include <string>
#include <iostream>

using std::string;

// some attributes which a car might have
struct Car {
        string wheel{"standard"};
        int nr_of_doors{5};
        string type{"normal"};
        int nr_of_seats{4};
        bool electric{false};

        friend std::ostream& operator<< (std::ostream& stream, const Car& _product);
};

// print content of Car
std::ostream& operator<< (std::ostream& stream, const Car& _product) {
        stream << "Wheel: " << _product.wheel << std::endl <<
        "Type: " << _product.type << std::endl <<
        "Nr. of doors: " << _product.nr_of_doors << std::endl <<
        "Nr. of seats: " << _product.nr_of_seats;
        if (_product.electric) {
                stream << std::endl << "Electric";
        }
}


#endif
