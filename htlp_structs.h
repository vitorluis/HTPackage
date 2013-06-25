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
    char _cache_filename[100];
    char _temp_dir[100];
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

struct bz_stream {
    char *next_in;
    unsigned int avail_in;
    unsigned int total_in;

    char *next_out;
    unsigned int avail_out;
    unsigned int total_out;

    void *state;

    void *(*bzalloc)(void *, int, int);
    void (*bzfree)(void *, void *);
    void *opaque;
};

#endif	/* HTLP_STRUCTS_H */

