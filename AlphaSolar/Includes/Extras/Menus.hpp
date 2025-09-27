//  __  __                      
// |  \/  | ___ _ __  _   _ ___ 
// | |\/| |/ _ \ '_ \| | | / __|
// | |  | |  __/ | | | |_| \__ \
// |_|  |_|\___|_| |_|\__,_|___/

// Application's menus

using namespace std;



void MainMenu() {
    cout << " \n\n\t\t\t\t  __  __      _        __  __               \n";
    cout << " \t\t\t\t |  \\/  |__ _(_)_ _   |  \\/  |___ _ _ _  _  \n";
    cout << " \t\t\t\t | |\\/| / _` | | ' \\  | |\\/| / -_) ' \\ || | \n";
    cout << " \t\t\t\t |_|  |_\\__,_|_|_||_| |_|  |_\\___|_||_\\_,_| \n\n";
    cout << "\t\t\t\t  solar -m \t returns to main menu." << endl;
    cout << "\t\t\t\t  solar -c \t returns to command menu." << endl;
    cout << "\t\t\t\t  solar -h \t returns to help menu." << endl;
    cout << "\t\t\t\t  solar -u \t returns to usage examples." << endl;
    cout << "\t\t\t\t  solar -C \t returns to Consumer Section." << endl;
    cout << "\t\t\t\t  solar -q \t quits the application." << endl;
    cout << endl << endl << endl;
    return;
}




void UsageExamples() {
    cout << "\n\n";
    cout << "\t\t\t\t  _   _                     ___                     _         \n";
    cout << "\t\t\t\t | | | |___ __ _ __ _ ___  | __|_ ____ _ _ __  _ __| |___ ___ \n";
    cout << "\t\t\t\t | |_| (_-</ _` / _` / -_) | _|\\ \\ / _` | '  \\| '_ \\ / -_|_-< \n";
    cout << "\t\t\t\t  \\___//__/\\__,_\\__, \\___| |___/_\\_\\__,_|_|_|_| .__/_\\___/__/ \n";
    cout << "\t\t\t\t                |___/                         |_|             \n";
    cout << "\t\t\t\t  solar -m           \t returns to main menu." << endl;
    cout << "\t\t\t\t  solar -c           \t returns to command menu." << endl;
    cout << "\t\t\t\t  solar -h           \t returns to help menu." << endl;
    cout << "\t\t\t\t  solar -u           \t returns to usage examples." << endl;
    cout << "\t\t\t\t  solar -C           \t returns to Consunmer Section." << endl;
    cout << "\t\t\t\t  solar -q           \t quits the application." << endl;
    cout << "\t\t\t\t  solar -C --add     \t adds a consumer." << endl;
    cout << "\t\t\t\t  solar -C --delete  \t deletes a consumer." << endl;
    cout << "\t\t\t\t  solar -C --search  \t searches a consumer." << endl;
    cout << "\t\t\t\t  solar -C --display \t displays all consumers." << endl;
    cout << "\t\t\t\t  solar -C --update  \t updates a consumer." << endl;
    cout << "\t\t\t\t  solar -C --exit    \t exits consumer section." << endl;
    cout << endl << endl << endl;
    return;
}



void HelpMenu() {
    cout << "\n\n";
    cout << " \t\t\t\t\t  _  _     _       \n";
    cout << " \t\t\t\t\t | || |___| |_ __  \n";
    cout << " \t\t\t\t\t | __ / -_) | '_ \\ \n";
    cout << " \t\t\t\t\t |_||_\\___|_| .__/ \n";
    cout << " \t\t\t\t\t            |_|    \n\n";
    cout << "\t\t\t\t\t   -m \t returns to main menu." << endl;
    cout << "\t\t\t\t\t   -c \t returns to command menu." << endl;
    cout << "\t\t\t\t\t   -h \t returns to help menu." << endl;
    cout << "\t\t\t\t\t   -u \t returns to usage examples." << endl;
    cout << "\t\t\t\t\t   -C \t returns to Consunmer Section." << endl;
    cout << "\t\t\t\t\t   -q \t quits the application." << endl;
    cout << "\n\n\t\t\t\tHere are some usage examples\n";
    cout << "\t\t\t\tsolar -m           \t returns to main menu." << endl;
    cout << "\t\t\t\tsolar -c           \t returns to command menu." << endl;
    cout << "\t\t\t\tsolar -h           \t returns to help menu." << endl;
    cout << "\t\t\t\tsolar -u           \t returns to usage examples." << endl;
    cout << "\t\t\t\tsolar -C           \t returns to Consunmer Section." << endl;
    cout << "\t\t\t\tsolar -q           \t quits the application." << endl;
    cout << "\t\t\t\tsolar -C --add     \t adds a consumer." << endl;
    cout << "\t\t\t\tsolar -C --delete  \t deletes a consumer." << endl;
    cout << "\t\t\t\tsolar -C --search  \t searches a consumer." << endl;
    cout << "\t\t\t\tsolar -C --display \t displays all consumers." << endl;
    cout << "\t\t\t\tsolar -C --update  \t updates a consumer." << endl;
    cout << "\t\t\t\tsolar -C --exit    \t exits consumer section." << endl;
    cout << endl << endl << endl;

    return;
}




void CommandsMenu() {
    cout << "\t\t\t\t\t   ___                              _     \n";
    cout << "\t\t\t\t\t  / __|___ _ __  _ __  __ _ _ _  __| |___ \n";
    cout << "\t\t\t\t\t | (__/ _ \\ '  \\| '  \\/ _` | ' \\/ _` (_-< \n";
    cout << "\t\t\t\t\t  \\___\\___/_|_|_|_|_|_\\__,_|_||_\\__,_/__/ \n\n\n\n";    
    cout << "\t\t\t\t\t   -m \t returns to main menu." << endl;
    cout << "\t\t\t\t\t   -c \t returns to command menu." << endl;
    cout << "\t\t\t\t\t   -h \t returns to help menu." << endl;
    cout << "\t\t\t\t\t   -u \t returns to usage examples." << endl;
    cout << "\t\t\t\t\t   -C \t returns to Consunmer Section." << endl;
    cout << "\t\t\t\t\t   -q \t quits the application." << endl;
    return;
}

