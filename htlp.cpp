#include "htlp.hpp"

HTLP::HTLP(char ** args) {
    if (strcmp("--version", args[1]) == 0) {
        this->showVersion();
    } else if (strcmp("--install", args[1]) == 0) {
        this->installPackage(args[2]);
    }
}

void HTLP::showVersion() {
    printf("HTPackage - Gerenciador de Pacotes\n");
    printf("%c[1mVersão 0.1\n", 27);
    printf("%c[0m", 27);
    printf("Criado por Vitor Luis V. Neto\n");
    printf("Contato: vitor@softwaredevelopment.com.br\n");
    printf("Bugs: bugs@howtolinux.com.br\n");
}

bool HTLP::installPackage(char* package) {
    return true;
}

bool HTLP::localInstallPackage(char* filename) {
    return true;
}
