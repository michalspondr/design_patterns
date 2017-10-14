#ifndef _CAR_BUILDER_
#define _CAR_BUILDER_
#include <memory>
#include <iostream>

#include "builder.h"
#include "car.h"

class CarBuilder : public pattern::Builder {
        public:
        CarBuilder() {
                car = std::unique_ptr<Car>(new Car);
        }
        
        // this is a random part of car
        // just to implement virtual method from Builder
        virtual void buildPart() {
              car->wheel = "customwheel";
        }

        // next builder methods
        void addDoors(int n) {car->nr_of_doors = n;}
        void addSeats(int n) {car->nr_of_seats = n;}
        void sportCar() {car->type = "sport";}
        void familyCar() {car->type = "family";}
        void electric() {car->electric = true;}

        std::unique_ptr<Car> getCar() {
                return std::move(car);
        }

        private:
        std::unique_ptr<Car> car;
};

#endif
