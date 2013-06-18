/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * htlp_download.hpp
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

#ifndef HTLP_DOWNLOAD_HPP
#define	HTLP_DOWNLOAD_HPP

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <vector>
#include <cctype>
#include <curl/curl.h>
#include <curl/easy.h>
#include "htlp_defines.hpp"

class HTLP_Download {
private:
    char * _package;
    char * _url;
    std::vector<char*> _url_list;
    CURL * _downloader;
    CURLcode _res;
    FILE * _stream_file;
    size_t writeData(void *ptr, size_t size, size_t nmemb, FILE *stream);
public:
    void setUrl(char * url);
    void setUrlList(std::vector<char*> list);
    int downloadPackage();
    int downloadPackageList();
};


#endif	/* HTLP_DOWNLOAD_HPP */

