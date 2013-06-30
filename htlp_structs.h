/* 
 * File:   htlp_structs.h
 * Author: vitor
 *
 * Created on June 20, 2013, 8:28 PM
 */
#ifndef HTLP_STRUCTS_H
#define	HTLP_STRUCTS_H
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <ctype.h>
#include <sys/types.h>

struct config {
    FILE * _file;
    const char * _name_package;
    const char * _version;
    const char * _author;
    int _size;
    const char * _requires;
    const char * _conflicts;
    const char * _pre_install;
    const char * _install;
    const char * _post_install;
};


struct package {
    char _name_package[100];
    char _url_package[100];
    char _local_filename[100];
    char _cache_filename[100];
    char _temp_dir[100];
    int _package_size;
    struct config _config;
};

struct data_connection {
    char _database_name[20];
    char * _database_user[20];
    char * _database_passwd[20];
    int port;
};

struct database {
    sqlite3 * _conn;
};
#endif	/* HTLP_STRUCTS_H */

