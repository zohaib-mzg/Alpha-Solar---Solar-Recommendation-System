//     ___                                                   __              _    _               
//    / __\ ___   _ __   ___  _   _  _ __ ___    ___  _ __  / _\  ___   ___ | |_ (_)  ___   _ __  
//   / /   / _ \ | '_ \ / __|| | | || '_ ` _ \  / _ \| '__| \ \  / _ \ / __|| __|| | / _ \ | '_ \ 
//  / /___| (_) || | | |\__ \| |_| || | | | | ||  __/| |    _\ \|  __/| (__ | |_ | || (_) || | | |
//  \____/ \___/ |_| |_||___/ \__,_||_| |_| |_| \___||_|    \__/ \___| \___| \__||_| \___/ |_| |_|

// App's consumer section
#include "Input_Validations/InputValidation.hpp"
#include "Parsing/Parsing_Algo.hpp"
#include "Calculations/LoadCalc.hpp"
#include "SomePrivateStuff/somePvtFuncs.hpp"

using namespace std;


// Functions written in the file

void ConsumerSecName(); // Consumer section name
void ConsumerSecMenu(); // Menu of this section
void AddConsumer(); // Add a consumer
void SearchConsumer(); // Search a consumer
void UpdateConsumer(); // Update a consumer
void DeleteConsumer(); // Delete a consumer
void DisplayConsumer(); // Display a consumer


// Main function of this file
void ConsumerManagement() {
    ConsumerSecName();
    ConsumerSecMenu();
    cout << "\n";
    while(true){

        string cmd = "";
        cout << "Solar/ConsumerSection >> ";
        getline(cin, cmd);

        if(cmd == ""){
            cmd = "";
        }
        else if(cmd == "solar -C --menu") {
            cout << endl;
            ConsumerSecMenu();
            cout << endl;
        }
        else if(cmd == "solar -C --add") {
            AddConsumer();
        }
        else if(cmd == "solar -C --delete") {
            DeleteConsumer();
        }
        else if(cmd == "solar -C --update") {
            UpdateConsumer();
        }
        else if(cmd == "solar -C --display") {
            DisplayConsumer();
        }
        else if(cmd == "solar -C --search") {
            SearchConsumer();
        }
        else if(cmd == "solar -C --exit") {
            cout << "\n\nExitting Consumer Section . . . \n\n" << endl;
            cout << "=======================================" << endl;
            system("ping -n 3 localhost >nul 2>&1");
            break;
        }
        else{
            cout << "\nCommand not found!" << endl;
            cout << "Here's the consumer section menu.\n" << endl;
            ConsumerSecMenu();
            cout << endl;
        }
    }
    return;
}


// Other functions

void ConsumerSecName() {
    cout << " \t\t\t\t   ____                                           \n";
    cout << " \t\t\t\t  / ___|___  _ __  ___ _   _ _ __ ___   ___ _ __  \n";
    cout << " \t\t\t\t | |   / _ \\| '_ \\/ __| | | | '_ ` _ \\ / _ \\ '__| \n";
    cout << " \t\t\t\t | |__| (_) | | | \\__ \\ |_| | | | | | |  __/ |    \n";
    cout << " \t\t\t\t  \\____\\___/|_| |_|___/\\__,_|_| |_| |_|\\___|_|    \n";
    cout << " \t\t\t\t / ___|  ___  ___| |_(_) ___  _ __                \n";
    cout << " \t\t\t\t \\___ \\ / _ \\/ __| __| |/ _ \\| '_ \\               \n";
    cout << " \t\t\t\t  ___) |  __/ (__| |_| | (_) | | | |              \n";
    cout << " \t\t\t\t |____/ \\___|\\___|\\__|_|\\___/|_| |_|              \n\n\n";
    return;
}

void ConsumerSecMenu() {
    cout << "\t\t\t\t   ________________   __     _ " << endl;
    cout << "\t\t\t\t   |  |  ||______| \\  ||     | " << endl;
    cout << "\t\t\t\t   |  |  ||______|  \\_||_____| \n\n" << endl;                       
    cout << "\t\t\t\tsolar -C --menu    \t return to menu." << endl;
    cout << "\t\t\t\tsolar -C --add     \t adds a consumer." << endl;
    cout << "\t\t\t\tsolar -C --delete  \t deletes a consumer." << endl;
    cout << "\t\t\t\tsolar -C --search  \t searches a consumer." << endl;
    cout << "\t\t\t\tsolar -C --display \t displays all consumers." << endl;
    cout << "\t\t\t\tsolar -C --update  \t updates a consumer." << endl;
    cout << "\t\t\t\tsolar -C --exit    \t exits consumer section." << endl;
    return;
}

// Consumer Management

void AddConsumer() {
    string ConsumerNo = ConsumerNoValidation();
    string Name = NameValidation();
    string PhoneNo = PhoneNoValidation();
    string Region = region();
    string Address = AddressValidation();
    double placeArea = placeAreaValidation(); // Total area of the place
    double Load = LoadCalculation(); // Total energy consumption per day
    int backupDays = BackupDays(); // Input back up days
    int noOfBatteries = batteryCalc(backupDays, Load);
    double energyRequired = SolarPanelsEst(Load, Region, backupDays); // Total capacity of the solar system that is required

    cout << "\n\nA backup of " << energyRequired << " kw will also be required." << endl;
    cout << "This will require " << noOfBatteries << " battery(s) for back up also." << endl;
    cout << "For these requirements and conditions, a solar panel system of " << energyRequired << " kw is required.\n";
    
    int numPanels = PanelsCalc(energyRequired, placeArea); // Total number of panels
    string status = "--";
    if (canBeInstalled) {
        status = "Installed";
    } else {
        status = "Couldn't be installed";
    }

    InverterPrice(energyRequired); // Calculates inverter price

    // Caculating total Cost
    consumerRecord.totalCost = Total_Cost.batteryCost + Total_Cost.panelsCost + Total_Cost.inverterCost;
    // Profile Handling
    string filePath = "Database/Consumers/" + ConsumerNo + ".txt";
    ofstream Consumer(filePath);
    //ConsumerNo,Name,PhoneNo,Region,Address,TotalLoad(watts),Backup(Days),SolarPanelSystem(kw),No. of Batteries, No. of Panels, status 
    Consumer << ConsumerNo << "," << Name << "," << PhoneNo << "," << Region << "," << Address << "," <<  ceil(Load) << ","<< backupDays << "," << consumerRecord.avgSunlightHours << "," <<  ceil(energyRequired) << "," << noOfBatteries << "," << numPanels << "," << consumerRecord.roofArea << "," << consumerRecord.totalCost << "," << status << endl;
    Consumer.close();
    filePath = "Database/consumerReport.csv";
    ofstream Report;
    Report.open(filePath, ios::app);
    Report << endl;
    Report << ConsumerNo << "," << Name << "," << PhoneNo << "," << Region << "," << Address << "," <<  ceil(Load) << ","<< backupDays << "," << consumerRecord.avgSunlightHours << "," <<  ceil(energyRequired) << "," << noOfBatteries << "," << numPanels << "," << consumerRecord.roofArea << "," << consumerRecord.totalCost << "," << status;
    cout << "\nConsumer Added successfully!\n";
    cout << "\n\nNo. of Batteries         : " << noOfBatteries << endl;
    cout << "No. of Panels            : " << numPanels << endl;
    cout << "Total Cost(PKR)          : " << consumerRecord.totalCost << endl;
    cout << "Status                   : " << status << endl;
    
    // Report generation here
    string reportPath = "Database/Reports/" + ConsumerNo + "_report.txt";
    ofstream report(reportPath);
    report << "That's the report/suggestions for your experience." << endl;
    report << "Total Load (kwh)         : " << Load << endl;
    report << "Average sunlight hours   : " << consumerRecord.avgSunlightHours << endl;
    report << "Roof Area (sq. meter)    : " << consumerRecord.roofArea << endl;
    report << "Energy Required (kwh)    : " << energyRequired << endl;
    report << "Backup (days)            : " << backupDays << endl;
    report << "No. of Batteries         : " << noOfBatteries << endl;
    report << "No. of Panels            : " << numPanels << endl;
    report << "Total Cost(PKR)          : " << consumerRecord.totalCost << endl;
    report << "Status                   : " << status << endl;
    if (status == "Installed") {
        report << "\n\nAccording to your energy needs, these are the best recommendations.\n" << endl;
        report << "By using these equipments, you can save upto 10\% of the total cost which is : " << consumerRecord.totalCost*0.1 << endl;
    } else {
        report << "\n\nAccording to your energy needs, your area is not enough to install the panels." << endl;
        report << "You can contact our mechanical team here -- 'alphasolar.mec@outlook.com'" << endl;
        report << "System can be installed after making some mechanical adjustments." << endl;
    }
    report.close();
    cout << "\n\nA report for better experience is stored at '" << reportPath << "'\n\n\n" << endl;
    cout << "solar -C --menu \t return to main menu\n\n" << endl;
    return;
}


void SearchConsumer() {
    string ConsumerNo = ConsumerNo_Validation();
    string Path = "Database/Consumers/" + ConsumerNo + ".txt";
    string Record, data;
    fstream Consumer(Path);
    if (Consumer.good()) {
        while(getline (Consumer, data)) {
            Record = data;
        }
        Consumer.close();
        // Parsing Algo
        cout << "\nHere's the data of the consumer.\n\n" << endl;
        ParsingAlgo(Record);
        cout << "Consumer No.             : " << consumerRecord.ConsumerNo << endl;
        cout << "Consumer Name            : " << consumerRecord.Name << endl;
        cout << "Consumer Phone No.       : " << consumerRecord.PhoneNo << endl;
        cout << "Consumer Region          : " << consumerRecord.Region << endl;
        cout << "Consumer Address         : " << consumerRecord.Address << endl;
        cout << "Total Load (kwh)         : " << consumerRecord.Load << endl;
        cout << "Average sunlight hours   : " << consumerRecord.avgSunlightHours << endl;
        cout << "Roof Area (sq. meter)    : " << consumerRecord.roofArea << endl;
        cout << "Energy Required (kwh)    : " << consumerRecord.energyRequired << endl;
        cout << "Backup (days)            : " << consumerRecord.backupDays << endl;
        cout << "No. of Batteries         : " << consumerRecord.noOfBatteries << endl;
        cout << "No. of Panels            : " << consumerRecord.noOfPanels << endl;
        cout << "Total Cost(PKR)          : " << consumerRecord.totalCost << endl;
        cout << "Status                   : " << consumerRecord.status << endl;
    } else {
        cout << "\n\nConsumer not Found!\n\n" << endl;
    }
    cout << "\n\nsolar -C --menu    \t return to menu.\n\n" << endl;
    return;
}




void UpdateConsumer() {
    string ConsumerNo = ConsumerNo_Validation();
    string filePath = "Database/Consumers/" + ConsumerNo + ".txt";
    if ( remove(filePath.c_str()) == 0 ) {
        cout << "\nNow enter new credentials to update!\n";
        string Name = NameValidation();
        string PhoneNo = PhoneNoValidation();
        string Region = region();
        string Address = AddressValidation();
        double placeArea = placeAreaValidation(); // Total area of the place
        double Load = LoadCalculation(); // Total energy consumption per day
        int backupDays = BackupDays(); // Input back up days
        int noOfBatteries = batteryCalc(backupDays, Load);
        double energyRequired = SolarPanelsEst(Load, Region, backupDays); // Total capacity of the solar system that is required

        cout << "\n\nA backup of " << energyRequired << " kw will also be required." << endl;
        cout << "This will require " << noOfBatteries << " battery(s) for back up also." << endl;
        cout << "For these requirements and conditions, a solar panel system of " << energyRequired << " kw is required.\n";
    
        int numPanels = PanelsCalc(energyRequired, placeArea); // Total number of panels
        string status = "--";
        if (canBeInstalled) {
            status = "Installed";
        } else {
            status = "Couldn't be installed";
        }

        InverterPrice(energyRequired); // Calculates inverter price

        // Caculating total Cost
        consumerRecord.totalCost = Total_Cost.batteryCost + Total_Cost.panelsCost + Total_Cost.inverterCost;
        // Profile Handling
        string filePath = "Database/Consumers/" + ConsumerNo + ".txt";
        ofstream Consumer(filePath);
        //ConsumerNo,Name,PhoneNo,Region,Address,TotalLoad(watts),Backup(Days),SolarPanelSystem(kw),No. of Batteries, No. of Panels, status 
        Consumer << ConsumerNo << "," << Name << "," << PhoneNo << "," << Region << "," << Address << "," <<  ceil(Load) << ","<< backupDays << "," << consumerRecord.avgSunlightHours << "," <<  ceil(energyRequired) << "," << noOfBatteries << "," << numPanels << "," << consumerRecord.roofArea << "," << consumerRecord.totalCost << "," << status << endl;
        Consumer.close();
        filePath = "Database/consumerReport.csv";
        ofstream Report;
        Report.open(filePath, ios::app);
        Report << endl;
        Report << ConsumerNo << "," << Name << "," << PhoneNo << "," << Region << "," << Address << "," <<  ceil(Load) << ","<< backupDays << "," << consumerRecord.avgSunlightHours << "," <<  ceil(energyRequired) << "," << noOfBatteries << "," << numPanels << "," << consumerRecord.roofArea << "," << consumerRecord.totalCost << "," << status;
        cout << "\nConsumer Added successfully!\n";
    
        // Report generation here
        string reportPath = "Database/Reports/" + ConsumerNo + "_report.txt";
        ofstream report(reportPath);
        report << "That's the report/suggestions for your experience." << endl;
        report << "Total Load (kwh)         : " << Load << endl;
        report << "Average sunlight hours   : " << consumerRecord.avgSunlightHours << endl;
        report << "Roof Area (sq. meter)    : " << consumerRecord.roofArea << endl;
        report << "Energy Required (kwh)    : " << energyRequired << endl;
        report << "Backup (days)            : " << backupDays << endl;
        report << "No. of Batteries         : " << noOfBatteries << endl;
        report << "No. of Panels            : " << numPanels << endl;
        report << "Total Cost(PKR)          : " << consumerRecord.totalCost << endl;
        report << "Status                   : " << status << endl;
        if (status == "Installed") {
            report << "\n\nAccording to your energy needs, these are the best recommendations.\n" << endl;
            report << "By using these equipments, you can save upto 10% of the total cost which is : " << consumerRecord.totalCost*0.1 << endl;
        } else {
            report << "\n\nAccording to your energy needs, your area is not enough to install the panels." << endl;
            report << "You can contact our mechanical team here -- 'alphasolar.mec@outlook.com'" << endl;
            report << "System can be installed after making some mechanical adjustments." << endl;
        }
        report.close();
        cout << "\nConsumer updated successfully!\n" << endl;
        cout << "\n\nNo. of Batteries         : " << noOfBatteries << endl;
        cout << "No. of Panels            : " << numPanels << endl;
        cout << "Total Cost(PKR)          : " << consumerRecord.totalCost << endl;
        cout << "Status                   : " << status << endl;
        cout << "A report is added at '" << reportPath << "'\n\n\n";
    } else {
        cout << "\nConsumer not found!\n";
    }
    cout << "\nsolar -C --menu    \t return to menu.\n\n\n" << endl;
    return;
}

void DeleteConsumer() {
    string ConsumerNo = ConsumerNo_Validation();
    string filePath = "Database/Consumers/" + ConsumerNo + ".txt";
    if (remove(filePath.c_str()) == 0) {
        cout << "\nConsumer successfully deleted!" << endl;
    } 
    else {
        cout << "\nConsumer not found!\n";
    }
    cout << "solar -C --menu    \t return to menu.\n" << endl;
    return;
}

namespace fs = filesystem;  // A namespace for filesystem library
void DisplayConsumer() {
    string folderPath = "Database/Consumers/";
    int i = 1;
    for (const auto& entry : fs::directory_iterator(folderPath)) { // A range based loop; iterates over every file in the data base folder 
        if (entry.is_regular_file() && entry.path().extension() == ".txt") { // Checks if the file is text file
            cout << "Consumer " << i << "\n\n";
            viewConsumer(entry.path()); // Calls the function view Consumer to Display that very consumer
            cout << "\n\n";
            i++;
        }
    }
    cout << "Total Consumers No.  : " << i-1 << endl; // Display Total number of Consumers
    cout << "solar -C --menu    \t return to menu.\n" << endl;
    return;
}