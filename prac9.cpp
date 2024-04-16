#include<iostream>

using namespace std;

class cm;
class mm
{
    int lmm;
public:
    mm()
    {
        lmm=0;
    }
    mm(float measure)
    {
        lmm=measure/10;
    }
    void display()
    {
        cout<<lmm;
    }

};
class cm
{
    float lcm;
public:
    cm()
    {
        lcm=0;
    }
    cm(float measure)
    {
        lcm=measure*10;
    }
    void display()
    {
        cout<<lcm;
    }
};
int main()
{
    int a;
    cout<<"Enter 1 for mm to cm or 2 for cm to mm";
    cin>>a;

    if(a==1){
        mm m1;
        int c;
        cin>>c;
        m1=c;
        m1.display();

    }
    else{
        cm c1;
        int b;
        cin>>b;
        c1=b;
        c1.display();

    }


    }

