#include "connector.h"

Connector::Connector()
    : m_maxLenghtOfString{ 256 }
{

}

Connector::Connector(const wchar_t *portName)
    : m_portName{ portName }
    , m_maxLenghtOfString{ 256 }
{
    m_port = ::CreateFile(
        m_portName,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );
}

Connector::~Connector() {
    if (m_port != nullptr) CloseHandle(m_port);
}

Connector::Error_t
Connector::send(const Connector::Data_t &data) {
    if (m_port == nullptr)
        return Error_t::HandleIsNull;

    if (data.isEmpty()) {
        m_currentState = Error_t::EmptyData;
        return m_currentState;
    }

    std::string str{ data.to_str() };
    DWORD dwSize = str.length();
    DWORD dwBytesWritten;

    if (WriteFile(m_port, str.c_str(), dwSize, &dwBytesWritten, NULL)) {
        m_currentState = Error_t::OK;
        return m_currentState;
    }

    m_currentState = Error_t::SendingError;
    return m_currentState;
}

Connector::Error_t
Connector::createConnection() {

    m_port = ::CreateFile(
        m_portName,
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    return checkHandle(m_port);
}

void Connector::closeConnection() {
    CloseHandle(m_port);
    m_port = nullptr;
    m_currentState = Error_t::HandleIsNull;
}

Connector::Error_t
Connector::setStandartSettings() const {
    if (m_port == nullptr)
        return Error_t::HandleIsNull;

    DCB dcbSerialParams = { 0 };
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);

    if (!GetCommState(m_port, &dcbSerialParams))
        return Error_t::GettingStateError;

    dcbSerialParams.BaudRate = CBR_9600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity   = NOPARITY;

    if(!SetCommState(m_port, &dcbSerialParams))
        return Error_t::SettingSerialPortError;

    return Error_t::OK;
}

Connector::Data_t
Connector::ReadCOM() {
    if (m_port != nullptr) {
        DWORD iSize;

        char finder;
        do {
            ReadFile(m_port, &finder, sizeof(finder), &iSize, 0);
        } while (finder != '@');

        std::string number_str{ "" };
        short counter{};

        do {
            ReadFile(m_port, &finder, sizeof(finder), &iSize, 0);
            number_str.append(1, finder);
            if (finder == ';') ++counter;
        } while (finder != '\n' && counter != 4);

        /* Разделение строки формата "x:__.____;y:__.____;z:__.____;w:__.____;"
         * на 4 числа типа float. По сути нас так учат на теории алгоритмов при
         * обработке строк, но мне кажется, что можно сделать изящьнее, избегая
         * конструкций "цикл -> ветвление -> цикл"
         */


        float result[4]{};
        short cur_id{};
        for (auto begin{ number_str.begin() }, end{ begin } ;
             end != number_str.end();
             begin = ++end) {

            if ((*begin >= '0' && *begin <= '9') ||
                *begin == '.' || *begin == '-') {

                // ищем конец строки по формату
                while (*end != ';') ++end;

                // переводим все, между begin и end в float
                int id{ begin - number_str.begin() };

                std::string substring{ number_str.substr(id, end - begin) };
                result[cur_id++] = std::stof(substring);
            }
        }

        return Data_t{
            result[0],
            result[1],
            result[2],
            result[3],
        };
    }

    return Data_t{ 0.0f, 0.0f, 0.0f, 0.0f };
}

void Connector::setPortName(LPCTSTR portName) {
    m_portName = portName;
}

Connector::Error_t Connector::currentState() const {
    return m_currentState;
}

std::string Connector::errorToString(const Error_t error) const{
    switch (error) {
    case Connector::Error_t::OK:
        return std::string{"OK"};

    case Connector::Error_t::EmptyData:
        return std::string{"Empty data"};

    case Connector::Error_t::HandleIsNull:
        return std::string{"Port is closed or not exsist"};

    case Connector::Error_t::PortNotFound:
        return std::string{"Port not found"};

    case Connector::Error_t::SendingError:
        return std::string{"Sending error"};

    case Connector::Error_t::InvalidHandle:
        return std::string{"Invalid port or handle"};

    case Connector::Error_t::GettingStateError:
        return std::string{"Getting state error"};

    case Connector::Error_t::SettingSerialPortError:
        return std::string{"Serial port can not set settings"};

    default:
        return std::string{"Unknown error"};

    }
}

void Connector::setCurrentState(const Error_t& currentState)
{
    m_currentState = currentState;
}

Connector::Error_t
Connector::checkHandle(const HANDLE& handle) const {
    if (handle == nullptr)
        return Error_t::HandleIsNull;

    if (handle == INVALID_HANDLE_VALUE) {
        if (GetLastError()==ERROR_FILE_NOT_FOUND)
            return Error_t::PortNotFound;

        return Error_t::InvalidHandle;
    }

    return Error_t::OK;
}
