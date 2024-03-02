#include <iostream>
#include <string>

using namespace std;

string cal_check(string& x) {
    int weights[] = { 6, 5, 4, 3 };

    int sum = 0;

    for (int i = 0; i < 4; ++i) {
        sum += (x[i] - '0') * weights[i];
    }


    int remainder = sum % 11;


    int checkDigit;
    if (remainder == 0)
        checkDigit = 0;
    else
        checkDigit = 11 - remainder;


    string frequentParkingNumber = x + to_string(checkDigit);

    return frequentParkingNumber;
}

int cal_total(int x, int y) {
    return x * y;
}

float half_discount(int a, int b) {
    return 0.5 * a * b;
}

float tenth_discount(int a, int b) {
    return 0.9 * a * b; // 10% discount means 90% of the original price
}

int main() {
    int dailyTotal = 0; // variable to keep track of the daily total payments
    string day;
    int time_of_arrival;
    int price_per_hour = 0;
    int hours_of_stay;
    char choice;
    string frequent_number;

    cout << "Enter the day of arrival at Parking: ";
    getline(cin, day);
    cout << "Enter the time of arrival between (00_24): ";
    cin >> time_of_arrival;

    cout << "Enter the Price for your stay per hour: ";
    cin >> price_per_hour;

    if (time_of_arrival <= 8 || time_of_arrival >= 24) {
        cout << "Your Time is OUT. You are not allowed to Park." << endl;
    }
    else {
        cout << "Enter the Number of hours you want to leave the car: ";
        cin >> hours_of_stay;
        cout << endl;

        cout << "Do you have any frequent number? if Yes enter (y or Y). if no enter(N or n): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y') {
            cout << "Enter the frequent number for parking: ";
            cin >> frequent_number;
            if (frequent_number == cal_check(frequent_number)) {
                if (time_of_arrival <= 16) 
                { // Before 16:00
                    dailyTotal += cal_total(hours_of_stay, price_per_hour); // Add the total without discount
                }
                else { // After 16:00
                    dailyTotal += cal_total(hours_of_stay, price_per_hour); // Add the total without discount
                    if (time_of_arrival <= 24 && time_of_arrival >= 16) 
                    {
                        cout << "You will get 50% discount." << endl;
                        dailyTotal -= half_discount(hours_of_stay, price_per_hour); // Subtract discount for evening charge
                    }
                    else
                    {
                        cout << "You will get 10% discount." << endl;
                        dailyTotal -= tenth_discount(hours_of_stay, price_per_hour); // Subtract discount for evening charge
                    }
                }
            }
            else {
                cout << "You Entered Wrong Frequent Number." << endl;
                cout << "You will not get any discount. " << endl;
                dailyTotal += cal_total(hours_of_stay, price_per_hour);
            }
        }
        else {
            cout << "You Don't Have any Frequent Number." << endl;
            cout << "You will not get any discount. " << endl;
            dailyTotal += cal_total(hours_of_stay, price_per_hour);
        }

        cout << "The total payment is: " << dailyTotal << endl; // Display total payment at the end of the day
    }

    return 0;
}
