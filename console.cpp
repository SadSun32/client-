#include "console.h"
using namespace std;

Console::Console(int argc, char **argv)
{
    int opt;
    while((opt = getopt(argc, argv, "i:p:o:h:a:r")) != -1)
    {
        switch(opt) 
        {
        case 'i': // айпи адрес сервера
                ip_ = string(optarg);
            break;
        case 'p': // порт
                port_ = strtol(optarg, nullptr);
            break;
        case 'a': // файл аутентификации
                auth_ = string(optarg);
            break;
        case 'o': // исходник
               original_ = string(optarg);
            break;
        case 'r': // результатник
               result_ = string(optarg);
            break;
        case 'h': // help
        default:
                std::cout << "Usage: " << argv[0] << "\n -i server address, \n -o name original file, \n -r name result file,\n -p server port,\n -a name auth file\n";
                exit(1);
        }
    }
}

