#ifndef FINDER_H
#define FINDER_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QPushButton>
class finder : public QDialog
{
    Q_OBJECT

public:
    finder(QWidget *parent = 0);
    ~finder();
signals:
    void findNext(const QString &str, Qt::CaseSensitivity cs);
    void findPrevious(const QString &str, Qt::CaseSensitivity cs);
private:
    QLabel *label;
    QLineEdit *line;
    QCheckBox *caseCheckBox;
    QCheckBox *backWardCheckBox;
    QPushButton *findbutton;
    QPushButton *closebutton;
public slots:
    void enableFindButton(const QString &);
    void findClicked();
};

#endif // FINDER_H
