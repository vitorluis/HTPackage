/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * htlp.cpp
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
#include "htlp.h"

void showVersion() {
    printf("HTPackage - Gerenciador de Pacotes\n");
    printf("%c[1mVersão 0.1\n", 27);
    printf("%c[0m", 27);
    printf("Criado por Vitor Luis V. Neto\n");
    printf("Contato: vitor@softwaredevelopment.com.br\n");
    printf("Bugs: bugs@howtolinux.com.br\n");
}

int installPackage(char* package) {
    return 0;
}

int localInstallPackage(char* filename) {
    return 0;
}
