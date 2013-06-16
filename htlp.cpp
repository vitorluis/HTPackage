#include "htlp.hpp"

HTLP::HTLP(char* option) {
    if (strcmp("--version",option) == 0) {
        printf("Versão 0.1\n");
    }
}
