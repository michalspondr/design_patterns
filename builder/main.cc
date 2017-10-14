#include <iostream>
#include <memory>

#include "carbuilder.h"
#include "car.h"

using namespace std;

// this is how builder is used
// the director ( = buildCar method) uses builder to simply create a new car
// and returns final product
unique_ptr<Car> buildCar(CarBuilder& builder) {
        builder.buildPart();
        builder.electric();
        builder.sportCar();
        builder.addSeats(2);
        builder.addDoors(2);

        return builder.getCar();
}

int main() {
        CarBuilder carBuilder;
        auto car = buildCar(carBuilder);

        cout << *car << endl;
}
