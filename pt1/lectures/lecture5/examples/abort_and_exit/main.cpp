#include <iostream>
#include <string>
#include <csignal>

class Test
{
public:
	Test(const std::string& name) : _name(name)
	{};
	~Test()
	{
		std::cout << "Destruction of " << _name << std::endl;
	};

private:
	std::string _name;
};

void signalHandler(int signal) 
{
    std::cout << "Signal handling" << std::endl; 
    if (signal == SIGABRT) {
        std::cout << "SIGABRT received" << std::endl;
    } else {
        std::cout << "Unexpected signal " << signal << " received" << std::endl;
    }
    exit(EXIT_FAILURE);
}


Test globalObj("Global");
static Test staticObj("Static in main");

int main()
{
    // системный вызов abort() посылает сигнал SIGABT вызвавшему его процессу
    // сигнал можно перхватить, зарегистрировав обработчик
    // При вызове abort() деструкторы объектов не вызываются (вообще)
    // Будут ли закрыты ассоциированные с процессом файловые дескрипторы - implementation defined
    // Память процесса может быть сброшена на диск для дальнейшего поиска ошибки (memory dump) 
    // auto handler = std::signal(SIGABRT, signalHandler);
    // if (handler == SIG_ERR) {
    //     std::cerr << "Setup failed" << std::endl;
    //     return EXIT_FAILURE;
    // }

	Test automaticObj("Automatic");
	// std::cout << "Aborting" << std::endl;  
	// std::abort();

	// Необработанное исключение приводит к вызову системной функции terminate(),
	// отвечающей за аварийное завершение процесса.
	// terminate(), в свою очередь, вызовет abort() 
	// throw 1;

	// Системный вызов exit() приводит к корректному завершению программы
	// с вызовом деструкторов неавтоматических объектов, сбросом всех буферов
	// и освобожением файловых дескрипторов
	std::exit(0);

	// return status аналогичен exit(status), но вызывает деструкторы
	// автоматических объектов
	//return 0;
}