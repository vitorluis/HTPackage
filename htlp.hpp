/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * htlp.hpp
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

#ifndef HTLP_HPP
#define	HTLP_HPP
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <map>
#include "htlp_database.hpp"
#include "htlp_install.hpp"
#include "htlp_download.hpp"

class HTLP {
private:
    char * option;
    char * name_package;
    HTLP_Install * _install_packages;
    
public:
    HTLP(char ** args);
    int validateOption();
    void showVersion();
    bool installPackage(char * package);    
    bool updatePackage(char * package);
    bool localInstallPackage(char * filename);
    bool upgradeAllPackages();
    std::map<int,char*> searchPackage(char * package);
    bool checkUpdate();
    bool removePackage();
    void showHelp();
};



#endif	/* HTLP_HPP */

