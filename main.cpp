#include "Room.h"
#include "Scenic.h"
#include "Courtyard.h"
#include "DeluxeSuite.h"
#include "Penthouse.h"
#include <iostream>
#include <stdlib.h> // for clear console
#include <stdio.h>
#include <iomanip>
#include <vector> // for vector
#include <string> // for converting an integer into string
#include <fstream> // for ifstream and ofstream

using namespace std;

//function prototypes
void displayMainMenu();
string getTodayDate();
void displayBookMenu(int, int, int, int);
void getTotal(int, int, int, int);
string convertString(string);
void openFile();
void outputFile(vector<string>);

int main() {

    int choice, room_choice;
    string sDate;
    string sCustomer, sRoomNum;
    vector<string> vInfo; // to store customers' info
    int cRoom_available = 70;
    int sRoom_available = 35;
    int dRoom_available = 15;
    int pRoom_available = 2;
    int cRoomNumMin = 100;  // Courtyard room number from 101 to 170
    int sRoomNumMin = 200;  // Scenic room number from 201 to 235
    int dRoomNumMin = 235;  // Deluxe room number from 236 to 250 
    int pRoomNumMin = 300;  // Penthouse room number from 301 to 302

    do {

        displayMainMenu();
        cin >> choice;

        //validate input
        while (choice < 1 || choice > 5) {
            cout << "\nInvalid choice\n"
                << "Please choose only from 1 to 3: ";
            cin >> choice;
        }

        if (choice == 1) {
            cout << "\n**************** RESERVE A ROOM ****************\n"
                << "\nHere are the list of available rooms with these prices:\n\n";

            displayBookMenu(cRoom_available, sRoom_available, dRoom_available, pRoom_available);
            cout << "\nPlease enter your choice (from 1 to 4): ";
            cin >> room_choice;

            //Validate input
            while (room_choice < 1 || room_choice > 4) {
                cout << "\nInvalid choice\n"
                    << "Please choose only from 1 to 4: ";
                cin >> room_choice;
            }

            cout << "Enter customer name: ";
            cin.ignore(); //ignore leading whitespace characters from previous input
            getline(cin, sCustomer);

            sCustomer = convertString(sCustomer); // convert input string into title case

            if (room_choice == 1) {
                if (cRoom_available > 0) {
                    Courtyard cRoom;
                    cRoom_available = cRoom.get_cRoom_available();
                    cRoomNumMin++;
                    cout << "\n------------------ A room is reserved ------------------\n\n"
                        << sCustomer << " has reserved Courtyard Room #"
                        << to_string(cRoomNumMin) << "  - $125\n";
                    sCustomer += " - reserved Courtyard Room #" + to_string(cRoomNumMin) + " - $125";
                    vInfo.push_back(sCustomer); 
                }
                else {
                    cout << "\nThere is no more available Courtyard Room\n";
                }
            }
            else if (room_choice == 2) {
                if (sRoom_available > 0) {
                    Scenic sRoom;
                    sRoom_available = sRoom.get_sRoom_available();
                    sRoomNumMin++;
                    cout << "\n------------------ A room is reserved ------------------\n\n"
                        << sCustomer << " has reserved Scenic Room #"
                        << to_string(sRoomNumMin) << "  - $145\n";
                    sCustomer += " - reserved Scenic Room #" + to_string(sRoomNumMin) + " - $145";
                    vInfo.push_back(sCustomer);
                }
                else {
                    cout << "\nThere is no more available Scenic Room\n";
                }
            }
            else if (room_choice == 3) {
                if (dRoom_available > 0) {
                    DeluxeSuite dRoom;
                    dRoom_available = dRoom.get_dRoom_available();
                    dRoomNumMin++;
                    cout << "\n------------------ A room is reserved ------------------\n\n"
                        << sCustomer << " has reserved Deluxe Suite Room #"
                        << to_string(dRoomNumMin) << "  - $350\n";
                    sCustomer += " - reserved Deluxe Room #" + to_string(dRoomNumMin) + " - $350";
                    vInfo.push_back(sCustomer);
                }
                else {
                    cout << "\nThere is no more available DeluxeSuite Room\n";
                }
            }
            else if (room_choice == 4) {
                if (pRoom_available > 0) {
                    Penthouse pRoom;
                    pRoom_available = pRoom.get_pRoom_available();
                    pRoomNumMin++;
                    cout << "\n------------------ A room is reserved ------------------\n\n"
                        << sCustomer << " has reserved Penthouse Room #"
                        << to_string(pRoomNumMin) << "  - $1135\n";
                    sCustomer += " - reserved Penthouse Room #" + to_string(pRoomNumMin) + " - $1135";
                    vInfo.push_back(sCustomer);
                }
                else {
                    cout << "\nThere is no more available Penthouse Room\n";
                }
            }
        
        }
        else if (choice == 2) {
            getTotal(cRoom_available, sRoom_available, dRoom_available, pRoom_available);
        }
        else if (choice == 3) { // read the file 
            openFile();
        }
        else if (choice == 4){
            outputFile(vInfo);
            vInfo.clear(); // empty the vector for future input
        }
        else {
            cout << "\n---------- Exit ----------\n";
            vInfo.clear(); // empty the vector for future input
        }
    } while (choice != 5);


    // displayBookMenu();
}

string getTodayDate() {

    int date, month, year;
    string sDate;

    cout << "\nPlease enter today's date \n(sperated by a space, in the format of MM DD YYYY): ";
    cin >> date >> month >> year;

    //validate inputs assuming the year from 2000 to 2021
    while (date <= 0 || date > 32|| month <= 0 || month > 13 || year < 1999 || year > 2022) {
        cout << "\nInvalid input \nPlease reenter today's date with valid information and the correct format: ";
        cin >> date >> month >> year;
    }

    //convert int type into string
    sDate = to_string(date) + "-" + to_string(month) + "-" + to_string(year);

    return sDate;
}


void displayMainMenu() {

    cout << "\n\n-------- WELCOME TO HOTEL CALIFORNIA -------\n\n"
        << "MAIN MENU\n\n"
        << "[1] Reserve a room\n"
        << "[2] Get revenue\n"
        << "[3] Retrieve customer information\n"
        << "[4] Output information to a file\n"
        << "[5] Exit\n"
        << "\nPlease enter your choice (from 1 to 5): ";
}

void displayBookMenu(int cRoom_available, int sRoom_available, int dRoom_available, int pRoom_available) {
    cout << left
        << setw(17) << "[1] Courtyard " << setw(17) << " - $125 a night  - "
        << setw(2) << 70 - cRoom_available << " room(s) booked - "
        << setw(2) << cRoom_available << " room(s) available\n"
        << setw(17) << "[2] Scenic " << setw(17) << " - $145 a night  - "
        << setw(2) << 35 - sRoom_available << " room(s) booked - "
        << setw(2) << sRoom_available << " room(s) available\n"
        << setw(17) << "[3] Deluxe Suite " << setw(17) << " - $350 a night  - " 
        << setw(2) << 15 - dRoom_available << " room(s) booked - "
        << setw(2) << dRoom_available << " room(s) available\n"
        << setw(17) << "[4] Penthouse " << setw(17) << " - $1135 a night - " 
        << setw(2) << 2 - pRoom_available << " room(s) booked - "
        << setw(2) << pRoom_available << " room(s) available\n"
        << setw(26) << "\nTotal available room(s): " << cRoom_available + sRoom_available + dRoom_available + pRoom_available;
}

void getTotal(int cRoom_available, int sRoom_available, int dRoom_available, int pRoom_available) {
    Room r;
    cout << "\n\n**************** REVENUE ****************\n\n";
    displayBookMenu(cRoom_available, sRoom_available, dRoom_available, pRoom_available);
    cout << left
        << setw(26) << "\nTotal reserved room(s): " << r.get_total_room_booked()
        << setw(26) << "\nTotal revenue: " << "$" << r.get_total_revenue() << "\n\n";
}

void openFile() {
    int date, month, year;
    string sDate;
    string x, sName;
    ifstream inFile;
    int iFind = 0;
    
    cout << "\n\n**************** RETRIEVE INFORMATION ****************\n\n"
        << "\nPlease enter the date you want to retrieve information \n"
        << "(sperated by a space, in the format of MM DD YYYY): ";
    cin >> date >> month >> year;
    //convert int type into string
    sDate = to_string(date) + "-" + to_string(month) + "-" + to_string(year);
    sDate += ".txt";

    inFile.open(sDate);
    // Check for error
    if (inFile.fail()) { // check if file already exists
        cerr << "Error: File cannnot be found";
        exit(1);
    }

    cout << "\nEnter name of the person you want to search: ";
    cin.ignore(); //ignore leading whitespace characters from previous input
    getline(cin, sName);

    sName = convertString(sName);

    cout << "\n---------------------------------------\n"
        << "Opening file: " << sDate << "...\n\n";
  
    while (getline(inFile, x)) { // read each line in the file
        if (x.rfind(sName, 0) == 0) {
            cout << "Found: "
                << x << endl;
            iFind = 1; //flag
        }
    }

    if (iFind == 0) // reach end of the file, but couldn't find the target name
    {
        cout << "Error: Cannot find that name in the file" << endl;
    }
    cout << "\nEnding file...\n";
    inFile.close();
}

string convertString(string sCustomer) {
    // convert input into lowercase
    for (int i = 0; i < sCustomer.length(); i++)
        sCustomer[i] = tolower(sCustomer[i]);

    // convert lowercase into title case
    sCustomer[0] = sCustomer[0] - 32;        //For First Letter

    for (int i = 0; sCustomer[i] != '\0'; i++)
    {
        if (sCustomer[i] == ' ')
        {
            sCustomer[i + 1] = sCustomer[i + 1] - 32;
        }
    }
    return sCustomer;
}

void outputFile(vector<string> vInfo) {
    Room r;
    //get current date
    string sDate = getTodayDate();

    //output file
    ofstream outFile;
    outFile.open(sDate+".txt");
    outFile << sDate << endl <<endl;
    for (int i = 0; i < vInfo.size(); i++)
    {
        outFile << vInfo[i] << endl;
    }
    outFile << endl << "-------------------------" << endl
        << "Total reserved room(s): " << r.get_total_room_booked() << endl
        << "Total revenue: $" << r.get_total_revenue() <<endl;

    outFile.close();
}