/* 
 * File:   htlp_parse_conf.h
 * Author: vitor
 *
 * Created on June 26, 2013, 7:08 PM
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

int htlp_parse_conf_main();

int htlp_parse_conf_open_file();
#endif	/* HTLP_PARSE_CONF_H */

