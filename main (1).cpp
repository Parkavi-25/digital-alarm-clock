#include <iostream>    // For input and output (cin, cout)
#include <thread>      // For sleeping (pausing the program)
#include <chrono>      // For time functions like seconds
#include <ctime>       // For getting the current date and time

int main() {
    // 1. Get the current time
    std::time_t currentTime = std::time(nullptr);          // Get the current time (in seconds)
    std::tm *localTime = std::localtime(&currentTime);     // Convert it to a readable format

    // 2. Display the current time to the user
    std::cout << "==============================\n";
    std::cout << "     SIMPLE ALARM CLOCK\n";
    std::cout << "==============================\n";
    std::cout << "Current Time: " << std::asctime(localTime);  // Print the current time in a readable format
    std::cout << "------------------------------\n";

    // 3. Ask the user for the alarm time (hour and minute)
    int hour, minute; 
    std::cout << "Enter the hour for the alarm (24-hour format): "; 
    std::cin >> hour;  // Get the hour from the user
    std::cout << "Enter the minute for the alarm: "; 
    std::cin >> minute;  // Get the minute from the user

    // 4. Display the alarm time set by the user
    std::cout << "------------------------------\n";
    std::cout << "Alarm is set for " << hour << ":"
              << (minute < 10 ? "0" : "") << minute << "\n";  // Display the set alarm time
    std::cout << "Simulating countdown...\n";
    std::cout << "------------------------------\n";

    // 5. Simulate a countdown before the alarm goes off
    for (int i = 5; i > 0; --i) {  // Start countdown from 5 seconds
        std::cout << "⏳ Alarm will trigger in " << i << " seconds...\n";  // Show countdown message
        std::this_thread::sleep_for(std::chrono::seconds(1));  // Wait for 1 second
    }

    // 6. Alarm goes off after the countdown
    std::cout << "==============================\n";
    std::cout << "⏰ Alarm Triggered! Wake up!\n";  // This is the alarm message
    std::cout << "==============================\n";

    // 7. End the program successfully
    return 0;  // Program ends here
}

