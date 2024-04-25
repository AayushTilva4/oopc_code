#include <iostream>
#include <string>
#include<iomanip>
using namespace std;
class product
{
protected:
    int id;
    string name;
    string manufaturer;
    float price;

public:
    product(int a, string b, string c, float d)
    {
        id = a;
        name = b;
        manufaturer = c;
        price = d;
    }
    virtual void putdata() = 0;
};
class smartwatch : public product
{
protected:
    float dial_size;

public:
    smartwatch(int a, string b, string c, float d, float t) : product(a, b, c, d)
    {
        dial_size = t;
    }
    void putdata()
    {
        cout<<id<<" : "<<name<<" : "<<manufaturer<<" : "<<price<<" : "<< dial_size<< endl;
    }
};
class bedsheet : public product
{
protected:
    float width, height;

public:
    bedsheet(int a, string b, string c, float d, float u, float i) : product(a, b, c, d)
    {
        width = u;
        height = i;
    }
    void putdata()
    {
        cout <<id<<" : "<<name<<" : "<<manufaturer<<" : "<<price<<" : "<<width<<" : "<<height<< endl;
    }
};
int main()
{
    int n;
    long int id;
    string name;
    string manuf;
    float price;
    float dial_size;
    float width, height;
    cout << "enter 1 for smartwatch menu" << endl;
    cout << "enter 2 for bedsheet menu" << endl;
    cin >> n;
    switch (n)
    {
    case 1:
        cout << "enter product id : ";
        cin >> id;
        cout << "enter product name : ";
        fflush(stdin);
        getline(cin, name);
        cout << "enter product manufacturer : ";
        fflush(stdin);
        getline(cin, manuf);
        cout << "enter product price : ";
        cin >> price;
        cout << "enter product dial size : ";
        cin >> dial_size;
        smartwatch *p;
        p = new smartwatch(id, name, manuf, price, dial_size);
        p->putdata();
        break;
    case 2:
        cout << "enter product id : ";
        cin >> id;
        cout << "enter product name : ";
        fflush(stdin);
        getline(cin, name);
        cout << "enter product manufacturer : ";
        fflush(stdin);
        getline(cin, manuf);
        cout << "enter product price : ";
        cin >> price;
        cout << "enter product width : ";
        cin >> width;
        cout << "enter product heigth : ";
        cin >> height;
        bedsheet *b;
        b = new bedsheet(id, name, manuf, price, width, height);
        b->putdata();
        break;
    }

    return 0;
}
