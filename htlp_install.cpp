/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * htlp_install.cpp
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
#include "htlp_install.hpp"

HTLP_Install::HTLP_Install(char* package) {
    //Copia para o atributo o package a ser instalado
    strcpy(this->_package, package);
}

bool HTLP_Install::searchPackage() {
    return true;
}

bool HTLP_Install::resolvDependencies() {
    return true;
}