/// \file SoloistConfiguration.h
/// \brief Contains the function to configure the Soloist.
///
/// Copyright (c) Aerotech, Inc. 2013-2013.
///

#ifndef __Soloist_CONFIGURATION_H__
#define __Soloist_CONFIGURATION_H__

#include "SoloistCommonTypes.h"
#include "SoloistCommonStructures.h"

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup configuration Configuration Functions
/// @{

/// \brief The handle to the Soloist configuration.
typedef void* SoloistConfigurationHandle;

/// \brief Represents a profile entry in the map file.
typedef struct {
	char controllerName[32]; ///< The controller name.
	COMMUNICATIONTYPE communicationType; ///< The communication type.
	DWORD spare[16]; ///< Reserved for future expansion
} SoloistProfileEntry;

/// \brief Opens the current configuration.
///
/// This function opens the current configuration file and stores it in memory.  The object can then be 
/// used to configure different Soloist settings.
/// \param[out] handle A pointer to a handle for the Soloist Configuration object.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistConfigurationOpen(SoloistConfigurationHandle* handle);

/// \brief Saves the configuration.
///
/// \param[in] handle A pointer to the Soloist Configuration object to save.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistConfigurationSave(SoloistConfigurationHandle handle);

/// \brief Closes a configuration, releasing any memory.
///
/// This function closes and cleans up the Soloist Configuration object.  To save the configuration, call
/// SoloistConfigurationSave().
/// \param[in] handle A pointer to the Soloist Configuration object to close.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistConfigurationClose(SoloistConfigurationHandle handle);

/// \brief Gets the count of entries in the network setup.
///
/// \param[in] handle A pointer to the Soloist Configuration object to use.
/// \param[out] count The number of entries in the network setup.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistConfigurationNetworkSetupGetCount(SoloistConfigurationHandle handle, DWORD* count);

/// \brief Sets an entry in the network setup.
///
/// \param[in] handle A pointer to the Soloist Configuration object to use.
/// \param[in] index The index of the entry to set.
/// \param[in] entry The information to set.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistConfigurationNetworkSetupSet(SoloistConfigurationHandle handle, DWORD index, SoloistProfileEntry entry);

/// \brief Gets an entry in the network setup.
///
/// \param[in] handle A pointer to the Soloist Configuration object to use.
/// \param[in] index The index of the entry to get.
/// \param[out] entry The entry information.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistConfigurationNetworkSetupGet(SoloistConfigurationHandle handle, DWORD index, SoloistProfileEntry* entry);

/// \brief Adds an entry to the network setup.
///
/// \param[in] handle A pointer to the Soloist Configuration object to use.
/// \param[in] entry The entry information.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistConfigurationNetworkSetupAdd(SoloistConfigurationHandle handle, SoloistProfileEntry entry);

/// \brief Removes an entry from the network setup.
///
/// \param[in] handle A pointer to the Soloist Configuration object to use.
/// \param[in] index The index of the entry to remove.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistConfigurationNetworkSetupRemove(SoloistConfigurationHandle handle, DWORD index);

/// @}

#ifdef __cplusplus
}
#endif

#endif
