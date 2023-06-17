#include<iostream>
#include<string>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<sstream>

using namespace std;

class Sinhvien {
    private:
        string mssv;
        string name;
        double gpa;
    public:
        Sinhvien() {}
        string get_mssv() { return this->mssv; }
        string get_name() { return this->name; }
        friend istream& operator >> (istream& in , Sinhvien& a);
        friend ostream& operator << (ostream& out , Sinhvien a);
};  

istream& operator >> (istream& in , Sinhvien& a){
    in >> a.mssv;
    in.ignore();
    getline(in , a.name);
    in >> a.gpa;
    return in;
}
ostream& operator << (ostream& out , Sinhvien a){
    out << a.mssv << " "
    << a.name << " "
    << a.gpa << "\n";
    return out;
}

class Management{
    private:
        map<string, vector<Sinhvien>> _class;
        map<string, vector<Sinhvien>> _major; 
    public:
        void add_in_class(Sinhvien &a) {
            this->_major[a.get_mssv().substr(0,2)].push_back(a);
        }
        void add_in_major(Sinhvien &a) {
            this->_class[a.get_mssv().substr(2,4)].push_back(a);
        }
        void query_by_class(string str) {
            for(Sinhvien x : this->_class[str]) cout << x;
        }   
        void query_by_major(string str) {
            for(Sinhvien x : this->_major[str]) cout << x;
        }
};


int main() {
    Management Uni;
    cout << "So sinh vien : \n";
    int n; cin >> n;
    for(int i = 0 ; i < n ; i++) {
        Sinhvien tmp; 
        cin >> tmp;
        Uni.add_in_class(tmp);
        Uni.add_in_major(tmp);
    }
    cout << "Tra cuu: number\n";
    int q; cin >> q; 
    while(q--) {
        string info; cin >> info;
        Uni.query_by_class(info);
        Uni.query_by_major(info);
    }
}       
