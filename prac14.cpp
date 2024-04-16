#include<iostream>
#include<string.h>
using namespace std;

class lit
{
private:
    long int id;
    string title;

public:
    void getdata()
    {
        cout<<"Enter Id: ";
        cin>>id;
        fflush(stdin);
        cout<<"Enter title: ";
        getline(cin,title);
        fflush(stdin);
    }
    void putdata()
    {
        cout<<"Id: ";
        cout<<id;
        cout<<"Title :";
        cout<<title;
    }
};
class e_lit : public virtual lit
{
private:
    string doi;
public:
    void e_getdata()
    {
        //getdata();
        cout<<"Enter DOI: ";
        getline(cin,doi);
        fflush(stdin);
    }
    void e_putdata()
    {
        putdata();
        cout<<" "<<doi;
    }
};
class hb_lit : public virtual lit
{
private:
    int copy_num;
public:
    void hb_getdata()
    {
        //getdata();
        cout<<"Enter number of copies: ";
        cin>>copy_num;
    }
    void hb_putdata()
    {
        putdata();
        cout<<" "<<copy_num;
    }
};
class books : public e_lit,public hb_lit
{
private:
    int ISBN;
    char TB;
public:
    void getbook()
    {
        getdata();
        cout<<"Enter the ISBN number: ";
        cin>>ISBN;
        fflush(stdin);
        cout<<"Enter (E)copy of (H)ardbound: ";
        cin>>TB;
        fflush(stdin);
        if(TB=='e'||TB=='E')
        {
            e_getdata();
        }
        if(TB=='h'||TB=='H')
        {
            hb_getdata();
        }
    }
    void putbook()
    {

        //cout<<"(E)copy of (H)ardbound: "<<TB;
        if(TB=='e'||TB=='E')
        {
            e_putdata();
        }
        if(TB=='h'||TB=='H')
        {
            hb_putdata();
        }
        cout<<ISBN;
    }
};
class mag : public e_lit,public hb_lit
{
private:
    int ISSN;
    char TM;
public:
    void getbook()
    {
        getdata();
        cout<<"Enter the ISSN number: ";
        cin>>ISSN;
        fflush(stdin);
        cout<<"Enter (E)copy of (H)ardbound: ";
        cin>>TM;
        fflush(stdin);
        if(TM=='e'||TM=='E')
        {
            e_getdata();
        }
        if(TM=='h'||TM=='H')
        {
            hb_getdata();
        }
    }
    void putbook()
    {

        //cout<<"(E)copy of (H)ardbound: "<<TM;
        if(TM=='e'||TM=='E')
        {
            e_putdata();
        }
        if(TM=='h'||TM=='H')
        {
            hb_putdata();
        }
        cout<<ISSN;
    }
};

int main()
{
    books b[25];
    mag m[25];

    int count_book=0,count_mag=0;
    char x;
    do
    {
        int a;
        cout<<"Enter 1 : Add book data"<<endl;
        cout<<"Enter 2 : Add magazine data"<<endl;
        cout<<"Enter 3 : List all books"<<endl;
        cout<<"Enter 4 : List all magazine"<<endl;
        cout<<"Enter your choice";
        cin>>a;

        switch(a)
        {
        case 1:char c;
                do
                {
                     b[count_book].getbook();
                     count_book++;
                     cout<<"Do you want to enter another book";
                     cin>>c;
                     fflush(stdin);
                }while(c=='y'||c=='Y');
                break;

        case 2:
            char d;
            do{
                b[count_mag].getdata();
                count_mag++;
                cout<<"Do you want to enter another book";
                cin>>d;
                fflush(stdin);
            }while(d=='y'||d=='Y');
            break;


        case 3:
            cout<<"List all of books";
            for(int i=0;i<count_book;i++)
            {
                b[i].putbook();
                cout<<endl;
            }
            break;


        case 4:
            cout<<"List of all magazines:";
            for(int i=0;i<count_mag;i++)
            {
                m[i].putbook();
                cout<<endl;
            }
            break;
        }
        cout<<"Enter M to get to the menu:";
        cin>>x;

    }while(x=='m'||x=='M');
}
