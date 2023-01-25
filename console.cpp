#include "console.h"
using namespace std;

console::console(int argc,char **argv){
    int opt;
    while((opt = getopt(argc, argv, "i:p:o:h:a:r")) != -1) {
        switch(opt) {
        case 'h': // help
        case 'i': // айпи адрес сервера
                ip = string(optarg);
            break;
        case 'p': // порт
                port=strtol(optarg,nullptr,10);
            break;
        case 'a': // файл аутентификации
                auth=string(optarg);
            break;
        case 'o': // исходник
               original=string(optarg);
           break;
        case 'r': // результатник
               Result= string(optarg);
            break;
            help(argv[0]);
        }
    }
        //если не установлен не один из обязательных параметраметров - выход
        if (!useIp || !useOriginal || !useResult) {
        	useIp  = useOriginal  = useResult =  false;
        	help(argv[0]);    
    } 
}

// краткая справки и досрочное завершение программы
void console::help(const char* progName){
    cout<<"Usage: "<< progName<< "\n -i server address, \n -o name original file, \n -r name result file,\n -p server port,\n -a name auth file\n";
    exit(1);
}
