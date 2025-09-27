using namespace std;

int len(string); // Returns the length of the string
int str_to_int(string); // Converts string into integer

int len(string s) {
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

int str_to_int(string s) {
    int int_s = 0;
    int i = 0;
    while ( i < len(s) ) {
        int_s = int_s * 10 + ((int)s[i] - 48);
        i++;
    }
    return int_s;
}