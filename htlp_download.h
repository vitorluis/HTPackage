/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * htlp_download.h
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <curl/curl.h>
#include <curl/easy.h>
#include <unistd.h>
#include <fcntl.h>
#include "htlp_defines.h"
#include "htlp_structs.h"
#include "htlp_typedefs.h"

size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream);

int downloadPackage(Package * package);
int downloadPackageList(Package packages[]);


#endif	/* HTLP_DOWNLOAD_HPP */

