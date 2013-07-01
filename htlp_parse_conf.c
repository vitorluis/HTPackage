/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * htlp_parse_conf.c
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
 *
 */

#include "htlp_parse_conf.h"

int htlp_parse_conf_main(Package * package, Config * conf) {
    /*
     * Função principal para ler a configuração do pacote.
     * Abre o arquivo de configuração
     */
    htlp_parse_conf_open_file(conf, package->_temp_dir);

    return PARSE_COMPLETE;
}

int htlp_parse_conf_open_file(Config * conf, char * temp_dir) {
    //Faz a abertura do arquivo
    conf->_file = fopen(strcat(temp_dir, "htlp/package.conf"), "r");

    //Verifica se o arquivo foi aberto com sucesso
    if (conf->_file == NULL)
        return ERROR_COULD_NOT_OPEN_STREAM_FILE;

    //Se chegar aqui, beleza, o arquivo foi aberto com sucesso

    return OPEN_STREAM_FILE_SUCCESSFULLY;
}

int htlp_parse_conf_parse(Package * package, Config* conf) {
    //Inicia o ponteiro
    config_init(&conf->config);

    //Abre o arquivo e faz a leitura
    if (!config_read(&conf->config, conf->_file))
        return ERROR_COULD_NOT_READ_CONF_FILE;

    //Agora faz a captura dos valores e coloca nos atributos da struct
    //Le o nome do pacote
    if (!config_lookup_string(&conf->config, "information.name", &conf->_name_package))
        return ERROR_PARSE_FAIL;

    //Faz a leitura da versão
    if (!config_lookup_string(&conf->config, "information.version", &conf->_version))
        return ERROR_PARSE_FAIL;

    //Faz a leitura do autor
    if (!config_lookup_string(&conf->config, "information.author", &conf->_author))
        return ERROR_PARSE_FAIL;

    //Leitura das dependencias
    if (!config_lookup_string(&conf->config, "information.depends", &conf->_depends))
        return ERROR_PARSE_FAIL;

    //Leitura dos conflitos
    if (!config_lookup_string(&conf->config, "information.conflicts", &conf->_conflicts))
        return ERROR_PARSE_FAIL;

    //Lê a arquitetura
    if (!config_lookup_string(&conf->config, "information.arch", &conf->_arch))
        return ERROR_PARSE_FAIL;

    //Lê o tamanho do arquivo
    if (!config_lookup_int(&conf->config, "information.size", &conf->_size))
        return ERROR_PARSE_FAIL;

    //Passa algumas informações do arquivo de configuração, para a struct package
    //Nome do pacote
    strcat(package->_name_package, conf->_name_package);

    //Tamanho do pacote
    package->_package_size = conf->_size;

    //Coloca o conf na struct package
    package->_config = conf;

    //Caso de sucesso em todas as leituras, retorna OK
    return PARSE_COMPLETE;
}