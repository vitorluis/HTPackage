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

    //Declaração das vars
    int file_descriptor_source;
    int file_descriptor_dest;
    char filename_dest[150];
    off_t offset = 0;
    struct stat stat_source;
    int copy_file;

    //Monta o path do arquivo de destino
    //Diretório do /var/cache/htpackage
    strcat(filename_dest, CACHE_PATH);

    //Nome do arquivo
    strcat(filename_dest, (const char *) filename);


    //Chama a syscall que abre o arquivo origem
    file_descriptor_source = open(filename, O_RDONLY);

    //Verifica se o arquivo foi aberto com sucesso, se não, retorna o erro
    if (file_descriptor_source == -1)
        return ERROR_COULD_NOT_OPEN_FILE;

    //Pega tamanho e permissão do arquivo de origem
    stat((const char *) filename, &stat_source);

    //Se chegar aqui, o arquivo origem foi aberto com sucesso
    //Vamos para a abertura do arquivo de destino.

    //Chama a syscall que abre o arquivo de destino
    file_descriptor_dest = open(filename_dest, O_CREAT);

    //Verifica se o arquivo foi criado.
    if (file_descriptor_dest == -1)
        return ERROR_COULD_NOT_CREATE_FILE;

    //Se chegar aqui, beleza, continua o processo de cópia
    copy_file = sendfile(file_descriptor_dest, file_descriptor_source, &offset, stat_source.st_size);
    
    //Verifica se foi copiado com sucesso
    if (copy_file != stat_source.st_size)
        return ERROR_COULD_NOT_COPY_FILE;

    //Se chegar aqui, o arquivo foi copiado com sucesso
    return COPY_FILE_SUCCESSFULLY;
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
        return ERROR_COULD_NOT_OPEN_STREAM_FILE;
    }
    fseek(file_stream, 0, SEEK_SET);
    return OPEN_STREAM_FILE_SUCCESSFULLY;
}