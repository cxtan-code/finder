#include "finder.h"
#include <QtGui>
#include <QHBoxLayout>
#include <QVBoxLayout>
finder::finder(QWidget *parent)
    : QDialog(parent)
{
    label = new QLabel(tr("Find &what:"));
    line = new QLineEdit();
    label->setBuddy(line);

    caseCheckBox = new QCheckBox(tr("Match &case"));
    backWardCheckBox = new QCheckBox(tr("Search &backward"));

    findbutton = new QPushButton(tr("&Find"));
    findbutton->setDefault(true);
    findbutton->setEnabled(false);

    closebutton = new QPushButton(tr("Close"));

    connect(line, SIGNAL(textChanged(const QString &)), this, SLOT(enableFindButton(const QString &)));
    connect(findbutton, SIGNAL(clicked()), this, SLOT(findClicked()));
    connect(closebutton, SIGNAL(clicked()), this, SLOT(close()));

    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(line);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backWardCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findbutton);
    rightLayout->addWidget(closebutton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    setLayout(mainLayout);
    setWindowTitle(tr("Find"));
    setFixedHeight(sizeHint().height());
}

finder::~finder()
{

}
void finder::enableFindButton(const QString &text){
    findbutton->setEnabled(!text.isEmpty());
}
void finder::findClicked(){
    QString text = line->text();
    Qt::CaseSensitivity cs = caseCheckBox->isChecked()?Qt::CaseSensitive:Qt::CaseInsensitive;
    if (backWardCheckBox->isChecked()){
        emit findPrevious(text, cs);
    }else{
        emit findNext(text, cs);
    }
}
