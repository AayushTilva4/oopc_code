#include<iostream>

using namespace std;

class emp
{
    float e;
    int y=0,m=0;
public:
    operator float()
    {
        return e;
    }
    void getdata()
    {

        cin>>y>>m;
        e=y+(m/12.0);

    }
};
int main()
{
    emp a;
    a.getdata();
    float exp;
    exp=a;
    cout<<exp;


}
