#include <iostream>
#include <string>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time() {
        hours = 0;
        minutes = 0;
        seconds = 0;
    }

    Time(int h, int m = 0, int s = 0) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    Time(std::string timeStr) {
        hours = std::stoi(timeStr.substr(0, 2));
        minutes = std::stoi(timeStr.substr(3, 2));
        seconds = std::stoi(timeStr.substr(6, 2));
    }

    Time(long long seconds) {
        hours = seconds / 3600;
        minutes = (seconds % 3600) / 60;
        seconds = seconds % 60;
    }

    long long toSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }

    Time operator+(long long seconds) const {
        return Time(toSeconds() + seconds);
    }

    Time operator-(long long seconds) const {
        return Time(toSeconds() - seconds);
    }

    long long operator-(const Time& other) const {
        return toSeconds() - other.toSeconds();
    }

    bool operator==(const Time& other) const {
        return toSeconds() == other.toSeconds();
    }

    bool operator!=(const Time& other) const {
        return toSeconds() != other.toSeconds();
    }

    bool operator<(const Time& other) const {
        return toSeconds() < other.toSeconds();
    }

    bool operator<=(const Time& other) const {
        return toSeconds() <= other.toSeconds();
    }

    bool operator>(const Time& other) const {
        return toSeconds() > other.toSeconds();
    }

    bool operator>=(const Time& other) const {
        return toSeconds() >= other.toSeconds();
    }

    std::string toString() const {
        std::string timeStr = "";
        if (hours < 10) {
            timeStr += "0";
        }
        timeStr += std::to_string(hours) + ":";
        if (minutes < 10) {
            timeStr += "0";
        }
        timeStr += std::to_string(minutes) + ":";
        if (seconds < 10) {
            timeStr += "0";
        }
        timeStr += std::to_string(seconds);
        return timeStr;
    }
};

int main() {
    Time t1(10, 30, 45);
    Time t2("12:15:30");
    Time t3(3600);

    std::cout << "t1: " << t1.toString() << std::endl;
    std::cout << "t2: " << t2.toString() << std::endl;
    std::cout << "t3: " << t3.toString() << std::endl;

    std::cout << "t1 + 3600: " << (t1 + 3600).toString() << std::endl;
    std::cout << "t2 - 1800: " << (t2 - 1800).toString() << std::endl;

    std::cout << "t2 - t1: " << (t2 - t1) << " seconds" << std::endl;

    std::cout << "t1 == t2: " << (t1 == t2) << std::endl;
    std::cout << "t1 != t2: " << (t1 != t2) << std::endl;
    std::cout << "t1 < t2: " << (t1 < t2) << std::endl;
    std::cout << "t1 <= t2: " << (t1 <= t2) << std::endl;
    std::cout << "t1 > t2: " << (t1 > t2) << std::endl;
    std::cout << "t1 >= t2: " << (t1 >= t2) << std::endl;

    return 0;
}
