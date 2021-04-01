#include "dialog.h"
#include <QLabel>

dialog::dialog()
{
    lineEdit = new QLineEdit;
    editLayout = new QFormLayout;
    editLayout->addRow(new QLabel(tr("NICKNAME: ")), lineEdit);
    editWidget = new QWidget;
    editWidget->setLayout(editLayout);

    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));

    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(editWidget);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);
    setWindowTitle("NEW HIGHSCORE!!");

}
