#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct ROOM_PRICING
{
    int singleRoom = 50;
    int doubleRoom = 90;
    int maisonetteRoom = 135;
};

struct REGISTER
{
    string clientName;
    string roomType;
    int nights;
    int rentNumber;
};

class Motel
{
    string name;
    int capacity;
    vector<REGISTER> bookings = {};
    unsigned int currentBookingNumber;
    int singleRoomCount = capacity * (40 / 100);
    int doubleRoomCount = capacity * (40 / 100);
    int mainsonetteRoomCount = capacity * (20 / 100);
    int i = -1;
    Motel(string name, int capacity)
    {

    }
    ROOM_PRICING getRoomPricing()
    {

    }
    void rentRoom(string clientName, string roomType, int numberOfNights)
    {
        if (roomType == "singleRoom" and singleRoomCount > 0)
        {
            i++;
            int rentNumber;
            cin >> rentNumber;
            bookings[i].clientName = clientName;
            bookings[i].roomType = roomType;
            bookings[i].nights = numberOfNights;
            bookings[i].rentNumber = rentNumber;
            singleRoomCount--;
        }
        if (roomType == "doubleRoom" and singleRoomCount > 0)
        {
            i++;
            int rentNumber;
            cin >> rentNumber;
            bookings[i].clientName = clientName;
            bookings[i].roomType = roomType;
            bookings[i].nights = numberOfNights;
            bookings[i].rentNumber = rentNumber;
            singleRoomCount--;
        }
    }
};

int main()
{
    
}