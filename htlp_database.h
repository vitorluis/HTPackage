/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * htlp_database.h
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

#ifndef HTLP_DATABASE_H
#define	HTLP_DATABASE_H
#include <sqlite3.h>

struct data_connection {
    char * _database_name;
    char * _database_user;
    char * _database_passwd;
    int port;
};

struct database {
    sqlite3 * _conn;
};

int openConnection(struct data_connection * data);
int executeQuery(char * sql);

#endif	/* HTLP_DATABASE_H */

