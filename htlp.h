/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * htlp.h
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

#ifndef HTLP_H
#define	HTLP_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htlp_database.h"
#include "htlp_install.h"
#include "htlp_download.h"
#include "htlp_localinstall.h"

/*
 * Valida os parametros que o usuário passar na linha de comando
 * Verifica se o parametro existe, e faz a chamada a função correspondente
 * 
 */
int validateOption();

/*
 * Mostra a versão do programa e algumas informações
 * adicionais e depois sai
 */

void showVersion();

/*
 * Faz chamada a principal função 
 * que é resposavel pela instalação dos pacotes
 */

int installPackage(char * name_package);


/*
 * Faz chamada a principal função que 
 * é responsavel pela instalação dos 
 * pacotes locais
 */


int localInstallPackage(char * local_filename);


/*
 * Faz chamada a principal função que 
 * é responsavel pelo upgrade de pacotes
 */


int upgradePackage(char * name_package);

/*
 * Faz chamada a principal função que 
 * é responsavel pelo instalação de pacotes
 * locais
 */

int localInstallPackage(char * filename);

/*
 * Faz chamada a principal função que 
 * é responsavel pelo upgrade de pacotes
 */

int upgradeAllPackages();

/*
 * Faz chamada a principal função que 
 * é responsavel pelo pesquisa de pacotes
 * no repositório
 */

char ** searchPackage(char * name_package);

/*
 * Faz chamada a principal função que 
 * é responsavel pelo upgrade de  todos os pacotes
 * instalados no sistema
 */
int checkUpdate();

/*
 * Faz chamada a principal função que 
 * é responsavel pela remoção de pacotes
 * instalados no sistema
 */

int removePackage();

/*
 * Mostra o conteúdo de ajuda e sai
 */
void showHelp();

#endif	/* HTLP_H */

