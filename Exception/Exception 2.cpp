#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

int convertToInt(string str) {
    try {
        int value = stoi(str);
        return value;
    }
    catch (const invalid_argument& e) {
        cout << "Invalid argument: String contain non-digital symbols" << endl;
    }
    catch (const out_of_range& e) {
        cout << "Out of range: Number out of range" << endl;
    }
    return -1;
}

/*int main() {
    int num1 = convertToInt("rfr123y");
    if (num1 != -1) {
        cout << num1 << endl;
    }

    int num2 = convertToInt("314748364855");
    if (num2 != -1) {
        cout << num2 << endl;
    }

    return 0;
}*/
