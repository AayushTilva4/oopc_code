#include<iostream>
#include<iomanip>
using namespace std;
class employee
{
    int id;
    string name;
    string qua;
    float exp;
    int contact;
    static int tot_no;
    static float ave_exp;
protected :
    void getdata()
    {
        cout << "Enter Employee id :";
        cin >> id;
        tot_no++;
        fflush(stdin);
        cout << "Enter Employee Name :";
        getline(cin,name);
        fflush(stdin);
        cout << "Enter Qualification :";
        cin>>qua;
        fflush(stdin);
        cout << "Enter Experience :";
        cin >> exp;
        ave_exp+=exp;
        cout << "Enter Contact :";
        cin >> contact;
        fflush(stdin);
    }
    void putdata()
    {
                cout.width(20);cout <<left<< "Employee Name " << ":"<<name << endl;
                cout.width(20);cout <<left<< "Qualification " << ":"<<qua << endl;
                cout.width(20);cout <<left<< "Experience " << ":"<<exp<< endl;
                cout.width(20);cout <<left<< "Contact Number " <<":"<< contact << endl;
    }
    int searchemp(int emp_id)
    {
        if (id==emp_id)
            return 1;
        else
            return 0;
    }

public:
    static void expe()
    {
        cout<<"everage exp="<<ave_exp/tot_no;
    }
};
int employee :: tot_no;
float employee :: ave_exp;

class teaching : public employee
{
    string desi,spec,pays;
public:
    int searchtemp(int ee_id)
    {
        return searchemp(ee_id);
    }
    void gettempdata()
    {
        getdata();
        cout<<"Enter designation of an employee :";
        getline(cin,desi);
        fflush(stdin);
        cout<<"Enter specialization of an employee :";
        getline(cin,spec);
        fflush(stdin);
        cout<<"Enter pay scale of an employee :";
        getline(cin,pays);
        fflush(stdin);
    }
    void puttempdata()
    {
        cout << "---------------------------------"<<endl;
        putdata();
        cout.width(20);cout <<left<< "Designation " << ":"<<desi << endl;
        cout.width(20);cout <<left<< "Specialization " << ":"<<spec << endl;
        cout.width(20);cout <<left<< "pay scale " << ":"<<pays << endl;
        cout << "---------------------------------"<<endl;
        cout<<endl;
        expe();
        cout<<endl<<endl;
    }
};
class nonteaching : public employee
{
    int salary;
public:
    int searchntemp(int eid)
    {
        return searchemp(eid);
    }
    void getntempdata()
    {
        getdata();
        cout<<"Enter salary of an employee :";
        cin>>salary;
    }
    void putntempdata()
    {
        cout << "---------------------------------"<<endl;
        putdata();
        cout.width(20);cout <<left<< "Salary " << ":"<<salary << endl;
        cout << "---------------------------------"<<endl;
        cout<<endl;
        expe();
        cout<<endl<<endl;
    }
};
int main()
{
    int i;
    int te,nte;
    cout << "Enter no of teaching Employee :";
    cin >> te;
    cout << "Enter no of non-teaching Employee :";
    cin >> nte;
    teaching e[te];
    nonteaching ne[nte];
    if (te>0)
        cout<<"Enter teaching employee data :"<<endl;
    for(i=0 ; i<te ; i++)
    {
         e[i].gettempdata();
    }
    if (nte>0)
        cout<<"Enter non-teaching employee data :"<<endl;
    for(i=0 ; i<nte ; i++)
    {
        ne[i].getntempdata();
    }
    char x;
    do {
        int e_id;
        cout << "Enter an employee id : ";
        cin >> e_id;
        int flag =0;
        for (i = 0; i < te; i++)
        {
            if(e[i].searchtemp(e_id))
            {
                e[i].puttempdata();
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            for (i = 0; i < nte; i++)
            {
                if(ne[i].searchntemp(e_id))
                {
                    ne[i].putntempdata();
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0)
            {
                cout << "*"<<endl;
                cout << "ERROR: ENTERED EMPLOYEE ID DOES NOT EXIST."<<endl;
                cout << "*"<<endl;
            }
        cout << endl <<"Press Y to get another employee detail, press N to exit: ";
        cin >> x;
        //fflush(stdin);

    } while (x == 'Y' || x == 'y');

    return 0;
}
