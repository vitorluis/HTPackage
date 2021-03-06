/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * htlp_parse_conf.h
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
 *
 */

#ifndef HTLP_PARSE_CONF_H
#define	HTLP_PARSE_CONF_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <libconfig.h>
#include "htlp_defines.h"
#include "htlp_structs.h"
#include "htlp_typedefs.h"

int htlp_parse_conf_main(Package * package, Config * conf);

int htlp_parse_conf_open_file(Config * conf, char * temp_dir);

int htlp_parse_conf_parse_information(Package * package, Config * conf);

int htlp_parse_conf_parse_pre_install(Config * conf);

int htlp_parse_conf_parse_install(Config * conf);

int htlp_parse_conf_parse_post_install(Config * conf);
#endif	/* HTLP_PARSE_CONF_H */