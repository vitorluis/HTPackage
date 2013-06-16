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
    std::string option;
    std::string name_package;
    
public:
    HTPL(std::string option);
    int validateOption();
    
    
};



#endif	/* HTLP_HPP */

