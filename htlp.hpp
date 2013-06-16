/* 
 * File:   htlp.hpp
 * Author: vitor
 *
 * Created on June 15, 2013, 9:06 PM
 */

#ifndef HTLP_HPP
#define	HTLP_HPP
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <sstream>
#include <bzlib.h>

class HTPL {
private:
    char * option;
    char * name_package;
    
public:
    HTPL(char * option);
    int validateOption();
    
    
};



#endif	/* HTLP_HPP */

