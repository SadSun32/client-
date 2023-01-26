#pragma once
#include "console.h"
#include "operator.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
using namespace std;

#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/filters.h>
#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>

using namespace CryptoPP;

class Web
{
public:
    Web(const Console & a, const Filer& op);
    ~Web();//<дecтруктор
    void Connect();///<Установка соединения между клиентом и сервером
    void Auth();///<Авторизация клиента на сервере

    /// Не используются!
    int Receiving(int Socket);
    void Sending(int Socket, char* buf, size_t size);
    void Install();

private:
    sockaddr_in * caddr;///<Cтруктура с адресом программы клиента
    sockaddr_in * saddr;///<Cтруктура с адресом программы сервера
    int socket_; ///< Основной сокет
    std::string login;///< Логин для авторизации
    std::string pswd;///< Пароль для авторизации
};
