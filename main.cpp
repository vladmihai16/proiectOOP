#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
#include <ctime>

enum class EventType { Movie, Sports, Concert };
enum class TicketType { Child, Student, Adult, Elder };
enum class Discounts { Adult = 0, Child = 50, Student = 40, Elder = 30 };

class Event {
private:
    std::string name = "placeholder";
    std::string city = "placeholder";
    std::string venue = "placeholder";
    std::string date = "1/01/1970";
    std::string time = "00:00";
    char* seatType = nullptr;
    int lengthOfSeatType = 0;
    char* takenSeatsNormal = nullptr;
    char* takenSeatsVIP = nullptr;
    int noOfRows = 0;
    int noOfColumns = 0;
    int price = 0;

    // static attributes
    static const int MIN_AGE = 1;
    static const int MIN_CITY_LENGTH = 2;
    static const int MIN_NAME_LENGTH = 2;
    static const int MIN_VENUE_LENGTH = 2;
    static const int MIN_ROWS = 1;
    static const int MIN_COLUMNS = 1;
    static const int MAX_DATE_SIZE = 10;
    static const int MIN_PRICE = 1;

public:
    void setEventType(EventType eventType) {
        // Implementation needed
    }

    void setCity(const std::string& newCity) {
        if (newCity.size() < Event::MIN_CITY_LENGTH) {
            throw std::invalid_argument("City name is too short!");
        }
        this->city = newCity;
    }

    void setName(const std::string& newName) {
        if (newName.size() < Event::MIN_NAME_LENGTH) {
            throw std::invalid_argument("Name is too short!");
        }
        this->name = newName;
    }

    void setDate(const std::string& newDate) {
        if (newDate.size() != Event::MAX_DATE_SIZE) {
            throw std::invalid_argument("Date format is not valid!");
        }
        this->date = newDate;
    }

    void setNoOfRows(int newNumber) {
        if (newNumber >= MIN_ROWS) {
            this->noOfRows = newNumber;
        } else {
            throw std::invalid_argument("Number of rows is too small!");
        }
    }

    void setNoOfColumns(int newNumber) {
        if (newNumber >= MIN_COLUMNS) {
            this->noOfColumns = newNumber;
        } else {
            throw std::invalid_argument("Number of columns is too small!");
        }
    }

    void setTakenSeatsNormal(int row, int column) {
        if (row >= 1 && row <= noOfRows && column >= 1 && column <= noOfColumns) {
            int seatIndex = (row - 1) * noOfColumns + column - 1;
            takenSeatsNormal[seatIndex] = 'O'; //'O' indicates the seat is taken
        } else {
            throw std::out_of_range("Invalid seat coordinates!");
        }
    }

    void setTakenSeatsVIP(int row, int column) {
        if (row >= 1 && row <= noOfRows && column >= 1 && column <= noOfColumns) {
            int seatIndex = (row - 1) * noOfColumns + column - 1;
            takenSeatsVIP[seatIndex] = 'O'; //idem setTakenSeatsNormal
        } else {
            throw std::out_of_range("Invalid seat coordinates!");
        }
    }

    void setPrice(int newPrice) {
        if (newPrice < MIN_PRICE) {
            throw std::invalid_argument("Price is too small");
        }
        this->price = newPrice;
    }

    //Getters 
};

int main() {
    Event myEvent;
    myEvent.setCity("New York");
    myEvent.setNoOfRows(5);
    myEvent.setNoOfColumns(10);
    myEvent.setTakenSeatsNormal(3, 5);
    myEvent.setTakenSeatsVIP(2, 8);

    //... restul codului

    return 0;
}
