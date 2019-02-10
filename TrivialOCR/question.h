#ifndef QUESTION_H
#define QUESTION_H
#include <QString>
#include <QObject>
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



class Question : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString question READ question NOTIFY questionChanged)
    Q_PROPERTY(QString answer READ answer NOTIFY answerChanged)
public:
    Question(QString question = "defaultQ", QString answer = "defaultA");
    void setQuestion(QString text);
    void setAnswer(QString text);
    QString question();
    QString answer();
private:
    QString question_;
    QString answer_;
    QString type_;



};

#endif // QUESTION_H
