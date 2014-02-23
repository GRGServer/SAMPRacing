// Constants
#include <grgserver\localconfig.inc>
#include <grgserver\constants.inc>
#include <grgserver\macros.inc>

// Structures
#include <grgserver\Structures\E_COMMANDALIAS.inc>
#include <grgserver\Structures\E_LANGUAGESTRING.inc>
#include <grgserver\Structures\E_PTD.inc>
#include <grgserver\Structures\E_PVAR.inc>
#include <grgserver\Structures\E_TELEPORT.inc>
#include <grgserver\Structures\E_VEHICLE.inc>
#include <grgserver\Structures\E_VEHICLEMODEL.inc>

// Global variables
#include <grgserver\globals.inc>
#include <grgserver\forwards.inc>

// functions
#include <grgserver\functions\AddLine.inc>
#include <grgserver\functions\CmdUsageMsg.inc>
#include <grgserver\functions\CreateDialog.inc>
#include <grgserver\functions\CreatePlayerTextDraws.inc>
#include <grgserver\functions\CreateVehicleEx.inc>
#include <grgserver\functions\ExecuteCommand.inc>
#include <grgserver\functions\GetLanguageByID.inc>
#include <grgserver\functions\GetLanguageID.inc>
#include <grgserver\functions\GetMySQLField.inc>
#include <grgserver\functions\GetPlayerNameEx.inc>
#include <grgserver\functions\GetVehicleEngineState.inc>
#include <grgserver\functions\Hash.inc>
#include <grgserver\functions\IsLoggedIn.inc>
#include <grgserver\functions\LanguageString.inc>
#include <grgserver\functions\LoadPlayer.inc>
#include <grgserver\functions\PlaySound.inc>
#include <grgserver\functions\ReloadCommandAliases.inc>
#include <grgserver\functions\ReloadLanguageStrings.inc>
#include <grgserver\functions\ReloadTeleports.inc>
#include <grgserver\functions\ReloadVehicleModels.inc>
#include <grgserver\functions\ResetPlayerVariables.inc>
#include <grgserver\functions\SavePlayer.inc>
#include <grgserver\functions\SavePlayers.inc>
#include <grgserver\functions\SaveTeleports.inc>
#include <grgserver\functions\SendClientMessageEx.inc>
#include <grgserver\functions\SetVehicleEngineState.inc>
#include <grgserver\functions\SpawnVehicle.inc>
#include <grgserver\functions\StopDrifting.inc>
#include <grgserver\functions\StrNotNull.inc>
#include <grgserver\functions\TeleportTo.inc>
#include <grgserver\functions\mysql_query_format.inc>
#include <grgserver\functions\str_replace.inc>

// callbacks
#include <grgserver\callbacks\OnDialogResponse.inc>
#include <grgserver\callbacks\OnGameModeExit.inc>
#include <grgserver\callbacks\OnGameModeInit.inc>
#include <grgserver\callbacks\OnPlayerCommandPerformed.inc>
#include <grgserver\callbacks\OnPlayerCommandText.inc>
#include <grgserver\callbacks\OnPlayerConnect.inc>
#include <grgserver\callbacks\OnPlayerDeath.inc>
#include <grgserver\callbacks\OnPlayerDisconnect.inc>
#include <grgserver\callbacks\OnPlayerExitVehicle.inc>
#include <grgserver\callbacks\OnPlayerSpawn.inc>
#include <grgserver\callbacks\OnPlayerUpdate.inc>
#include <grgserver\callbacks\OnVehicleDamageStatusUpdate.inc>

// dialogs
#include <grgserver\dialogs\D_Login.inc>
#include <grgserver\dialogs\D_Register_Language.inc>
#include <grgserver\dialogs\D_Register_Password1.inc>
#include <grgserver\dialogs\D_Register_Password2.inc>
#include <grgserver\dialogs\D_SpawnVehicle.inc>

// timers
#include <grgserver\timers\Timer_EveryMinute.inc>
#include <grgserver\timers\Timer_EverySecond.inc>

// commands
#include <grgserver\commands\addtp.inc>
#include <grgserver\commands\drift.inc>
#include <grgserver\commands\engine.inc>
#include <grgserver\commands\god.inc>
#include <grgserver\commands\makeadmin.inc>
#include <grgserver\commands\reload.inc>
#include <grgserver\commands\spawnvehicle.inc>
#include <grgserver\commands\tp.inc>
#include <grgserver\commands\tpto.inc>

