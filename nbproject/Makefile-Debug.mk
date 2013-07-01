#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=gcc
CXX=gcc
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux-x86
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/htlp.o \
	${OBJECTDIR}/htlp_database.o \
	${OBJECTDIR}/htlp_decompress.o \
	${OBJECTDIR}/htlp_download.o \
	${OBJECTDIR}/htlp_install.o \
	${OBJECTDIR}/htlp_localinstall.o \
	${OBJECTDIR}/htlp_parse_conf.o \
	${OBJECTDIR}/main.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

# C Compiler Flags
CFLAGS=-Wall

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-ltar -lcurl -lconfig -lz -lpthread

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/htpackage

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/htpackage: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/htpackage ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/htlp.o: htlp.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/htlp.o htlp.c

${OBJECTDIR}/htlp_database.o: htlp_database.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/htlp_database.o htlp_database.c

${OBJECTDIR}/htlp_decompress.o: htlp_decompress.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -g -Wall -MMD -MP -MF $@.d -o ${OBJECTDIR}/htlp_decompress.o htlp_decompress.c

${OBJECTDIR}/htlp_download.o: htlp_download.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/htlp_download.o htlp_download.c

${OBJECTDIR}/htlp_install.o: htlp_install.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/htlp_install.o htlp_install.c

${OBJECTDIR}/htlp_localinstall.o: htlp_localinstall.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -g -Wall -MMD -MP -MF $@.d -o ${OBJECTDIR}/htlp_localinstall.o htlp_localinstall.c

${OBJECTDIR}/htlp_parse_conf.o: htlp_parse_conf.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -g -Wall -MMD -MP -MF $@.d -o ${OBJECTDIR}/htlp_parse_conf.o htlp_parse_conf.c

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.c

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/parse_conf.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/tests/parse_conf.o: tests/parse_conf.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} $@.d
	$(COMPILE.c) -g -I. -I. -Wall -MMD -MP -MF $@.d -o ${TESTDIR}/tests/parse_conf.o tests/parse_conf.c


${OBJECTDIR}/htlp_nomain.o: ${OBJECTDIR}/htlp.o htlp.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/htlp.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/htlp_nomain.o htlp.c;\
	else  \
	    ${CP} ${OBJECTDIR}/htlp.o ${OBJECTDIR}/htlp_nomain.o;\
	fi

${OBJECTDIR}/htlp_database_nomain.o: ${OBJECTDIR}/htlp_database.o htlp_database.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/htlp_database.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/htlp_database_nomain.o htlp_database.c;\
	else  \
	    ${CP} ${OBJECTDIR}/htlp_database.o ${OBJECTDIR}/htlp_database_nomain.o;\
	fi

${OBJECTDIR}/htlp_decompress_nomain.o: ${OBJECTDIR}/htlp_decompress.o htlp_decompress.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/htlp_decompress.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -g -Wall -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/htlp_decompress_nomain.o htlp_decompress.c;\
	else  \
	    ${CP} ${OBJECTDIR}/htlp_decompress.o ${OBJECTDIR}/htlp_decompress_nomain.o;\
	fi

${OBJECTDIR}/htlp_download_nomain.o: ${OBJECTDIR}/htlp_download.o htlp_download.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/htlp_download.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/htlp_download_nomain.o htlp_download.c;\
	else  \
	    ${CP} ${OBJECTDIR}/htlp_download.o ${OBJECTDIR}/htlp_download_nomain.o;\
	fi

${OBJECTDIR}/htlp_install_nomain.o: ${OBJECTDIR}/htlp_install.o htlp_install.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/htlp_install.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/htlp_install_nomain.o htlp_install.c;\
	else  \
	    ${CP} ${OBJECTDIR}/htlp_install.o ${OBJECTDIR}/htlp_install_nomain.o;\
	fi

${OBJECTDIR}/htlp_localinstall_nomain.o: ${OBJECTDIR}/htlp_localinstall.o htlp_localinstall.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/htlp_localinstall.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -g -Wall -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/htlp_localinstall_nomain.o htlp_localinstall.c;\
	else  \
	    ${CP} ${OBJECTDIR}/htlp_localinstall.o ${OBJECTDIR}/htlp_localinstall_nomain.o;\
	fi

${OBJECTDIR}/htlp_parse_conf_nomain.o: ${OBJECTDIR}/htlp_parse_conf.o htlp_parse_conf.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/htlp_parse_conf.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.c) -g -Wall -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/htlp_parse_conf_nomain.o htlp_parse_conf.c;\
	else  \
	    ${CP} ${OBJECTDIR}/htlp_parse_conf.o ${OBJECTDIR}/htlp_parse_conf_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -g -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/main_nomain.o main.c;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/htpackage

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
