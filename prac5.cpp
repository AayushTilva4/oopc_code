#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int count=0 ;
class circle
{   private:
    int r;
    public:
        circle ()
        {
            r=1;
            count++;
        }
        circle (int r1)
        {
            r = r1;
            count++;
        }
        circle(circle & s)
        {

            r = s.r;
            count++;
        }
        void display()
        {
            cout<<"circle with radius r  "<<r<<" has area : "<<3.14 *r * r<<"\n";
        }

        void act_obj()
        {
            cout<<"total active object is :"<<count<<"\n";
        }
        ~circle()
        {
            cout<<"one object is deleted"<<"\n";
            count--;
            act_obj();
        }
};
int main()
{
    circle a1;
    a1.display();
    circle a2(20);
    a2.display();
    circle a3(a1);
    a3.display();

return 0;

}
