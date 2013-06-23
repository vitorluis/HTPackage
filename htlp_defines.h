/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * htlp_defines.hpp
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

#ifndef HTLP_DEFINES_HPP
#define	HTLP_DEFINES_HPP

/*
 * Definições de erros
 */

//Erro geral
#define ERROR_GENERAL_CODE -1

//Erros em relação aos pacotes
#define ERROR_PACKAGE_NOT_FOUND 100
#define ERROR_BROKEN_DEPENDENCIES 101

//Erros em relação a conexão com a internet
#define ERROR_NOT_CONNECTED 102
#define ERROR_HTTP_404 103
#define ERROR_DOWNLOAD_FAILED 114
#define ERROR_UNABLE_TO_RESOLVE_DNS 104

//Erros em relação ao database
#define ERROR_DATABASE_NOT_FOUND 105
#define ERROR_COULD_NOT_NOT_OPEN_DATABASE 106
#define ERROR_DRIVER_NOT_FOUND 107
#define ERROR_BROKEN_DATABASE 108

//Erro em relação aos arquivos
#define ERROR_FILE_NOT_FOUND 109
#define ERROR_PERMISSION_DENIED 110
#define ERROR_UNABLE_TO_DECOMPRESS 111
#define ERROR_UNABLE_TO_COMPRESS 112
#define ERROR_COULD_NOT_OPEN_STREAM_FILE 116
#define ERROR_COULD_NOT_OPEN_FILE 118
#define ERROR_COULD_NOT_CREATE_FILE 119
#define ERROR_COULD_NOT_COPY_FILE 120

/*
 * Definições de paths
 */

#define HOME_PATH "/var/htpackage/"
#define DATABASE_PATH "/var/htpackage/data/"
#define CACHE_PATH "/var/cache/htpackage/"
#define LOG_PATH "/var/log/htpackage/"
#define CONF_FILES_PATH "/etc/htpackage/"
#define BIN_PATH "/usr/bin/"

/*
 * Definições do Banco de Dados
 */

#define DATABASE_FILENAME "Packages.db"
#define DATABASE_NAME "packages"
#define DATABASE_USER "htpackage"
#define DATABASE_PASSWD "htlinux2013"

/*
 * Definições do cURL
 */

#define DOWNLOAD_SUCCESSFULLY 113

/*
 * Definições de Instalação
 */



#define INSTALLATION_SUCCESSFULLY 114
#define INSTALLATION_FAILED 115

/*
 * Definições de arquivos
 */


#define OPEN_STREAM_FILE_SUCCESSFULLY 117
#define COPY_FILE_SUCCESSFULLY 121

#endif	/* HTLP_DEFINES_HPP */

