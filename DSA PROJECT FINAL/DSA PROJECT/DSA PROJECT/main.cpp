#include <iostream>
#include <bits/stdc++.h>
#include "Admin.h"
#include "User.h"
using namespace std;

int count1=0;
string array_suggestions[20];
 string arr[200];
 int arr_size;
void admin_menu(Admin A)
{
int option;
    cout<<"\n\n\t\tKINDLY SELECT AN OPTION :";
    cout<<"\n\t\t1. ADD DATA";
    cout<<"\n\t\t2. DELETE DATA";
    cout<<"\n\t\t3. MODIFY DATA";
    cout<<"\n\t\t4. DISPLAY DATA";
    cout<<"\n\t\t5. EXIT\n\tOPTION :";
    cin>>option;
    switch(option)
    {
    case 1:
         A.add_data();
         break;
    case 2:
         A.delete_data();
         break;
    case 3:
         A.modify_data();
         break;
    case 4:
        A.display_data();
        break;
    }

}

struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isWordEnd;
};

TrieNode* getNode()
{
    struct TrieNode* Parent_node = new TrieNode;
    Parent_node->isWordEnd = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        Parent_node->children[i] = NULL;

    return Parent_node;
}

void insert(struct TrieNode* root, const string data)
{
    struct TrieNode* current_node=root;
    for (int level=0;level<data.length();level++)
    {
        int index = CHAR_TO_INDEX(data[level]);
       //cout<<"\n\n\tINDEX:"<<index;
        if (!current_node->children[index])
        {//cout<<"\ncheck"<<index;
            current_node->children[index]=getNode();
        }
            current_node=current_node->children[index];
    }

    // mark last node as leaf
    current_node->isWordEnd = true;
}

bool isLastNode(struct TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return 0;
    return 1;
}

void givesuggestions(struct TrieNode* root,string currPrefix)
{
    // found a string in Trie with the given prefix
    if (root->isWordEnd)
        {
            array_suggestions[count1]=currPrefix;
            //cout << currPrefix << endl;
            count1++;
        }

    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i]) {
            // child node character value
            char child = 'a' + i;
            givesuggestions(root->children[i],
                           currPrefix + child);
        }
}

int AutoSuggestions(TrieNode* root, const string query)
{
    struct TrieNode* current_node = root;
    for (char c : query) {
        int ind = CHAR_TO_INDEX(c);
      //cout<<"\n****INDEX"<<ind;
        // no string in the Trie has this prefix
        if (!current_node->children[ind])
            return 0;

        current_node=current_node->children[ind];
    }
    if (isLastNode(current_node))
        {
        cout << query << endl;
        return -1;
    }
    givesuggestions(current_node, query);
    return 1;
}

void User_menu()
{
    int flag=0;
    string data;
    string line;
    int option;
    while(1)
    {
    cout<<"\n\n\t\tWHAT DO YOU WANT TO SEARCH :";
    getline(cin,data);
    struct TrieNode* root = getNode();
    for(int i=0;i<arr_size;i++)
    {
        insert(root,arr[i]);
    }
    int comp = AutoSuggestions(root, data);
    if (comp == -1)
        cout << "NO OTHER COUNTRY DATA FOUND WITH THIS PREFIX\n";

    else if (comp == 0)
        cout << "NO COUNTRY FOUND WITH THIS NAME\n";
    else
    {
    cout<<"\n\n\tTHE AUTO SUGGESTIONS ARE :";
    for(int i=0;i<count1;i++)
    {
        cout<<endl<<"\n\t\t\t"<<i+1<<". "<<array_suggestions[i];
    }
    cout<<"\n\n\t\tWHICH DATA YOU WANT TO SEARCH .PRESS 1 FOR FIRST , 2 FOR SECOND..... ";
    while(1)
    {
         flag=0;
    cout<<"\n\tOPTION : ";
    cin>>option;
    if(option<count1)
    {
        fstream file;
        file.open("Country_info.txt");
        while(file)
        {

        getline(file,line);
        if(line==array_suggestions[option])
        {
            flag=1;
            cout<<"\n\n\t\t\t"<<line;
            for(int i=0;i<5;i++)
            {
                getline(file,line);
                cout<<"\n\t\t\t"<<line;
            }
        }

        }
        if(flag==1)
        {
            file.close();
            break;
        }
    }
    else
    {
        cout<<"WRONG OPTION CHOSEN TRY AGAIN .";
    }
    }
    }
    cout<<"\n\n\t\tDO YOU WANT TO SEARCH MORE , TYPE 1 FOR YES AND 0 FOR NO \n\tOPTION : ";
        cin>>option;
        if(option==1)
        {
            continue;
        }
        else
            break;
    }
}

/**/


int main()
{
    bool a;
    int option;
        cout<<"\n\t\t****************";
        cout<<"\n\t\tWELCOME TO .....";
        cout<<"\n\t\t****************";
    while(1)
    {
        cout<<"\n\n\tCHOOSE AN OPTION : ";
        cout<<"\n\t\t\t1. ADMIN\n\t\t\t2. USER\n\tOPTION = ";
        cin>>option;
        if(option==1)
        {
            Admin A;
            while(1)
            {
            cout<<"\n\n\tCHOOSE AN OPTION : ";
            cout<<"\n\t\t\t1. ALREADY HAVE AN ACCCOUNT: LOGIN\n\t\t\t2. DONOT HAVE AN ACCOUNT: SIGNUP\n\tOPTION = ";
            cin>>option;
            if(option==1)
            {
                a=A.login();
                if(a==1)
                {
                    cout<<"\n\n\tYOU HAVE BEEN SUCCESSFULLY LOGGED IN ";
                    admin_menu(A);
                }
                else
                {
                    cout<<"\n\n\tLOGIN FAILED .";
                    return 0;
                }
                break;
            }
            else if(option==2)
            {
                a=A.signup();
                if(a==1)
                {
                    cout<<"\n\n\tYOU HAVE BEEN SIGNED UP SUCCESSFULLY";
                    admin_menu(A);
                }
                else
                {
                    cout<<"\n\n\tSIGNUP FAILED .";
                    return 0;
                }
                break;
            }
            else
            {
                cout<<"\n\tWRONG OPTION CHOSEN . ENTER AGAIN .";
                continue;
            }
            }
            admin_menu(A);
        }
        else if(option==2)
        {
            User U;
            while(1)
            {
            cout<<"\n\n\tCHOOSE AN OPTION : ";
            cout<<"\n\t\t\t1. ALREADY HAVE AN ACCCOUNT: LOGIN\n\t\t\t2. DONOT HAVE AN ACCOUNT: SIGNUP\n\tOPTION = ";
            cin>>option;
            if(option==1)
            {
                U.login();

                for(int i=0;i<U.size;i++)
                {
                    arr[i]=U.Arr[i];
                }
                arr_size=U.size;
                User_menu();
                break;
            }
            else if(option==2)
            {
                U.signup();
                for(int i=0;i<U.size;i++)
                {
                    arr[i]=U.Arr[i];
                }
                User_menu();
                break;
            }
            else
            {
                cout<<"\n\tWRONG OPTION CHOSEN . ENTER AGAIN .";
                continue;
            }
            }
            //
        }
        else
        {
            cout<<"\n\n\tWRONG INPUT! TRY AGAIN";
            continue;
        }
        break;
    }

    getchar();
    return 0;
}

