/*
 ID: tony1021
 PROG: friday
 LANG: C++
 */

#include <iostream>
#include <fstream>
using namespace std;

class Date {
private:
    int month;
    int year;
    int day;
    
public:
    
    Date() {
        month = 1;
        year = 1900;
        day = 5; //0~6 correspond Mon thru Sun.
    }
    
    int dayOfNextMonth() {
        switch (month) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                day += 31;
                day %= 7;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                day += 30;
                day %= 7;
                break;
            case 2:
                if (year % 4 != 0) {
                    day += 28;
                    day %= 7;
                } else {
                    if (year % 100 == 0 && year % 400 != 0) {
                        day += 28;
                        day %= 7;
                        break;
                    }
                    day += 29;
                    day %= 7;
                    break;
                }
            default:
                break;
        }
        ++month;
        if (month == 13) {
            month = 1;
            ++year;
        }
        return day;
    }
    
    int getYear() { return year; }
    int getDay() { return day; }
    
};

int main() {
    
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
    
    int N;
    int num[7] = {0,0,0,0,0,1,0};
    
    cin >> N;
    
    Date obj;
    
    while (obj.getYear() - 1900 < N) {
         ++num[ obj.dayOfNextMonth() ];
    }

    --num[ obj.getDay() ];
    
    cout << num[5] << " "
        << num[6] << " ";
    
    for (int i = 0; i < 4; ++i) {
        cout << num[i] << " ";
    }
    cout << num[4] << "\n";
    
    
    return 0;
}
