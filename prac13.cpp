#include<iostream>
#include<iomanip>
#include<string.h>
using namespace std;
class employee
{
    int id;
    string name;
    string qua;
    float exp;
    int contact;
    static int ave_exp,tot_no;

protected:
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
        getline(cin,qua);
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

                cout << "---------------------------------"<<endl;
                cout.width(20);cout <<left<< "Employee Name " << ":"<<name << endl;
                cout.width(20);cout <<left<< "Qualification " << ":"<<qua << endl;
                cout.width(20);cout <<left<< "Experience " << ":"<<exp<< endl;
                cout.width(20);cout <<left<< "Contact Number " <<":"<< contact << endl;
                cout << "---------------------------------"<<endl;

    }
    int searchemp(int nid)
    {
        if(nid==id)
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


class t_emp : public employee
{
private:
    string designation;
    string special;
    string pay_scale;

public:
    void getdata()
    {
        employee :: getdata();
        cout<<"Enter the Designation :";
        getline(cin,designation);
        cout<<"Enter the Specialization :";
        getline(cin,special);
        cout<<"Enter the Pay scale :";
        getline(cin,pay_scale);
    }
    void putdata()
    {
        employee :: putdata();
        cout.width(20);cout <<left<< "Designation " << ":"<<designation<< endl;
        cout.width(20);cout <<left<< "Specialization" << ":"<<special << endl;
        cout.width(20);cout <<left<< "Pay scale " << ":"<<pay_scale<< endl;
    }
    int searchemp(int eid)
    {
        /*int p;
        p=employee :: searchemp(eid)*/
        return employee :: searchemp(eid);
    }
};
class non_t_emp : public employee
{
private:
    float salary;
public:
    void getdata()
    {
        employee :: getdata();
        cout<<"Enter salary :";
        cin>>salary;
    }
    void putdata()
    {

        employee :: putdata();
        cout<<salary;
    }
    int searchemp(int eid)
    {

        return employee :: searchemp(eid);
    }
};


int employee :: ave_exp=0;
int employee :: tot_no=0;
int main()
{
    int t_num;
    cout<<"Enter the number of the teaching employees you want to enter :";
    cin>>t_num;
    t_emp tn[t_num];
    for(int i=0;i<t_num;i++)
    {
        tn[i].getdata();
    }

    int n_t_num;
    cout<<"Enter the number of the non-teaching employees you want to enter :";
    cin>>n_t_num;
    non_t_emp nt[n_t_num];
    for(int i=0;i<n_t_num;i++)
    {
        nt[i].getdata();
    }

    char a;
    do
    {
        int eid;
        cout<<"Enter employee id :";
        cin>>eid;
        fflush(stdin);
        int flag=0;
        for(int i=0;i<t_num;i++)
        {
            if(tn[i].searchemp(eid))
            {
                tn[i].putdata();
                flag =1;
                break;
            }
        }

        for(int i=0;i<n_t_num;i++)
        {
            if(nt[i].searchemp(eid))
            {
                nt[i].putdata();
                flag =1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"Error"<<endl;
        }
    cout<<"Enter Y if you want more."<<endl;
    cin>>a;
    }while(a=='y' || a=='Y');

    employee :: expe();
    return 0;
}


