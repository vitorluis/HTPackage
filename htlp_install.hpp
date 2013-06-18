/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * htlp_install.hpp
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

#ifndef HTLP_INSTALL_HPP
#define	HTLP_INSTALL_HPP

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <map>
#include "htlp_defines.hpp"
#include "htlp_database.hpp"
#include "htlp_download.hpp"
#include "htlp_decompress.hpp"



class HTLP_Install {
private:
    char * _package;
    HTLP_Download * _downloader;
    HTLP_Database * _packages_database;
    HTLP_Decompress * _decompress_package;
    
public:
    HTLP_Install(char * package);
    bool searchPackage();
    bool resolvDependencies();
    bool downloadPackages();
    bool installPackages();
    void freeMemory();
};


#endif	/* HTLP_INSTALL_HPP */

