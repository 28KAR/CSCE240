// Copyright 2026 bhipp
#include<fstream>
using std::ifstream;
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
#include<string>
using std::string;
#include<cctype>

int main(int argc, char *argv[]) {
  // executable must be called with a test number 0-6 for the sample tests,
  // 0-9 once the additional grading tests are added
  if ( argc != 2  || argv[1][0] < '0' || argv[1][0] > '0' ) {
    cout << "Invalid test" << endl;
    return 1;
  }
  // convert the character to an integer
  int which = argv[1][0] - '0';
  string correct[1] = { "expected-output1.txt" };
  string student[1] = { "student-output1.txt" };
  ifstream correctfile(correct[which]);
  ifstream studentfile(student[which]);
  bool match = true;
  char correctchar, stuchar;
  int i = 0;
  cout << "Your output:" << endl;
  correctchar = correctfile.get();
  stuchar = studentfile.get();
  while ( correctfile.good() && studentfile.good() && match ) {
    match = correctchar == stuchar;
    cout << stuchar;
    if ( !match )
      cout << "<- this character "
           << (isspace(stuchar) ? "(a white-space character) " : "")
           << "should be " << correctchar
           << (correctchar == ' ' ? "(a space)" :
                  (correctchar == '\t' ? "(a tab)" :
                    (correctchar == '\n' ? "(a newline)" : ""))) << endl;
    ++i;
    correctchar = correctfile.get();
    stuchar = studentfile.get();
  }

  cout << "\n";
  if ( !match ) {
    cout << "output error at character " << i
         << "\n\nOpen " << student[which] << " to view your full output and "
         << "compare it to the expected ouput in " << correct[which] << endl;
    cout << "0 points for test " << argv[1][0] << endl;
  } else if ( !correctfile.eof() ) {
    cout << "student file ended too soon"
         << "\n\nOpen " << student[which] << " to view your full output and "
         << "compare it to the expected ouput in " << correct[which] << endl;
    cout << "0 points for test " << argv[1][0] << endl;
  } else if ( !studentfile.eof() ) {
    cout << "extra output in student file"
         << "\n\nOpen " << student[which] << " to view your full output and "
         << "compare it to the expected ouput in " << correct[which] << endl;
    cout << "0.1 points for test " << argv[1][0] << endl;
  } else {
    cout << "match!" << endl;
    cout << "0.4 points for p4test " << (which + 1) << endl;
  }
  return 0;
}
