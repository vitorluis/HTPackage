/* 
 * File:   htlp_install.hpp
 * Author: vitor
 *
 * Created on June 15, 2013, 10:29 PM
 */

#ifndef HTLP_INSTALL_HPP
#define	HTLP_INSTALL_HPP

class HTLP_Install {
private:
    char * package;
public:
    bool resolvDependencies();
    bool downloadPackages();
    bool installPackages();
};


#endif	/* HTLP_INSTALL_HPP */

