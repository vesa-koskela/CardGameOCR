#include "question.h"

Question::Question(QString question, QString answer) :
    question_(question),
    answer_(answer)

{

}

void Question::setQuestion(QString text)
{
    question_ = text;
}

void Question::setAnswer(QString text)
{
    answer_ = text;
}

QString Question::question()
{
    return question_;
}

QString Question::answer()
{
    return answer_;
}
