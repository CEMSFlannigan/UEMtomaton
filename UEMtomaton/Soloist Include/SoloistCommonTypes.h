/// \file SoloistCommonTypes.h
/// \brief Contains some common types that are used throughout the library.
/// 
/// Copyright (c) Aerotech, Inc. 2010-2013.
/// 

#ifndef __Soloist_COMMONTYPES_H__
#define __Soloist_COMMONTYPES_H__

#include <wtypes.h>
#include "SoloistCommonStructures.h"

/// \brief The handle to the Soloist.
///
/// This is used to communicate with an Soloist.  You can
/// get one by calling SoloistConnect().
typedef void* SoloistHandle;

/// \brief The handle to the Soloist Data Collection Configuration.
///
/// This is used to hold the Soloist Data Collection Configuration.
/// See SoloistDataCollectionConfigCreate() for initalization details.
typedef void* SoloistDataCollectConfigHandle;

/// \brief All available tasks to run commands or programs on.
///
typedef enum
{
	TASKID_Library = 0,
	TASKID_01 = 1,
	TASKID_02 = 2,
	TASKID_03 = 3,
	TASKID_04 = 4,
	TASKID_Auxiliary = 5,
} TASKID;

/// \brief Define for specifying that the function is to be exported.
///
/// This is necessary to mark functions as exported from this library 
/// and allow other libraries and applications to call them.
///
/// Most users can safely ignore this.
#ifdef __Soloist_C_LIBRARY_INTERNAL__
#define DLLENTRYDECLARATION       /*__declspec(dllexport)*/ __stdcall
#else
#define DLLENTRYDECLARATION       __declspec(dllimport) __stdcall
#endif

/// \brief Define for marking functions as obsolete or deprecated.
#if defined(__GCCXML__) || defined(__GNUC__)
	#define DEPRECATED(reason) __declspec(deprecated)
#elif _MSC_VER >= 1400
	#define DEPRECATED(reason) __declspec(deprecated(reason))
#elif _MSC_VER >= 1300
	#define DEPRECATED(reason) __declspec(deprecated)
#else
	#define DEPRECATED(reason) 
#endif

#endif // __SOLOIST_COMMONTYPES_H__
