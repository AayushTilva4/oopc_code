#include<iostream>

using namespace std;

class exp
{
    int y;
    int m;
public:
    exp()
    {
        y=0;
        m=0;
    }
    exp(float experience)
    {
        y=experience;
        m=((experience-y)*12);
    }
    void display()
    {
        cout<<"Employee experience is "<<y<<" year and "<<m<<" months"<<endl;
    }
};
int main()
{
    exp p1;
    float a;
    cout<<"Enter employee experience :";
    cin>>a;
    p1=a;
    p1.display();
}
