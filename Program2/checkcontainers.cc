// Copyright 2026 bhipp
#include<iostream>
using std::cout;
using std::endl;
#include<fstream>
using std::ifstream;
#include<cstring>

int main(int argc, char * argv[] ) {
  if ( argc != 2 ) {
    cout << "Must be run with the name of a file to check" << endl;
    return 2;
  }
  ifstream student(argv[1]);
  char line[101] = "";
  char next_char;
  while ( student.good() ) {
    student >> next_char;
    if ( next_char == '/' ) {
      student >> next_char;
      if ( next_char == '/' ) {
        student.getline(line, 100);
      }
      if ( next_char == '*' ) {
        char prev;
        student >> next_char;
        do {
          prev = next_char;
          student >> next_char;
        } while ( !(prev == '*' && next_char == '/') && student.good() );
      }
    }

    // partial check for container classes
    if ( next_char == 's' ) {
      student >> line;
      if ( strcmp(line, "tring") == 0 || strcmp(line, "tring;") == 0 ||
           strcmp(line, "td::string") == 0 ||
           strcmp(line, "td::string;") == 0 ||
           strcmp(line, "td::vector") == 0 ||
           strcmp(line, "td::vector;") == 0 ||
           strcmp(line, "td::list") == 0 ||
           strcmp(line, "td::list;") == 0 ) {
        cout << "Unallowed use of s" << line << " in " << argv[1]
             << "\nStudent grade = 0." << endl;
        return 1;
      }
    }
    
  }

  return 0;
}
