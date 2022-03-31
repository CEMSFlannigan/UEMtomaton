/// \file Soloist.h
/// \brief Contains the includes of all the other files that allow access to the Soloist C Library.
///
/// Include this file to get all the functionality of the C library.
/// 
/// Copyright (c) Aerotech, Inc. 2010-2013.
/// 

/// \mainpage Soloist C Library
/// \brief This is documentation for the Soloist C Library.
///
/// The following is an example of enabling an axis:
/// \dontinclude "Examples.chh"
/// \skip GlobalSimpleExample
/// \until }
/// \until }
///
/// Example programs can be found in <b>[InstallDir]\\Samples\\Cpp\\CLibrary\\</b> and <b>[InstallDir]\\Samples\\C\\CLibrary\\</b>.
///
/// The C Library files can be found in <b>[InstallDir]\\CLibrary</b>.\n
/// 1) <b>include</b> directory contains the header files.\n
/// 2) <b>lib</b> and <b>lib64</b> directories contain the 32-bit and 64-bit lib files.\n
/// 3) <b>bin</b> and <b>bin64</b> directories contain the 32-bit and 64-bit dll files.
///
/// All of the files found in <b>bin</b> and <b>bin64</b> are required for proper operation.  Do one of the following for the 
/// application to load correctly:\n
/// 1) Add <b>[InstallDir]\\CLibrary\\bin\\</b> and <b>[InstallDir]\\CLibrary\\bin64\\</b> to the PATH.\n
/// 2) Copy all the the *.dll files from <b>[InstallDir]\\CLibrary\\bin\\</b> and <b>[InstallDir]\\CLibrary\\bin64\\</b> into the output directory.\n

#ifndef __Soloist_H__
#define __Soloist_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "SoloistCommonTypes.h"
#include "SoloistCommonStructures.h"
#include "SoloistAeroBasicCommands.h"
#include "SoloistErrorCodes.h"
#include "SoloistConnection.h"
#include "SoloistCommands.h"
#include "SoloistError.h"
#include "SoloistParameter.h"
#include "SoloistParameterId.h"
#include "SoloistProgram.h"
#include "SoloistStatus.h"
#include "SoloistVariable.h"
#include "SoloistInformation.h"
#include "SoloistEnumNames.h"
#include "SoloistDataCollection.h"
#include "SoloistConfiguration.h"

#ifdef __cplusplus
}
#endif

#endif // __Soloist_H__
