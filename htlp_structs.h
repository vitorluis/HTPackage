/* 
 * File:   htlp_structs.h
 * Author: vitor
 *
 * Created on June 20, 2013, 8:28 PM
 */

#ifndef HTLP_STRUCTS_H
#define	HTLP_STRUCTS_H
#include <sqlite3.h>

struct package {
    char _name_package[100];
    char _url_package[100];
    char _local_filename[100];
    int _package_size;
};

struct data_connection {
    char * _database_name;
    char * _database_user;
    char * _database_passwd;
    int port;
};

struct database {
    sqlite3 * _conn;
};

#endif	/* HTLP_STRUCTS_H */

