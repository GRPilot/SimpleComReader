#pragma once

#include <QMainWindow>
#include <QMessageBox>

#include "connector.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Window; }
QT_END_NAMESPACE

class Window : public QMainWindow
{
    Q_OBJECT
    using _data = Connector::Data_t;
    using _error = Connector::Error_t;

public:
    Window(QWidget *parent = nullptr);
    ~Window();

private slots:
    void on_connectButton_clicked();
    void on_sendButton_clicked();

private:
    Ui::Window *ui;
    Connector  *m_connector;

    _data getData();
    void reading(const clock_t seconds);
    void showData(const _data& data) const;
    void showError(const QString& message, _error) const;
    void addDataInTable(const float* data) const;
    bool makeConnection() const;
};
