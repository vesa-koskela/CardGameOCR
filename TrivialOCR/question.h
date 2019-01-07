#ifndef QUESTION_H
#define QUESTION_H
#include <QString>
#include <memory>

using std::shared_ptr;

namespace QuestionType {
    const QString Blue = "Geography";
    const QString Pink = "Entertainment";
    const QString Yellow = "History";
    const QString Purple = "Culture";
    const QString Green = "Natural Science";
    const QString Orange = "Sports and free time";
}


class Question
{
public:
    Question();
private:
    QString question_;
    QString answer_;
    QString type_;
    int cardNumber_;



};

#endif // QUESTION_H
