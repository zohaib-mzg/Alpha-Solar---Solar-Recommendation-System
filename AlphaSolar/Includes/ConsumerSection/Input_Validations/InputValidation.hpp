//    ___                   _,   _     _                        
//   ( /                _/_( |  /     //o    /     _/_o         
//    / _ _    ,_   , , /    | /__,  //,  __/ __,  / ,  __ _ _  
//  _/_/ / /__/|_)_(_/_(__   |/(_/(_(/_(_(_/_(_/(_(__(_(_)/ / /_
//            /|                                                
//           (/                                               


// This file contains the following functions


//string ConsumerNoValidation(); // For the validation of Consumer number while adding a new consumer
//string NameValidation(); // For the validation of Consumer name
//string PhoneNoValidation(); // For the validation of Consumer Phone number
//string AddressValidation(); // For the validation of Address of the Consumer
//string region(); // For the validation of Consumer of Region
//int BackupDays(); // For the validation Backup Days
//string ConsumerNo_Validation(); // For the validation of Consumer Number for other than adding the new consumer
//float AreaValidation(); // For the validation of Consumer's house/place area
//double placeAreaValidation(); // For the validation of total area of the place

using namespace std;


string NameValidation() {
    bool isInvalid;
    string name;
    do {
        isInvalid = false;
        cout << "Enter name  : ";
        getline(cin, name);
        if (len(name) == 0) {
            isInvalid = true;
            cout << "\nEmpty input Field. Please enter something.\n" << endl;
        } else {
            for(int i = 0; i < len(name) && !isInvalid; i++) {
                if(name[i] != ' ' && ((int)name[i] <= 64 || ((int)name[i] > 90 && (int)name[i] < 97) || (int)name[i] > 122)) {
                    isInvalid = true;
                    cout << "\nInvalid Name.\nName should only be containing alphabets and a space.\nTry again\n";
                }
            }
        }
    } while (isInvalid);
    return name;
}


string PhoneNoValidation() {
    bool isInvalid;
    string phoneNo;
    do {
        isInvalid = false;
        cout << "Enter phone number  : ";
        getline(cin, phoneNo);
        if (len(phoneNo) == 0) {
            isInvalid = true;
            cout << "\nEmpty input Field. Please enter something.\n" << endl;
        } else {
            for (int i = 0; i < len(phoneNo); i++) {
                if((int)phoneNo[i] < 48 || (int)phoneNo[i] > 57) {
                    cout << "\nInvalid phone number.\nPhone number should only be containing numbers.\nTry again\n";
                    isInvalid = true;
                    break;
                }
            }
        }
    } while (isInvalid);
    return phoneNo;
}

string AddressValidation() {
    string address;
    bool isInvalid;
    do {
        cout << "Enter Consumer Address : ";
        getline(cin, address);
        isInvalid = false;
        if (len(address) == 0) {
            isInvalid = true;
            cout << "\nEmpty input Field. Please enter something.\n" << endl;
        } else {
            for (int i = 0; i < len(address) && (!isInvalid); i++) {
                if (address[i] == ',') {
                    isInvalid = true;
                    cout << "\nInvalid Address! It should not be containing a comma(,)\nTry again!\n" << endl;
                }
            }
        }
    } while (isInvalid);
    return address;
}


// For Adding a consumer
string ConsumerNoValidation() {

    bool isInvalid;
    bool isExisting;
    string id;
    do {
        isInvalid = false;
        isExisting = false;
        cout << "Enter Consumer No : ";
        getline(cin, id);
        if (len(id) == 0) {
            isInvalid = true;
            cout << "\nEmpty input Field. Please enter something.\n" << endl;
        } else {
            for (int i = 0; i < len(id); i++) {
                if((int)id[i] < 48 || (int)id[i] > 57) {
                    isInvalid = true;
                    cout << "\nInvalid Consumer Number!\nConsumer No should only be containing numbers.\nTry again.\n";
                    break;
                }
            }
        }
        if ( !isInvalid ) {
            string Path = "DataBase/Consumers/" + id + ".txt";
            ifstream file(Path);
            if (file.good()) {
                cout << "That Consumer Number is Already taken!\nTry again.\n";
                isExisting = true;
            }
            file.close();
        }

    } while (isInvalid || isExisting);
    
    return id;
}

int BackupDays() {
    int days;
    bool isInvalid;
    string input;
    do {
        isInvalid = false;
        cout << "Enter the days you want the back up storage for : ";
        getline(cin, input);
        if (len(input) == 0) {
            isInvalid = true;
            cout << "\nEmpty input Field. Please enter something.\n" << endl;
        } else {
            for (int i = 0; i < len(input) && !isInvalid; i++) {
                if (input[i] < 48 || input[i] > 57) {
                    isInvalid = true;
                    cout << "\nInvlalid Input!" << endl;
                }
            }
        }
        if (!isInvalid) {
            days = str_to_int(input);
            if (days <= 0) {
                isInvalid = true;
                cout << "\nInvlalid Input!" << endl;
            }
        }
        
    } while (isInvalid);
    return days;
}


// for other functions other than adding a consumer
string ConsumerNo_Validation() {
    bool isInvalid;
    string id;
    do {
        isInvalid = false;
        cout << "Enter Consumer No : ";
        getline(cin, id);
        for (int i = 0; i < len(id); i++) {
            if((int)id[i] < 48 || (int)id[i] > 57) {
                isInvalid = true;
                cout << "\nInvalid Consumer Number!\nConsumer No should only be containing numbers.\nTry again.\n";
                break;
            }
        }
    } while (isInvalid);
    
    return id;
}

bool Option_Validation(string option) {   // This a function for this file's options' validation
    bool isValid = true;
    if (len(option) == 0) {
        cout << "\nEmpty input Field. Please enter something.\n" << endl;
        return false;
    }
    for (int i = 0; i < len(option) && isValid; i++) {
        if (option[i] < 48 || option[i] > 57) {
            isValid = false;
        }
    }
    return isValid;
}

string region() {

    string Regions[5] = {"Equatorial Regions", "Tropical Regions", "Subtropical Regions", "Temperate Regions", "Polar Regions"};
    cout << "\n\n\t\t Regions Menu" << endl;
    cout << "\n1.  Equatorial Regions (e.g., Central Africa, Southeast Asia, Amazon Basin)" << endl;
    cout << "2.  Tropical Regions (e.g, India, Brazil, Northen Austrailia)" << endl;
    cout << "3.  Subtropical Regions (e.g., Southern United States, Mediterranean, Southern Australia)" << endl;
    cout << "4.  Temperate Regions (e.g., most of Europe, parts of China, United States)" << endl;
    cout << "5.  Polar Regions (e.g., Arctic, Antarctic)" << endl;
    cout << "\n\nIf you don't know your region, you can check it here -- 'https://www.google.com'\n\n" << endl;
    int option;
    string input;
    do {
        cout << "Enter region number : ";
        getline(cin, input);
        if (Option_Validation(input)) {
            option = str_to_int(input);
                if ( option < 1 || option > 5 ) {
                    cout << "\nInvalid Input!\nTry again.\n";
                }
        } else if (!Option_Validation(input)) {
            if (len(input) > 0)
                cout << "\nInvalid Input!\nTry again.\n";
        }
    } while ( (!Option_Validation(input)) || (option < 1 || option > 5) );

    option--;
    return Regions[option];
}

float AreaValidation(double totalArea) {
    float area;
    bool isInvalid;
    string input;
    do {
        isInvalid = false;
        cout << "Enter the usable area of the roof/place in square meters : ";
        getline(cin, input);
        if (len(input) == 0) {
            isInvalid = true;
            cout << "\nInput Field Empty! Please input according to instructions!\n" << endl;
        } else {
            for (int i = 0; i < len(input) && !isInvalid; i++) {
                if ( input[i] < 48 || input[i] > 57) {
                    isInvalid = true;
                    cout << "\nInvlalid Input!" << endl;
                }
            }
        }
        if (!isInvalid) {
            area = str_to_int(input);
            if (area == 0) {
                isInvalid = true;
                cout << "\nInvlalid Input!" << endl;
            }
            else if (area > totalArea) {
                isInvalid = true;
                cout << "\nInvlalid Input! Usable area greater than total area of the place.\n" << endl;
            }
        }

    } while (isInvalid);
    return area;
}


double placeAreaValidation() { // Total area of the place
    string input;
    bool isInvalid;
    double area;
    do {
        isInvalid = false;
        cout << "Enter the area of the place in marlas : ";
        getline(cin, input);
        if (len(input) == 0) {
            isInvalid = true;
            cout << "\nInput Field Empty! Please input according to instructions!\n" << endl;
        } else {
            for (int i = 0; i < len(input) && !isInvalid; i++) {
                if (input[i] < 48 || input[i] > 57) {
                    isInvalid = true;
                    cout << "\nInvalid Input!\nTry again.\n";
                }
            }
        }
        if (!isInvalid) {
            area = str_to_int(input);
            area *= 25; // Conversion from marla to square meters
            if (area <= 0) {
                isInvalid = true;
                cout << "\nInvalid Input!\nTry again.\n";
            }
        }
    } while (isInvalid);
    return area;
}