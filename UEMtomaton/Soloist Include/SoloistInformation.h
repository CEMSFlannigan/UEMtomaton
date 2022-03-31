/// \file SoloistInformation.h
/// \brief Contains the functions to get information about Soloists.
/// 
/// Copyright (c) Aerotech, Inc. 2010-2013.
/// 

#ifndef __Soloist_INFORMATION_H__
#define __Soloist_INFORMATION_H__

#include "SoloistCommonTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup information Controller Information Functions
/// @{

/// The Version structure is used to hold information about the version of a particular component
typedef struct tagVersion {
	DWORD major; ///< The major version number
	DWORD minor; ///< The minor version number
	DWORD patch; ///< The patch number
	DWORD build; ///< The build number
	DWORD spare[4]; ///< Reserved for future expansion
} Version;

/// \brief Gets the name of a controller.
///
/// \param[in] handle The handle to the Soloist
/// \param[in] size The size of the buffer for the name
/// \param[out] name The buffer for the name
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistInformationGetName(SoloistHandle handle, ULONG size, LPSTR name);

/// \brief Gets the communication type of a controller.
///
/// \param[in] handle The handle to the Soloist
/// \param[out] communicationType The communication type of the controller
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistInformationGetCommunicationType(SoloistHandle handle, COMMUNICATIONTYPE* communicationType);

/// \brief Retrieves the version information of the C library.
///
/// \param[out] pVersion A pointer to a Version struct to be populated with the version information of the C library.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistInformationGetLibraryVersion(Version* pVersion);

/// @}

#ifdef __cplusplus
}
#endif

#endif
