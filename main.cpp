#include "console.h"
#include "operator.h"
#include "connect.h"

int main(int argc, char **argv)
{
	Console a(argc, argv);
	Filer op(a);
	Web web(a, op);

	///Здесь должны выполняться какие-то команды

	std::cout << op.getAmount() << std::endl;
	for (int i = 0; i < op.getAmount(); ++i)
	{
		std::vector<uint64_t> v = op.getVector(i);
		uint64_t s = op.getVectorSize(i);
		std::cout << s << std::endl;
		for (int i = 0; i < s; ++i)
			std::cout << '\t' << v[i] << std::endl;
	}
	
	std::cout << "login: "<< op.getLogin() << std::endl;	
	std::cout << "pswd: " << op.getPswd() << std::endl;	   
	return 0;
}
