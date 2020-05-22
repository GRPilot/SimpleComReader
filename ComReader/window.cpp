#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent)
    : QMainWindow{ parent }
    , ui{ new Ui::Window }
    , m_connector{ new Connector() }
{
    ui->setupUi(this);
}

Window::~Window() {
    delete m_connector;
    delete ui;
}

void Window::showData(const Window::_data& data) const {
    if (data.isEmpty())
        return;

    float values[] {
        data.x,
        data.y,
        data.z,
        data.w
    };

    addDataInTable(values);
}

void Window::showError(const QString& message, _error error) const {
    if (message.isEmpty())
        return;

    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.setInformativeText(
        QString{"Error: %1"}
        .arg(m_connector->errorToString(error).c_str())
    );
    msgBox.setStandardButtons(QMessageBox::Ok);

    msgBox.exec();
}

void Window::addDataInTable(const float* data) const {
    if (data == nullptr)
        return;

    const int rowCount{ ui->outTable->rowCount() };
    const int columnCount{ ui->outTable->columnCount() };
    ui->outTable->insertRow(rowCount);

    for (int item_id{}; item_id < columnCount; ++item_id) {
        ui->outTable
          ->setItem(
              rowCount,
              item_id,
              new QTableWidgetItem{
                  QString::number(data[item_id])
              }
        );
    }
}

bool Window::makeConnection() const {
    QString portName{
        ui->comsComboBox->currentText()
    };

    LPCTSTR wchar_portName{ (LPCTSTR)portName.utf16() };
    m_connector->setPortName(wchar_portName);
    _error status{ m_connector->createConnection() };

    if (status != _error::OK) {
        showError(
            QString{"Порт %1 недоступен"}.arg(portName),
            status
        );
        return false;
    }

    status = m_connector->setStandartSettings();

    if (status != _error::OK) {
        showError(
            QString{"Не удается установить стандартные настройки для порта %1"}.arg(portName),
            status
        );
        return false;
     }

    return true;
}

// TODO: Сделать чтение в другом потоке
void Window::on_connectButton_clicked() {

    if (makeConnection()) {

        reading(ui->countOfPackets->value());

        m_connector->closeConnection();
    }
}

Window::_data Window::getData() {
    return m_connector->ReadCOM();
}

void Window::reading(const long countOfPockets) {

    for (long pockets{}; pockets < countOfPockets; ++pockets) {
       _data buf{ getData() };
       showData(buf);
    }
}

void Window::on_sendButton_clicked() {
        if(makeConnection()) {
            _data sendingData{
                static_cast<float>(ui->x_box->value()),
                static_cast<float>(ui->y_box->value()),
                static_cast<float>(ui->z_box->value()),
                static_cast<float>(ui->w_box->value())
            };

            m_connector->send(sendingData);
        } else {
            showError("Не удалось отправить сообщение.", _error::SendingError);
        }
        m_connector->closeConnection();
}


