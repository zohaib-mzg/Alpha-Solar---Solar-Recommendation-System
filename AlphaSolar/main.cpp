//    _____           .__         
//   /     \  _____   |__|  ____  
//  /  \ /  \ \__  \  |  | /    \ 
// /    Y    \ / __ \_|  ||   |  \
// \____|__  /(____  /|__||___|  /
//         \/      \/          \/ 


// All our includes 

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <filesystem>
#include <cstdio>
#include <cmath>
#include "Includes/CustomFunctions/customFuncs.hpp"
#include "Includes/Extras/Logo.hpp"
#include "Includes/Extras/Messages.hpp"
#include "Includes/Extras/Menus.hpp"
#include "Includes/Extras/LoadingBar.hpp"
#include "Includes/ConsumerSection/ConsumerSec.hpp"



using namespace std;

// Main Function

int main() {
    Title();
    system("cls");
    name();
    cout << "\n\nLoading . . . " << endl;
    loadingBar();
    cout << "\n\n";
    MainMenu();
    cout << endl;
    while(true) {
        
        string command = "";
        cout << "Solar >> ";
        getline(cin, command);
        if(command == "solar -m"){ // Call main function
            system("clear");
            name();
            MainMenu();
        }
        else if(command == ""){ // If command is empty
            command = "";
        }
        else if(command == "solar -q"){ // To quit the application
            cout << "\nExitting . . ." << endl;
            system("ping -n 3 loclahost >nul 2>&1");
            bye();
            break;
        }
        else if(command == "solar -h"){ // To go to help menu
            HelpMenu();
        }
        else if(command == "solar -c"){ // To go to command menu
            CommandsMenu();
        }
        else if(command == "solar -u"){ // To go to usage examples
            UsageExamples();
        }
        else if(command == "solar -C"){ // To go to Consumer Section
            system("cls");
            ConsumerManagement();
            system("cls");
            name();
            MainMenu();
        }
        else{
            cout << "\nError! Command not found!\n";
            cout << "Here's the main menu\n";
            MainMenu();
        }
    }
    cout << endl;

    cout << "Hello World!" << endl;
    return 0;
}



// Command for pausing the system
// ping -n 3 loclahost >nul 2>&1