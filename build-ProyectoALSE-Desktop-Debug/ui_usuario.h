/********************************************************************************
** Form generated from reading UI file 'usuario.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USUARIO_H
#define UI_USUARIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usuario
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *_username;
    QLabel *label;
    QLineEdit *_usrpassword;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *usuario)
    {
        if (usuario->objectName().isEmpty())
            usuario->setObjectName(QStringLiteral("usuario"));
        usuario->resize(331, 197);
        usuario->setModal(false);
        layoutWidget = new QWidget(usuario);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(60, 20, 218, 122));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font;
        font.setPointSize(14);
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        _username = new QLineEdit(layoutWidget);
        _username->setObjectName(QStringLiteral("_username"));

        gridLayout->addWidget(_username, 0, 1, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        _usrpassword = new QLineEdit(layoutWidget);
        _usrpassword->setObjectName(QStringLiteral("_usrpassword"));

        gridLayout->addWidget(_usrpassword, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        buttonBox = new QDialogButtonBox(usuario);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(90, 150, 166, 25));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(usuario);

        QMetaObject::connectSlotsByName(usuario);
    } // setupUi

    void retranslateUi(QDialog *usuario)
    {
        usuario->setWindowTitle(QApplication::translate("usuario", "Ingreso de usuario", Q_NULLPTR));
        label_2->setText(QApplication::translate("usuario", "Clave", Q_NULLPTR));
        label->setText(QApplication::translate("usuario", "Usuario", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class usuario: public Ui_usuario {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USUARIO_H
