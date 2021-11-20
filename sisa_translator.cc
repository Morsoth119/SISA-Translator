#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void print_title() {
    cout << "     _______. __       _______.     ___         .___________..______          ___      .__   __.      _______. __          ___   .___________.  ______   .______" << endl;
    cout << "    /       ||  |     /       |    /   \\        |           ||   _  \\        /   \\     |  \\ |  |     /       ||  |        /   \\  |           | /  __  \\  |   _  \\" << endl;
    cout << "   |   (----`|  |    |   (----`   /  ^  \\       `---|  |----`|  |_)  |      /  ^  \\    |   \\|  |    |   (----`|  |       /  ^  \\ `---|  |----`|  |  |  | |  |_)  |" << endl;
    cout << "    \\   \\    |  |     \\   \\      /  /_\\  \\          |  |     |      /      /  /_\\  \\   |  . `  |     \\   \\    |  |      /  /_\\  \\    |  |     |  |  |  | |      /" << endl;
    cout << ".----)   |   |  | .----)   |    /  _____  \\         |  |     |  |\\  \\----./  _____  \\  |  |\\   | .----)   |   |  `----./  _____  \\   |  |     |  `--'  | |  |\\  \\----." << endl;
    cout << "|_______/    |__| |_______/    /__/     \\__\\        |__|     | _| `._____/__/     \\__\\ |__| \\__| |_______/    |_______/__/     \\__\\  |__|      \\______/  | _| `._____|" << endl;
    cout << endl;
}

void hex_to_bin(vector<int>& bin, char hexa, int pos) {
    pos *= 4;

    for (int i = 0; i < bin.size(); ++i) {
        switch (hexa) {
        case '0': bin[pos - 1] = 0; bin[pos - 2] = 0; bin[pos - 3] = 0; bin[pos - 4] = 0;
            break;
        case '1': bin[pos - 1] = 0; bin[pos - 2] = 0; bin[pos - 3] = 0; bin[pos - 4] = 1;
            break;
        case '2': bin[pos - 1] = 0; bin[pos - 2] = 0; bin[pos - 3] = 1; bin[pos - 4] = 0;
            break;
        case '3': bin[pos - 1] = 0; bin[pos - 2] = 0; bin[pos - 3] = 1; bin[pos - 4] = 1;
            break;
        case '4': bin[pos - 1] = 0; bin[pos - 2] = 1; bin[pos - 3] = 0; bin[pos - 4] = 0;
            break;
        case '5': bin[pos - 1] = 0; bin[pos - 2] = 1; bin[pos - 3] = 0; bin[pos - 4] = 1;
            break;
        case '6': bin[pos - 1] = 0; bin[pos - 2] = 1; bin[pos - 3] = 1; bin[pos - 4] = 0;
            break;
        case '7': bin[pos - 1] = 0; bin[pos - 2] = 1; bin[pos - 3] = 1; bin[pos - 4] = 1;
            break;
        case '8': bin[pos - 1] = 1; bin[pos - 2] = 0; bin[pos - 3] = 0; bin[pos - 4] = 0;
            break;
        case '9': bin[pos - 1] = 1; bin[pos - 2] = 0; bin[pos - 3] = 0; bin[pos - 4] = 1;
            break;
        case 'A':
        case 'a': bin[pos - 1] = 1; bin[pos - 2] = 0; bin[pos - 3] = 1; bin[pos - 4] = 0;
            break;
        case 'B':
        case 'b': bin[pos - 1] = 1; bin[pos - 2] = 0; bin[pos - 3] = 1; bin[pos - 4] = 1;
            break;
        case 'C':
        case 'c': bin[pos - 1] = 1; bin[pos - 2] = 1; bin[pos - 3] = 0; bin[pos - 4] = 0;
            break;
        case 'D':
        case 'd': bin[pos - 1] = 1; bin[pos - 2] = 1; bin[pos - 3] = 0; bin[pos - 4] = 1;
            break;
        case 'E':
        case 'e': bin[pos - 1] = 1; bin[pos - 2] = 1; bin[pos - 3] = 1; bin[pos - 4] = 0;
            break;
        case 'F':
        case 'f': bin[pos - 1] = 1; bin[pos - 2] = 1; bin[pos - 3] = 1; bin[pos - 4] = 1;
            break;
        
        default:
            break;
        }
    }   
}

void bin_to_dec(int b7, int b6, int b5, int b4, int b3, int b2, int b1, int b0, int n_bits, bool neg) {
    int dec = 0;

    if (n_bits == 6)
        dec = -b5*pow(2, 5) + b4*pow(2, 4) + b3*pow(2, 3) + b2*pow(2, 2) + b1*pow(2, 1) + b0;
    else if (n_bits == 8 and neg == true)
        dec = -b7*pow(2, 7) + b6*pow(2, 6) + b5*pow(2, 5) + b4*pow(2, 4) + b3*pow(2, 3) + b2*pow(2, 2) + b1*pow(2, 1) + b0;
    else if (n_bits == 8 and neg == false)
        dec = b7*pow(2, 7) + b6*pow(2, 6) + b5*pow(2, 5) + b4*pow(2, 4) + b3*pow(2, 3) + b2*pow(2, 2) + b1*pow(2, 1) + b0;
    
    cout << dec;
}

void print_operation(vector<int> n) {
    if (n[15] == 0 and n[14] == 0 and n[13] == 0 and n[12] == 0) {
        if (n[2] == 0 and n[1] == 0 and n[0] == 0) cout << "AND ";
        else if (n[2] == 0 and n[1] == 0 and n[0] == 1) cout << "OR ";
        else if (n[2] == 0 and n[1] == 1 and n[0] == 0) cout << "XOR ";
        else if (n[2] == 0 and n[1] == 1 and n[0] == 1) cout << "NOT ";
        else if (n[2] == 1 and n[1] == 0 and n[0] == 0) cout << "ADD ";
        else if (n[2] == 1 and n[1] == 0 and n[0] == 1) cout << "SUB ";
        else if (n[2] == 1 and n[1] == 1 and n[0] == 0) cout << "SHA ";
        else if (n[2] == 1 and n[1] == 1 and n[0] == 1) cout << "SHL ";

        if (n[5] == 0 and n[4] == 0 and n[3] == 0) cout << "R0,";
        else if (n[5] == 0 and n[4] == 0 and n[3] == 1) cout << "R1,";
        else if (n[5] == 0 and n[4] == 1 and n[3] == 0) cout << "R2,";
        else if (n[5] == 0 and n[4] == 1 and n[3] == 1) cout << "R3,";
        else if (n[5] == 1 and n[4] == 0 and n[3] == 0) cout << "R4,";
        else if (n[5] == 1 and n[4] == 0 and n[3] == 1) cout << "R5,";
        else if (n[5] == 1 and n[4] == 1 and n[3] == 0) cout << "R6,";
        else if (n[5] == 1 and n[4] == 1 and n[3] == 1) cout << "R7,";

        if (n[11] == 0 and n[10] == 0 and n[9] == 0) cout << "R0";
        else if (n[11] == 0 and n[10] == 0 and n[9] == 1) cout << "R1";
        else if (n[11] == 0 and n[10] == 1 and n[9] == 0) cout << "R2";
        else if (n[11] == 0 and n[10] == 1 and n[9] == 1) cout << "R3";
        else if (n[11] == 1 and n[10] == 0 and n[9] == 0) cout << "R4";
        else if (n[11] == 1 and n[10] == 0 and n[9] == 1) cout << "R5";
        else if (n[11] == 1 and n[10] == 1 and n[9] == 0) cout << "R6";
        else if (n[11] == 1 and n[10] == 1 and n[9] == 1) cout << "R7";

        if (n[2] != 0 or n[1] != 1 or n[0] != 1) {
            if (n[8] == 0 and n[7] == 0 and n[6] == 0) cout << ",R0";
            else if (n[8] == 0 and n[7] == 0 and n[6] == 1) cout << ",R1";
            else if (n[8] == 0 and n[7] == 1 and n[6] == 0) cout << ",R2";
            else if (n[8] == 0 and n[7] == 1 and n[6] == 1) cout << ",R3";
            else if (n[8] == 1 and n[7] == 0 and n[6] == 0) cout << ",R4";
            else if (n[8] == 1 and n[7] == 0 and n[6] == 1) cout << ",R5";
            else if (n[8] == 1 and n[7] == 1 and n[6] == 0) cout << ",R6";
            else if (n[8] == 1 and n[7] == 1 and n[6] == 1) cout << ",R7";
        }
    }
    else if (n[15] == 0 and n[14] == 0 and n[13] == 0 and n[12] == 1) {
        bool error = false;

        if (n[2] == 0 and n[1] == 0 and n[0] == 0) cout << "CMPLT ";
        else if (n[2] == 0 and n[1] == 0 and n[0] == 1) cout << "CMPLE ";
        else if (n[2] == 0 and n[1] == 1 and n[0] == 1) cout << "CMPEQ ";
        else if (n[2] == 1 and n[1] == 0 and n[0] == 0) cout << "CMPLTU ";
        else if (n[2] == 1 and n[1] == 0 and n[0] == 1) cout << "CMPLEU ";
        else {
            cout << "Error: OPERATION NOT DEFINED";
            error = true;
        }
        if (not error) {
            if (n[5] == 0 and n[4] == 0 and n[3] == 0) cout << "R0,";
            else if (n[5] == 0 and n[4] == 0 and n[3] == 1) cout << "R1,";
            else if (n[5] == 0 and n[4] == 1 and n[3] == 0) cout << "R2,";
            else if (n[5] == 0 and n[4] == 1 and n[3] == 1) cout << "R3,";
            else if (n[5] == 1 and n[4] == 0 and n[3] == 0) cout << "R4,";
            else if (n[5] == 1 and n[4] == 0 and n[3] == 1) cout << "R5,";
            else if (n[5] == 1 and n[4] == 1 and n[3] == 0) cout << "R6,";
            else if (n[5] == 1 and n[4] == 1 and n[3] == 1) cout << "R7,";

            if (n[11] == 0 and n[10] == 0 and n[9] == 0) cout << "R0";
            else if (n[11] == 0 and n[10] == 0 and n[9] == 1) cout << "R1";
            else if (n[11] == 0 and n[10] == 1 and n[9] == 0) cout << "R2";
            else if (n[11] == 0 and n[10] == 1 and n[9] == 1) cout << "R3";
            else if (n[11] == 1 and n[10] == 0 and n[9] == 0) cout << "R4";
            else if (n[11] == 1 and n[10] == 0 and n[9] == 1) cout << "R5";
            else if (n[11] == 1 and n[10] == 1 and n[9] == 0) cout << "R6";
            else if (n[11] == 1 and n[10] == 1 and n[9] == 1) cout << "R7";

            if (n[8] == 0 and n[7] == 0 and n[6] == 0) cout << ",R0";
            else if (n[8] == 0 and n[7] == 0 and n[6] == 1) cout << ",R1";
            else if (n[8] == 0 and n[7] == 1 and n[6] == 0) cout << ",R2";
            else if (n[8] == 0 and n[7] == 1 and n[6] == 1) cout << ",R3";
            else if (n[8] == 1 and n[7] == 0 and n[6] == 0) cout << ",R4";
            else if (n[8] == 1 and n[7] == 0 and n[6] == 1) cout << ",R5";
            else if (n[8] == 1 and n[7] == 1 and n[6] == 0) cout << ",R6";
            else if (n[8] == 1 and n[7] == 1 and n[6] == 1) cout << ",R7";
        }
    }
    else if (n[15] == 0 and n[14] == 0 and n[13] == 1 and n[12] == 0) {
        cout << "ADDI ";

        if (n[8] == 0 and n[7] == 0 and n[6] == 0) cout << "R0,";
        else if (n[8] == 0 and n[7] == 0 and n[6] == 1) cout << "R1,";
        else if (n[8] == 0 and n[7] == 1 and n[6] == 0) cout << "R2,";
        else if (n[8] == 0 and n[7] == 1 and n[6] == 1) cout << "R3,";
        else if (n[8] == 1 and n[7] == 0 and n[6] == 0) cout << "R4,";
        else if (n[8] == 1 and n[7] == 0 and n[6] == 1) cout << "R5,";
        else if (n[8] == 1 and n[7] == 1 and n[6] == 0) cout << "R6,";
        else if (n[8] == 1 and n[7] == 1 and n[6] == 1) cout << "R7,";

        if (n[11] == 0 and n[10] == 0 and n[9] == 0) cout << "R0,";
        else if (n[11] == 0 and n[10] == 0 and n[9] == 1) cout << "R1,";
        else if (n[11] == 0 and n[10] == 1 and n[9] == 0) cout << "R2,";
        else if (n[11] == 0 and n[10] == 1 and n[9] == 1) cout << "R3,";
        else if (n[11] == 1 and n[10] == 0 and n[9] == 0) cout << "R4,";
        else if (n[11] == 1 and n[10] == 0 and n[9] == 1) cout << "R5,";
        else if (n[11] == 1 and n[10] == 1 and n[9] == 0) cout << "R6,";
        else if (n[11] == 1 and n[10] == 1 and n[9] == 1) cout << "R7,";

        bin_to_dec(0, 0, n[5], n[4], n[3], n[2], n[1], n[0], 6, true);
    }
    else if (n[15] == 0 and n[14] == 0 and n[13] == 1 and n[12] == 1) {
        cout << "LD ";

        if (n[8] == 0 and n[7] == 0 and n[6] == 0) cout << "R0,";
        else if (n[8] == 0 and n[7] == 0 and n[6] == 1) cout << "R1,";
        else if (n[8] == 0 and n[7] == 1 and n[6] == 0) cout << "R2,";
        else if (n[8] == 0 and n[7] == 1 and n[6] == 1) cout << "R3,";
        else if (n[8] == 1 and n[7] == 0 and n[6] == 0) cout << "R4,";
        else if (n[8] == 1 and n[7] == 0 and n[6] == 1) cout << "R5,";
        else if (n[8] == 1 and n[7] == 1 and n[6] == 0) cout << "R6,";
        else if (n[8] == 1 and n[7] == 1 and n[6] == 1) cout << "R7,";

        bin_to_dec(0, 0, n[5], n[4], n[3], n[2], n[1], n[0], 6, true);

        cout << "(";

        if (n[11] == 0 and n[10] == 0 and n[9] == 0) cout << "R0";
        else if (n[11] == 0 and n[10] == 0 and n[9] == 1) cout << "R1";
        else if (n[11] == 0 and n[10] == 1 and n[9] == 0) cout << "R2";
        else if (n[11] == 0 and n[10] == 1 and n[9] == 1) cout << "R3";
        else if (n[11] == 1 and n[10] == 0 and n[9] == 0) cout << "R4";
        else if (n[11] == 1 and n[10] == 0 and n[9] == 1) cout << "R5";
        else if (n[11] == 1 and n[10] == 1 and n[9] == 0) cout << "R6";
        else if (n[11] == 1 and n[10] == 1 and n[9] == 1) cout << "R7";

        cout << ")";
    }
    else if (n[15] == 0 and n[14] == 1 and n[13] == 0 and n[12] == 0) {
        cout << "ST ";
        
        bin_to_dec(0, 0, n[5], n[4], n[3], n[2], n[1], n[0], 6, true);

        cout << "(";

        if (n[11] == 0 and n[10] == 0 and n[9] == 0) cout << "R0";
        else if (n[11] == 0 and n[10] == 0 and n[9] == 1) cout << "R1";
        else if (n[11] == 0 and n[10] == 1 and n[9] == 0) cout << "R2";
        else if (n[11] == 0 and n[10] == 1 and n[9] == 1) cout << "R3";
        else if (n[11] == 1 and n[10] == 0 and n[9] == 0) cout << "R4";
        else if (n[11] == 1 and n[10] == 0 and n[9] == 1) cout << "R5";
        else if (n[11] == 1 and n[10] == 1 and n[9] == 0) cout << "R6";
        else if (n[11] == 1 and n[10] == 1 and n[9] == 1) cout << "R7";

        cout << "),";

        if (n[8] == 0 and n[7] == 0 and n[6] == 0) cout << "R0";
        else if (n[8] == 0 and n[7] == 0 and n[6] == 1) cout << "R1";
        else if (n[8] == 0 and n[7] == 1 and n[6] == 0) cout << "R2";
        else if (n[8] == 0 and n[7] == 1 and n[6] == 1) cout << "R3";
        else if (n[8] == 1 and n[7] == 0 and n[6] == 0) cout << "R4";
        else if (n[8] == 1 and n[7] == 0 and n[6] == 1) cout << "R5";
        else if (n[8] == 1 and n[7] == 1 and n[6] == 0) cout << "R6";
        else if (n[8] == 1 and n[7] == 1 and n[6] == 1) cout << "R7";
    }
    else if (n[15] == 0 and n[14] == 1 and n[13] == 0 and n[12] == 1) {
        cout << "LDB ";

        if (n[8] == 0 and n[7] == 0 and n[6] == 0) cout << "R0,";
        else if (n[8] == 0 and n[7] == 0 and n[6] == 1) cout << "R1,";
        else if (n[8] == 0 and n[7] == 1 and n[6] == 0) cout << "R2,";
        else if (n[8] == 0 and n[7] == 1 and n[6] == 1) cout << "R3,";
        else if (n[8] == 1 and n[7] == 0 and n[6] == 0) cout << "R4,";
        else if (n[8] == 1 and n[7] == 0 and n[6] == 1) cout << "R5,";
        else if (n[8] == 1 and n[7] == 1 and n[6] == 0) cout << "R6,";
        else if (n[8] == 1 and n[7] == 1 and n[6] == 1) cout << "R7,";

        bin_to_dec(0, 0, n[5], n[4], n[3], n[2], n[1], n[0], 6, true);

        cout << "(";

        if (n[11] == 0 and n[10] == 0 and n[9] == 0) cout << "R0";
        else if (n[11] == 0 and n[10] == 0 and n[9] == 1) cout << "R1";
        else if (n[11] == 0 and n[10] == 1 and n[9] == 0) cout << "R2";
        else if (n[11] == 0 and n[10] == 1 and n[9] == 1) cout << "R3";
        else if (n[11] == 1 and n[10] == 0 and n[9] == 0) cout << "R4";
        else if (n[11] == 1 and n[10] == 0 and n[9] == 1) cout << "R5";
        else if (n[11] == 1 and n[10] == 1 and n[9] == 0) cout << "R6";
        else if (n[11] == 1 and n[10] == 1 and n[9] == 1) cout << "R7";

        cout << ")";
    }
    else if (n[15] == 0 and n[14] == 1 and n[13] == 1 and n[12] == 0) {
        cout << "STB ";
        
        bin_to_dec(0, 0, n[5], n[4], n[3], n[2], n[1], n[0], 6, true);

        cout << "(";

        if (n[11] == 0 and n[10] == 0 and n[9] == 0) cout << "R0";
        else if (n[11] == 0 and n[10] == 0 and n[9] == 1) cout << "R1";
        else if (n[11] == 0 and n[10] == 1 and n[9] == 0) cout << "R2";
        else if (n[11] == 0 and n[10] == 1 and n[9] == 1) cout << "R3";
        else if (n[11] == 1 and n[10] == 0 and n[9] == 0) cout << "R4";
        else if (n[11] == 1 and n[10] == 0 and n[9] == 1) cout << "R5";
        else if (n[11] == 1 and n[10] == 1 and n[9] == 0) cout << "R6";
        else if (n[11] == 1 and n[10] == 1 and n[9] == 1) cout << "R7";

        cout << "),";

        if (n[8] == 0 and n[7] == 0 and n[6] == 0) cout << "R0";
        else if (n[8] == 0 and n[7] == 0 and n[6] == 1) cout << "R1";
        else if (n[8] == 0 and n[7] == 1 and n[6] == 0) cout << "R2";
        else if (n[8] == 0 and n[7] == 1 and n[6] == 1) cout << "R3";
        else if (n[8] == 1 and n[7] == 0 and n[6] == 0) cout << "R4";
        else if (n[8] == 1 and n[7] == 0 and n[6] == 1) cout << "R5";
        else if (n[8] == 1 and n[7] == 1 and n[6] == 0) cout << "R6";
        else if (n[8] == 1 and n[7] == 1 and n[6] == 1) cout << "R7";
    }
    else if (n[15] == 1 and n[14] == 0 and n[13] == 0 and n[12] == 0) {
        if (n[8] == 0) cout << "BZ ";
        else if (n[8] == 1) cout << "BNZ ";

        if (n[11] == 0 and n[10] == 0 and n[9] == 0) cout << "R0,";
        else if (n[11] == 0 and n[10] == 0 and n[9] == 1) cout << "R1,";
        else if (n[11] == 0 and n[10] == 1 and n[9] == 0) cout << "R2,";
        else if (n[11] == 0 and n[10] == 1 and n[9] == 1) cout << "R3,";
        else if (n[11] == 1 and n[10] == 0 and n[9] == 0) cout << "R4,";
        else if (n[11] == 1 and n[10] == 0 and n[9] == 1) cout << "R5,";
        else if (n[11] == 1 and n[10] == 1 and n[9] == 0) cout << "R6,";
        else if (n[11] == 1 and n[10] == 1 and n[9] == 1) cout << "R7,";

        bin_to_dec(n[7], n[6], n[5], n[4], n[3], n[2], n[1], n[0], 8, true);
    }
    else if (n[15] == 1 and n[14] == 0 and n[13] == 0 and n[12] == 1) {
        if (n[8] == 0) cout << "MOVI ";
        else if (n[8] == 1) cout << "MOVHI ";

        if (n[11] == 0 and n[10] == 0 and n[9] == 0) cout << "R0,";
        else if (n[11] == 0 and n[10] == 0 and n[9] == 1) cout << "R1,";
        else if (n[11] == 0 and n[10] == 1 and n[9] == 0) cout << "R2,";
        else if (n[11] == 0 and n[10] == 1 and n[9] == 1) cout << "R3,";
        else if (n[11] == 1 and n[10] == 0 and n[9] == 0) cout << "R4,";
        else if (n[11] == 1 and n[10] == 0 and n[9] == 1) cout << "R5,";
        else if (n[11] == 1 and n[10] == 1 and n[9] == 0) cout << "R6,";
        else if (n[11] == 1 and n[10] == 1 and n[9] == 1) cout << "R7,";

        bin_to_dec(n[7], n[6], n[5], n[4], n[3], n[2], n[1], n[0], 8, true);
    }
    else if (n[15] == 1 and n[14] == 0 and n[13] == 1 and n[12] == 0) {
        if (n[8] == 0) cout << "IN ";
        else if (n[8] == 1) {
            cout << "OUT ";
            bin_to_dec(n[7], n[6], n[5], n[4], n[3], n[2], n[1], n[0], 8, false);
            cout << ",";
        }

        if (n[11] == 0 and n[10] == 0 and n[9] == 0) cout << "R0";
        else if (n[11] == 0 and n[10] == 0 and n[9] == 1) cout << "R1";
        else if (n[11] == 0 and n[10] == 1 and n[9] == 0) cout << "R2";
        else if (n[11] == 0 and n[10] == 1 and n[9] == 1) cout << "R3";
        else if (n[11] == 1 and n[10] == 0 and n[9] == 0) cout << "R4";
        else if (n[11] == 1 and n[10] == 0 and n[9] == 1) cout << "R5";
        else if (n[11] == 1 and n[10] == 1 and n[9] == 0) cout << "R6";
        else if (n[11] == 1 and n[10] == 1 and n[9] == 1) cout << "R7";

        if (n[8] == 0) {
            cout << ",";
            bin_to_dec(n[7], n[6], n[5], n[4], n[3], n[2], n[1], n[0], 8, false);
        }
    }
    else cout << "Error: OPERATION NOT DEFINED";
}

int main() {
    char hex;

    vector<int> num(16, 0);

    //print_title();
    cout << endl << "---SISA TRANSLATOR-----------------------" << endl;
        
    cout << "Enter an operation (hexadecimal): ";

    for (int i = 4; i > 0; --i) {
        cin >> hex;

        hex_to_bin(num, hex, i);
    }

    cout << "> ";

    print_operation(num);

    cout << endl << "-----------------------------------------" << endl << endl;
}