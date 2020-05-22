#pragma once

#include <windows.h>
#include <thread>
#include <string>

class Connector {
 public:
    Connector();
    Connector(const wchar_t *portName);
    ~Connector();

    struct Data_t {
        float x;
        float y;
        float z;
        float w;
        Data_t(float _x, float _y, float _z, float _w)
            : x{ _x }, y{ _y }, z{ _z }, w{ _w }, isInit{ true } {}

        bool isEmpty() const {
            return !isInit;
        }

        std::string to_str() const {
            std::string result{ "@x:" };
            result.append(std::to_string(this->x));
            result.append(";y:");
            result.append(std::to_string(this->y));
            result.append(";z:");
            result.append(std::to_string(this->z));
            result.append(";w:");
            result.append(std::to_string(this->w));
            result.append(";\n");

            return result;
        }

     private:
        bool isInit{ false };
    };

    enum class Error_t {
        OK,
        PortNotFound,
        InvalidHandle,
        HandleIsNull,

        GettingStateError,
        SettingSerialPortError,

        EmptyData,
        SendingError,
    };

    Error_t send(const Data_t& data);
    Error_t createConnection();
    void    closeConnection();

    Error_t setStandartSettings() const;
    Data_t  ReadCOM();
    void    setPortName(LPCTSTR portName);

    Error_t currentState() const;
    std::string errorToString(const Error_t error) const;
    void setCurrentState(const Error_t& currentState);

private:
    HANDLE m_port;
    LPCTSTR m_portName;
    Error_t m_currentState;
    const short m_maxLenghtOfString;

    Error_t checkHandle(const HANDLE &handle) const;
};

