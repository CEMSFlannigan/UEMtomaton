/// \file SoloistParameter.h
/// \brief Contains the functions to retrieve and send parameters from or to the drive.
/// 
/// Copyright (c) Aerotech, Inc. 2010-2013.
/// 

#ifndef __Soloist_PARAMETER_H__
#define __Soloist_PARAMETER_H__

#include "SoloistCommonTypes.h"
#include "SoloistParameterId.h"

#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup parameter Parameter Functions
/// @{

/// \brief Retrieves the value of a double parameter from the drive.
///
/// This function will retrieve the value of one of the double type parameters to a double variable. 
///
/// \param[in] handle The handle to the Soloist
/// \param[in] parameterID The ID number of the parameter.
/// \param[in] index The index of the task. To be ignored for axis and system parameters.
/// \param[out] value The retrieved double value of the parameter.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistParameterGetValue(SoloistHandle handle, PARAMETERID parameterID, DWORD index, DOUBLE* value);

/// \brief Retrieves the value of a string parameter from the drive.
///
/// This function will retrieve the value of one of the string type parameters to a string variable. 
///
/// Retrieve a string value of a parameter from the drive
///
/// \param[in] handle The handle to the Soloist
/// \param[in] parameterID The ID number of the parameter.
/// \param[in] index The index of the task. To be ignored for axis and system parameters.
/// \param[in] size The number of characters to be retrieved
/// \param[out] value The retrieved string value of the parameter.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistParameterGetValueString(SoloistHandle handle, PARAMETERID parameterID, DWORD index, ULONG size, LPSTR value);

/// \brief Sends the value of a double parameter to the drive.
///
/// This function will send the value of one of the double type parameters to the drive. 
///
/// \param[in] handle The handle to the Soloist
/// \param[in] parameterID The ID number of the parameter.
/// \param[in] index The index of the task. To be ignored for axis and system parameters.
/// \param[in] value The double value of the parameter to be sent.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistParameterSetValue(SoloistHandle handle, PARAMETERID parameterID, DWORD index, DOUBLE value);

/// \brief Sends the value of a string parameter to the drive.
///
/// This function will send the value of one of the string type parameters to the drive. 
///
/// \param[in] handle The handle to the Soloist
/// \param[in] parameterID The ID number of the parameter.
/// \param[in] index The index of the task. To be ignored for axis and system parameters.
/// \param[in] value The string value of the parameter to be sent.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistParameterSetValueString(SoloistHandle handle, PARAMETERID parameterID, DWORD index, LPCSTR value);

/// \brief Commits parameters on the controller.
///
/// This function will commit the active parameters on the controller.
///
/// \param[in] handle The handle to the Soloist
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistParameterCommit(SoloistHandle handle);

/// @}

#ifdef __cplusplus
}
#endif

#endif // __Soloist_PARAMETER_H__
