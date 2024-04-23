#include <iostream>
#include <iomanip>
#include <ctime>

class Clock {
private:
    int hours;
    int minutes;
    int seconds;
public:
    // Constructor to initialize the time
    Clock(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Function to add hours to the clock
    void addHour(int h) {
        hours = (hours + h) % 24; // 24-hour clock
    }

    // Function to add minutes to the clock
    void addMinute(int m) {
        minutes = (minutes + m) % 60;
        if (minutes < 0) {
            minutes += 60;
            addHour(-1);
        }
    }

    // Function to add seconds to the clock
    void addSecond(int s) {
        seconds = (seconds + s) % 60;
        if (seconds < 0) {
            seconds += 60;
            addMinute(-1);
        }
    }

    // Function to display time in 12-hour format
    void display12Hour() {
        int hour12 = hours % 12;
        if (hour12 == 0) hour12 = 12; // 12-hour clock
        std::cout << std::setfill('0') << std::setw(2) << hour12 << ":"
            << std::setw(2) << minutes << ":" << std::setw(2) << seconds;
        if (hours >= 12) std::cout << " PM";
        else std::cout << " AM";
    }

    // Function to display time in 24-hour format
    void display24Hour() {
        std::cout << std::setfill('0') << std::setw(2) << hours << ":"
            << std::setw(2) << minutes << ":" << std::setw(2) << seconds;
    }
};

// Function to display menu and get user input
void displayMenu(Clock& clock12, Clock& clock24) {
    int choice;
    std::cout << "\nMENU\n";
    std::cout << "1. Add Hour\n";
    std::cout << "2. Add Minute\n";
    std::cout << "3. Add Second\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        int hour;
        std::cout << "Enter hours to add: ";
        std::cin >> hour;
        clock12.addHour(hour);
        clock24.addHour(hour);
        break;
    case 2:
        int minute;
        std::cout << "Enter minutes to add: ";
        std::cin >> minute;
        clock12.addMinute(minute);
        clock24.addMinute(minute);
        break;
    case 3:
        int second;
        std::cout << "Enter seconds to add: ";
        std::cin >> second;
        clock12.addSecond(second);
        clock24.addSecond(second);
        break;
    case 4:
        std::cout << "Exiting...\n";
        exit(0);
    default:
        std::cout << "Invalid choice. Please try again.\n";
    }
}

int main() {
    // Get current time
    std::time_t currentTime;
    std::tm localTime;
    time(&currentTime);
    localtime_s(&localTime, &currentTime);
    int currentHours = localTime.tm_hour;
    int currentMinutes = localTime.tm_min;
    int currentSeconds = localTime.tm_sec;

    // Create clocks with current time
    Clock clock12(currentHours, currentMinutes, currentSeconds);
    Clock clock24(currentHours, currentMinutes, currentSeconds);

    // Main loop
    while (true) {
        // Display menu and process user input
        displayMenu(clock12, clock24);

        // Display both clocks
        std::cout << "\n12-Hour Clock: ";
        clock12.display12Hour();
        std::cout << "\n24-Hour Clock: ";
        clock24.display24Hour();
        std::cout << "\n";
    }

    return 0;
}
