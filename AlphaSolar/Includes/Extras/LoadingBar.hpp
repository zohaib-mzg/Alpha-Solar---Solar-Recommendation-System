//  _                    _ _             ____             
// | |    ___   __ _  __| (_)_ __   __ _| __ )  __ _ _ __ 
// | |   / _ \ / _` |/ _` | | '_ \ / _` |  _ \ / _` | '__|
// | |__| (_) | (_| | (_| | | | | | (_| | |_) | (_| | |   
// |_____\___/ \__,_|\__,_|_|_| |_|\__, |____/ \__,_|_|   
//                                 |___/                  


using namespace std;

void loadingBar() {
    string barchar = "#";
    cout << "\n[";
    for (int i = 0; i < 5; i++){
        cout << barchar;
        barchar += "######";
        system("ping -n 1 loclahost >nul 2>&1");
    }
    cout << "#]\n\n\n" << endl;
    return;
}