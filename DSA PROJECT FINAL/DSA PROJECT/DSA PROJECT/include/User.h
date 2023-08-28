#include<iostream>
#include<string.h>
#include <bits/stdc++.h>
using namespace std;
#ifndef USER_H
#define USER_H
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

class User
{
    public:
        string Arr[200];
        int size;
        User();
        virtual ~User();
        void signup();
        void login();
        void search_data();
        //void next_page();
        //void previous_page();

    private:
        string username;
        string password;
        string name,email;
        User *nptr,*fptr;
};

#endif // USER_H
