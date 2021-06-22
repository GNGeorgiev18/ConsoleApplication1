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
    int capacity = 10;
    vector<REGISTER> bookings = {};
    unsigned int currentBookingNumber = 0;
    int singleRoomCount = capacity * (40.0 / 100.0);
    int doubleRoomCount = capacity * (40.0 / 100.0);
    int mainsonetteRoomCount = capacity * (20.0 / 100.0);
    int i = -1;
    int rentNumber = 0;
public:
    Motel(string name, int capacity)
    {

    }
    /*ROOM_PRICING getRoomPricing()
    {

    }*/

    string rentRoom(string clientName, string roomType, int numberOfNights)
    {
        if (roomType == "singleRoom")
        {
            if (singleRoomCount > 0)
            {
                i++;
                rentNumber++;
                bookings.push_back({ bookings[i].clientName = clientName });
                bookings.push_back({ bookings[i].roomType = roomType });
                //bookings.push_back({ bookings[i].nights = numberOfNights });
                //bookings.push_back({ bookings[i].rentNumber = rentNumber });
                singleRoomCount--;
                return "Enjoy your time here Mr. / Mrs. " + clientName + ". Your booking is " + to_string(rentNumber) + ".";
            }
            return "No " + roomType + " rooms available!" + "Available double rooms: " + to_string(doubleRoomCount) + "Available mainsonette rooms: " + to_string(mainsonetteRoomCount);
        }
        if (roomType == "doubleRoom")
        {
            if (doubleRoomCount > 0)
            {
                i++;
                int rentNumber;
                cin >> rentNumber;
                bookings[i].clientName = clientName;
                bookings[i].roomType = roomType;
                bookings[i].nights = numberOfNights;
                bookings[i].rentNumber = rentNumber;
                doubleRoomCount--;
                return "Enjoy your time here Mr. / Mrs. " + clientName + ". Your booking is " + to_string(rentNumber) + ".";
            }
            return "No " + roomType + " rooms available!" + "Available single rooms: " + to_string(singleRoomCount) + "Available mainsonette rooms: " + to_string(mainsonetteRoomCount);
        }
        if (roomType == "maisonetteRoom")
        {
            if (mainsonetteRoomCount > 0)
            {
                i++;
                int rentNumber;
                cin >> rentNumber;
                bookings[i].clientName = clientName;
                bookings[i].roomType = roomType;
                bookings[i].nights = numberOfNights;
                bookings[i].rentNumber = rentNumber;
                mainsonetteRoomCount--;
                return "Enjoy your time here Mr. / Mrs. " + clientName + ". Your booking is " + to_string(rentNumber) + ".";
            }
            return "No " + roomType + " rooms available!" + "Available single rooms: " + to_string(singleRoomCount) + "Available double rooms: " + to_string(doubleRoomCount);
        }
        return  "Not happening";
    }
};

int main()
{
    Motel m("ssd", 10);
    cout << m.rentRoom("Ivan", "singleRoom", 3);
}