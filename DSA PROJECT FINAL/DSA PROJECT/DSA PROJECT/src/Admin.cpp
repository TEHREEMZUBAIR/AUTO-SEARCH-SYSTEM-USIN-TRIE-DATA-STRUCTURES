#include "Admin.h"
#include<fstream>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

Admin::Admin()
{
};

Admin::~Admin()
{
};

/*void Admin::load_data()
{
    fstream file;
    file.open("signup.txt",ios::in);
    file>>username;
    if(username=="")
    {
        cout<<"FILE IS EMPTY ";
    }
    else
    {
        while(!file.eof())
            {
            Admin *temp=new Admin;
            file>>temp->username;
            file>>temp->name;
            file>>temp->email;
            file>>temp->password;
            if(fptr==NULL)
            {
                temp->nptr=NULL;
                fptr=temp;
            }
            else
            {
                temp->nptr=fptr;
                fptr=temp;
            }
            }
    }
}*/
bool Admin::signup()
{
    int flag=0;
    int count1=0;
    string line;
    fstream data_file;
    cout<<"\n\n\tPLEASE ENTER THE FOLLOWING DATA FOR SIGNUP :";
    cin.ignore();
    while(1)
    {
    cout<<"\n\t\tYOUR EMAIL ADDRESS :";
    getline(cin,email);
    data_file.open("signup.txt");
    while(data_file)
    {
        flag=0;
        getline(data_file,line);
        if(line==email)
        {
            count1++;
            cout<<"\n\tTHIS EMAIL ALREADY EXISTS ,TRY AGAIN";
            data_file.close();
            flag=1;
            break;
        }
        if(count1==2)
        {
            return 0;
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
    data_file.open("signup.txt",ios::app);
    data_file<<endl<<name;
    data_file<<endl<<username;
    data_file<<endl<<email;
    data_file<<endl<<password;
    data_file.close();
    return 1;
    /*Admin *temp=new Admin;
    cout<<"\n\n\tPLEASE ENTER THE FOLLOWING DATA FOR SIGNUP :\n\t\tYOUR FULL NAME :";
    cin>>temp->name;
    cout<<"\n\t\tUSER NAME :";
    cin>>temp->username;
    cout<<"\n\t\tEMAIL ADDRESS:";
    cin>>temp->email;
    cout<<"\n\t\tPASSWORD :";
    cin>>temp->password;
    if(this->fptr==NULL)
    {
        temp->nptr==NULL;
        fptr=temp;
    }
    else
    {
        temp->nptr=fptr;
        fptr=temp;
    }
    cout<<"\n\n\t\tYOU HAVE BEEN SUCCESSFULLY SIGNED UP";*/
}
bool Admin::login()
{
    int count1=0;
    string line;
    int flag0=0,flag1=0;
    cin.ignore();
    cout<<"\n\tPLEASE ENTER YOUR EMAIL ADDRESS :";
    getline(cin,email);
    fstream data_file;
    data_file.open("signup.txt");
    while(data_file)
    {
        flag1=0;
        flag0=0;
        getline(data_file,line);
        if(line==email)
        {
            count1++;
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
        if(count1==2)
        {
            return 0;
        }
    }
    return 1;
}
 void Admin::add_data()
 {
      string *Arr=new string[200];
     fstream file,file1,file2,file3;
     file.open("data.txt",ios::app);
     file.close();
     int flag=0;
      string line;
      string country;
      int i=0,size=0;
      file1.open("data.txt");
      while(file1)
      {
          getline(file1,line);
          //cout<<endl<<line;
          Arr[i]=line;
          i++;
      }
      file1.close();
      size=i;
      cin.ignore();
      cout<<"\n\tENTER THE NAME OF THE COUNTRY THAT YOU WANT TO ADD :";
      getline(cin,country);
      for(i=0;i<size;i++)
      {

          if(Arr[i]==country)
          {
              cout<<"\n\n\tTHIS COUNTRY IS ALREADY PRESENT ,TRY ANOTHER ONE.";
              flag=1;
              return;
          }
      }
      Arr[size]=country;
      sort_array(Arr,++size);
      file2.open("data.txt",ios::out);
      for(i=0;i<size;i++)
      {
          file2<<Arr[i]<<endl;
      }
      file2.close();
      Nodeptr newCountry=new Country();
      cout<<"\n\n\tENTER THE DATA YOU WANT TO ADD";
      cout<<"\n\n\t\tNAME :";
      getline(cin,newCountry->name);
      cout<<"\n\t\tCAPITAL :";
      getline(cin,newCountry->Capital);
      cout<<"\n\t\tAREA :";
      getline(cin,newCountry->Area);
      cout<<"\n\t\tCURRENCY :";
      getline(cin,newCountry->Currency);
      cout<<"\n\t\tPOPULATION :";
      getline(cin,newCountry->Population);
      cout<<"\n\t\tLANGUAGES :";
      getline(cin,newCountry->languages);

      file3.open("Country_info.txt",ios::app);
      file3<<endl<<newCountry->name;
      file3<<endl<<"Capital :"<<newCountry->Capital;
      file3<<endl<<"Area :"<<newCountry->Area;
      file3<<endl<<"Currency :"<<newCountry->Currency;
      file3<<endl<<"Population :"<<newCountry->Population;
      file3<<endl<<"Languages :"<<newCountry->languages;
      file3.close();
 }

 void Admin::delete_data()
 {
     int flag=0;
     string line;
     string delete_country;
     cin.ignore();
     cout<<"\n\n\t\tENTER THE NAME OF THE COUNTRY THAT YOU WANT TO DELET FROM DATA BASE .";
     getline(cin,delete_country);
     fstream file,temp;
     file.open("Country_info.txt");
     temp.open("temp.txt",ios::app);
     while(file)
     {
         flag=0;
         getline(file,line);
         if(line==delete_country)
         {
             flag=1;
             for(int i=0;i<5;i++)
             {
                 getline(file,line);
             }
         }
         else
         {
             temp<<endl<<line;
         }
     }
     file.close();
     remove("Country_info.txt");
     temp.close();
     rename("temp.txt","Country_info.txt");
     if(flag==0)
     {
         cout<<"\n\n\tTHE ENTERED COUNTRY NAME IS NOT PRESENT IN DATA BASE. ";
     }
     else
     {
         cout<<"\n\n\tDATA HAS BEEN DELETED SUCCESSFULLY .";
     }

 }
 void Admin::modify_data()
 {
     int flag=0;
     string line;
     string modify_country;
     cin.ignore();
     cout<<"\n\n\tENTER THE NAME OF THE COUNTRY WHOSE DATA YOU WANT TO MODIFY :";
     getline(cin,modify_country);
    fstream file,temp;
    file.open("Country_info.txt");
    temp.open("temp.txt",ios::app);
    while(file)
    {
        flag=0;
        getline(file,line);
        if(line==modify_country)
        {
            for(int i=0;i<5;i++)
            {
                getline(file,line);
            }
            flag=1;
            Nodeptr newCountry=new Country();
            cout<<"\n\n\t\tNAME :";
            getline(cin,newCountry->name);
            cout<<"\n\t\tCAPITAL :";
            getline(cin,newCountry->Capital);
            cout<<"\n\t\tAREA :";
            getline(cin,newCountry->Area);
            cout<<"\n\t\tCURRENCY :";
            getline(cin,newCountry->Currency);
            cout<<"\n\t\tPOPULATION :";
            getline(cin,newCountry->Population);
            cout<<"\n\t\tLANGUAGES :";
            getline(cin,newCountry->languages);


            temp<<endl<<newCountry->name;
            temp<<endl<<"Capital :"<<newCountry->Capital;
            temp<<endl<<"Area :"<<newCountry->Area;
            temp<<endl<<"Currency :"<<newCountry->Currency;
            temp<<endl<<"Population :"<<newCountry->Population;
            temp<<endl<<"Languages :"<<newCountry->languages;
        }
            temp<<endl<<line;

        }
        file.close();
        remove("Country_info.txt");
        temp.close();
        rename("temp.txt","Country_info.txt");
        if(flag==1)
        {
            cout<<"\n\n\tTHE ENTERED COUNTRY NAME HAS BEEN MODIFIED  IN DATA BASE. ";
        }
        else
        {
            cout<<"\n\n\tTHE ENETERED COUNTRY IS NOT PRESENT IN DATABASE. .";
        }


 }

void Admin::display_data()
{
    fstream file;
    int i=0;
    int j=1;
    string line;
    file.open("Country_info.txt");
    while(file)
    {
        getline(file,line);

        if(i%6==0||i==0)
        {
            cout<<endl<<"\n\t\t"<<j<<". "<<line;
            j++;
        }
        else
        {
            cout<<endl<<"\t\t  "<<"  . "<<line;
        }
i++;
    }
    file.close();
}
 void Admin::sort_array(string *arr,int size)
 {
     for (int startIndex = 0; startIndex < size; startIndex++) {
        int smallestIndex = startIndex;

    for (int currentIndex = startIndex+1; currentIndex < size; currentIndex++) {
            if (arr[currentIndex] < arr[smallestIndex]) {
                smallestIndex = currentIndex;
            }
        }
    swap(arr[startIndex], arr[smallestIndex]);
    }
 }
