/// \file SoloistAeroBasicCommands.h
/// \brief Contains immediate commands
/// 
/// Copyright (c) Aerotech, Inc. 2010-2013.
/// 

#ifndef __Soloist_AEROBASIC_COMMANDS_H__
#define __Soloist_AEROBASIC_COMMANDS_H__

#include "SoloistCommonTypes.h"
#include "SoloistCommonStructures.h"
#ifdef __cplusplus
extern "C" {
#endif

/// \defgroup root Generic Commands

/// \defgroup motion Motion Commands

/// \defgroup motsetup Motion Setup Commands

/// \brief Specifies the SCurve value to use.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/SCURVE_Command.html">SCURVE</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motsetup
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Value The value by which to SCurve.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionSetupScurve
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionSetupScurve(SoloistHandle handle, DOUBLE Value);

/// \brief Sets motion commands to be in absolute mode.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/ABS_Command.html">ABS</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motsetup
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionSetupAbsolute
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionSetupAbsolute(SoloistHandle handle);

/// \brief Sets motion commands to be in incremental mode.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/INC_Command.html">INC</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motsetup
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionSetupIncremental
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionSetupIncremental(SoloistHandle handle);

/// \brief Specifies the ramp mode calculation type to use.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/RAMP MODE_Command.html">RAMP MODE</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motsetup
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Mode The ramp mode to use.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionSetupRampMode
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionSetupRampMode(SoloistHandle handle, RAMPMODE Mode);

/// \brief Specifies distance-based acceleration and deceleration.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/RAMP DIST_Command.html">RAMP DIST</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motsetup
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Value The acceleration and deceleration distance.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionSetupRampDistAccel
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionSetupRampDistAccel(SoloistHandle handle, DOUBLE Value);

/// \brief Specifies distance-based acceleration and deceleration.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/RAMP DIST_Command.html">RAMP DIST</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motsetup
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Value The acceleration and deceleration distance.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionSetupRampDistDecel
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionSetupRampDistDecel(SoloistHandle handle, DOUBLE Value);

/// \brief Specifies rate-based acceleration and deceleration.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/RAMP RATE_Command.html">RAMP RATE</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motsetup
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Value The acceleration and deceleration rate.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionSetupRampRateAccel
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionSetupRampRateAccel(SoloistHandle handle, DOUBLE Value);

/// \brief Specifies rate-based acceleration and deceleration.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/RAMP RATE_Command.html">RAMP RATE</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motsetup
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Value The acceleration and deceleration rate.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionSetupRampRateDecel
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionSetupRampRateDecel(SoloistHandle handle, DOUBLE Value);

/// \brief Specifies time-based acceleration and deceleration.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/RAMP TIME_Command.html">RAMP TIME</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motsetup
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Value The acceleration and deceleration time.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionSetupRampTimeAccel
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionSetupRampTimeAccel(SoloistHandle handle, DOUBLE Value);

/// \brief Specifies time-based acceleration and deceleration.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/RAMP TIME_Command.html">RAMP TIME</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motsetup
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Value The acceleration and deceleration time.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionSetupRampTimeDecel
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionSetupRampTimeDecel(SoloistHandle handle, DOUBLE Value);

/// \brief Sets an arbitrary position value, in encoder counts, in external position register.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/SETEXTPOS_Command.html">SETEXTPOS</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motsetup
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Value The value to set in external position register.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionSetupSetExtPos
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionSetupSetExtPos(SoloistHandle handle, DOUBLE Value);

/// \brief Sets or clears an arbitrary program offset position.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/POSOFFSET_Command.html">POSOFFSET</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motsetup
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Value The value at which to set the parameter.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionSetupPosOffsetSet
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionSetupPosOffsetSet(SoloistHandle handle, DOUBLE Value);

/// \brief Sets or clears an arbitrary program offset position.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/POSOFFSET_Command.html">POSOFFSET</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motsetup
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionSetupPosOffsetClear
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionSetupPosOffsetClear(SoloistHandle handle);

/// \brief Configures the position data capture.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/POSCAP_Function.html">POSCAP</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motsetup
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[out] returnValue The captured position.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionSetupPosCapStatus
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionSetupPosCapStatus(SoloistHandle handle, DOUBLE* returnValue);

/// \brief Configures the position data capture.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/POSCAP_Function.html">POSCAP</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motsetup
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] SourceNumber The source of the position data to be captured.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionSetupPosCapSetSource
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionSetupPosCapSetSource(SoloistHandle handle, DWORD SourceNumber);

/// \brief Configures the position data capture.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/POSCAP_Function.html">POSCAP</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motsetup
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] TriggerNumber The user interrupt signal to use as the trigger for the position capture hardware.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionSetupPosCapSetTrigger
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionSetupPosCapSetTrigger(SoloistHandle handle, DWORD TriggerNumber);

/// \brief Configures the position data capture.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/POSCAP_Function.html">POSCAP</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motsetup
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionSetupPosCapSetArm
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionSetupPosCapSetArm(SoloistHandle handle);

/// \brief Specifies the time scale to use.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/TIMESCALE_Command.html">TIMESCALE</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motsetup
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Percentage The percentage timescaling, 1 - 200.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionSetupTimeScale
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionSetupTimeScale(SoloistHandle handle, DOUBLE Percentage);


/// \brief Disables the axis.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/DISABLE_Command.html">DISABLE</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motion
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionDisable
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionDisable(SoloistHandle handle);

/// \brief Enables the axis.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/ENABLE_Command.html">ENABLE</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motion
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionEnable
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionEnable(SoloistHandle handle);

/// \brief Acknowledges and clears the fault on the axis.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/FAULTACK_Command.html">FAULTACK</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motion
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionFaultAck
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionFaultAck(SoloistHandle handle);

/// \brief Freeruns the axis.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/FREERUN_Command.html">FREERUN</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motion
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Speed The speed at which to run the axis.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionFreeRun
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionFreeRun(SoloistHandle handle, DOUBLE Speed);

/// \brief Freeruns the axis.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/FREERUN_Command.html">FREERUN</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motion
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionFreeRunStop
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionFreeRunStop(SoloistHandle handle);

/// \brief Homes the axis.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/HOME_Command.html">HOME</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motion
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionHome
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionHome(SoloistHandle handle);

/// \brief Executes a linear move on the axis.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/LINEAR_Command.html">LINEAR</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motion
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Distance The distance to move the axis.
/// \param[in] Speed The vectorial speed at which to move the axis.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionLinear
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionLinear(SoloistHandle handle, DOUBLE Distance, DOUBLE Speed);

/// \brief Halts the profiled motion queue and prevents motion from starting.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/HALT_Command.html">HALT</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motion
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionHalt
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionHalt(SoloistHandle handle);

/// \brief Starts execution of the profiled motion queue.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/START_Command.html">START</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motion
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionStart
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionStart(SoloistHandle handle);

/// \brief Executes an incremental move on the axis.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/MOVEINC_Command.html">MOVEINC</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motion
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Distance The distance to move the axis, in user units.
/// \param[in] Speed The speed at which to move the axis, in user units.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionMoveInc
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionMoveInc(SoloistHandle handle, DOUBLE Distance, DOUBLE Speed);

/// \brief Executes an absolute move on an axis.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/MOVEABS_Command.html">MOVEABS</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motion
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Distance The location to move the axis to, in user units.
/// \param[in] Speed The speed at which to move the axis, in user units.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionMoveAbs
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionMoveAbs(SoloistHandle handle, DOUBLE Distance, DOUBLE Speed);

/// \brief Sets motion blocking to On or Off.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/BLOCKMOTION_Command.html">BLOCKMOTION</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motion
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] OnOff Sets motion blocking to On or OFF.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionBlockMotion
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionBlockMotion(SoloistHandle handle, ONOFF OnOff);

/// \brief Sets the mode of wait of a task.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/WAIT MODE_Command.html">WAIT MODE</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motion
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Type The wait mode type to set. Possible modes are NOWAIT, MOVEDONE, and INPOS.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionWaitMode
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionWaitMode(SoloistHandle handle, WAITTYPE Type);

/// \brief Sets the autofocus to On or Off.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/AUTOFOCUS_Command.html">AUTOFOCUS</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup motion
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] OnOff Sets the autofocus to On or Off.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistMotionAutoFocus
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistMotionAutoFocus(SoloistHandle handle, ONOFF OnOff);


/// \defgroup reg Register Commands

/// \brief Locks a specified semaphore.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/LOCK_Command.html">LOCK</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup reg
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Semaphore The semaphore to lock.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistRegisterLock
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistRegisterLock(SoloistHandle handle, SEMAPHORES Semaphore);

/// \brief Unlocks a specified semaphore.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/UNLOCK_Command.html">UNLOCK</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup reg
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] RegSet The semaphore to unlock.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistRegisterUnLock
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistRegisterUnLock(SoloistHandle handle, SEMAPHORES RegSet);

/// \brief Provides access to the global integer variable (register) set.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/IGLOBAL_Function.html">IGLOBAL</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup reg
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] RegNumber The variable (register) number in the set.
/// \param[in] Value The value to store.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistRegisterIntegerGlobalWrite
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistRegisterIntegerGlobalWrite(SoloistHandle handle, DWORD RegNumber, DWORD Value);

/// \brief Provides access to the global integer variable (register) set.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/IGLOBAL_Function.html">IGLOBAL</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup reg
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] RegNumber The variable (register) number in the set.
/// \param[out] returnValue The stored value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistRegisterIntegerGlobalRead
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistRegisterIntegerGlobalRead(SoloistHandle handle, DWORD RegNumber, DWORD* returnValue);

/// \brief Provides access to the global double variable (register) set.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/DGLOBAL_Function.html">DGLOBAL</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup reg
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] RegNumber The variable (register) number in the set.
/// \param[in] Value The value to store.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistRegisterDoubleGlobalWrite
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistRegisterDoubleGlobalWrite(SoloistHandle handle, DWORD RegNumber, DOUBLE Value);

/// \brief Provides access to the global double variable (register) set.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/DGLOBAL_Function.html">DGLOBAL</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup reg
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] RegNumber The variable (register) number in the set.
/// \param[out] returnValue The stored value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistRegisterDoubleGlobalRead
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistRegisterDoubleGlobalRead(SoloistHandle handle, DWORD RegNumber, DOUBLE* returnValue);


/// \defgroup io IO Commands

/// \brief Reads the analog input value.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/AIN_Function.html">AIN</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup io
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Channel The analog channel to get the value of.
/// \param[out] returnValue The value of the analog input.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistIOAnalogInput
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistIOAnalogInput(SoloistHandle handle, DWORD Channel, DOUBLE* returnValue);

/// \brief Sets the value of the analog output.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/AOUT_Command.html">AOUT</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup io
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Channel The analog channel to set the value of.
/// \param[in] ChannelCount The number of elements in the Channel array
/// \param[in] Value The value of the analog output.
/// \param[in] ValueCount The number of elements in the Value array
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistIOAnalogOutput
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistIOAnalogOutput(SoloistHandle handle, DWORD* Channel, DWORD ChannelCount, DOUBLE* Value, DWORD ValueCount);

/// \brief Reads the digital input value.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/DIN_Function.html">DIN</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup io
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Port The port from which to read the value.
/// \param[in] Bit The bit to read.
/// \param[out] returnValue The value of the digital input.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistIODigitalInput
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistIODigitalInput(SoloistHandle handle, DWORD Port, DWORD Bit, DWORD* returnValue);

/// \brief Sets the digital output.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/DOUT_Command.html">DOUT</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup io
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Port The port on which to set the value.
/// \param[in] Value The value to set the port to.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistIODigitalOutputEntire
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistIODigitalOutputEntire(SoloistHandle handle, DWORD Port, DWORD Value);

/// \brief Sets the digital output.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/DOUT_Command.html">DOUT</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup io
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Port The port on which to set the value.
/// \param[in] Bits The bits to set.
/// \param[in] BitsCount The number of elements in the Bits array
/// \param[in] Values The values to set the bits to.
/// \param[in] ValuesCount The number of elements in the Values array
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistIODigitalOutputByBits
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistIODigitalOutputByBits(SoloistHandle handle, DWORD Port, DWORD* Bits, DWORD BitsCount, DWORD* Values, DWORD ValuesCount);

/// \brief Controls the brake output of the axis.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/BRAKE_Command.html">BRAKE</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup io
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] OnOff Sets the brake to On or Off.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistIOBrake
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistIOBrake(SoloistHandle handle, ONOFF OnOff);


/// \defgroup status Status Commands

/// \brief Gets the position feedback latched when the marker signal occurred during a home.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PMRKLATCH_Function.html">PMRKLATCH</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup status
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[out] returnValue The latched marker position.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistStatusPositionMarkerLatched
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistStatusPositionMarkerLatched(SoloistHandle handle, DOUBLE* returnValue);

/// \brief Gets the Ethernet status.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/ETHERSTATUS_Function.html">ETHERSTATUS</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup status
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[out] returnValue The status of the Ethernet code.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistStatusEtherStatus
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistStatusEtherStatus(SoloistHandle handle, ETHERNETSTATUS* returnValue);

/// \brief Gets the setting of one of the modal variables.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/GETMODE_Function.html">GETMODE</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup status
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] ModeType The type of information that is requested.
/// \param[out] returnValue The requested value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistStatusGetMode
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistStatusGetMode(SoloistHandle handle, MODETYPE ModeType, DOUBLE* returnValue);


/// \defgroup tuning Tuning Commands

/// \brief Sets all the servo control loop gains.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/SETGAIN_Command.html">SETGAIN</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup tuning
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] GainKp The GainKp value.
/// \param[in] GainKi The GainKi value.
/// \param[in] GainKpos The GainKpos value.
/// \param[in] GainAff The GainAff value.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistTuningSetGain
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistTuningSetGain(SoloistHandle handle, DOUBLE GainKp, DOUBLE GainKi, DOUBLE GainKpos, DOUBLE GainAff);

/// \brief Sends a direct current command to the servo control loop.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/MCOMM_Command.html">MCOMM</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup tuning
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Current The current to output, in amperes.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistTuningMComm
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistTuningMComm(SoloistHandle handle, DOUBLE Current);

/// \brief Generates an open-loop current command.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/MSET_Command.html">MSET</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup tuning
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Current The current to output, in amperes.
/// \param[in] Angle The electrical angle.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistTuningMSet
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistTuningMSet(SoloistHandle handle, DOUBLE Current, DOUBLE Angle);

/// \brief Generates sinusoidal oscillation on an axis.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/OSCILLATE_Command.html">OSCILLATE</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup tuning
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Distance The distance to move the axis.
/// \param[in] Frequency The frequency at which to move the axis.
/// \param[in] Cycles The number of cycles to complete.
/// \param[in] NumFreqs The number of frequencies to execute (multiples of ).
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistTuningOscillate
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistTuningOscillate(SoloistHandle handle, DOUBLE Distance, DOUBLE Frequency, DWORD Cycles, DWORD NumFreqs);

/// \brief Initiates loop transmission mode.

///
/// \ingroup tuning
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Mode Sets the loop transmission mode to On or OFF.
/// \param[in] Amplitude Sets the maximum loop output as a percentage.
/// \param[in] Frequency The frequency of the disturbance generated, in Hertz.
/// \param[in] Type The type of loop transmission to run.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistTuningLoopTrans
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistTuningLoopTrans(SoloistHandle handle, LOOPTRANSMISSIONMODE Mode, DOUBLE Amplitude, DOUBLE Frequency, LOOPTRANSMISSIONTYPE Type);


/// \defgroup dataacq DataAcquisition Commands

/// \brief Enables data collection.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/DATAACQ ON_Command.html">DATAACQ ON</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup dataacq
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] NumberOfSamples The number of samples to be collected. After the specified number of samples are collected, data acquisition turns off automatically. On multi-axis drives, multiple samples can be collected at each trigger event, so this argument must specify the number of data samples to store, not the number of trigger events.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistDataAcquisitionArraySetup
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistDataAcquisitionArraySetup(SoloistHandle handle, DWORD NumberOfSamples);

/// \brief Transfers drive array values into the specified controller array variables.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/DATAACQ READ_Command.html">DATAACQ READ</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup dataacq
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] VariableStart The starting location of IGLOBAL where captured data will be read into.
/// \param[in] NumberOfSamples The number of samples to be read back.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistDataAcquisitionArrayRead
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistDataAcquisitionArrayRead(SoloistHandle handle, DWORD VariableStart, DWORD NumberOfSamples);

/// \brief Specifies the data element collected when a trigger occurs.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/DATAACQ INPUT_Command.html">DATAACQ INPUT</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup dataacq
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] SourceSignal The source signal to be collected.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistDataAcquisitionInput
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistDataAcquisitionInput(SoloistHandle handle, DWORD SourceSignal);

/// \brief Specifies which signal will be monitored to collect data.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/DATAACQ TRIGGER_Command.html">DATAACQ TRIGGER</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup dataacq
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] TriggerSignal The signal to be triggered on.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistDataAcquisitionTrigger
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistDataAcquisitionTrigger(SoloistHandle handle, DWORD TriggerSignal);

/// \brief Turns off data acquisition. All previously specified DATAACQ command configurations are cleared and must be re-specified if required.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/DATAACQ OFF_Command.html">DATAACQ OFF</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup dataacq
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistDataAcquisitionOff
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistDataAcquisitionOff(SoloistHandle handle);


/// \defgroup pso PSO Commands

/// \brief Gets the PSO status information.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOSTATUS_Function.html">PSOSTATUS</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[out] returnValue The PSO status bits.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOStatus
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOStatus(SoloistHandle handle, DWORD* returnValue);

/// \brief Sends array mode distances into the PSO array.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOARRAY_Command.html">PSOARRAY</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] StartIndex The index on which to start.
/// \param[in] NumberOfPoints The number of points to send.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOArrayDistance
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOArrayDistance(SoloistHandle handle, DWORD StartIndex, DWORD NumberOfPoints);

/// \brief Sends array mode distances into the PSO array.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOARRAY_Command.html">PSOARRAY</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] StartIndex The index on which to start.
/// \param[in] NumberOfPoints The number of points to send.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOArrayLaser
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOArrayLaser(SoloistHandle handle, DWORD StartIndex, DWORD NumberOfPoints);

/// \brief Sends array mode distances into the PSO array.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOARRAY_Command.html">PSOARRAY</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] StartIndex The index on which to start.
/// \param[in] NumberOfPoints The number of points to send.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOArrayWindow1
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOArrayWindow1(SoloistHandle handle, DWORD StartIndex, DWORD NumberOfPoints);

/// \brief Sends array mode distances into the PSO array.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOARRAY_Command.html">PSOARRAY</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] StartIndex The index on which to start.
/// \param[in] NumberOfPoints The number of points to send.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOArrayWindow2
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOArrayWindow2(SoloistHandle handle, DWORD StartIndex, DWORD NumberOfPoints);

/// \brief Enables and disables the PSO hardware.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOCONTROL_Command.html">PSOCONTROL</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Mode The mode of operation of the PSO hardware.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOControl
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOControl(SoloistHandle handle, PSOMODE Mode);

/// \brief Sets the distance to travel between firing events.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSODISTANCE_Command.html">PSODISTANCE</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSODistanceArray
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSODistanceArray(SoloistHandle handle);

/// \brief Sets the distance to travel between firing events.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSODISTANCE_Command.html">PSODISTANCE</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] FireDistance The distance an axis must travel before a firing event triggers the pulse generator.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSODistanceFixed
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSODistanceFixed(SoloistHandle handle, DOUBLE FireDistance);

/// \brief Sets the PSO output mode.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOOUTPUT PULSE_Command.html">PSOOUTPUT PULSE</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOOutputPulse
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOOutputPulse(SoloistHandle handle);

/// \brief Sets the PSO output mode.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOOUTPUT PULSE BIT MASK_Command.html">PSOOUTPUT PULSE BIT MASK</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOOutputPulseBitMask
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOOutputPulseBitMask(SoloistHandle handle);

/// \brief Sets the PSO output mode.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOOUTPUT TOGGLE_Command.html">PSOOUTPUT TOGGLE</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOOutputToggle
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOOutputToggle(SoloistHandle handle);

/// \brief Sets the PSO output mode.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOOUTPUT WINDOW_Command.html">PSOOUTPUT WINDOW</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOOutputWindow
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOOutputWindow(SoloistHandle handle);

/// \brief Sets the PSO output mode.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOOUTPUT PULSE WINDOW MASK_Command.html">PSOOUTPUT PULSE WINDOW MASK</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOOutputPulseWindowMaskHard
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOOutputPulseWindowMaskHard(SoloistHandle handle);

/// \brief Sets the PSO output mode.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOOUTPUT PULSE WINDOW MASK_Command.html">PSOOUTPUT PULSE WINDOW MASK</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] EdgeMode Specifies the pulse output behavior. This argument is required if the EDGE keyword is used.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOOutputPulseWindowMaskEdgeMode
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOOutputPulseWindowMaskEdgeMode(SoloistHandle handle, DWORD EdgeMode);

/// \brief Sets the PSO output mode.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOOUTPUT PULSE WINDOW BIT MASK_Command.html">PSOOUTPUT PULSE WINDOW BIT MASK</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] EdgeMode Specifies the pulse output behavior. This argument is required if the EDGE keyword is used.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOOutputPulseWindowBitMask
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOOutputPulseWindowBitMask(SoloistHandle handle, DWORD EdgeMode);

/// \brief Sets the PSO output mode.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOOUTPUT CONTROL_Command.html">PSOOUTPUT CONTROL</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Mode Used on all drives to select the mode of PSO output.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOOutputControl
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOOutputControl(SoloistHandle handle, DWORD Mode);

/// \brief Sets the PSO output mode.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOOUTPUT BIT MAP_Command.html">PSOOUTPUT BIT MAP</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOOutputBitMap
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOOutputBitMap(SoloistHandle handle);

/// \brief Sets the PSO output mode.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOOUTPUT BIT MAP_Command.html">PSOOUTPUT BIT MAP</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Mode Specifies the mode of operation for the BIT MAP functionality. If this argument is omitted or set to 0, only the most-significant bit (bit 31) of each array value is used. If set to 1, all 32 bits of each array value is used.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOOutputBitMapMode
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOOutputBitMapMode(SoloistHandle handle, DWORD Mode);

/// \brief Sets the PSO output mode.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOOUTPUT PULSE EXTSYNC_Command.html">PSOOUTPUT PULSE EXTSYNC</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOOutputPulseExtSync
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOOutputPulseExtSync(SoloistHandle handle);

/// \brief Configures the pulse sequence used for PSO.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOPULSE_Command.html">PSOPULSE</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] TotalTime The total time of generated pulse in microseconds.
/// \param[in] OnTime The time of the cycle when the PSO output is in the ON state.
/// \param[in] NumCycles The number of pulses to generate in a single pulse event.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOPulseCyclesOnly
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOPulseCyclesOnly(SoloistHandle handle, DOUBLE TotalTime, DOUBLE OnTime, DOUBLE NumCycles);

/// \brief Configures the pulse sequence used for PSO.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOPULSE_Command.html">PSOPULSE</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] TotalTime The total time of generated pulse in microseconds.
/// \param[in] OnTime The time of the cycle when the PSO output is in the ON state.
/// \param[in] DelayTime The time to delay between a fire event and the laser output.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOPulseDelayOnly
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOPulseDelayOnly(SoloistHandle handle, DOUBLE TotalTime, DOUBLE OnTime, DOUBLE DelayTime);

/// \brief Configures the pulse sequence used for PSO.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOPULSE_Command.html">PSOPULSE</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] TotalTime The total time of generated pulse in microseconds.
/// \param[in] OnTime The time of the cycle when the PSO output is in the ON state.
/// \param[in] NumCycles The number of pulses to generate in a single pulse event.
/// \param[in] DelayTime The time to delay between a fire event and the laser output.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOPulseCyclesAndDelay
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOPulseCyclesAndDelay(SoloistHandle handle, DOUBLE TotalTime, DOUBLE OnTime, DOUBLE NumCycles, DOUBLE DelayTime);

/// \brief Configures the PSO distance tracking counters.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOTRACK INPUT_Command.html">PSOTRACK INPUT</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Source The encoder to use as the source.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOTrackInput
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOTrackInput(SoloistHandle handle, PSOENCODER Source);

/// \brief Configures the PSO distance tracking counters.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOTRACK RESET_Command.html">PSOTRACK RESET</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] RBitMask The mask of possible conditions that can hold the tracking counter in reset.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOTrackReset
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOTrackReset(SoloistHandle handle, DWORD RBitMask);

/// \brief Configures the PSO distance tracking counters.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOTRACK DIRECTION_Command.html">PSOTRACK DIRECTION</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] DBitMask The mask of possible directions to be suppressed when tracking position.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOTrackDirection
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOTrackDirection(SoloistHandle handle, DWORD DBitMask);

/// \brief Enables the PSO Window Hardware.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOWINDOW ON_Command.html">PSOWINDOW ON</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOWindowOn
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOWindowOn(SoloistHandle handle);

/// \brief Disables the PSO Window Hardware.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOWINDOW OFF_Command.html">PSOWINDOW OFF</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOWindowOff
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOWindowOff(SoloistHandle handle);

/// \brief Configures which encoder channel is connected to each window.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOWINDOW INPUT_Command.html">PSOWINDOW INPUT</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Source The encoder source to use.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOWindowInput
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOWindowInput(SoloistHandle handle, PSOENCODER Source);

/// \brief Resets the window counter to 0 based on the encoder marker signal.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOWINDOW RESET_Command.html">PSOWINDOW RESET</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] BitMask The mask of possible conditions that hold the tracking counter in reset.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOWindowReset
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOWindowReset(SoloistHandle handle, DWORD BitMask);

/// \brief Loads the specified window counter with a value.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOWINDOW LOAD_Command.html">PSOWINDOW LOAD</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] Value The value to load into the specified window.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOWindowLoad
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOWindowLoad(SoloistHandle handle, DWORD Value);

/// \brief Specifies the array mode parameters for the specified PSO window.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOWINDOW RANGE ARRAY_Command.html">PSOWINDOW RANGE ARRAY</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] EdgeCode An optional argument that restricts updating to one encoder direction.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOWindowRangeArray
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOWindowRangeArray(SoloistHandle handle, DOUBLE EdgeCode);

/// \brief Specifies the low and high comparison values for specified PSO window.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/PSOWINDOW RANGE_Command.html">PSOWINDOW RANGE</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup pso
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \param[in] LowValue The low position range for fixed window.
/// \param[in] HighValue The high position range for fixed window.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistPSOWindowRange
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistPSOWindowRange(SoloistHandle handle, DOUBLE LowValue, DOUBLE HighValue);


/// \brief Acknowledges all axis faults and clears all task errors.

/// \htmlonly This command is the same as "<a href="mk:@MSITStore:Soloist.chm::/Commands/ACKNOWLEDGEALL_Command.html">ACKNOWLEDGEALL</a>" in AeroBasic.
/// \endhtmlonly
///
/// \ingroup root
///
/// \param[in] handle The handle to the controller on which to execute the command.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
///
/// Example usage:
///
/// \dontinclude "CommandsDoc.h"
/// \skip SoloistAcknowledgeAll
/// \until SoloistDisconnect
BOOL DLLENTRYDECLARATION SoloistAcknowledgeAll(SoloistHandle handle);



#ifdef __cplusplus
}
#endif

#endif // __Soloist_AEROBASIC_COMMANDS_H__

