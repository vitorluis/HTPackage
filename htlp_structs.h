/* 
 * File:   htlp_structs.h
 * Author: vitor
 *
 * Created on June 20, 2013, 8:28 PM
 */
#ifndef HTLP_STRUCTS_H
#define	HTLP_STRUCTS_H
#include <sqlite3.h>
#include <ctype.h>
#include <sys/types.h>

struct package {
    char _name_package[100];
    char _url_package[100];
    char _local_filename[100];
    char _cache_filename[100];
    char _temp_dir[100];
    int _package_size;
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

struct config {
    char _name_package[50];
    char _version[10];
    char _author[50];
    size_t _size;
    char _requires[30];
    char _conflicts[30];
    char * pre_install[50];
    char * install[50];
    char * post_install[50];
};

#endif	/* HTLP_STRUCTS_H */

