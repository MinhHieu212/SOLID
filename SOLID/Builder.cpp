#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    string name, color, description;
    int numOfWheel, numOfSeat;

public:
    Car(string name, string color, string des, int seat, int wheel) {
        this->color = color;
        this->description = des;
        this->name = name;
        this->numOfSeat = seat;
        this->numOfWheel = wheel;
    }
    void Dump() {
        cout << " My name is: " << this->name << " \n Desciption: "
            << this->description << " \n The color: "
            << this->color << "\n NumOfSeat: "
            << this->numOfSeat << " \n NumOfWheel: "
            << this->numOfWheel << "\n";
    }
};

class CarBuilder;

class Builder {
public:
    virtual CarBuilder addName(string name) = 0;
    virtual CarBuilder addColor(string color) = 0;
    virtual CarBuilder addDes(string description) = 0;
    virtual CarBuilder addNumOfSeat(int seats) = 0;
    virtual CarBuilder addNumOfWheel(int wheels) = 0;
    virtual Car Build() = 0;
};

class CarBuilder : public Builder {
private:
    string name, color, description;
    int numOfWheel, numOfSeat;

public:
    CarBuilder();
    CarBuilder addName(string name) override {
        this->name = name;
        return *this;
    }
    CarBuilder addColor(string color) override {
        this->color = color;
        return *this;
    }
    CarBuilder addDes(string description) override {
        this->description = description;
        return *this;
    }
    CarBuilder addNumOfSeat(int seats) override {
        this->numOfSeat = seats;
        return *this;
    }
    CarBuilder addNumOfWheel(int wheels) override {
        this->numOfWheel = wheels;
        return *this;
    }
    Car Build() override {
        return *(new Car(this->name, this->color, this->description, this->numOfSeat, this->numOfWheel));
    }
};

int main() {
    CarBuilder  _carrbuilder;
    Car myCar = _carrbuilder.addColor("Honda civic type R")
                            .addDes("Normal car I am love the most")
                            .addName("Minh Hieu 2k3")
                            .addNumOfSeat(4)
                            .addNumOfWheel(4)
                            .Build();

    myCar.Dump();
    
    return 0;
}
