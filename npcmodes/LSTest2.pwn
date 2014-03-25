#include "a_npc"
#define RECORDING1 "LSTest2"

main()
{
}

public OnRecordingPlaybackEnd()
{
	StartRecordingPlayback(1, RECORDING1);
}

public OnNPCEnterVehicle(vehicleid, seatid)
{
	StartRecordingPlayback(1, RECORDING1);
}
public OnNPCExitVehicle()
{
	StopRecordingPlayback();
}