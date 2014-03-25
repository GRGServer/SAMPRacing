#include "a_npc"
#define RECORDING2 "LSTest3"

main()
{
}

public OnRecordingPlaybackEnd()
{
	StartRecordingPlayback(1, RECORDING2);
}

public OnNPCEnterVehicle(vehicleid, seatid)
{
	StartRecordingPlayback(1, RECORDING2);
}
public OnNPCExitVehicle()
{
	StopRecordingPlayback();
}