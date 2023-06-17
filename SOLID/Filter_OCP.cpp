#include <iostream>
#include <list>
#include <string.h>

        // có thể có nhiểu loại item khác (Product, Phone, Car ...) đều cần có filter => filter is core
        // các tiêu chi so sánh cũng có thể định nghĩa theo hình thức => core thứ 2

using namespace std;

enum TypeFile {txt , csv , cpp};

class FileItem{
    public:    
        string name;
        TypeFile type;
        string date;
    public:
        FileItem() {}
        FileItem(string name_ , TypeFile type_ , string date_) :
                name(name_) , type(type_) , date(date_) {} 
};

class ProductItem{
    public:    
        string name;
        string date;
        int size;
    public:
        ProductItem() {}
        ProductItem(string name_ , string _date , int size_) :
                name(name_) , date(_date) , size(size_) {} 
};

template <class T>
class CriteriaFilter{
    public:
        virtual bool cmp (T item) = 0; 
};

template <class T> 
class AbsFilter{
    public:
        virtual list<T> Filter(list<T> source , CriteriaFilter<T>* ismatch) = 0;
};

class Filter_byName : public CriteriaFilter<FileItem> {
    private:
        string name;
    public:
        Filter_byName (string name_) {
            this->name = name_;
        } 
        bool cmp (FileItem item) override {
            return this->name == item.name;
        }
};

class Filter_byType : public CriteriaFilter<FileItem> {
    private:
        TypeFile type;
    public:
        Filter_byType (TypeFile type_) {
            this->type = type_;
        } 
        bool cmp (FileItem item) override {
            return this->type == item.type;
        }
};

class Filter_byDate : public CriteriaFilter<FileItem> {
    private:
        string date;
    public:
        Filter_byDate (string date_) {
            this->date = date_;
        } 
        bool cmp (FileItem item) override {
            return this->date == item.date;
        }
};

class FileFilter : public AbsFilter<FileItem> {
public: 
    list<FileItem> Filter(list<FileItem> source, CriteriaFilter<FileItem>* ismatch) override {
        list<FileItem> result;
        for (const auto& item : source) {
            if (ismatch->cmp(item)) {
                result.push_back(item);
            }
        }
        return result;
    }
};

class Product_byName : public CriteriaFilter<FileItem> {
    private:
        string date;
    public:
        Product_byName (string date_) {
            this->date = date_;
        } 
        bool cmp (FileItem item) override {
            return this->date == item.date;
        }
};

class Product_bySize : public CriteriaFilter<ProductItem> {
    private:
        int size;
    public:
        Product_bySize (int size_) {
            this->size = size_;
        } 
        bool cmp (ProductItem item) override {
            return this->size == item.size;
        }
};

class ProductFilter : public AbsFilter<ProductItem> {
public: 
    list<ProductItem> Filter(list<ProductItem> source, CriteriaFilter<ProductItem>* ismatch) override {
        list<ProductItem> result;
        for (const auto& item : source) {
            if (ismatch->cmp(item)) {
                result.push_back(item);
            }
        }
        return result;
    }
};

int main() {


}