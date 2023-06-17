#include<iostream>
#include<string>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<sstream>

using namespace std;

class Person{
    public: 
        string name;
        string id;
        string address;
        Person();
        Person(string n , string i , string a) 
            : name(n) , id(i) , address(a) {} 
        void show() {
            cout << "Name is : " << this->name
            << " id is : " << this->id
            << " address is : " << this->address << endl;
        }
};

class PropertyContract {
private:
    Person customer;
    string date_create;
    string valid_bound;
    int cost;
public:
    PropertyContract(Person cus ,string today , string valid , int cost) 
    : customer(cus), date_create(today), valid_bound(valid) , cost(cost) {}
    virtual void Show_Contract() {
        cout << "===== INFO CUSTOMER ===== \n";
        customer.show();
        cout << "===== Contract Info ===== \n";
        cout << date_create << " with " << valid_bound << " Cost : " << this->cost << endl;
    }
};

class Inter_Contract : public PropertyContract {
    public:
        Inter_Contract( Person cus ,string today , string valid , int cost) 
        : PropertyContract(cus , today , valid, cost) {}
        virtual void Rent_Contract() {
            cout << "Renting contract create success! \n vilid 50 year! \n";
        }
        virtual void Buy_contract() {
            cout << "Buying contract create success! \n Congratulations ! \n";
        }
};

class Exter_Contract : public PropertyContract {
    public:
        Exter_Contract( Person cus ,string today , string valid , int cost) 
        : PropertyContract(cus , today , valid, cost) {}
        virtual void Rent_Contract() {
            cout << "Renting contract create success! \n vilid 50 year! \n";
        }
};
  
class City_Customer : public Inter_Contract {
    City_Customer( Person cus ,string today , string valid , int cost) : 
    Inter_Contract( cus , today ,  valid ,  cost ) {}
    void Rent_Contract() override {
        cout << "Renting contract create success! \n vilid 50 year! \n";
        cout << "IN CITY tax : 20% \n";
    }
    void Buy_contract() override {
        cout << "Buying contract create success! \n Congratulations ! \n";
        cout << "IN CITY tax : 20% \n";
    }
};

class Remote_Area_Customer : public Inter_Contract {
    Remote_Area_Customer( Person cus ,string today , string valid , int cost) : 
    Inter_Contract( cus , today ,  valid ,  cost ) {}
    void Rent_Contract() override {
        cout << "Renting contract create success! \n vilid 50 year! \n";
        cout << "IN CITY tax : 5% \n";
    }
    void Buy_contract() override {
        cout << "Buying contract create success! \n Congratulations ! \n";
        cout << "IN CITY tax : 5% \n";
    }
};

// IN VN LAW the foreigner can't buy BDS in VN, they only can rent with 50 years valid

class Foreigner_Customer : public Exter_Contract {
    Foreigner_Customer( Person cus ,string today , string valid , int cost) : 
    Exter_Contract( cus , today ,  valid ,  cost ) {}
    void Rent_Contract() override {
        cout << "Renting contract create success! \n vilid 50 year! \n";
        cout << "With Poreigner tax : 10% \n";
    }
};


