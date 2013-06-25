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
    //Copia o arquivo
    if (htlp_decompress_copy_file(package) != COPY_FILE_SUCCESSFULLY)
        return ERROR_UNABLE_TO_DECOMPRESS;

    //Se chegar aqui, Faz a descompressão
    htlp_decompress_decompress(package->_cache_filename);

}

int htlp_decompress_copy_file(Package * package) {

    //Declaração das vars
    int file_descriptor_source;
    int file_descriptor_dest;
    char * filename_dest;
    char * temp_filename_dest;
    off_t offset = 0;
    struct stat stat_source;
    int copy_file;

    //Monta o path do arquivo de destino
    //Diretório do /var/cache/htpackage
    temp_filename_dest = (char *) malloc(150);
    strcat(package->_cache_filename, CACHE_PATH);

    //Monta o nome do arquivo de destino
    temp_filename_dest = strrchr(package->_local_filename, '/');
    if (temp_filename_dest == NULL) {
        strcat(package->_cache_filename, (const char *) temp_filename_dest);
    } else {
        strcat(package->_cache_filename, (const char *) temp_filename_dest + 1);
    }

    //Chama a syscall que abre o arquivo origem
    file_descriptor_source = open(package->_local_filename, O_RDONLY);


    //Verifica se o arquivo foi aberto com sucesso, se não, retorna o erro
    if (file_descriptor_source == -1)
        return ERROR_COULD_NOT_OPEN_FILE;

    //Pega tamanho e permissão do arquivo de origem
    stat((const char *) package->_local_filename, &stat_source);

    //Se chegar aqui, o arquivo origem foi aberto com sucesso
    //Vamos para a abertura do arquivo de destino.

    //Chama a syscall que abre o arquivo de destino
    file_descriptor_dest = open(package->_cache_filename, O_WRONLY | O_CREAT, stat_source.st_mode);

    //Verifica se o arquivo foi criado.
    if (file_descriptor_dest == -1)
        return ERROR_COULD_NOT_CREATE_FILE;

    //Se chegar aqui, beleza, continua o processo de cópia
    copy_file = sendfile(file_descriptor_dest, file_descriptor_source, &offset, stat_source.st_size);

    //Verifica se foi copiado com sucesso
    if (copy_file != stat_source.st_size)
        return ERROR_COULD_NOT_COPY_FILE;

    //Se chegar aqui, o arquivo foi copiado com sucesso

    //Fecha os file descriptors
    close(file_descriptor_dest);
    close(file_descriptor_source);

    //Desaloca a memória
    //TODO: Por algum motivo da segfault no free()
    //Desativando temporariamente

    //free(temp_filename_dest);
    //free(filename_dest);

    //Retorna Sucesso
    return COPY_FILE_SUCCESSFULLY;
}

int htlp_decompress_decompress(char * cache_filename) {

    //Declara as vars
    TAR * tar_file;
    char rootdir[200];
    tartype_t gztype = {(openfunc_t) htlp_decompress_gzopen, (closefunc_t) gzclose, (readfunc_t) gzread, (writefunc_t) gzwrite};

    //Copia o diretório de output
    strcpy(rootdir, "/var/cache/htpackage/");

    //Cria a pasta para jogar os arquivos dentro

    if (tar_open(&tar_file, cache_filename, &gztype, O_RDONLY, 0, TAR_GNU) == -1)
        return ERROR_COULD_NOT_OPEN_FILE;


    if (tar_extract_all(tar_file, rootdir) != 0)
        return ERROR_UNABLE_TO_DECOMPRESS;


    if (tar_close(tar_file) != 0)
        return ERROR_COULD_NOT_CLOSE_FILE;

    return 0;
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

int htlp_decompress_gzopen(char *pathname, int oflags, int mode) {
    char *gzoflags;
    gzFile gzf;
    int fd;

    switch (oflags & O_ACCMODE) {
        case O_WRONLY:
            gzoflags = "wb";
            break;
        case O_RDONLY:
            gzoflags = "rb";
            break;
        default:
        case O_RDWR:
            errno = EINVAL;
            return -1;
    }

    fd = open(pathname, oflags, mode);
    if (fd == -1)
        return -1;

    if ((oflags & O_CREAT) && fchmod(fd, mode))
        return -1;

    gzf = gzdopen(fd, gzoflags);
    if (!gzf) {
        errno = ENOMEM;
        return -1;
    }

    return (int) gzf;
}