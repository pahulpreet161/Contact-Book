#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class contactbook
{
public:
    char name[50];
private:
    char phnumber [10];
public:
    void accept()
    {
        cout<<endl<<"Enter Contact Name";
        cin>>name;
        cout<<endl<<"Enter Phone Number";
        cin>>phnumber;
    }
    void display()
    {
        cout<<endl<<name<<"\t\t"<<phnumber;
    }
};
contactbook obj;
void addname()
{
    obj.accept();
    fstream wr;
    wr.open("contactbook.txt",ios::app);
    wr.write((char *)&obj,sizeof(obj));
    cout<<endl<<"Object Written";
    wr.close();
}
void readname()
{
    fstream rd;
    rd.open("contactbook.txt",ios::in);
    rd.seekg(0,ios::end);
    int n =rd.tellg();
    int nnames=n/sizeof (obj);
    rd.seekg(0,ios::beg);
    for (int i=1;i<=nnames;i++);
    {
        rd.read((char *)&obj,sizeof (obj));
        obj.display();
    }
}
void searchname()
{
    char sr[50];
    cout<<endl<<"Enter Name";
    cin>>sr;
    fstream rd;
    rd.open("contactbook.txt",ios::in);
    rd.seekg(0,ios::end);
    int n=rd.tellg();
    int nnames=n/sizeof(obj);
    rd.seekg(0,ios::beg);
    for (int i=1;i<=nnames;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if (strcmp(sr,obj.name)==0)
            {
                obj.display();
            }
        else
        {
            cout<<"";
        }

    }
}
void removename()
{
    fstream rd,wr;
    rd.open("contactbook.txt",ios::in);
    wr.open("temp.txt",ios::out);

    char s[50];
    cout<<endl<<"Enter Name";
    cin>>s;
    rd.seekg(0,ios::end);
    int n=rd.tellg();
    int nname=n/sizeof(obj);
    rd.seekg(0,ios::beg);

    for (int i=1;i<=nname;i++)
    {
        rd.read((char*)&obj,sizeof(obj));
        if (strcmp(obj.name,s)==0)
        {

            cout<<endl<<"Name Deleted";
        }
        else
        {
            wr.write((char*)&obj,sizeof(obj));
        }
    }
    rd.close();
    wr.close();
    remove("contactbook.txt");
    rename("temp.txt","contactbook.txt");
}


main()
{
    contactbook obj;

    int e=0,choice;
    while (e!=1)
    {
        cout<<endl<<"***********************";
        cout<<endl<<"WELCOME TO CONTACT BOOK";
        cout<<endl<<"***********************";
        cout<<endl<<"Enter 1 to Add The Name";
        cout<<endl<<"Enter 2 to Search The Name";
        cout<<endl<<"Enter 3 to View The name";
        cout<<endl<<"Enter 4 to Delete The Name";
        cout<<endl<<"Enter 5 to Exit";
        cout<<endl<<"Enter CHOICE";
        cin>>choice;
        cout<<"***********************";
        switch (choice)
        {
            case 1:
            {
                addname();
                break;
            }
            case 2:
            {
                searchname();
                break;
            }
            case 3:
            {
                readname();
                break;
            }
            case 4:
            {
                removename();
            }
            case 5:
            {
                e=1;
                break;
            }

        }
    }

}
