#include<fstream>
#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;
#include "User.h"


User::User()
{

    fstream file,file1;
    this->nptr==NULL;
    this->fptr==NULL;
    file.open("data.txt",ios::app);
    file.close();
    int flag=0;
    string line;
      int i=0,size=0;
      file1.open("data.txt");
      while(file1)
      {
          getline(file1,line);
          //cout<<endl<<line;
          Arr[i]=line;
          i++;
      }
      this->size=i;
      file1.close();
    //load_data();
}

User::~User()
{
    //dtor
}
void User::signup()
{
               User *temp=new User;
                cout<<"\n\n\n\n\t\t----------------------------------";
		        cout<<"\n\t\t          ACCOUNT SIGN UP";
		        cout<<"\n\t\t----------------------------------";

		        int flag=0;
    string line;
    fstream data_file;
    cout<<"\n\n\tPLEASE ENTER THE FOLLOWING DATA FOR SIGNUP :";
      cin.ignore();
    while(1)
    {
    cout<<"\n\t\tYOUR EMAIL ADDRESS :";

    getline(cin,email);
    data_file.open("User_data.txt");
    while(data_file)
    {
        flag=0;
        getline(data_file,line);
        if(line==email)
        {
            cout<<"\n\tTHIS EMAIL ALREADY EXISTS ,TRY AGAIN";
            data_file.close();
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        continue;
    }
    cout<<"\n\t\tUSER NAME :";
    getline(cin,username);
    cout<<"\n\t\tNAME :";
    getline(cin,name);
    cout<<"\n\t\tPASSWORD :";
    getline(cin,password);
    break;
    }
    data_file.close();
    data_file.open("User_data.txt",ios::app);
    data_file<<endl<<name<<endl;
    data_file<<username<<endl;
    data_file<<email<<endl;
    data_file<<password;
    data_file.close();
}
void User::login()
{
    string line;
    int flag0=0,flag1=0;
    cin.ignore();
    while(1)
    {
    cout<<"\n\tPLEASE ENTER YOUR EMAIL ADDRESS :";
    getline(cin,email);
    fstream data_file;
    data_file.open("User_data.txt");
    while(data_file)
    {
        flag1=0;
        flag0=0;
        getline(data_file,line);
        if(line==email)
        {
            flag1=1;
            getline(data_file,line);
            cout<<"\n\tPASSWORD :";
            getline(cin,password);
            if(line==password)
            {
                flag0=1;
                break;
            }
        }
    }
    if(flag0==1)
    {
        cout<<"\n\t\tYOU HAVE BEEN SUCCESSFULLY LOGGED IN .";
        break;
    }
    else
    {
        cout<<"\n\n\tTHIS EMAIL IS NOT PRESENT";
        continue;
    }
    }
    return;
}
