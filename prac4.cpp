#include<iostream>
#include<string.h>
#include<iomanip>
#define pi 3.14

using namespace std;
float area(int r);
int area(int h,int w);
int area(int h,int w,int d);

int main()
{
    int r,h,w,d;
    cout<<"Enter the radius of a circle : ";
    cin>>r;
    cout<<"\nThe area of a circle is :"<<area(r);

    cout<<"\n\nEnter the height of a rectangle : ";
    cin>>h;
    cout<<"\nEnter the width of a rectangle : ";
    cin>>w;
    cout<<"\nThe area of a rectangle is :"<<area(h,w);

    cout<<"\n\nEnter the height of a cuboid :";
    cin>>h;
    cout<<"\nEnter the width of a cuboid :";
    cin>>w;
    cout<<"\nEnter the depth of a cuboid :";
    cin>>d;
    cout<<"\nThe are of a cuboid is : "<<area(h,w,d);
    cout<<"\n\n";
}

float area(int r)
{
    return pi*r*r;
}
int area(int h,int w)
{
    return h*w;
}
int area(int h,int w,int d)
{
    return h*w*d;
}
