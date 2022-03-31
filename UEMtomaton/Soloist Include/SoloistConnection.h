/// \file SoloistConnection.h
/// \brief Contains the functions to establish connections to Soloists.
/// 
/// Copyright (c) Aerotech, Inc. 2010-2013.
/// 

#ifndef __Soloist_CONNECTION_H__
#define __Soloist_CONNECTION_H__

#include "SoloistCommonTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup connection Connection Functions
/// @{

/// \brief Connects to all Soloists.
///
/// This function will connect to all the mapped Soloists that are
/// available on the Network.
///
/// \param[out] handles The array of handles to the Soloists
/// \param[out] handleCount The number of handles returned
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistConnect(SoloistHandle** handles, DWORD* handleCount);

/// \brief Disconnects from all the Soloists.
///
/// This function disconnects from all the Soloists and frees resources allocated for the different 
/// handles. The handle used must be the same handle that was returned from SoloistConnect.
///
/// \param[in] handles The handles to the Soloist
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistDisconnect(SoloistHandle* handles);

/// \brief Resets the Soloist.
///
/// This resets the Soloist system.
///
/// \param[in] handle The handle to the Soloist
/// \param[in] restartPrograms Set to TRUE to run program automation after reset.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistReset(SoloistHandle handle, BOOL restartPrograms);

/// @}

#ifdef __cplusplus
}
#endif

#endif
