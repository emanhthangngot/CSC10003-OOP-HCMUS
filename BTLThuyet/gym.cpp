#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<vector>
#include<fstream>
#include<ctime>
#include<stdio.h>

using namespace std;


class NgayThang {
    public:
        int day;
        int month;
        int year;
        NgayThang() {}
        NgayThang(int d, int m , int y): day(d), month(m), year(y) {}
        bool isLeap(int y) const {
            return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        }
        int toDays() const {
            static const int monthDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
            int days = year * 365 + day;
            for(int i = 0; i< month - 1; ++i) {
                days += monthDay[i];
            }
            for(int i = 0; i < year; i++) {
                if(isLeap(i)) ++days;
            }
            if(isLeap(year) && month > 2) {
                ++days;
            }
            return days;
        } 
        int operator-(const NgayThang& other) {
            return this->toDays() - other.toDays();
        }
};

void getCurrentDate(int *day, int *month, int *year) {
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    *day = local->tm_mday;
    *month = local->tm_mon + 1;  // Tháng bắt đầu từ 0
    *year = local->tm_year + 1900;  // Năm tính từ 1900
}

class GymParticipant {
    private:
        string participant_id;
        NgayThang register_day;
        int vipLevel;
    public:
        void input() {
            int d, m, y;
            cin >> participant_id >> d >> m >> y;
            register_day = NgayThang(d, m, y);
            vipLevel = 1; // default ban đầu
        }
        
        void display() {
            cout << participant_id << " - " 
                << register_day.day << "/" << register_day.month << "/" << register_day.year 
                << " - VIP Level: " << vipLevel << endl;
        }
    
        void updateLevel() {
            NgayThang current;
            getCurrentDate(&current.day, &current.month, &current.year);
            int numberRegisterDay = current - register_day;
            if(numberRegisterDay < 50) vipLevel = 1;
            else if(numberRegisterDay < 150) vipLevel = 2;
            else if (numberRegisterDay >= 350) vipLevel = 3;
        }
};

class GymController {
    private:
        vector<GymParticipant> listParticipant;
    public:
        void getList() {
            for(int i = 0; i< listParticipant.size(); i++) {
                listParticipant[i].updateLevel();
            }
        }

        void inputList(int n) {
            GymParticipant temp;
            for (int i = 0; i < n; ++i) {
                temp.input();
                listParticipant.push_back(temp);
            }
        }

        void displayList() {
            for (auto& p : listParticipant) {
                p.display();
            }
        }
        
};

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    GymController gymStore;
    gymStore.inputList(n);     // Đọc dữ liệu từ file
    gymStore.getList();        // Cập nhật level theo ngày hiện tại
    gymStore.displayList();    // In ra kết quả

}
