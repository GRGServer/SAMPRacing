#include <a_npc>

#define _inc_a_npc

#include <sscanf_npc>

#include <grgserver/constants>
#include <grgserver/macros>
#include <grgserver/functions/StrNotNull>

new g_playbackType;
new g_recordingName[STRINGLENGTH_NPCRECORDINGNAME];
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
        StartRecordingPlaybackEx();
    }
    else
    {
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
        PauseRecordingPlayback();
        return;
    }

    if (IsStr(command, NPCCMD_RESUME))
    {
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

        new delay = strval(parameters);
        if (delay)
        {
            SetTimer("StartRecordingPlaybackEx", delay, false);
        }
        else
        {
            StartRecordingPlaybackEx();
        }
        return;
    }

    if (IsStr(command, NPCCMD_STOP))
    {
        StopRecordingPlayback();
        return;
    }

    Log("Invalid command!");
}

forward StartRecordingPlaybackEx();
public StartRecordingPlaybackEx()
{
    StartRecordingPlayback(g_playbackType, g_recordingName);
}