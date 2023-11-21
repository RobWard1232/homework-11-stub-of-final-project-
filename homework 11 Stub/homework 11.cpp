//Name: Robert Ward
//Date: 
//Purpose: the purpose to this program is to intake the specified variables from the console, it then outputs that in proper format into the txt file
//this is just a test sample right now and most likely does not work, the final assignment should be done shortly.

//necessary imports, there may be more in the future.
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <unistd.h>

using namespace std;


//main method
int main () {

    //inputs for general description of the patient
    string input, gender, description, end;
    int age;

    //grabs the username for the computers current user
    const char* username = getenv("USER");
    
    //sets the file path for writing to the txt file
    string filePath = "/Users/" + string(username) + "/Desktop/test/patients.txt";


    //tells program where to output to
    ofstream outputFile(filePath, ios::app);

    //checks for if the file is open, if the file is closed while the program is running it will send an error message
    if (!outputFile.is_open()) {
        cerr << "Failed to open the file." << endl;
        return -1;
    }

    //loop
    while (true) {
    
        cout << endl << "input your patients name: ";

        //input patients name

        cout << endl << "input your patients gender: ";

        //input patients gender

        cout << endl << "input your patients age: ";
        
        //input patients age

        cout << endl << "input your patients general description: ";

        //input patients general description

        //outputs the assigned descriptions to the txt file
        outputFile << "name:" << input << endl;
        outputFile << "gender: "<< gender << endl;
        outputFile << "age: " << age << endl;
        outputFile << "description: "<< description << endl << endl;

        //asks user if they want to log another patient to the database
        cout << "would you like to add another patient to the database? y/n" << endl;
        cin >> end;
        //ignore function to tell the program to ignore this so it does not add its input to the text file.
        cin.ignore();

        //if statements to check if user inputs y to add another patient
        if (end != "y") {
            break;
        } else {
            continue;
        }
    }
    
    //closing output file.
    outputFile.close();

    //success message
    cout << "Data written to file successfully." << endl;

    return 0;
}