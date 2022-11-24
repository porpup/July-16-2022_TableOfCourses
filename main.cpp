//Date: July-16-2022
//Name: Oleksandr Shyryayev
//Description: Table of Courses in C++

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Courses{
    string courseNumber;
    string title;
    double hoursPerWeek;
    string session;
};

void getData(Courses& data, vector <Courses> *vecCourses);
void displayTable(vector <Courses> vecCourses);
void deleteData(vector <Courses> *vecCourses);

int main(){
    char option;
    Courses corses;
    vector <Courses> vecCourses;

    //Adding courses to Table
    vecCourses.push_back({"420-AP1-AS", "Algorithm and Programming", 8, "S2022"});
    vecCourses.push_back({"420-DB1-AS", "DataBases", 8, "S2022"});
    vecCourses.push_back({"420-DW1-AS", "Introduction to Web Development", 4, "S2022"});
    vecCourses.push_back({"201-114-AS", "Applied Mathematics", 2, "S2022"});
    vecCourses.push_back({"420-225-AS", "Computer Achitecture, DOS622", 7, "S2022"});
    vecCourses.push_back({"420-CT1-AS", "Computer Tools", 4, "S2022"});

    //Printing programs header
    cout << "********************************************************" << endl;
    cout << "*             Oleksandr Shyryayev - 2210888            *" << endl;
    cout << "*                    LaSalle Student                   *" << endl;
    cout << "*         Table of Courses (Version: 0.3.8 BETA)       *" << endl;
    cout << "********************************************************" << endl;

    //Main menu
    do{
        cout << " ------------------------------------------------------" << endl;
        cout << "|  '1' -- Display table                                |" << endl;
        cout << "|  '2' -- Input data                                   |" << endl;
        cout << "|  '3' -- Delete data                                  |" << endl;
        cout << "|  '0' -- Exit                                         |" << endl;
        cout << " ------------------------------------------------------" << endl;
        cout << "   Option: ";
        cin >> option;

        switch(option){
        case '1':
            system("cls"); //Hide previously displayed lines
            displayTable(vecCourses);
            break;
        case '2':
            system("cls");
            getData(corses, &vecCourses);
            break;
        case '3':
            system("cls");
            deleteData(&vecCourses);
            break;
        case '0':
            system("cls");
            cout << "Good bye!" << endl;
            cout << "Exiting program..." << endl;
            break;
        default:
            system("cls");
            cout << "\nError: Invalid option..." << endl << endl;
        }
    }while(option != '0');

    return 0;
}

void displayTable(vector <Courses> vecCourses){


    cout << " --------------------------------------------------------------------------------- " << endl;
    cout << "|" << setw(3) << "";
    cout << " |" << setw(14) << "Course number" << " |";
    cout << setw(32) << "Title" << " |";
    cout << setw(15) << "Hours per week" << " |";
    cout << setw(8) << "Session" << " |" << endl;
    cout << " --------------------------------------------------------------------------------- " << endl;

    for(int i=0; i<vecCourses.size(); i++){
        cout << "|" << setw(3) << i + 1;
        cout << " |" << setw(14) << vecCourses[i].courseNumber << " |";
        cout << setw(32) << vecCourses[i].title << " |";
        cout << setw(15) << vecCourses[i].hoursPerWeek << " |";
        cout << setw(8) << vecCourses[i].session << " |" << endl;
        cout << " --------------------------------------------------------------------------------- " << endl;
    }
}

void getData(Courses& data, vector <Courses> *vecCourses){
    //Asking user to add data
    cout << "Enter Course Number: ";
    cin.ignore();
    getline(cin, data.courseNumber);
    cout << "Enter Title: ";
    getline(cin, data.title);
    cout << "Enter Hours per Week: ";
    cin >> data.hoursPerWeek;
    cout << "Enter Session: ";
    cin.ignore();
    getline(cin, data.session);

    vecCourses->push_back({data.courseNumber, data.title, data.hoursPerWeek, data.session}); //adding data to vecCourses
    cout << "\nData has been saved." << endl << endl;
}

void deleteData(vector <Courses> *vecCourses){
    int option;

    displayTable(*vecCourses);
    cout << "Enter number to delete: ";
    cin >> option;
    vecCourses->erase(vecCourses->begin() + (option - 1)); //erase specific data from vector
    system("cls");
    cout << "Number " << option << " has been deleted." << endl << endl;
    displayTable(*vecCourses);
}
