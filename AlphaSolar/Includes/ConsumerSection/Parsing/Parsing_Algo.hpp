//    _____                   _               
//   |  __ \                 (_)              
//   | |__) |__ _  _ __  ___  _  _ __    __ _ 
//   |  ___// _` || '__|/ __|| || '_ \  / _` |
//   | |   | (_| || |   \__ \| || | | || (_| |
//   |_|    \__,_||_|   |___/|_||_| |_| \__, |
//                                       __/ |
//                                      |___/  


using namespace std;

struct Consumer {
    string ConsumerNo;
    string Name;
    string PhoneNo;
    string Region;
    string Address;
    string status;
    int Load;
    int energyRequired;
    int noOfBatteries;
    int backupDays;
    int avgSunlightHours;
    int noOfPanels;
    int roofArea;
    long long totalCost;
} consumerRecord;


//ConsumerNo,Name,PhoneNo,Region,Address,TotalLoad(w),Backup(Days), Sunlight Hours,energyRequired(kw),No. of Batteries, No. of Panels,roofArea, totalCost,status

int ParsingAlgo(string myString) {

    int j = 0;
    int i = 0;
    while (i < myString.size()) {
        string attribute = "";
        while (i < myString.size() && myString[i] != ',') {
            attribute += myString[i];
            i++;
        }
        i++;

        if (j == 0) {
            consumerRecord.ConsumerNo = attribute;
        } else if (j == 1) {
            consumerRecord.Name = attribute;
        } else if (j == 2) {
            consumerRecord.PhoneNo = attribute;
        } else if (j == 3) {
            consumerRecord.Region = attribute;
        } else if (j == 4) {
            consumerRecord.Address = attribute;
        } else if (j == 5) {
            consumerRecord.Load = str_to_int(attribute);
        } else if (j == 6) {
            consumerRecord.backupDays = str_to_int(attribute);
        } else if (j == 7) {
            consumerRecord.avgSunlightHours = str_to_int(attribute);
        } else if (j == 8) {
            consumerRecord.energyRequired = str_to_int(attribute);
        } else if (j == 9) {
            consumerRecord.noOfBatteries = str_to_int(attribute);
        } else if (j == 10) {
            consumerRecord.noOfPanels = str_to_int(attribute);
        } else if (j == 11) {
            consumerRecord.roofArea = str_to_int(attribute);
        } else if (j == 12) {
            consumerRecord.totalCost = str_to_int(attribute);
        } else if (j == 13) {
            consumerRecord.status = attribute;
        }

        j++;
    }
    return 0;
}