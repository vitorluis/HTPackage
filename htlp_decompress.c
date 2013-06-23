/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * htlp_decompress.c
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
#include "htlp_decompress.h"

int htlp_decompress_main(Package* package) {

}

int htlp_decompress_copy_file(char * filename) {
    /*
        int fdSource = open(source, O_RDONLY);

        if (fdSource > 0) {
            if (lockf(fdSource, F_LOCK, 0) == -1) return 0; 
     *    } else return 0;


        int fdDest = open(dest, O_CREAT);
        off_t lCount;
        struct stat sourceStat;
        if (fdSource > 0 && fdDest > 0) {
            if (!stat(source, &sourceStat)) {
                int len = sendfile(fdDest, fdSource, &lCount, sourceStat.st_size);
                if (len > 0 && len == sourceStat.st_size) {
                    close(fdDest);
                    close(fdSource);

                    if (lockf(fdSource, T_LOCK, 0) == -1) {
                        if (lockf(fdSource, F_ULOCK, 0) == -1) {

                        } else {
                            return 1; 
                        }
                    } else {

                        return 0; 
                    }
                }
            }
        }*/
    return 0;
}

int htlp_decompress_decompress(char * filename) {
    //Abre o Stream do arquivo
    FILE * file_stream;
    htlp_decompress_open_file(filename, file_stream);

    //Faz a descompactação
    int bzError;
    BZFILE *bzf;
    char buf[4096];

    bzf = BZ2_bzReadOpen(&bzError, file_stream, 0, 0, NULL, 0);
    if (bzError != BZ_OK) {
        perror("HTPackage LocalInstall Error");
        return ERROR_UNABLE_TO_DECOMPRESS;
    }

    while (bzError == BZ_OK) {
        int nread = BZ2_bzRead(&bzError, bzf, buf, sizeof buf);
        if (bzError == BZ_OK || bzError == BZ_STREAM_END) {
            size_t nwritten = fwrite(buf, 1, nread, stdout);
            if (nwritten != (size_t) nread) {
                fprintf(stderr, "E: short write\n");
                return -1;
            }
        }
    }

    if (bzError != BZ_STREAM_END) {
        fprintf(stderr, "E: bzip error after read: %d\n", bzError);
        return -1;
    }

    BZ2_bzReadClose(&bzError, bzf);
}

int htlp_decompress_open_file(char* filename, FILE * file_stream) {
    file_stream = fopen(filename, "rb");
    if (file_stream == NULL) {
        perror(filename);
        return ERROR_COULD_OPEN_STREAM_FILE;
    }
    fseek(file_stream, 0, SEEK_SET);
    return OPEN_STREAM_FILE_SUCCESSFULLY;
}