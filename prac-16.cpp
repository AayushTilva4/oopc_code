#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class car {
private:
    float mileage;
    int tank_capacity;
    string transmission;
    int seating;
    string airbag;
    string model_name;
    float price;
    string fuel;

public:
    string get_model_name() {
        return model_name;
    }

    string get_fuel() {
        return fuel;
    }

    float get_price() {
        return price;
    }

    void get_detail(string model_name, string fuel, float price, float mileage, string transmission, int tank_capacity, int seating, string airbag) {
        this->model_name = model_name;
        this->fuel = fuel;
        this->price = price;
        this->mileage = mileage;
        this->tank_capacity = tank_capacity;
        this->transmission = transmission;
        this->seating = seating;
        this->airbag = airbag;
    }

    void display() {
        cout << setw(10) << get_model_name();
        cout << setw(10) << get_fuel();
        cout << setw(10) << get_price();
        cout << setw(12) << mileage;
        cout << setw(15) << transmission;
        cout << setw(15) << tank_capacity;
        cout << setw(10) << seating;
        cout << setw(10) << airbag << endl;
    }
};

void display1() {
    cout << setw(10) << left << "Model" << setw(10) << "Fuel" << setw(10) << "Price" << setw(12) << "Mileage" << setw(15) << "Transmission" << setw(15) << "Tank Capacity" << setw(10) << "Seating" << setw(10) << "Airbags" << endl;
    cout << setw(20) << " " << setw(10) << "(Lakhs)" << setw(10) << "(km/L)" << setw(17) << " " << setw(15) << "(Liters)" << setw(12) << "Capacity" << endl;
}

int main() {
    int k = 1, count = 0;
    string car_name[100];
    ifstream inf("cardata.txt");

    if (!inf) {
        cout << "Unable to open file";
        return 1;
    }

    cout << "File opened successfully\n";
    string model_name_name, fuel_type, transmission, airbag;
    string price, mileage, tank_capacity;
    float price1, mileage1, tank_capacity1;
    string seating;
    int seating1;
    car c[100];

    while (inf) {
        getline(inf, model_name_name, ',');
        getline(inf, fuel_type, ',');
        getline(inf, price, ',');
        price1 = stof(price);
        getline(inf, mileage, ',');
        mileage1 = stof(mileage);
        getline(inf, transmission, ',');
        getline(inf, tank_capacity, ',');
        tank_capacity1 = stof(tank_capacity);
        getline(inf, seating, ',');
        seating1 = stoi(seating);
        getline(inf, airbag, ';');

        c[count++].get_detail(model_name_name, fuel_type, price1, mileage1, transmission, tank_capacity1, seating1, airbag);

    }

    inf.close();
    for(int i=0;i<count-1;i++){
        car_name[i] = c[i].get_model_name();
    }

    while (k != 0) {
        cout << endl << "WELCOME TO TATA MOTORS" << endl;
        cout << "GET CAR DETAIL AS PER YOUR PREFERENCE" << endl;
        cout << "(1) model_name NAME" << "   " << "(2) FUEL TYPE" << "   " << "(3) PRICE RANGE" << endl;
        cout << "Enter your option:";
        cin >> k;
        cout << "-----------------------------------------" << endl;

        switch (k) {
            case 1: {
                int car_choose;
                cout << endl << "List of Cars :" << endl;
                for (int i = 0; i < count-1; i++) {
                    cout << i + 1 << " " << car_name[i] << setw(5);
                }
                cout << endl;
                cout << "Choose your car to get detail:";
                cin >> car_choose;
                display1();
                for (int i = 0; i < count-1; i++) {
                    if (c[i].get_model_name() == car_name[car_choose - 1]) {
                        c[i].display();
                        break;
                    }
                }
                break;
            }
            case 2: {
                int a;
                string fuelTypes[] = {"Petrol", "Diesel", "CNG", "EV"};
                cout << "TATA MOTORS Available With Fuel option :" << endl;
                cout << "(1)Petrol  (2)Diesel  (3)CNG  (4)Electric" << endl;
                cout << "Enter Your Fuel Preference :";
                cin >> a;
                display1();
                for (int i = 0; i < count-1; i++) {
                    if (c[i].get_fuel() == fuelTypes[a - 1]) {
                        c[i].display();
                    }
                }
                break;
            }
            case 3: {
                int vy;
                cout << "Enter Your Maximum Affordable Range in Lakhs :";
                cin >> vy;
                display1();
                for (int i = 0; i < count-1; i++) {
                    if (c[i].get_price() <= vy) {
                        c[i].display();
                    }
                }
                break;
            }
        }

        cout << "PRESS 0 TO EXIT OTHERWISE PRESS 1:";
        cin >> k;
    }

    return 0;
}
