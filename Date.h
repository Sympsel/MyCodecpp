#ifndef P3_27_DATE_H
#define P3_27_DATE_H

#include "iostream"
using namespace std;


class Date {
public:
    explicit Date(int year = 1970, int month = 1, int day = 1) {
        if (month < 1 || month > 12 || day < 1 || day > getMonthDay(year, month)) {
            cout << "Date: Invalid date" << endl;
            return;
        }
        year_ = year;
        month_ = month;
        day_ = day;
    }

    Date(const Date &date) {
        year_ = date.year_;
        month_ = date.month_;
        day_ = date.day_;
    }

    void show() const {
        cout << year_ << "-" << month_ << "-" << day_ << endl;
    }

    static int getMonthDay(int year, int month) {
        if (month < 1 || month > 12) {
            cout << "getMonthDay: Invalid date" << endl;
            return 0;
        }
        if (month == 2 && ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0))
            return 29;
        int arr[] = {31, 28, 31, 30,
                     31, 30, 31, 31,
                     30, 31, 30, 31};
        return arr[month - 1];
    }

    void setDate(int year, int month, int day) {
        if (month < 1 || month > 12 || day < 1 || day > getMonthDay(year, month)) {
            cout << "setDate: Invalid date" << endl;
            return;
        }
    }

    void setYear(int year) {
        if (year < 1970) {
            cout << "setYear: Invalid date" << endl;
            return;
        }
    }

    void setMonth(int month) {
        if (month < 1 || month > 12) {
            cout << "steMonth: Invalid date" << endl;
            return;
        }
        month_ = month;
    }

    void setDay(int day) {
        if (day < 1 || day > getMonthDay(year_, month_)) {
            cout << "setDay: Invalid date" << endl;
            return;
        }
    }

    [[nodiscard]] int getYear() const { return year_; }

    [[nodiscard]] int getMonth() const { return month_; }

    [[nodiscard]] int getDay() const { return day_; }

    void operator+=(int days) {
        if (days > 0) {
            day_ += days;
            while (day_ > getMonthDay(year_, month_)) {
                day_ -= getMonthDay(year_, month_);
                month_++;
                if (month_ == 13) {
                    month_ = 1;
                    year_++;
                }
            }
        } else if (days < 0) {
            day_ += days;
            while (day_ < 1) {
                month_--;
                if (month_ == 0) {
                    month_ = 12;
                    year_--;
                }
                day_ += getMonthDay(year_, month_);
            }
        }
    }

    Date operator+(int days) const {
        Date newDate(*this);
        newDate += (days);
        return newDate;
    }

    Date operator-(int days) const {
        Date newDate(*this);
        newDate += (days);
        return newDate;
    }

    Date &operator=(const Date &date) {
        if (this != &date) {
            year_ = date.year_;
            month_ = date.month_;
            day_ = date.day_;
        }
        return *this;
    }

    bool operator==(const Date &date) const {
        return year_ == date.year_ && month_ == date.month_ && day_ == date.day_;
    }

    bool operator>(const Date &date) const {
        return year_ > date.year_ ||
                year_ == date.year_ && month_ > date.month_ ||
                year_ == date.year_ && month_ == date.month_ && day_ > date.day_;
    }

    bool operator<(const Date &date) const {
        return year_ < date.year_ ||
                year_ == date.year_ && month_ < date.month_ ||
                year_ == date.year_ && month_ == date.month_ && day_ < date.day_;
    }

    bool operator>=(const Date &date) const {
        return *this > date || *this == date;
    }

    bool operator<=(const Date &date) const {
        return *this < date || *this == date;
    }

private:
    int year_;
    int month_;
    int day_;
};


#endif //P3_27_DATE_H
