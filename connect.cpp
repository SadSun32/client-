#include "connect.h"

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
using namespace CryptoPP;

Web::Web(const Console & a, const Filer& op): caddr(new sockaddr_in),
                                              saddr(new sockaddr_in)
{
   	caddr->sin_port = htons(a.getPort());
    caddr->sin_addr.s_addr = inet_addr(a.getIP().c_str());
    
    /// Надо бы заполнить
    saddr->sin_family = AF_INET;
   	saddr->sin_port = 0;
    saddr->sin_addr.s_addr = 0;
    
    socket_ = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_ == -1) 
    {
        std::cerr << "Error open socket\n";
        close(socket_);
        exit(1);
    }

    int value = 1;
    setsockopt(socket_, SOL_SOCKET, SO_REUSEADDR, &value, sizeof(int));
    
    login = op.getLogin();
    pswd  = op.getPswd();
}

/// После заполнения saddr
void Web::Install()
{
    int rc = bind(socket_, (const sockaddr *) saddr, sizeof (sockaddr_in));
    if (rc == -1) 
    {
        cerr << "Error bind socket with local address\n";
        close(socket_);
        exit(1);
    }

    rc = connect(socket_, (const sockaddr*) caddr, sizeof(sockaddr_in));
    if (rc == -1) 
    {
        cerr << "Error connect socket with server\n";
        close(socket_);
        exit(1);
    }
}

void Web::Auth() 
{
    const size_t BUFSIZE = 2048;  

    send(socket_, login.c_str(), login.length(), 0);//отправляем login
    
    std::string msg;///< Сообщение для отправки данных
    msg.reserve(BUFSIZE);
    recv(socket_, msg.c_str(), msg.length(), 0);//получаем ответ
    if (msg == "ERR")
    {
        cerr << "Not found login\n";
        close(socket_);
        exit(1);
    }

	msg += pswd;

    std::string Hash;///< Зашифрованный пароль
    Weak::MD5 hash;

    StringSource(msg, true, new HashFilter(hash, new HexEncoder(new StringSink (Hash))));

    int rc = send(socket_, Hash.c_str(), Hash.length(), 0); // отправляем  Hash

    if (rc == -1) 
    {
        std::cerr << "Error send message\n";
        close(socket_);
        exit(1);
    }

    delete[] buf;  
}

/// и где это будет использовано? 
void Web::Sending(int Socket, char* buf, size_t size) 
{
    int rc = send(Socket, (const void*) &buf, sizeof(buf), 0);
    if (rc == -1) 
    {
        std::cerr << "Error send message\n";
        close(Socket);
        exit(1);
    }
}

/// и где это? 
int Web::Receiving(int Socket)
{
    uint64_t piece;
    int rc = recv(Socket,(void*) &piece, sizeof(piece), 0);
    if (rc == -1) 
    {
        std::cerr <<"Error receive answer\n";
        close(Socket);
        exit(1);
    }
    
    return piece;
}

Web::~Web()
{
	delete caddr;
	delete saddr;
}
