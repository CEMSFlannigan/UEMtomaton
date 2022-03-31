/// \file SoloistCommands.h
/// \brief Contains the functions to execute AeroBasic commands.
/// 
/// Copyright (c) Aerotech, Inc. 2010-2013.
/// 

#ifndef __Soloist_COMMANDS_H__
#define __Soloist_COMMANDS_H__

#ifdef __cplusplus
extern "C" {
#endif

/// \ingroup root
///
/// \brief Executes an AeroBasic command in the immediate task.
///
/// The immediate command will be executed, and this function will wait
/// until the command is done executing.  The RET variable will be
/// returned in returnValue.
///
/// The following example shows how to get a value back from the executed code:
/// \dontinclude "Examples.chh"
/// \skip CommandExecuteReturnExample
/// \until }
///
/// \param[in] handle The handle to the Soloist
/// \param[in] command The AeroBasic command to execute
/// \param[out] returnValue The return value of the command, pass in NULL if no value given
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistCommandExecute(SoloistHandle handle, LPCSTR command, DOUBLE* returnValue);

/// \ingroup motion
///
/// \brief Aborts motion on given axes.
///
/// The motion on the given axes will be aborted.  This command does use
/// tasks and therefore will be executed asynchronously with regard to other commands.
/// This is an asynchronous call.  When this function returns the abort will be started, 
/// but it will not be finished.
///
/// \param[in] handle The handle to the Soloist
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistMotionAbort(SoloistHandle handle);

/// \ingroup motion
///
/// \brief Waits for motion to be done on given axes.
///
/// The command will block until motion is done on given
/// axes with the given criteria, or the wait times out.
///
/// \param[in] handle The handle to the Soloist
/// \param[in] waitOption Either WAITOPTION_MoveDone or WAITOPTION_InPosition
/// \param[in] timeout The timeout to wait for in milliseconds.  -1 means to wait forever, 0 means to not wait.
/// \param[out] timedOut Whether the wait timed out or not. This parameter can be NULL if the timeout information is not desired.
/// \return TRUE on success, FALSE if an error occurred. Call SoloistGetLastError() for more information.
BOOL DLLENTRYDECLARATION SoloistMotionWaitForMotionDone(SoloistHandle handle, WAITOPTION waitOption, DWORD timeout, BOOL* timedOut);

#ifdef __cplusplus
}
#endif

#endif
