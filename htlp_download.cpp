/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * htlp_download.cpp
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

#include "htlp_download.hpp"

size_t write_data(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

HTLP_Download::HTLP_Download(const char* url, const char* package) {
    //Inicia as vars
    this->_url = (char*) url;
    this->_package = (char*) package;
}

void HTLP_Download::setUrl(const char* url) {
    //Seta a URL no atributo da classe
    strcpy(this->_url, url);
    return;
}

void HTLP_Download::setUrlList(std::vector<char*> list) {
    this->_url_list = list;
    return;
}

int HTLP_Download::downloadPackage() {
    //Inicia o ponteiro de cURL
    this->_downloader = curl_easy_init();

    //Filename final
    char * output_filename = new char[300];
    sprintf(output_filename, "%s%s", CACHE_PATH, this->_package);
    
    if (this->_downloader) {
        this->_stream_file = fopen(output_filename, "wb");
        curl_easy_setopt(this->_downloader, CURLOPT_URL, this->_url);
        curl_easy_setopt(this->_downloader, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(this->_downloader, CURLOPT_WRITEDATA, this->_stream_file);
        this->_res = curl_easy_perform(this->_downloader);

        //Limpa o ponteiro do cURL
        curl_easy_cleanup(this->_downloader);
        fclose(this->_stream_file);
        delete(output_filename);
    }

    if (access(output_filename,F_OK) == -1) {
        return ERROR_DOWNLOAD_FAILED;
    } else {
        return DOWNLOAD_SUCCESSFULL;
    }
}
