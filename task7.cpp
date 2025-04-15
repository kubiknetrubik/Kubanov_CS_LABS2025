#include <algorithm>
#include <iostream>
#include <string>
#include <list>
#include <random>
#include<iomanip>
//variant 5
class Date {
    private:
       int day;
       int month;
       int year;

    public:
       Date() : day(1), month(1), year(1970) {}

       Date(int d, int m, int y) : day(d), month(m), year(y) {}



       bool operator==(const Date& other) const { return (day == other.day && month == other.month && year == other.year); }

       bool operator<(const Date& other) const {
           if (year != other.year)
               return year < other.year;
           if (month != other.month)
               return month < other.month;
           return day < other.day;
       }
       friend std::ostream& operator<<(std::ostream& out, Date& rec);
       int GetYear() const { return year; }
};
std::ostream& operator<<(std::ostream& out,Date& rec){
    if(rec.day>9&&rec.month>9 ){
        out<<rec.day<<'.'<<rec.month<<'.'<<rec.year<<'\n';
    }
    if(rec.day>9&&rec.month<=9 ){
        out<<rec.day<<'.'<<'0'<<rec.month<<'.'<<rec.year<<'\n';
    }
    if(rec.day<=9&&rec.month>9 ){
        out<<'0'<<rec.day<<'.'<<rec.month<<'.'<<rec.year<<'\n';
    }
    if(rec.day<=9&&rec.month<=9 ){
        out<<'0'<<rec.day<<'.'<<'0'<<rec.month<<'.'<<rec.year<<'\n';
    }

    return out;
}
void print(std::list<Date> list) {
    std::list<Date>::iterator iter;
    for(iter = list.begin();iter!= list.end();++iter){
        std::cout<< *iter;
    }
    std::cout << std::endl;
}

int main() {
    std::list<Date> dates={Date(1, 2, 1963),Date(14, 7, 1995),Date(7, 12, 2088),Date(5, 3, 2030),Date(24, 9, 2013),Date(19, 9, 2020)};
    print(dates);

    std::list<Date> futureDates;
    for (Date date : dates) {
        if (date.GetYear() > 2025) {
            futureDates.push_back(date);
        }
    }

    std::cout << "Future" << std::endl;
    print(futureDates);

    return 0;
}
