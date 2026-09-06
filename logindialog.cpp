#include "logindialog.h"
#include "ui_logindialog.h"

#include <QMessageBox>
#include <QPushButton>

LoginDialog::LoginDialog(const UserList &userList, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
    , users(userList)
{
    ui->setupUi(this);

    connect(ui->pushButtonLogin, &QPushButton::clicked, this, &LoginDialog::onLoginClicked);
    connect(ui->pushButtonQuit, &QPushButton::clicked, this, &LoginDialog::reject);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

User LoginDialog::authenticatedUser() const
{
    return m_user;
}

void LoginDialog::onLoginClicked()
{
    const QString username = ui->lineEditUsername->text().trimmed();
    const QString password = ui->lineEditPassword->text();

    const User *user = users.authenticate(username, password);
    if (!user) {
        QMessageBox::warning(this, tr("Login failed"),
                             tr("Unknown username or wrong password."));
        ui->lineEditPassword->clear();
        ui->lineEditPassword->setFocus();
        return;
    }

    m_user = *user;
    accept();
}
