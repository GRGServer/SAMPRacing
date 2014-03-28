#include <a_npc>

#define _inc_a_npc

#include <sscanf_npc>

#include <grgserver/constants>
#include <grgserver/macros>
#include <grgserver/functions/StrNotNull>

new g_playbackType;
new g_recordingName[STRINGLENGTH_NPCRECORDINGNAME];
new g_recordingRunning;
new g_repeat;

public OnClientMessage(color, text[])
{
	if (color != COLOR_NPCCOMMAND)
	{
		return;
	}

	new command[100];
	new parameters[200];
	if (sscanf(text, "ss", command, parameters))
	{
		if (sscanf(text, "s", command))
		{
			Log("Invalid message format!");
			return;
		}
	}

	HandleCommand(command, parameters);
}

public OnRecordingPlaybackEnd()
{
	if (g_repeat)
	{
		g_recordingRunning = true;
		StartRecordingPlayback(g_playbackType, g_recordingName);
	}
	else
	{
		g_recordingRunning = false;
		SendCommand("/npccmd " #NPCCMD_RECORDINGENDED);
	}
}

Log(string[])
{
	new command[200];
	format(command, sizeof(command), "/npccmd " #NPCCMD_LOG " %s", string);
	SendCommand(command);
}

HandleCommand(command[], parameters[])
{
	if (IsStr(command, NPCCMD_PAUSE))
	{
		g_recordingRunning = false;
		PauseRecordingPlayback();
		return;
	}

	if (IsStr(command, NPCCMD_RESUME))
	{
		g_recordingRunning = true;
		ResumeRecordingPlayback();
		return;
	}

	if (IsStr(command, NPCCMD_SETRECORDING))
	{
		new playbackType;
		new recordingName[STRINGLENGTH_NPCRECORDINGNAME];
		if (sscanf(parameters, "ds", playbackType, recordingName))
		{
			Log("Invalid arguments!");
			return;
		}

		g_playbackType = playbackType;
		g_recordingName = recordingName;

		// Fix for keeping NPC at spawn location till start of the recording (If not already running)
		if (!g_recordingRunning)
		{
			StartRecordingPlayback(g_playbackType, g_recordingName);
			PauseRecordingPlayback();
		}

		return;
	}

	if (IsStr(command, NPCCMD_SETREPEAT))
	{
		g_repeat = strval(parameters);
		return;
	}

	if (IsStr(command, NPCCMD_START))
	{
		if (!StrNotNull(g_recordingName))
		{
			Log("No recording defined!");
			return;
		}

		g_recordingRunning = true;
		StartRecordingPlayback(g_playbackType, g_recordingName);
		return;
	}

	if (IsStr(command, NPCCMD_STOP))
	{
		g_recordingRunning = false;
		StopRecordingPlayback();
		return;
	}

	Log("Invalid command!");
}