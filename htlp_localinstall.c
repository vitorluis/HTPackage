/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * htlp_localinstall.c
 * Copyright (C) 2013 Vitor Luis V. Neto <vitor@softwaredevelopment.com.br>
 * 
 * HTPackage is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * HTPackage is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "htlp_localinstall.h"

int htlp_localinstall_file_exists(char * filename) {
    if (access(filename, F_OK))
        return ERROR_FILE_NOT_FOUND;
    
    //Se o arquivo existe, retorna OK
    return FILE_EXISTS;
}

int htlp_localinstall_decompress(Package* package) {

    //ID da Thread
    pthread_t thread;
    void * status;


    //Chama a função principal responsavel pela descompactação
    pthread_create(&thread, NULL, htlp_decompress_main, (void*)package);
    pthread_join(thread, &status);

    if (*((int*) status) != DECOMPRESS_SUCCESSFULLY)
        return ERROR_UNABLE_TO_DECOMPRESS;


    //Se tudo der certo, manda um OK
    return DECOMPRESS_SUCCESSFULLY;
}

int htlp_localinstall_main(Package* package) {

    /*
     * Processos de instalação do local package
     * 
     * Verifica se o arquivo existe
     */

    if (htlp_localinstall_file_exists(package->_local_filename) == ERROR_FILE_NOT_FOUND) {
        perror("HTPackage LocalInstall Error");
        return INSTALLATION_FAILED;
    }

    /*
     * Se o arquivo existe, vamos para o proximo passo
     * Que é descompactar o arquivo
     */

    if (htlp_localinstall_decompress(package) != DECOMPRESS_SUCCESSFULLY) {
        perror("HTPackage LocalInstall Error");
        return INSTALLATION_FAILED;
    }

    /*
     * Agora faz o parse do arquivo de configuração do pacote
     * Que se encontra no diretório htlp
     */
    return INSTALLATION_SUCCESSFULLY;
}

int htlp_localinstall_exec_pre_install(const char* script) {
    /*
     * Executa o script, que é o pre install
     */
    if (system(script) != 0)
        return EXECUTE_PRE_INSTALL_FAILED;
    
    return EXECUTE_PRE_INSTALL_SUCCESSFULLY;
}