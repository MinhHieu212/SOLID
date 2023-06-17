#include <iostream>
#include <list>
#include <string.h>
#include <fstream>

#define FileName "diary.txt"

using namespace std;

class Export;
class EntryManager;

class ErrorManager {
    public:
        void GetError(const std::exception& ex) {
            cerr << "Program has error is : " << ex.what() << endl;
        }
};

class DiaryEntry{
    public:
        string title , id , date , contents;
    public:   
        DiaryEntry() {}
        DiaryEntry(string _title , string _id , string _date , string _contents) {
            this->contents = _contents;
            this->date = _date;
            this->id = _id;
            this->title = _title;
        }
};

class DiaryBook{
    private:
        list<DiaryEntry>* diary_book = new list<DiaryEntry>();
    public:
        list<DiaryEntry>* getDiaryBook() {
            return this->diary_book;
        }
};

class Export {
    public:    
        ErrorManager * error = new ErrorManager();

        void savetofile(DiaryBook *Book) {
            ofstream myfile(FileName);
            list<DiaryEntry>* tmp = Book->getDiaryBook();
            try
            {
               if(myfile.is_open()) {
                    for(auto x : *tmp) {
                        myfile << "====== new entry ======== \n";
                        myfile << x.title << "\n";
                        myfile << x.date<< "\n";
                        myfile << x.id<< "\n";
                        myfile << x.contents<< "\n";
                    }
                    myfile.close();
                }else{
                    cout << "Open file faile! \n";
                }
            }
            catch(const std::exception& ex)
            {
                error->GetError(ex);
            }
        }
};

class EntryManager {
    public:
        ErrorManager * error = new ErrorManager();

        void addEntry(DiaryEntry newentry , DiaryBook* Book ){
            try {
                Book->getDiaryBook()->push_back(newentry);
            }
            catch(const std::exception& ex) {
                error->GetError(ex);
            }
        }
       void removeEntry(int idx, DiaryBook* Book) {
        try {
            list<DiaryEntry>* diaryBook = Book->getDiaryBook();
            if (idx >= 0 && idx < diaryBook->size()) {
                auto it = diaryBook->begin();
                std::advance(it, idx);
                diaryBook->erase(it);
            } else {
                cout << "Invalid index!" << endl;
            }
        } catch (const std::exception& ex) {
            error->GetError(ex);
        }
    }
};

class PrintInfo {
    public:
        ErrorManager * error = new ErrorManager();

        void show_book(DiaryBook* book) {

            list<DiaryEntry>* tmp = book->getDiaryBook();
            try
            {
                for(auto x : *tmp) {
                    cout << "====== new entry ======== \n";
                    cout << x.title << endl;
                    cout << x.date << endl;
                    cout << x.id << endl;
                    cout << x.contents << endl;
                }  
            }
            catch(const std::exception& ex)
            {
                error->GetError(ex);
            }
        }
};


int main() {
    DiaryBook* Book = new DiaryBook();
    PrintInfo* Printer = new PrintInfo();
    EntryManager* IO_book = new EntryManager();
    Export* save = new Export();

    IO_book->addEntry({"TOI HAPPY" , "24/04/2023" , 
                        "1" , "Chuan bi toi deadline ma van ngu rat ngon"}
                        , Book
                       ); 

    IO_book->addEntry({"TOI SAD" , "25/04/2023" , 
                        "2" , "Toi mat ngu toi bi diem kem kkkk"}
                        , Book
                       ); 
                       
    IO_book->addEntry({"MY BIRTHDAY" , "02/12/2023" , 
                        "3" , "Happy birthday Min Hiu, chuc ban hoc tap tot hon!"}
                        , Book
                       );

    IO_book->addEntry({"MY MOTHER BIRTHDAY" , "02/12/2023" , 
                        "4" , "to day is a specical day with me!!"}
                        , Book
                       );
                       
    IO_book->removeEntry(3, Book);

    Printer->show_book(Book);
    save->savetofile(Book);
}