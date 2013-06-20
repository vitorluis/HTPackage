/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * htlp_install.h
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

#ifndef HTLP_INSTALL_H
#define	HTLP_INSTALL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "htlp_defines.h"
#include "htlp_database.h"
#include "htlp_download.h"
#include "htlp_decompress.h"

struct package {
    char * _name_package;
    char * _url_package;
    int _package_size;
};

int htlp_install_searchPackage();
int htlp_install_resolvDependencies();
int htlp_install_downloadPackages();
int htlp_install_installPackages();
void htlp_install_freeMemory();


#endif	/* HTLP_INSTALL_H */