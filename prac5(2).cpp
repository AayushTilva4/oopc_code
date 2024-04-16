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
        circle(circle *s)
        {

            r = s->r;
            count++;
        }
        void display()
        {
            cout<<"circle with radius r  "<<r<<" has area : "<<3.14 *r * r<<endl<<"\n";
        }

        void act_obj()
        {
            cout<<"total active object is :"<<count<<"\n"<<endl;
        }
        ~circle()
        {
            cout<<"one object is deleted"<<"\n"<<endl;
            count--;
            act_obj();
        }
};
int main()
{
    circle *a1=new circle();
    a1->display();

    circle *a2=new circle(20);
    a2->display();

    circle *a3=new circle(*a1);
    a3->display();
    delete a1;
    delete a2;
    delete a3;

return 0;

}

