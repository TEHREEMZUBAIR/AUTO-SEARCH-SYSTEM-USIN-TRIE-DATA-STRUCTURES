#include<iostream>
#include<string.h>
using namespace std;
#ifndef ADMIN_H
#define ADMIN_H

struct Country{
    string name;
    string Capital;
    string Area;
    string Currency;
    string Population;
    string languages;
    };

typedef Country* Nodeptr;

class Admin
{

    public:
        Admin();
        Country* getNode(void);
        virtual ~Admin();
        bool signup();
        bool login();
        void add_data();
        void delete_data();
        void modify_data();
        void display_data();
        void sort_array(string *arr,int size);
        bool comparator(string a,string b)
{
    return a<b;
}
    private:
        Nodeptr head;
        string *Arr;
        string username;
        string password;
        string name,email;
        Admin *nptr,*fptr,*temp;
};

#endif // ADMIN_H
