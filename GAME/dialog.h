#ifndef DIALOG_H
#define DIALOG_H

#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QDialog>

class dialog: public QDialog
{
public:
    dialog();
    QVBoxLayout * mainLayout;
    QWidget * editWidget;
    QFormLayout * editLayout;
    QLineEdit * lineEdit;
    QDialogButtonBox* buttonBox;
};

#endif // DIALOG_H
