#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std;
void print_marksheet();
void sgpa();
int main()
{
   print_marksheet();
   return 0;
}
void print_marksheet()
{
    int semester;
    char student_ID[8],student_name[20];
    std::cout<<"Enter student ID :";
    std::cin>>student_ID;
    std::cout<<"Enter Student Name :";
    std::cin>>student_name;
    std::cout<<"Enter semester :";
    std::cin>>semester;
    fflush(stdin);
    char subject[3][30];
    int tmarks[3],pmarks[3];
    string tgrade[10],pgrade[10];
    int pgrade_pnt[3],tgrade_pnt[3];
    int tcredit[2]={4,4},pcredit[2]={4,4};
    for(int i=0;i<3;i++)
    {
        std::cout<<"Enter "<<i+1<<" subject name :";

        std::cin.getline(subject[i],30);
        //fflush(stdin);
    }
    /*
    for(int i=0;i<3;i++)
    {
        std::cout<<subject[i]<<"\n";
    }*/
    for(int i=0;i<3;i++)
    {
      //cout<<"Enter marks of "<<subject[i];
      cout<<"theory marks of "<<subject[i]<<" : ";

      cin>>tmarks[i];
      cout<<"practical marks of "<<subject[i]<<" : ";
      cin>>pmarks[i];
    }
    for(int i=0;i<3;i++)
    {
        if(tmarks[i]>=80)
        {
            tgrade[i]="AA";
            tgrade_pnt[i] = 10;
        }
        else if(tmarks[i]<80 && tmarks[i]>=73){
            tgrade[i]="AB";
            tgrade_pnt[i] = 9;
        }
        else if(tmarks[i]<73 && tmarks[i]>=66)
        {
            tgrade[i]="BB";
            tgrade_pnt[i] = 8;
        }
        else if(tmarks[i]<66 && tmarks[i]>=60)
        {
            tgrade[i]="BC";
            tgrade_pnt[i] = 7;
        }
        else if(tmarks[i]<60 && tmarks[i]>=55)
        {
            tgrade[i]="CC";
            tgrade_pnt[i] = 6;
        }
        else if(tmarks[i]<55  && tmarks[i]>=50)
        {
            tgrade[i]="CD";
            tgrade_pnt[i] = 5;
        }
        else if(tmarks[i]<50  && tmarks[i]>=45)
        {
            tgrade[i]="DD";
            tgrade_pnt[i] = 4;
        }
        else if(tmarks[i]<45)
        {
            tgrade[i]="FF";
            tgrade_pnt[i] = 0;
        }

        if(pmarks[i]>=80)
        {
            pgrade[i]="AA";
            pgrade_pnt[i] = 10;
        }
        else if(pmarks[i]<80 && pmarks[i]>=73){
            pgrade[i]="AB";
            pgrade_pnt[i] = 9;
        }
        else if(pmarks[i]<73 && pmarks[i]>=66)
        {
            pgrade[i]="BB";
            pgrade_pnt[i] = 8;
        }
        else if(pmarks[i]<66 && pmarks[i]>=60)
        {
            pgrade[i]="BC";
            pgrade_pnt[i] = 7;
        }
        else if(pmarks[i]<60 && pmarks[i]>=55)
        {
            pgrade[i]="CC";
            pgrade_pnt[i] = 6;
        }
        else if(pmarks[i]<55  && pmarks[i]>=50)
        {
            pgrade[i]="CD";
            pgrade_pnt[i] = 5;
        }
        else if(pmarks[i]<50  && pmarks[i]>=45)
        {
            pgrade[i]="DD";
            pgrade_pnt[i] = 4;
        }
        else if(pmarks[i]<45)
        {
            pgrade[i]="FF";
            pgrade_pnt[i] = 0;
        }

    }
    std::cout<<"student details : \n";
    std::cout.width(15);
    std::cout<<left<<"student ID"<<":"<<student_ID<<"\n";
    std::cout.width(15);
    std::cout<<left<<"student name"<<":"<<student_name<<"\n";
    std::cout.width(15);
    std::cout<<left<<"semester"<<":"<<semester<<"\n";
    fflush(stdin);
    cout.width(25);
    cout<<right<<"Theory";

    cout.width(25);
    cout<<right<<"Practical"<<"\n";
     for(int i=0;i<3;i++)
    {
       cout.width(20);
       cout<<left<<subject[i];
       cout.width(20);
       cout<<left<<tgrade[i];
       cout.width(20);
       cout<<left<<pgrade[i]<<"\n";
    }
    float sum1=0,sum2=0;
    for(int i=0;i<2;i++)
    {
        sum1 = sum1 + ((float)tgrade_pnt[i]*tcredit[i])/(tcredit[i]+pcredit[i]);
        sum2 = sum2 + ((float)pgrade_pnt[i]*pcredit[i])/(tcredit[i]+pcredit[i]);
    }
   float sgpa=(sum1+sum2)/2;
   std::cout<<"sgpa : ";
   std::cout<<setprecision(2)<<sgpa;
}

