#include "header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <chrono>
#include <ctime>

int main(){
    Event myEvent;
    myEvent.setCity("New York");
    myEvent.setNoOfRows(5);
    myEvent.setNoOfColumns(10);
    myEvent.setTakenSeatsNormal(3, 5);
    myEvent.setTakenSeatsVIP(2, 8);

    Buyer john("John Davids", 25, TicketType::Adult);
    BoughtTickets johnsTicket(1, john, 15);

    std::cout << "Event ID: " << johnsTicket.getEventID() << std::endl;
    std::cout << "Buyer: " << johnsTicket.getBuyer()->getName() << std::endl;
    std::cout << "Seat Number: " << johnsTicket.getSeatNumber() << std::endl;
    //restul codului?

    return 0;
}
