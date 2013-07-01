/*
 * File:   parse_conf.c
 * Author: vitor
 *
 * Created on Jun 30, 2013, 10:02:34 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "../htlp.h"
#include "../htlp_defines.h"
#include "../htlp_structs.h"
#include "../htlp_typedefs.h"
#include "../htlp_parse_conf.h"

/*
 * Simple C Test Suite
 */

void test1() {
    printf("parse_conf test 1\n");
}

void test2() {
    printf("parse_conf test 2\n");
    printf("%%TEST_FAILED%% time=0 testname=test2 (parse_conf) message=error message sample\n");
}

int main(int argc, char** argv) {
    printf("%%SUITE_STARTING%% parse_conf\n");
    printf("%%SUITE_STARTED%%\n");

    printf("%%TEST_STARTED%% test1 (parse_conf)\n");
    test1();
    printf("%%TEST_FINISHED%% time=0 test1 (parse_conf) \n");

    printf("%%TEST_STARTED%% test2 (parse_conf)\n");
    test2();
    printf("%%TEST_FINISHED%% time=0 test2 (parse_conf) \n");

    printf("%%SUITE_FINISHED%% time=0\n");

    return (EXIT_SUCCESS);
}
