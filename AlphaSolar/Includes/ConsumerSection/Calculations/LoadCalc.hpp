//   /$$                                 /$$  /$$$$$$            /$$                     /$$             /$$     /$$                    
//  | $$                                | $$ /$$__  $$          | $$                    | $$            | $$    |__/                    
//  | $$        /$$$$$$   /$$$$$$   /$$$$$$$| $$  \__/  /$$$$$$ | $$  /$$$$$$$ /$$   /$$| $$  /$$$$$$  /$$$$$$   /$$  /$$$$$$  /$$$$$$$ 
//  | $$       /$$__  $$ |____  $$ /$$__  $$| $$       |____  $$| $$ /$$_____/| $$  | $$| $$ |____  $$|_  $$_/  | $$ /$$__  $$| $$__  $$
//  | $$      | $$  \ $$  /$$$$$$$| $$  | $$| $$        /$$$$$$$| $$| $$      | $$  | $$| $$  /$$$$$$$  | $$    | $$| $$  \ $$| $$  \ $$
//  | $$      | $$  | $$ /$$__  $$| $$  | $$| $$    $$ /$$__  $$| $$| $$      | $$  | $$| $$ /$$__  $$  | $$ /$$| $$| $$  | $$| $$  | $$
//  | $$$$$$$$|  $$$$$$/|  $$$$$$$|  $$$$$$$|  $$$$$$/|  $$$$$$$| $$|  $$$$$$$|  $$$$$$/| $$|  $$$$$$$  |  $$$$/| $$|  $$$$$$/| $$  | $$
//  |________/ \______/  \_______/ \_______/ \______/  \_______/|__/ \_______/ \______/ |__/ \_______/   \___/  |__/ \______/ |__/  |__/


// This file contains the following functions
// Some validation functions are also added due to the scope issues
int numApplianceValidation(string appliance); // Handles validation for number of appliances
int HoursValidation(); // Handles input for usage hours of a particular appliance
int LoadValidation(string appliance); // Handles input for power rating of a particular appliance
int LoadValidation(); // Overloaded Function for Validation of Total Load in case the consumer know it
int sunlightHoursValidation(); // Handles input for average sunlight at consumer's place
double LoadCalculation(); // Calculates the total energy of the consumer's place
double SolarPanelsEst(double Load, string region, int bdays); // Estimates the required energy for solar panels system
int batteryCalc(int bdays, double load); // Determines number and prices of batteries selected by consumer
int PanelsCalc(double total_load); // Determines number and prices of panels selected by consumer
void InverterPrice(double Load); // Determines the inverter price selected by the user
bool optionValidation(string option); // Validates if an option is correct


using namespace std;

struct Price { // A struct to store prices of battery, panels and inverter.
    long long batteryCost;
    long long panelsCost;
    long long inverterCost;
} Total_Cost;

int numApplianceValidation(string appliance) {

    string input;
    bool isInvalid;
    int numApp;
    do {
        isInvalid = false;

        if (appliance == "Other") {
            cout << "Enter the number of other appliance(s) you have : ";
            getline(cin, input);
        }
        else {
            cout << "Enter the number of " << appliance << "(s) you have : ";
            getline(cin, input);
        }

        for (int i = 0; i < len(input) && !isInvalid; i++) {
            if (input[i] < 48 || input[i] > 57) {
                isInvalid = true;
                cout << "\nInvlalid Input!" << endl;
            }
        }
        if (!isInvalid) {
            numApp = str_to_int(input);
            if (numApp <= 0) {
                isInvalid = true;
                cout << "\nInvlalid Input!" << endl;
            }
        }
    } while (isInvalid);

    return numApp;

}


// Only for load calculation function

int HoursValidation() {
    int hours;
    bool isInvalid;
    string input;
    do {
        isInvalid = false;
        cout << "Enter the daily usage in hours : ";
        getline(cin, input);
        for (int i = 0; i < len(input) && !isInvalid; i++) {
            if (input[i] < 48 || input[i] > 57) {
                isInvalid = true;
                cout << "\nInvlalid Input!" << endl;
            }
        }
        if (!isInvalid) {
            hours = str_to_int(input);
            if (hours <= 0 || hours > 24) {
                isInvalid = true;
                cout << "\nInvlalid Input! Hours must be greater than 0 and less than or equal to 24!\n" << endl;
            }
        }
        
    } while (isInvalid);
    return hours;
}


int LoadValidation(string appliance) {
    string input;
    int load;
    bool isInvalid;
    do {
        isInvalid = false;
        if (appliance == "Other") {
            cout << "Enter power rating of other appliance(s) in watts: ";
            getline(cin, input);
        }
        else {
            cout << "Enter power rating of " << appliance << "(s) in watts: ";
            getline(cin, input);
        }


        for (int i = 0; i < len(input) && !isInvalid; i++) {
            if (input[i] < 48 || input[i] > 57) {
                isInvalid = true;
                cout << "\nInvlalid Input!" << endl;
            }
        }
        if (!isInvalid) {
            load = str_to_int(input);
            if (load <= 0) {
                isInvalid = true;
                cout << "\nInvlalid Input!" << endl;
            }
        }
        
    } while (isInvalid);
    return load;
}

int LoadValidation() { // Overloaded Function for Validation of Total Load in case the consumer know it
    string input;
    int load;
    bool isInvalid;
    do {

        isInvalid = false;
        cout << "Enter the total required energy of place in watt hour : ";
        getline(cin, input);

        for (int i = 0; i < input.size() && !isInvalid; i++) {
            if (input[i] < 48 || input[i] > 57) {
                isInvalid = true;
                cout << "\nInvlalid Input!" << endl;
            }
        }
        if (!isInvalid) {
            load = stod(input);
            if (load <= 0) {
                isInvalid = true;
                cout << "\nInvlalid Input!" << endl;
            }
        }
        
    } while (isInvalid);
    return load;
}

int sunlightHoursValidation() {
    int hours;
    bool isInvalid;
    string input;
    do {
        isInvalid = false;
        cout << "Enter the daily average sunlight hours : ";
        getline(cin, input);
        for (int i = 0; i < len(input) && !isInvalid; i++) {
            if (input[i] < 48 || input[i] > 57) {
                isInvalid = true;
                cout << "\nInvlalid Input!" << endl;
            }
        }
        if (!isInvalid) {
            hours = str_to_int(input);
            if (hours < 1) {
                isInvalid = true;
                cout << "\nInvlalid Input!" << endl;
            }
        }
        
    } while (isInvalid);
    return hours;
}

bool optionValidation(string option) {
    bool isValid = true;
    if (len(option) == 0) {
        isValid = false;
        cout << "\nInput field empty! please input somethng according to the instructions!\n" << endl;
    } else {
        for (int i = 0; i < len(option) && isValid; i++) {
            if (option[i] < 48 || option[i] > 57) {
                isValid = false;
            }
        }
    }
    return isValid;
}

// Calculation for Load comes here.
double LoadCalculation() {
    double totalLoad = 0;
    int totalHours = 0;
    string doesKnow = "1";
    double load_in_Kwh = 0.0;
    string Appliances[9] = {"Fan", "Bulb", "TV", "Washing Machine", "Air Conditioner", "Iron", "Refrigerator", "Microwave Oven", "Other"};
    
    // ask THE COSTUMER if  he/she knows the total load
    do {
        cout << "Do you know the total required energy of the place?\nEnter 1 in the case you know and 2 if you don't know : ";
        getline(cin, doesKnow);
        if (doesKnow != "1" && doesKnow != "2") {
            cout << "\nInvalid Input!\nTry again.\n" << endl;
        }
    } while (doesKnow != "1" && doesKnow != "2");
    // If Consumer know the total load
    if (doesKnow == "1") {
        totalLoad = ceil(LoadValidation() / 1000.0);
        return totalLoad;
    }
    // Algo to calculate the load
    else if (doesKnow == "2") {
        string repeat = "y";
        string input;
        int applianceNo;
        cout << "\n\t\tCategories of appliances\n";
        cout << setw(5) << left << "No";
        cout << setw(20) << left << "Appliance" << endl;
        for (int i = 0; i < 9; i++) {
            cout << setw(5) << left << i+1;
            cout << setw(20) << left << Appliances[i] << endl;
        }
        // Keeps taking input untill user done with the appliances
        while (repeat == "y") {
            bool isInvalid;
            do {
                cout << "Enter the corresponding number of Appliance to select it : ";
                getline(cin, input);
                if (optionValidation(input)) {
                    applianceNo = str_to_int(input);
                    if ( applianceNo < 1 || applianceNo > 9 ) {
                        cout << "\nInvalid Input!\nTry again.\n";
                    }
                } else if (!optionValidation(input)) {
                    cout << "\nInvalid Input!\nTry again.\n";
                }

            } while ( (!optionValidation(input)) || (applianceNo < 1 || applianceNo > 9) );
            applianceNo -= 1;
            int noOfAppliance = numApplianceValidation(Appliances[applianceNo]);
            int applianceLoad = LoadValidation(Appliances[applianceNo]);
            int hours = HoursValidation();
            float load_kwh = (noOfAppliance * applianceLoad * hours) / 1000.0;
            totalLoad += load_kwh;
            
            do {

                cout << "\nEnter y to select another appliance or to select this one again for different category." << endl;
                cout << "\n\t\tOR\n n other key to exit appliances." << endl;
                getline(cin,repeat);

                if (repeat != "y" && repeat != "n") {
                    cout << "Invalid Input!\nTry again.\n" << endl;
                }
            
            } while (repeat != "y" && repeat != "n");
        }
    }
    totalLoad = ceil(totalLoad);
    return totalLoad;
}


// Estimates the solar panel system's energy
double SolarPanelsEst(double Load, string region, int bdays) {
    // Calculating load in account for region
    if ( region ==  "Equatorial Regions") {
        float sunlightHours = 9.5;
        cout << "\nThe average sunlight hours in the selected region are : " << sunlightHours << " hours." << endl;
        cout << "For minimum uncertainty, input the sunlight hours exactly at the concerned place." << endl;
    }
    else if ( region ==  "Tropical Regions" || region == "Subtropical Regions") {
        cout << "\nThe average sunlight hours in the selected region are 7-9 hours." << endl;
        cout << "For minimum uncertainty, input the sunlight hours exactly at the concerned place." << endl;
    }
    else if ( region ==  "Temperate Regions") {
        cout << "\nThe average sunlight hours in the selected region are generally 5-8 hours." << endl;
        cout << "For minimum uncertainty, input the sunlight hours exactly at the concerned place." << endl;
    }
    else if ( region ==  "Polar Regions") {
        cout << "\nThe average sunlight hours in the selected region vary between 0-24 hours." << endl;
        cout << "For minimum uncertainty, input the sunlight hours exactly at the concerned place." << endl;
    }

    consumerRecord.avgSunlightHours = sunlightHoursValidation(); // Sunlight hours
    double energy_needed = Load / 0.80; // Divided the total energy by derating factor = 0.8 in account for efficiency losses
    energy_needed *= bdays;
    energy_needed = ceil(energy_needed);
    return energy_needed; // kwh
}

int batteryCalc(int bdays, double load) {
    load /= 0.8; // Account for efficiency losses
    double BackupRequired = load * bdays;
    string brands[11] = {"Osaka", "Osaka", "Osaka", "AGS", "AGS", "Exide", "Exide", "Phoenix", "Phoenix", "Volta", "Volta"};
    string models[11] = {"12GEN-MR45", "CR65L+", "MF-100L", "GR-65", "HB-100R Atlas Hybrid", "N65L", "EX110R", "XP-75R", "TX-1100", "CR65L+", "MF75L"};
    int volts[11] = {32, 24, 40, 60, 48, 32, 32, 32, 48, 32, 60};
    int capacity[11] = {50, 80, 225, 180, 80, 45, 100, 60, 125, 80, 225};
    int price[11] = {9000, 12100, 19000, 13400, 20500, 13100, 21500, 15200, 33000, 13100, 14800};
    
    cout << "\n\n\t\tBattery Menu\n" << endl;
    cout << setw(4) << left << "No. ";
    cout << setw(10) << left << "Brand";
    cout << setw(22) << left << "Model";
    cout << setw(7) << left << "Volts";
    cout << setw(17) << left << "Capacity(Ah)";
    cout << setw(15) << left << "Price(PKR)" << endl;
    for (int i = 0; i < 11; i++) {
        cout << setw(4) << left << i+1;
        cout << setw(10) << left << brands[i];
        cout << setw(22) << left << models[i];
        cout << setw(7) << left << volts[i];
        cout << setw(17) << left << capacity[i];
        cout << setw(15) << left << price[i] << endl;
    }
    // Input validation for option
    cout << "\n\n\n" << endl;
    int option;
    string input;
    do {
        cout << "Enter corressponding number of battery to select it : ";
        getline(cin, input);
        if (optionValidation(input)) {
            option = str_to_int(input);
            if ( option < 1 || option > 11 ) {
                cout << "\nInvalid Input!\nTry again.\n";
            }
        } else if (!optionValidation(input)) {
            cout << "\nInvalid Input!\nTry again.\n";
        }
    } while ( (!optionValidation(input)) || (option < 1 || option > 11) );
    option--;
    // Calculation for batteries
    double energy_capacity = capacity[option] * volts[option] / 1000.0;
    double noOfBatteries = ceil(BackupRequired / energy_capacity);
    int NoOfBatteries = noOfBatteries;
    Total_Cost.batteryCost = NoOfBatteries * price[option];
    return NoOfBatteries;
}

bool canBeInstalled;

int PanelsCalc(double total_load, double totalArea) {
    // total load is the required energy in kwh
    int size = 6;
    total_load *= 1000; // Required energy (wh)
    string models[6] = {"LONGI Mono Perc", "LONGI HIMO 6", "LONGI Mono Perc", "LONGI HIMO 6 Mono", "LONGI Mono Perc", "LONGI HIMO 6"}; 
    int capacity[6] = {560, 585, 550, 575, 555, 580}; // Wh
    string dimensions[6] = {"2278x1134x30", "2278x1134x30", "2278x1134x30", "2278x1134x30", "2278x1134x30", "2278x1134x30"}; // mm
    double prices[6] = {31920, 33345, 39050, 48720, 39950, 39440}; // Rupees
    
    cout << "\n\n\t\tSolar Panels menu\n" << endl;
    cout << setw(4) << left << "No.";
    cout << setw(22) << left << "Name";
    cout << setw(14) << left << "Capacity(Wh)";
    cout << setw(20) << left << "Dimensions(mm)";
    cout << setw(10) << left << "Price(PKR)" << endl;
    for (int i = 0; i < size; i++) {
        cout << setw(4) << left << i+1;
        cout << setw(22) << left << models[i];
        cout << setw(14) << left << capacity[i];
        cout << setw(20) << left << dimensions[i];
        cout << setw(6) << left << prices[i] << endl;
    }
    cout << "\n\nEnter the corresponding number of solar panels to select it.\n\n";
    int option;
    string input;
    do {
        cout << "Enter the panel number : ";
        getline(cin, input);
        if (optionValidation(input)) {
            option = str_to_int(input);
                if ( option < 1 || option > 6 ) {
                    cout << "\nInvalid Input!\nTry again.\n";
                }
        } else if (!optionValidation(input)) {
            cout << "\nInvalid Input!\nTry again.\n";
        }
    } while ( (!optionValidation(input)) || (option < 1 || option > 6) );

    option--;
    float panel_area = 2.6; // panel area in square_meter; All panels provided have same area
    consumerRecord.roofArea = AreaValidation(totalArea); // Square meter
    double numPanels_by_Area = ceil(consumerRecord.roofArea / panel_area); // Number of panels calculated by roof area
    double numPanels_by_Load = ceil(total_load / (capacity[option]*consumerRecord.avgSunlightHours)); // Number of panels calculated by energy consumption
    // Comparing the panels calculated by roof area with panels calculated by energy consumption
    Total_Cost.panelsCost = numPanels_by_Load * prices[option];
    if (numPanels_by_Load <= numPanels_by_Area) {
        int numPanels = numPanels_by_Load; // Storing the number of panels in int
        cout << "The number of required solar panels are : " << numPanels << endl;
        canBeInstalled = true;
        return numPanels;
    } else {
        cout << "The number of required solar panels are : " << numPanels_by_Load << endl;
        cout << "\n\nSolar Panels system can't be installed on consumer's roof as it's not sufficient!" << endl;
        cout << "It can be installed by making some adjustments." << endl;
        cout << "You can contact to our mechanical team here -- 'alphasolar.mec@outlook.com'" << endl;
        canBeInstalled = false;
        return numPanels_by_Load;
    }
    return 0;
}

void InverterPrice(double Load) {
    // Uses the load in kw
    string brands[10] = {"Solis", "GoodWe", "FoxESS", "Knox", "Growatt", "Inverex", "Maxpower", "Solarmax", "Crown", "Knox"};
    string models[10] = {"Solis 3.0kW", "GW5000-DT", "FoxEss", "Krypton 8000", "5kW Inverter", "Nitrox 10 Kw", "Suntronic 10kW", "Onyx Ultra PV 9000", "Xavier 3.6kW", "Xenon 22500 IP65"};
    double capacityKW[10] = {3, 5, 5, 6, 5, 10, 10, 9, 3.6, 15};
    long long prices[10] = {245000, 245000, 245000, 270000, 245000, 425000, 530000, 850000, 168000, 850000};
    double Capacity = 0;
    int option, k = 0;
    Total_Cost.inverterCost = 0;
    cout << "\n\nInverter menu\n\n";
    cout << setw(5) << left << "No.";
    cout << setw(15) << left << "Brand";
    cout << setw(20) << left << "Model";
    cout << setw(15) << left << "Capacity(kw)";
    cout << setw(10) << left << "Price(PKR)" << endl;
    for (int i = 0; i < 10; i++) {
        cout << setw(5) << left << i+1;
        cout << setw(15) << left << brands[i];
        cout << setw(20) << left << models[i];
        cout << setw(15) << left << capacityKW[i];
        cout << setw(10) << left << prices[i] << endl;
    }
    cout << "\n\nYour energy requirement is : " << Load << " kw. Choose the inverter the capacity of which is at least equal to your load.\n\n";
    do { // Repeats itself untill the Capacity becomes equal to Total required energy
        bool isInvalid;
        if ( k > 0 )
            cout << "\n\nThe inverter you chose is not capable according to the load requirements\nYou may choose another inverter.\n" << endl;
        int option;
        string input;
        do {
            cout << "Enter the inverter number : ";
            getline(cin, input);
            if (optionValidation(input)) {
                option = str_to_int(input);
                if ( option < 1 || option > 10 ) {
                    cout << "\nInvalid Input!\nTry again.\n";
                }
            } else if (!optionValidation(input)) {
                cout << "\nInvalid Input!\nTry again.\n";
            }
        } while ( (!optionValidation(input)) || (option < 1 || option > 10) );

        option--;
        Capacity += capacityKW[option];
        Total_Cost.inverterCost += prices[option];
        k++;
    } while (Capacity < Load);

    return;

}