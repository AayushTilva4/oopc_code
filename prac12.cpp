#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std;
class result;
class student
{
private:
    string id,name;
    int sem;
public:
    void getdata()
    {
        cout<<"Enter id :";
        getline(cin,id);
        cout<<"Enter name :";
        getline(cin,name);
        cout<<"Enter semester :";
        cin>>sem;
    }
    void putdata()
    {
        cout<<"student details : \n";
        cout.width(15);
        cout<<left<<"student ID"<<":"<<id<<"\n";
        cout.width(15);
        cout<<left<<"student name"<<":"<<name<<"\n";
        cout.width(15);
        cout<<left<<"semester"<<":"<<sem<<"\n";
        fflush(stdin);
    }
    void getdata_result(result &r);
    void putdata_result(result &r);
};
class result
{
private:
    char subject[3][20];
    int sub_credit[3];
    int tmarks[3],pmarks[3];
    string tgrade[10],pgrade[10];
    int pgrade_pnt[3],tgrade_pnt[3];
    int tcredit[2]={4,4},pcredit[2]={4,4};
    float sgpa;


    friend void student :: getdata_result(result &);
    friend void student :: putdata_result(result &);
};
void student :: getdata_result(result &r)
    {
        for(int i=0;i<3;i++)
        {
            std::cout<<"Enter "<<i+1<<" subject name :";
            std::cin.getline(r.subject[i],30);
        }
        for(int i=0;i<3;i++)
        {
            cout<<"theory marks of "<<r.subject[i]<<" : ";
            cin>>r.tmarks[i];
            cout<<"practical marks of "<<r.subject[i]<<" : ";
            cin>>r.pmarks[i];
        }
    }
    void student :: putdata_result(result &r)
    {
        for(int i=0;i<3;i++)
        {
            if(r.tmarks[i]>=80)
            {
                r.tgrade[i]="AA";
                r.tgrade_pnt[i] = 10;
            }
            else if(r.tmarks[i]<80 && r.tmarks[i]>=73){
                r.tgrade[i]="AB";
                r.tgrade_pnt[i] = 9;
            }
            else if(r.tmarks[i]<73 && r.tmarks[i]>=66)
            {
                r.tgrade[i]="BB";
                r.tgrade_pnt[i] = 8;
            }
            else if(r.tmarks[i]<66 && r.tmarks[i]>=60)
            {
                r.tgrade[i]="BC";
                r.tgrade_pnt[i] = 7;
            }
            else if(r.tmarks[i]<60 && r.tmarks[i]>=55)
            {
                r.tgrade[i]="CC";
                r.tgrade_pnt[i] = 6;
            }
            else if(r.tmarks[i]<55  && r.tmarks[i]>=50)
            {
                r.tgrade[i]="CD";
                r.tgrade_pnt[i] = 5;
            }
            else if(r.tmarks[i]<50  && r.tmarks[i]>=45)
            {
                r.tgrade[i]="DD";
                r.tgrade_pnt[i] = 4;
            }
            else if(r.tmarks[i]<45)
            {
                r.tgrade[i]="FF";
                r.tgrade_pnt[i] = 0;
            }

            if(r.pmarks[i]>=80)
            {
                r.pgrade[i]="AA";
                r.pgrade_pnt[i] = 10;
            }
            else if(r.pmarks[i]<80 && r.pmarks[i]>=73)
            {
                r.pgrade[i]="AB";
                r.pgrade_pnt[i] = 9;
            }
            else if(r.pmarks[i]<73 && r.pmarks[i]>=66)
            {
                r.pgrade[i]="BB";
                r.pgrade_pnt[i] = 8;
            }
            else if(r.pmarks[i]<66 && r.pmarks[i]>=60)
            {
                r.pgrade[i]="BC";
                r.pgrade_pnt[i] = 7;
            }
            else if(r.pmarks[i]<60 && r.pmarks[i]>=55)
            {
                r.pgrade[i]="CC";
                r.pgrade_pnt[i] = 6;
            }
            else if(r.pmarks[i]<55  && r.pmarks[i]>=50)
            {
                r.pgrade[i]="CD";
                r.pgrade_pnt[i] = 5;
            }
            else if(r.pmarks[i]<50  && r.pmarks[i]>=45)
            {
                r.pgrade[i]="DD";
                r.pgrade_pnt[i] = 4;
            }
            else if(r.pmarks[i]<45)
            {
                r.pgrade[i]="FF";
                r.pgrade_pnt[i] = 0;
            }
        }



        cout.width(25);
        cout<<right<<"Theory";
        cout.width(25);
        cout<<right<<"Practical"<<"\n";
        for(int i=0;i<3;i++)
        {
            cout.width(20);
            cout<<left<<r.subject[i];
            cout.width(20);
            cout<<left<<r.tgrade[i];
            cout.width(20);
            cout<<left<<r.pgrade[i]<<"\n";
        }
        float sum1=0,sum2=0;
        for(int i=0;i<2;i++)
        {
            sum1 = sum1 + ((float)r.tgrade_pnt[i]*r.tcredit[i])/(r.tcredit[i]+r.pcredit[i]);
            sum2 = sum2 + ((float)r.pgrade_pnt[i]*r.pcredit[i])/(r.tcredit[i]+r.pcredit[i]);
        }
        float sgpa;
        r.sgpa=(sum1+sum2)/2;
        std::cout<<"sgpa : ";
        std::cout<<setprecision(2)<<r.sgpa;
    }


int main()
{
    student s1;
    result r1;

    s1.getdata();
    s1.putdata();
    s1.getdata_result(r1);
    s1.putdata_result(r1);

    return 0;
}
