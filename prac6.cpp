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
    static int ave_exp,tot_no;
public:
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
    void putdata(int e_id)
    {
        if (id == e_id)
            {
                cout << "---------------------------------"<<endl;
                cout.width(20);cout <<left<< "Employee Name " << ":"<<name << endl;
                cout.width(20);cout <<left<< "Qualification " << ":"<<qua << endl;
                cout.width(20);cout <<left<< "Experience " << ":"<<exp<< endl;
                cout.width(20);cout <<left<< "Contact Number " <<":"<< contact << endl;
                cout << "---------------------------------"<<endl;
                expe();
            }
    }
    static void expe()
    {
        cout<<"everage exp="<<ave_exp/tot_no;
    }

};
int employee :: ave_exp;
int employee :: tot_no;
int main()
{
    int i;
    int n;
    cout << "Enter no of Employee :";
    cin >> n;
    employee e[n];

   for(i=0 ; i<n ; i++)
   {
    e[i].getdata();
   }
    char x;
    do {
        int e_id;
        cout << "Enter an employee id : ";
        cin >> e_id;

        for (i = 0; i < n; i++)
        {
            e[i].putdata(e_id);

            if(i==n)
            {
                cout << "*"<<endl;
                cout << "ERROR: ENTERED EMPLOYEE ID DOES NOT EXIST."<<endl;
                cout << "*"<<endl;
            }
        }
        cout << endl <<"Press Y to get another employee detail, press N to exit: ";
        cin >> x;
        fflush(stdin);
    } while (x == 'Y' || x == 'y');

    return 0;
}
