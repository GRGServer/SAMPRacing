#include "a_npc"//Baut die Include "a_npc" ein
#define RECORDING "LSTest1"// BulletLS gegen euren Aufnahmenamen ersetzen!

main()
{
}

public OnRecordingPlaybackEnd()
{
	StartRecordingPlayback(1, RECORDING);//1 = Aufnahmetyp - Fahrzeug, Recording = Der oben definierte Aufnahmename
}

public OnNPCEnterVehicle(vehicleid, seatid)
{
	StartRecordingPlayback(1, RECORDING);//1 = Aufnahmetyp - Fahrzeug, Recording = Der oben definierte Aufnahmename
}
public OnNPCExitVehicle()
{
	StopRecordingPlayback();
}