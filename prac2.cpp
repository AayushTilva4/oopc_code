#include<iostream>
#include<string>
using namespace std;

struct employee
{
    int emp_id;
    string name;
    string qua;
    float exp;
    long int number;

    void getdata()
    {
        cout<<"Enter employee ID : ";
        cin>>emp_id;
        fflush(stdin);
        cout<<"Enter employee name : ";
        cin>>name;
        fflush(stdin);
        cout<<"Enter qualification : ";
        cin>>qua;
        fflush(stdin);
        cout<<"Enter experience : ";
        cin>>exp;
        fflush(stdin);
        cout<<"Enter contact number : ";
        cin>>number;
        fflush(stdin);
    }
    void display()
    {
        cout<<"\n"<<"Employee details are : "<<"\n";
        cout.width(20);
        cout<<left<<"Employee ID is"<<": "<<emp_id<<endl;
        cout.width(20);
        cout<<left<<"Name"<<": "<<name<<endl;
        cout.width(20);
        cout<<left<<"Qualification"<<": "<<qua<<endl;
        cout.width(20);
        cout<<left<<"Experience"<<": "<<exp<<endl;
        cout.width(20);
        cout<<left<<"Contact number"<<": "<<number<<endl;
    }
};

int main()
{
    int n,i,tid;
    char ans;
    cout<<"Enter number of the employee : ";
    cin>>n;

    employee e[n];
    for(i=0;i<n;i++)
    {
        cout<<"Enter details of employee "<<i+1<<": "<<endl;
        e[i].getdata();
    }
    cout<<"\n\n";
    fflush(stdin);
    do
    {
        fflush(stdin);
    cout<<"Enter employee ID :";
    cin>>tid;


    for(i=0;i<n;i++)
    {
        if(e[i].emp_id==tid)
        {
            e[i].display();
            break;
        }

    }
    if(i==n)
    {
        cout<<"Error : Entered employee ID does not exist."<<"\n";
    }
        cout<<"Press Y to get another employee detail, Press N to exit."<<"\n";

        cin>>ans;

    }while(ans=='Y'|| ans=='y');

}
