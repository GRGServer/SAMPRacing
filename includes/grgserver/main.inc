// Constants
#include <grgserver\localconfig.inc>
#include <grgserver\constants.inc>
#include <grgserver\macros.inc>

// Structures
#include <grgserver\Structures\enum_languageString.inc>
#include <grgserver\Structures\enum_permission.inc>
#include <grgserver\Structures\enum_playerVariable.inc>
#include <grgserver\Structures\enum_vehicle.inc>
#include <grgserver\Structures\enum_vehicleModel.inc>

// Global variables
#include <grgserver\arrays.inc>
#include <grgserver\globals.inc>

// functions
#include <grgserver\functions\AddLine.inc>
#include <grgserver\functions\CmdUsageMsg.inc>
#include <grgserver\functions\CreateDialog.inc>
#include <grgserver\functions\CreateVehicleEx.inc>
#include <grgserver\functions\ExecuteCommand.inc>
#include <grgserver\functions\GetLanguageID.inc>
#include <grgserver\functions\GetMySQLField.inc>
#include <grgserver\functions\GetPlayerNameEx.inc>
#include <grgserver\functions\GetPlayerVersionEx.inc>
#include <grgserver\functions\GetVehicleEngineState.inc>
#include <grgserver\functions\IsBanned.inc>
#include <grgserver\functions\IsLoggedIn.inc>
#include <grgserver\functions\LanguageString.inc>
#include <grgserver\functions\LoadPlayer.inc>
#include <grgserver\functions\LoadPlayerPermissions.inc>
#include <grgserver\functions\MySQLEscapeString.inc>
#include <grgserver\functions\PlaySound.inc>
#include <grgserver\functions\ReloadLanguageStrings.inc>
#include <grgserver\functions\ReloadVehicleModels.inc>
#include <grgserver\functions\ResetPlayerVariables.inc>
#include <grgserver\functions\SavePlayer.inc>
#include <grgserver\functions\SendClientMessageEx.inc>
#include <grgserver\functions\SetPlayerMoney.inc>
#include <grgserver\functions\SetVehicleEngineState.inc>
#include <grgserver\functions\SpawnVehicle.inc>
#include <grgserver\functions\StrNotNull.inc>
#include <grgserver\functions\str_replace.inc>

// callbacks
#include <grgserver\callbacks\OnDialogResponse.inc>
#include <grgserver\callbacks\OnGameModeInit.inc>
#include <grgserver\callbacks\OnPlayerCommandPerformed.inc>
#include <grgserver\callbacks\OnPlayerCommandText.inc>
#include <grgserver\callbacks\OnPlayerConnect.inc>
#include <grgserver\callbacks\OnPlayerDisconnect.inc>
#include <grgserver\callbacks\OnPlayerSpawn.inc>

// dialogs
#include <grgserver\dialogs\D_Login.inc>
#include <grgserver\dialogs\D_PreviewInfo.inc>
#include <grgserver\dialogs\D_Register_Language.inc>
#include <grgserver\dialogs\D_Register_Password1.inc>
#include <grgserver\dialogs\D_Register_Password2.inc>
#include <grgserver\dialogs\D_SpawnVehicle.inc>

// commands
#include <grgserver\commands\admin.inc>
#include <grgserver\commands\engine.inc>
#include <grgserver\commands\spawnvehicle.inc>

