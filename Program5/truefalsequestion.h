#ifndef _TRUEFALSEQUESTION_H_
#define _TRUEFALSEQUESTION_H_

#include "question.h"
using std::string;

class TrueFalseQuestion : public Question {
  public:
    TrueFalseQuestion(string question = "True or False?", bool answer = true);

    bool GetAnswer();
    void SetAnswer(bool answer);
    virtual ~TrueFalseQuestion();
    virtual string Print(bool answer);

  private:
    bool answer;

};

int main();

#endif