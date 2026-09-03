//  -------------------------------------  //
//  Copyright Katherine Asher Rogers 2026  //
//  -------------------------------------  //
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {

    int largestBase10, largestCount, count = 0;

    //  Loop for repeat processes
    bool loop = true;
    do {
        //  Initialize Variables
        int num, base;
        char cont;
        count++;

        //  User Input Prompts
        cin >> num >> base >> cont;

        //  Begins Conversion Process
        //  Check Base Validity
        if (base < 2 || base > 9) {
            cout << "Base Not Accepted\n";
            return 1;
        }

        //  num == 0 case
        if (num == 0) {
            cout << 0 << endl;

        //  Converting to Base 10 Beginning
        } else {

            //  Convert to Base 10
            int num10 = 0;
            int ten = 10;
            int tempnum = 0;
            do {
                //  Tests for Invalid digits in num
                tempnum = num % 10;
                if (tempnum >= base) {
                    cout << "Invalid Digit(s) in Number\n";
                    return -1;
                }

                num10 += (tempnum * ten);
                num /= 10;
                ten *= 10;
            } while (num > 0);

            cout << num10 << endl;
            num = num10;

        }

        //  Update Largerst Number
        if (num > largestBase10) {
            largestBase10 = num;
            largestCount = count;
        }

        //  Check continue ask
        if (cont != 'n' && cont != 'N' && cont != 'y' && cont != 'Y') {
            cout << "Invalid Repeat Char\n";
            return 1;
        }
        if (cont == 'n' || cont == 'N') {
            switch (largestCount) {
                case 1:
                    cout << "Of the " << count << " values input the 1st value entered (" << largestBase10 << ") was the largest\n";
                    break;
                case 2:
                    cout << "Of the " << count << " values input the 2nd value entered (" << largestBase10 << ") was the largest\n";
                    break;
                case 3:
                    cout << "Of the " << count << " values input the 3rd value entered (" << largestBase10 << ") was the largest\n";
                    break;
                default:
                    cout << "Of the " << count << " values input the " << largestCount << "th value entered (" << largestBase10 << ") was the largest\n";
                    break;
            }
            return 1;
        }

    } while (loop);
    
    return 0;
}