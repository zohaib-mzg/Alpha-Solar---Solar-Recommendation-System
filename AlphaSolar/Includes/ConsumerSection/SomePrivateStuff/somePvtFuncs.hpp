
//   ######                                          #####                             
//   #     # #####  # #    #   ##   ##### ######    #     # ##### #    # ###### ###### 
//   #     # #    # # #    #  #  #    #   #         #         #   #    # #      #      
//   ######  #    # # #    # #    #   #   #####      #####    #   #    # #####  #####  
//   #       #####  # #    # ######   #   #               #   #   #    # #      #      
//   #       #   #  #  #  #  #    #   #   #         #     #   #   #    # #      #      
//   #       #    # #   ##   #    #   #   ######     #####    #    ####  #      #      
//                                                                                     




namespace fs = filesystem; // A namespace for filesystem library
using namespace std;

void viewConsumer(const fs::path& filePath) {
    string data, Record;
    ifstream file(filePath);
    if (file.is_open()) {
        while(getline (file, data)) {
            Record = data;
        }
        file.close();
        // Parsing Algo
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
    }
}