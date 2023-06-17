# include <iostream>
#include <string.h>

using namespace std;

//#define PROBLEM
#ifdef PROBLEM

/* Vi pham single reponsibility */
class Student {
    private:
        string name, id , address;
    public:
        Student() {};
        Student(string name , string id , string address) : name(name) , id(id) , address(address) {}
        void getInfoSimple() {
            cout << this->name + " " + this->id + " " + this->address << endl; 
        } 
        void getInfoDetail() {
            cout << "Information of student\n";
            cout << "Name is: " + name + "\n"
            + " Id is : " + id + "\n" 
            + "Address is :" + address + "\n";
        }
        void ChangeInfo(string name , string id , string address) {
            this->name = name;
            this->address = address;
            this->id = id;
        }
};

#else

/* Apply Single responsibility principle tao ra 2 class GetInfor voi ChangeInto
    Tach cac chuc nang co trong class thanh cac class chuc nang rieng biet */
/*  Neu co them cac class Person Teacher thi sao */  

/*  Open Close pinciple -> ta có thế open them cac class va chi viec ke thua class cu
    ma khong thay doi cac cource cu khong bi anh huong
    co the open them class workwr , mamager ke thua class person. Class GetInFor no problem  */

class Person {
    public:
        string name , id , address;
        Person() {}
        Person(string name , string id , string address) : name(name) , id(id) , address(address) {}
        virtual void getinfo_plus() {}
        virtual void setinfo_plus(string) {}
};

class Student : public Person {
    public:     
        string grade;
        Student() {}
        Student(string name , string id , string address , string grade) : Person(name , id , address) , grade(grade) {}
        void getinfo_plus() override {
            cout << "grade is :" + this->grade << endl;
        }
        void setinfo_plus(string newgrade) override {
            this->grade = newgrade;
        } 
};

class Teacher : public Person {
    public:     
        string certification;
        Teacher() {}
        Teacher(string name , string id , string address , string certi) : Person(name , id , address) , certification(certi) {}
        void getinfo_plus() override {
            cout << "Certification is :" + this->certification << endl;
        }
        void setinfo_plus(string newCerti) override {
            this->certification = newCerti;
        }
};

class GetInfor {
    public:
        void getInfoSimple(Person *person) {
            cout << person->name + " " + person->id + " " + person->address << endl; 
            person->getinfo_plus();
        } 
        void getInfoDetail(Person *person) {
            cout << "Information of student\n";
            cout << "Name is: " + person->name + "\n"
            + "Id is : " + person->id + "\n" 
            + "Address is: " + person->address + "\n";
            person->getinfo_plus();
        }
};

class ChangeInfo {
    public:
        void changeInfo(Person* person , string newname , string newid , string newaddress , string newInfo) {
            person->name = newname;
            person->address = newaddress;
            person->id = newid;
            person->setinfo_plus(newInfo);
        } 
};

#endif

int main() {
    Person* student = new Teacher("Tran Minh Hieu" , "2113363" , "Hoa dong, Vinh chau" , "HCMUT EDU VN");
    GetInfor Get;
    Get.getInfoSimple(student);
    ChangeInfo Change;
    Change.changeInfo(student , "Tran Minh Tien" , "2113333" , "Hoa khoi, Hoa dong, Vinh chau" , "US EDU VN");
    Get.getInfoDetail(student);
}