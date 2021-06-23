#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ROOM_PRICING
{
    int singleRoom;
    int doubleRoom;
    int maisonetteRoom;
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
    vector<REGISTER> bookings;
    unsigned int currentBookingNumber = 0;
    int singleRoomCount = capacity * (40.0 / 100.0);
    int doubleRoomCount = capacity * (40.0 / 100.0);
    int mainsonetteRoomCount = capacity * (20.0 / 100.0);
    int i = -1;
    int rentNumber = 0;
public:
    Motel(string name, int capacity)
    {
        name = name;
        capacity = capacity;
    }

    ROOM_PRICING getRoomPricing()
    {
        ROOM_PRICING room;
        room.singleRoom = 50;
        room.doubleRoom = 90;
        room.maisonetteRoom = 135;
        return room;
    }

    string rentRoom(string clientName, string roomType, int numberOfNights)
    {
        REGISTER temp;
        temp.clientName = clientName;
        temp.roomType = roomType;
        temp.nights = numberOfNights;
        if (roomType == "singleRoom")
        {
            if (singleRoomCount > 0)
            {
                i++;
                rentNumber++;
                temp.rentNumber = rentNumber;
                bookings.push_back(temp);
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

    string checkOut(int bookingNumber)
    {
        if (bookings[bookingNumber-1].roomType == "singleRoom")
        {
            singleRoomCount++;
            return "We hope you enjoyed your time here, Mr. / Mrs. " + bookings[bookingNumber - 1].clientName + ". The total amount of money you have to pay is " + to_string(bookings[bookingNumber - 1].nights * 50) + " BGN.";
        }
        if (bookings[i].roomType == "doubleRoom")
        {
            doubleRoomCount++;
            return "We hope you enjoyed your time here, Mr. / Mrs. " + bookings[bookingNumber - 1].clientName + ". The total amount of money you have to pay is " + to_string(bookings[bookingNumber - 1].nights * 90) + " BGN.";
        }
        if (bookings[i].roomType == "maisonetteRoom")
        {
            mainsonetteRoomCount++;
            return "We hope you enjoyed your time here, Mr. / Mrs. " + bookings[bookingNumber - 1].clientName + ". The total amount of money you have to pay is " + to_string(bookings[bookingNumber - 1].nights * 135) + " BGN.";
        }
        return "The booking " + to_string(bookingNumber) + "is invalid.";
    }
};

int main()
{
    Motel motel = Motel("MedenRudnik", 10);
    cout << motel.rentRoom("Peter", "singleRoom", 3);
    cout << motel.rentRoom("Peter", "singleRoom", 3);
}