// TimerFix v2 beta by Slice

#if !defined _samp_included
	#error Please include a_samp before Timer Fix.
#endif

#if !defined TIMER_FIX_TICK_INTERVAL
	#define TIMER_FIX_TICK_INTERVAL  5
#endif

#if !defined TIMER_FIX_TIMER_SLOTS
	#define TIMER_FIX_TIMER_SLOTS  128
#endif

#if !defined TIMER_FIX_MAX_ARGUMENTS
	#define TIMER_FIX_MAX_ARGUMENTS  32
#endif

#if !defined TIMER_FIX_PERFORMANCE_CHECKS
	#define TIMER_FIX_PERFORMANCE_CHECKS  true
#endif

#if !defined TIMER_FIX_DEBUG
	#define TIMER_FIX_DEBUG  false
#endif

#define TF::  TF_

enum TF::e_TIMER {
	bool:e_bIsUsed,
	     e_iNumArguments,
	     e_axArguments[TIMER_FIX_MAX_ARGUMENTS],
#if TIMER_FIX_DEBUG
	     e_aiArgumentTypes[TIMER_FIX_MAX_ARGUMENTS],
#endif
	     e_iFunctionAddress,
	     e_szFunctionName[32],
	     e_iInterval,
	     e_iNextCall,
	bool:e_bIsRepeating
};

static
#if TIMER_FIX_DEBUG
	TF::gs_szDebugBuffer[512],
#endif
	TF::gs_Timers[TIMER_FIX_TIMER_SLOTS][TF::e_TIMER],
	TF::gs_iCurrentTimer = -1
;

// Fix for y_timers
#define _Timer_C(O@  _Timer_C(SetTimerEx

stock SetTimerHook(const szFunctionName[], iInterval, {bool, _}:bRepeating, const szFormat[] = !"", {_, PlayerText3D, Text, Text3D, Menu, DB, DBResult, File, Float}:...) {
	static
		bool:s_bTimerTickTimerStarted = false
	;
	
	if (!s_bTimerTickTimerStarted) {
		SetTimer(!"TF_TimerTick", TIMER_FIX_TICK_INTERVAL, true);
		
		s_bTimerTickTimerStarted = true;
	}
	
	new
		iSlot = -1
	;
	
	for (new i = 0; i < sizeof(TF::gs_Timers); i++) {
		if (!TF::gs_Timers[i][e_bIsUsed]) {
			iSlot = i;
			
			break;
		}
	}
	
	if (iSlot == -1) {
		print(!"(TimerFix) ERROR: Ran out of timer slots. Increase TIMER_FIX_TIMER_SLOTS (current value: " #TIMER_FIX_TIMER_SLOTS ").");
		
		return -1;
	}
	
	if (!(TF::gs_Timers[iSlot][e_iFunctionAddress] = TF::GetPublicFunctionAddress(szFunctionName))) {
		new
			szFunctionNameUnpacked[32]
		;
		
		strunpack(szFunctionNameUnpacked, szFunctionName);
		
		printf("(TimerFix) ERROR: Invalid function (\"%s\").", szFunctionNameUnpacked);
		
		return -1;
	}
	
	new
		#if TIMER_FIX_DEBUG
			bool:bFormatIsPacked = ispacked(szFormat),
		#endif
			     iNumArgs = max(0, numargs() - 4)
	;
	
	if (iNumArgs != strlen(szFormat)) {
		new
			szFormatUnpacked[128 char]
		;
		
		strunpack(szFormatUnpacked, szFormat);
		
		printf("(TimerFix) ERROR: The number of arguments (%d) doesn't match the number of arguments in the format specifier (\"%s\").", iNumArgs, szFormatUnpacked);
		
		return -1;
	}
	
	TF::gs_Timers[iSlot][e_bIsUsed]       = true;
	TF::gs_Timers[iSlot][e_bIsRepeating]  = bRepeating;
	TF::gs_Timers[iSlot][e_iInterval]     = iInterval;
	TF::gs_Timers[iSlot][e_iNextCall]     = GetTickCount() + iInterval;
	TF::gs_Timers[iSlot][e_iNumArguments] = iNumArgs;
	
	strunpack(TF::gs_Timers[iSlot][e_szFunctionName], szFunctionName, 32);
	
	for (new i = 0; i < iNumArgs; i++) {
		TF::gs_Timers[iSlot][e_axArguments][i] = getarg(4 + i);
		
		#if TIMER_FIX_DEBUG
			TF::gs_Timers[iSlot][e_aiArgumentTypes][i] = bFormatIsPacked ? szFormat{i} : szFormat[i];
		#endif
	}
	
	#if TIMER_FIX_DEBUG
		printf("(TimerFix) DEBUG: Timer created; %d = \"%s\".", iSlot, TF::gs_Timers[iSlot][e_szFunctionName]);
	#endif
	
	return iSlot;
}

stock KillTimerHook(iTimer) {
	if (0 <= iTimer < sizeof(TF::gs_Timers)) {
		if (TF::gs_Timers[iTimer][e_bIsUsed]) {
			TF::gs_Timers[iTimer][e_bIsUsed] = false;
			
			#if TIMER_FIX_DEBUG
				printf("(TimerFix) DEBUG: Killed timer %d (\"%s\").", iTimer, TF::gs_Timers[iTimer][e_szFunctionName]);
			#endif
			
			return true;
		}
	}
	
	#if TIMER_FIX_DEBUG
		printf("(TimerFix) DEBUG: Failed to kill timer %d; not in use / invalid id.", iTimer);
	#endif
	
	return false;
}

#define SetTimer    SetTimerHook
#define SetTimerEx  SetTimerHook
#define KillTimer   KillTimerHook

stock KillThisTimer() {
	if (TF::gs_iCurrentTimer != -1)
		KillTimer(TF::gs_iCurrentTimer);
}

forward TF::TimerTick();
public TF::TimerTick() {
	new
		iTick,
		iFunc,
		iArg,
		i, j
	;
	
	if (TF::gs_iCurrentTimer != -1) {
		printf("(TimerFix) ERROR: The function \"%s\" didn't properly execute, some timers might not have been called.", TF::gs_Timers[TF::gs_iCurrentTimer][e_szFunctionName]);
		
		TF::gs_iCurrentTimer = -1;
	}
	
	for (i = 0; i < sizeof(TF::gs_Timers); i++) {
		if (!TF::gs_Timers[i][e_bIsUsed])
			continue;
		
		if ((iTick = GetTickCount()) >= TF::gs_Timers[i][e_iNextCall]) {
			iFunc = TF::gs_Timers[i][e_iFunctionAddress];
			
			// This is done before and after execution, in case execution fails
			if (TF::gs_Timers[i][e_bIsRepeating])
				TF::gs_Timers[i][e_iNextCall] = iTick + TF::gs_Timers[i][e_iInterval] - 1;
			
			#if TIMER_FIX_DEBUG
				TF::PrintFunctionCall(i);
			#endif
			
			j = TF::gs_Timers[i][e_iNumArguments];
			
			
			TF::gs_iCurrentTimer = i;
			
			// Push the arguments
			while (--j >= 0) {
				#emit CONST.alt   TF_gs_Timers
				#emit LOAD.S.pri  i
				#emit IDXADDR
				#emit MOVE.alt
				#emit LOAD.I
				#emit ADD
				#emit ADD.C       8 // e_axArguments * 4
				#emit MOVE.alt
				#emit LOAD.S.pri  j
				#emit IDXADDR
				#emit LOAD.I
				#emit PUSH.pri
			}
			
			// Push the number of arguments
			iArg = TF::gs_Timers[i][e_iNumArguments] * 4;
			
			#emit PUSH.S      iArg

			// Push the return address
			#emit LCTRL		  6
			#emit ADD.C		  28
			#emit PUSH.pri

			// Call the function
			#emit LOAD.S.pri  iFunc
			#emit SCTRL		  6
			
			#if TIMER_FIX_PERFORMANCE_CHECKS
				if (GetTickCount() - iTick > 10) {
					printf("(TimerFix) WARNING: The function \"%s\" took %dms to execute! This will affect other timers.", TF::gs_Timers[i][e_szFunctionName], GetTickCount() - iTick);
				}
			#endif
			
			if (TF::gs_Timers[i][e_bIsRepeating])
				TF::gs_Timers[i][e_iNextCall] = GetTickCount() + TF::gs_Timers[i][e_iInterval] - 1;
			else {
				TF::gs_Timers[i][e_bIsUsed] = false;
				
				#if TIMER_FIX_DEBUG
					printf("(TimerFix) DEBUG: Timer %d (\"%s\") finished.", i, TF::gs_Timers[i][e_szFunctionName]);
				#endif
			}
			
			TF::gs_iCurrentTimer = -1;
		}
	}
}

stock TF::PrintFunctionCall(i) {
	format(TF::gs_szDebugBuffer, sizeof(TF::gs_szDebugBuffer), "(TimerFix) DEBUG: Calling: %s(", TF::gs_Timers[i][e_szFunctionName]);
	
	for (new j = 0; j < TF::gs_Timers[i][e_iNumArguments]; j++) {
		if (j)
			strcat(TF::gs_szDebugBuffer, ", ");
		
		switch (TF::gs_Timers[i][e_aiArgumentTypes][j]) {
			case 'f', 'F':
				format(TF::gs_szDebugBuffer, sizeof(TF::gs_szDebugBuffer), "%s%.2f", TF::gs_szDebugBuffer, TF::gs_Timers[i][e_axArguments][j]);
			
			default:
				format(TF::gs_szDebugBuffer, sizeof(TF::gs_szDebugBuffer), "%s%d", TF::gs_szDebugBuffer, TF::gs_Timers[i][e_axArguments][j]);
		}
	}
	
	strcat(TF::gs_szDebugBuffer, ")");
	
	print(TF::gs_szDebugBuffer);
}

stock TF::GetPublicFunctionAddress(const szName[]) {
	new
		iIndex,
		iTemp
	;
	
	if (-1 != (iIndex = funcidx(szName))) {
		// Load the offset to DAT from the prefix
		#emit LCTRL		   1
		
		// Invert it so we have the offset to the prefix from DAT
		#emit NEG
		
		// Copy it to alt for use later
		#emit MOVE.alt
		
		// Add 32 to jump to the offset containing the public function's table
		#emit ADD.C		   32
		
		// Read the value there; must be done using LREF because
		// it's outside of the DAT section
		#emit STOR.S.pri   iTemp
		#emit LREF.S.pri   iTemp
		
		// Add the value we just loaded to the prefix (that we stored in alt)
		#emit ADD
		
		// Add index * 8 (each entry contains 2 cells - a pointer to the function's name
		// and a pointer to the function itself, relative to COD).
		#emit LOAD.S.alt   iIndex
		#emit SHL.C.alt	   3
		
		// Add that to the offset
		#emit ADD
		
		// Now get the address it's pointing to. This seems to only work
		// using LREF (as opposed to LOAD.I, for example).
		#emit STOR.S.pri   iTemp
		#emit LREF.S.pri   iTemp
		
		// Restore the stack
		#emit STACK		   8
		
		// Return the address
		#emit RETN
	}
	
	return 0;
}