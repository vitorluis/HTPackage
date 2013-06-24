/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * htlp_decompress.h
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

#ifndef HTLP_DECOMPRESS_PACKAGE_H
#define	HTLP_DECOMPRESS_PACKAGE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bzlib.h>
#include <zlib.h>
#include <libtar.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/sendfile.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "htlp_defines.h"
#include "htlp_structs.h"
#include "htlp_typedefs.h"

int htlp_decompress_main(Package * package);

int htlp_decompress_decompress(char * filename);

int htlp_decompress_copy_file(char * filename);

int htlp_decompress_open_file(char * filename, FILE * file_stream);
#endif	/* HTLP_DECOMPRESS_PACKAGE_HPP */

