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
#include <map>
#include <bzlib.h>

class HTLP {
private:
    char * option;
    char * name_package;
    
public:
    HTLP(char ** args);
    int validateOption();
    void showVersion();
    bool installPackage(char * package);    
    bool updatePackage(char * package);
    bool localInstallPackage(char * filename);
    bool upgradeAllPackages();
    std::map<int,char*> searchPackage(char * package);
};



#endif	/* HTLP_HPP */

