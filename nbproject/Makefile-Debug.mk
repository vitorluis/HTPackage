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
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=`pkg-config --libs libcurl` -ltar  

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/htpackage

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/htpackage: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/htpackage ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/htlp.o: htlp.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags libcurl`   -MMD -MP -MF $@.d -o ${OBJECTDIR}/htlp.o htlp.c

${OBJECTDIR}/htlp_database.o: htlp_database.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags libcurl`   -MMD -MP -MF $@.d -o ${OBJECTDIR}/htlp_database.o htlp_database.c

${OBJECTDIR}/htlp_decompress.o: htlp_decompress.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -g `pkg-config --cflags libcurl`   -MMD -MP -MF $@.d -o ${OBJECTDIR}/htlp_decompress.o htlp_decompress.c

${OBJECTDIR}/htlp_download.o: htlp_download.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags libcurl`   -MMD -MP -MF $@.d -o ${OBJECTDIR}/htlp_download.o htlp_download.c

${OBJECTDIR}/htlp_install.o: htlp_install.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags libcurl`   -MMD -MP -MF $@.d -o ${OBJECTDIR}/htlp_install.o htlp_install.c

${OBJECTDIR}/htlp_localinstall.o: htlp_localinstall.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.c) -g `pkg-config --cflags libcurl`   -MMD -MP -MF $@.d -o ${OBJECTDIR}/htlp_localinstall.o htlp_localinstall.c

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} $@.d
	$(COMPILE.cc) -g `pkg-config --cflags libcurl`   -MMD -MP -MF $@.d -o ${OBJECTDIR}/main.o main.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/htpackage

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
