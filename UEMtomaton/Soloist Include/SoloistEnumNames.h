/// @file SoloistEnumNames.h
/// \brief Contains functions to retrieve the names of various enumeration values.
/// 
/// Copyright (c) Aerotech, Inc. 2010-2013.
/// 

#ifndef __Soloist_ENUM_NAMES__
#define __Soloist_ENUM_NAMES__

#include "SoloistCommonTypes.h"
#include "SoloistCommonStructures.h"
/// @defgroup enumname Enumeration Name Functions

#ifdef __cplusplus
extern "C" {
#endif
/// \brief Retrieves the name of a SERVORATEPARAMETER value.
///
/// @ingroup enumname
///
/// @param[in] value The SERVORATEPARAMETER enumeration value for which to retrieve the string name.
/// @param[in] valueNameBuffer The output buffer that will contain the string name of the enumeration value.
/// @param[in] valueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumServoRateParameterGetValueName(SERVORATEPARAMETER value, LPSTR valueNameBuffer, DWORD valueNameBufferSize);

/// \brief Retrieves the name of a TASKSTATE value.
///
/// @ingroup enumname
///
/// @param[in] value The TASKSTATE enumeration value for which to retrieve the string name.
/// @param[in] valueNameBuffer The output buffer that will contain the string name of the enumeration value.
/// @param[in] valueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumTaskStateGetValueName(TASKSTATE value, LPSTR valueNameBuffer, DWORD valueNameBufferSize);

/// \brief Retrieves the name of a DEBUGFLAGS bit value.
///
/// @ingroup enumname
///
/// @param[in] bitValue The DEBUGFLAGS enumeration bit value for which to retrieve the string name. Note that this bit value must contain only one bit that is high.
/// @param[in] bitValueNameBuffer The output buffer that will contain the string name of the enumeration bit value.
/// @param[in] bitValueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration bit value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumDebugFlagsGetBitName(DEBUGFLAGS bitValue, LPSTR bitValueNameBuffer, DWORD bitValueNameBufferSize);

/// \brief Retrieves the name of a AXISSTATUS bit value.
///
/// @ingroup enumname
///
/// @param[in] bitValue The AXISSTATUS enumeration bit value for which to retrieve the string name. Note that this bit value must contain only one bit that is high.
/// @param[in] bitValueNameBuffer The output buffer that will contain the string name of the enumeration bit value.
/// @param[in] bitValueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration bit value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumAxisStatusGetBitName(AXISSTATUS bitValue, LPSTR bitValueNameBuffer, DWORD bitValueNameBufferSize);

/// \brief Retrieves the name of a AXISFAULT bit value.
///
/// @ingroup enumname
///
/// @param[in] bitValue The AXISFAULT enumeration bit value for which to retrieve the string name. Note that this bit value must contain only one bit that is high.
/// @param[in] bitValueNameBuffer The output buffer that will contain the string name of the enumeration bit value.
/// @param[in] bitValueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration bit value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumAxisFaultGetBitName(AXISFAULT bitValue, LPSTR bitValueNameBuffer, DWORD bitValueNameBufferSize);

/// \brief Retrieves the name of a DATACOLLECTIONFLAGS bit value.
///
/// @ingroup enumname
///
/// @param[in] bitValue The DATACOLLECTIONFLAGS enumeration bit value for which to retrieve the string name. Note that this bit value must contain only one bit that is high.
/// @param[in] bitValueNameBuffer The output buffer that will contain the string name of the enumeration bit value.
/// @param[in] bitValueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration bit value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumDataCollectionFlagsGetBitName(DATACOLLECTIONFLAGS bitValue, LPSTR bitValueNameBuffer, DWORD bitValueNameBufferSize);

/// \brief Retrieves the name of a STATUSITEM value.
///
/// @ingroup enumname
///
/// @param[in] value The STATUSITEM enumeration value for which to retrieve the string name.
/// @param[in] valueNameBuffer The output buffer that will contain the string name of the enumeration value.
/// @param[in] valueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumStatusItemGetValueName(STATUSITEM value, LPSTR valueNameBuffer, DWORD valueNameBufferSize);

/// \brief Retrieves the name of a LOOPTRANSMISSIONMODE value.
///
/// @ingroup enumname
///
/// @param[in] value The LOOPTRANSMISSIONMODE enumeration value for which to retrieve the string name.
/// @param[in] valueNameBuffer The output buffer that will contain the string name of the enumeration value.
/// @param[in] valueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumLoopTransmissionModeGetValueName(LOOPTRANSMISSIONMODE value, LPSTR valueNameBuffer, DWORD valueNameBufferSize);

/// \brief Retrieves the name of a LOOPTRANSMISSIONTYPE value.
///
/// @ingroup enumname
///
/// @param[in] value The LOOPTRANSMISSIONTYPE enumeration value for which to retrieve the string name.
/// @param[in] valueNameBuffer The output buffer that will contain the string name of the enumeration value.
/// @param[in] valueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumLoopTransmissionTypeGetValueName(LOOPTRANSMISSIONTYPE value, LPSTR valueNameBuffer, DWORD valueNameBufferSize);

/// \brief Retrieves the name of a ONOFF value.
///
/// @ingroup enumname
///
/// @param[in] value The ONOFF enumeration value for which to retrieve the string name.
/// @param[in] valueNameBuffer The output buffer that will contain the string name of the enumeration value.
/// @param[in] valueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumOnOffGetValueName(ONOFF value, LPSTR valueNameBuffer, DWORD valueNameBufferSize);

/// \brief Retrieves the name of a PSOENCODER value.
///
/// @ingroup enumname
///
/// @param[in] value The PSOENCODER enumeration value for which to retrieve the string name.
/// @param[in] valueNameBuffer The output buffer that will contain the string name of the enumeration value.
/// @param[in] valueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumPsoEncoderGetValueName(PSOENCODER value, LPSTR valueNameBuffer, DWORD valueNameBufferSize);

/// \brief Retrieves the name of a PSOMODE value.
///
/// @ingroup enumname
///
/// @param[in] value The PSOMODE enumeration value for which to retrieve the string name.
/// @param[in] valueNameBuffer The output buffer that will contain the string name of the enumeration value.
/// @param[in] valueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumPsoModeGetValueName(PSOMODE value, LPSTR valueNameBuffer, DWORD valueNameBufferSize);

/// \brief Retrieves the name of a RAMPMODE value.
///
/// @ingroup enumname
///
/// @param[in] value The RAMPMODE enumeration value for which to retrieve the string name.
/// @param[in] valueNameBuffer The output buffer that will contain the string name of the enumeration value.
/// @param[in] valueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumRampModeGetValueName(RAMPMODE value, LPSTR valueNameBuffer, DWORD valueNameBufferSize);

/// \brief Retrieves the name of a ETHERNETSTATUS bit value.
///
/// @ingroup enumname
///
/// @param[in] bitValue The ETHERNETSTATUS enumeration bit value for which to retrieve the string name. Note that this bit value must contain only one bit that is high.
/// @param[in] bitValueNameBuffer The output buffer that will contain the string name of the enumeration bit value.
/// @param[in] bitValueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration bit value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumEthernetStatusGetBitName(ETHERNETSTATUS bitValue, LPSTR bitValueNameBuffer, DWORD bitValueNameBufferSize);

/// \brief Retrieves the name of a SEMAPHORES value.
///
/// @ingroup enumname
///
/// @param[in] value The SEMAPHORES enumeration value for which to retrieve the string name.
/// @param[in] valueNameBuffer The output buffer that will contain the string name of the enumeration value.
/// @param[in] valueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumSemaphoresGetValueName(SEMAPHORES value, LPSTR valueNameBuffer, DWORD valueNameBufferSize);

/// \brief Retrieves the name of a WAITOPTION value.
///
/// @ingroup enumname
///
/// @param[in] value The WAITOPTION enumeration value for which to retrieve the string name.
/// @param[in] valueNameBuffer The output buffer that will contain the string name of the enumeration value.
/// @param[in] valueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumWaitOptionGetValueName(WAITOPTION value, LPSTR valueNameBuffer, DWORD valueNameBufferSize);

/// \brief Retrieves the name of a WAITTYPE value.
///
/// @ingroup enumname
///
/// @param[in] value The WAITTYPE enumeration value for which to retrieve the string name.
/// @param[in] valueNameBuffer The output buffer that will contain the string name of the enumeration value.
/// @param[in] valueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumWaitTypeGetValueName(WAITTYPE value, LPSTR valueNameBuffer, DWORD valueNameBufferSize);

/// \brief Retrieves the name of a MODETYPE value.
///
/// @ingroup enumname
///
/// @param[in] value The MODETYPE enumeration value for which to retrieve the string name.
/// @param[in] valueNameBuffer The output buffer that will contain the string name of the enumeration value.
/// @param[in] valueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumModeTypeGetValueName(MODETYPE value, LPSTR valueNameBuffer, DWORD valueNameBufferSize);

/// \brief Retrieves the name of a COMPILERERRORTYPE value.
///
/// @ingroup enumname
///
/// @param[in] value The COMPILERERRORTYPE enumeration value for which to retrieve the string name.
/// @param[in] valueNameBuffer The output buffer that will contain the string name of the enumeration value.
/// @param[in] valueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumCompilerErrorTypeGetValueName(COMPILERERRORTYPE value, LPSTR valueNameBuffer, DWORD valueNameBufferSize);

/// \brief Retrieves the name of a DAYOFWEEK value.
///
/// @ingroup enumname
///
/// @param[in] value The DAYOFWEEK enumeration value for which to retrieve the string name.
/// @param[in] valueNameBuffer The output buffer that will contain the string name of the enumeration value.
/// @param[in] valueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumDayOfWeekGetValueName(DAYOFWEEK value, LPSTR valueNameBuffer, DWORD valueNameBufferSize);

/// \brief Retrieves the name of a REGISTERTYPE value.
///
/// @ingroup enumname
///
/// @param[in] value The REGISTERTYPE enumeration value for which to retrieve the string name.
/// @param[in] valueNameBuffer The output buffer that will contain the string name of the enumeration value.
/// @param[in] valueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumRegisterTypeGetValueName(REGISTERTYPE value, LPSTR valueNameBuffer, DWORD valueNameBufferSize);

/// \brief Retrieves the name of a COMPONENTTYPE value.
///
/// @ingroup enumname
///
/// @param[in] value The COMPONENTTYPE enumeration value for which to retrieve the string name.
/// @param[in] valueNameBuffer The output buffer that will contain the string name of the enumeration value.
/// @param[in] valueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumComponentTypeGetValueName(COMPONENTTYPE value, LPSTR valueNameBuffer, DWORD valueNameBufferSize);

/// \brief Retrieves the name of a COMMUNICATIONTYPE value.
///
/// @ingroup enumname
///
/// @param[in] value The COMMUNICATIONTYPE enumeration value for which to retrieve the string name.
/// @param[in] valueNameBuffer The output buffer that will contain the string name of the enumeration value.
/// @param[in] valueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumCommunicationTypeGetValueName(COMMUNICATIONTYPE value, LPSTR valueNameBuffer, DWORD valueNameBufferSize);

/// \brief Retrieves the name of a BUILDRESULTKIND value.
///
/// @ingroup enumname
///
/// @param[in] value The BUILDRESULTKIND enumeration value for which to retrieve the string name.
/// @param[in] valueNameBuffer The output buffer that will contain the string name of the enumeration value.
/// @param[in] valueNameBufferSize The size, in bytes, of the output buffer that will contain the string name of the enumeration value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistEnumBuildResultKindGetValueName(BUILDRESULTKIND value, LPSTR valueNameBuffer, DWORD valueNameBufferSize);

#ifdef __cplusplus
}
#endif
#endif // __Soloist_ENUM_NAMES__

