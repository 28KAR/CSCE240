// Copyright 2026 CSCE240
#include<iostream>
using std::cout;
using std::endl;
#include"question.h"
#include"truefalsequestion.h"

/*
The class will
accessor and mutator functions for the private data member, and a virtual
destructor and Print function. You will also redefine the SetQuestion function. Read
the comments in the supplied truefalsequestion.h header file for more detailed
requirements. Initial tests for the functionality of the TrueFalseQuestion class have
been provided in the attached testtf.cc source file. You are encouraged to create more
rigorous tests.
*/

class TrueFalseQuestion : public Question {
  public:
    TrueFalseQuestion(string question = "True or False?", bool answer = true) {
      this->question = question;
      this->answer = answer;
    };

    bool GetAnswer() {
      return this->answer;
    };

    void SetAnswer(bool answer) {
      this->answer = answer;
    };

    void SetQuestion(string question) {
      this->question = question;
    };
    virtual ~TrueFalseQuestion() {



    };

    virtual string Print(bool answer) {



    };

  private:
    bool answer;
    string question;

};

int main() {
  TrueFalseQuestion tf1,
                    tf2("True or False? CSCE240 is the best class ever."),
                    tf3("True or False? I am eight feet tall.", false);
  cout << "Test default constructor / Print(false)" << endl;
  tf1.Print(false);
  cout << "Print(true)" << endl;
  tf1.Print(true);
  cout << "\nTest constructor with one argument / Print(false)" << endl;
  tf2.Print(false);
  cout << "Print(true)" << endl;
  tf2.Print(true);
  cout << "\nTest constructor with two arguments / Print(false)" << endl;
  tf3.Print(false);
  cout << "Print(true)" << endl;
  tf3.Print(true);
  tf1.SetQuestion("Sounds good.");
  cout << "\nTest redefined SetQuestion / Print(false)" << endl;
  tf1.Print(false);
  cout << "Print(true)" << endl;
  tf1.Print(true);
  return 0;
}
