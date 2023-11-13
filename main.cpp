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
        this->type = eventType;
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
    std::string getName() const {
        return name;
    }

    std::string getCity() const {
        return city;
    }

    std::string getVenue() const {
        return venue;
    }

    std::string getDate() const {
        return date;
    }

    std::string getTime() const {
        return time;
    }

    const char* getSeatType() const {
        return seatType;
    }

    const char* getTakenSeatsNormal() const {
        return takenSeatsNormal;
    }

    const char* getTakenSeatsVIP() const {
        return takenSeatsVIP;
    }

    int getNoOfRows() const {
        return noOfRows;
    }

    int getNoOfColumns() const {
        return noOfColumns;
    }

    int getPrice() const {
        return price;
    }

    // Default constructor
    Event() {
        //initialize attributes with default values
        this->name = "Default Event";
        this->city = "Default City";
        this->name = "Default Event";
        this->city = "Default City";
        this->venue = "Default Venue";
        this->date = "1/01/1970";
        this->time = "00:00";
        this->seatType = nullptr;
        this->lengthOfSeatType = 0;
        this->noOfRows = 0;
        this->noOfColumns = 0;
        this->price = 0;
        this->takenSeatsNormal = nullptr;
        this->takenSeatsVIP = nullptr;
    }

     Event(const Event& other) {
        //copy attributes from another instance
        this->name = other.name;
        this->city = other.city;
        this->venue = other.venue;
        this->date = other.date;
        this->time = other.time;

        if (other.seatType != nullptr) {
            int len = std::strlen(other.seatType) + 1;
            this->seatType = new char[len];
            std::strcpy(this->seatType, other.seatType);
        } else {
            this->seatType = nullptr;
        }

        this->lengthOfSeatType = other.lengthOfSeatType;
        this->noOfRows = other.noOfRows;
        this->noOfColumns = other.noOfColumns;
        this->price = other.price;

        //allocating new memory for each array and copying the content
        this->takenSeatsNormal = new char[noOfRows * noOfColumns];
        std::copy(other.takenSeatsNormal, other.takenSeatsNormal + noOfRows * noOfColumns, this->takenSeatsNormal);

        this->takenSeatsVIP = new char[noOfRows * noOfColumns];
        std::copy(other.takenSeatsVIP, other.takenSeatsVIP + noOfRows * noOfColumns, this->takenSeatsVIP);
    }
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
