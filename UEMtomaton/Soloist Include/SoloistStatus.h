/// \file SoloistStatus.h
/// \brief Contains the functions to obtain Soloist status information.
/// 
/// Copyright (c) Aerotech, Inc. 2010-2013.
/// 

#ifndef __Soloist_STATUS_H__
#define __Soloist_STATUS_H__

#include "SoloistCommonTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup status Status Commands
/// @{

/// \brief Retrieves multiple status items from the Soloist.
///
/// This function will retrieve an array of status items. Provide
/// an array of item codes to collect for the given axis.
///
/// The following example shows how to get multiple status values at once:
/// \dontinclude "Examples.chh"
/// \skip StatusItemsExample
/// \until }
/// \until }
///
/// \param[in] handle The handle to the Soloist
/// \param[in] numberOfItems The number of items to retrieve.  The size
/// of the array arguments must be greater than or equal to this number.
/// \param[in] itemCodeArray An array of the item codes to retrieve.
/// \param[out] itemValuesArray An array to contain the data retrieved.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistStatusGetItems(SoloistHandle handle, DWORD numberOfItems, STATUSITEM* itemCodeArray, DOUBLE* itemValuesArray);

/// \brief Retrieves a single status item from the Soloist.
///
/// This function will retrieve the specified status item. Provide
/// the item code to collect.
///
/// \param[in] handle The handle to the Soloist
/// \param[in] itemCode The item code to retrieve.
/// \param[out] itemValue A pointer to a double to contain the retrieved value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistStatusGetItem(SoloistHandle handle, STATUSITEM itemCode, DOUBLE* itemValue);

/// @}

#ifdef __cplusplus
}
#endif

#endif // __Soloist_STATUS_H__
