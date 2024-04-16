#include<iostream>

using namespace std;

class complex
{
  private:
    int data,a,b;
  public:
    void getdata()
    {
        cout<<"Enter real part: ";
        cin>>a;
        cout<<"Enter imaginary part: ";
        cin>>b;
    }

    void putdata()
    {
        if(b<0)
        {
            cout<<a<<b<<"i";
        }
        else
        {
            cout<<a<<"+"<<b<<"i";
        }
    }
    complex operator + (complex &z)
    {
        complex temp;
        temp.a = a + z.a;
        temp.b = b + z.b;
        return temp;
    }
    complex operator - (complex &z)
    {
        complex temp;
        temp.a = a - z.a;
        temp.b = b - z.b;
        return temp;
    }
    complex operator * (complex &z)
    {
        complex temp;
        temp.a = (a*z.a)-(b*z.b);
        temp.b = (a*z.b)+(b*z.b);
        return temp;
    }
    complex operator / (complex &z)
    {
        complex temp;
        temp.a = ((a*z.a)+(b*z.b))/(z.a*z.a+b*b);
        temp.b = ((b*z.a)-(a*z.b))/(z.a*z.a+b*b);
        return temp;
    }
    complex  operator ! ()
    {
        complex temp;
        temp.a=-a;
        temp.b=-b;
        return temp;
    }
    //friend complex operator + (complex &z);
    //friend complex operator - (complex &z);
};

int main()
{
    complex w,x,y,u;
    char j;
    x.getdata();
    y.getdata();

    cout<<"Choose operation"<<endl;
    cout<<"(+) Addition"<<endl<<"(-) Subtraction"<<endl<<"(*) Multiplication"<<endl<<"(/) Division"<<endl<<"(!) Negative"<<endl;
    cin>>j;

    if(j=='+')
    {
        w=x+y;
    w.putdata();
    }
    else if(j=='-')
    {
        w=x-y;
        w.putdata();
    }
    else if(j=='*')
    {
        w=x*y;
        w.putdata();
    }
    else if(j=='/')
    {
        w=x/y;
        w.putdata();
    }
    else if(j=='!')
    {
        w=!x;
        u=!y;
        w.putdata();
        cout<<"/n";
        u.putdata();
    }


    return 0;
}
