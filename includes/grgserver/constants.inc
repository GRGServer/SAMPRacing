// Audio files
#define AUDIOFILE_GARAGEBOUGHT          "bought.ogg"
#define AUDIOFILE_VEHICLEBOUGHT         "bought.ogg"


// Colors
#define COLOR_CHAT                      0xAAFFAAFF
#define COLOR_ERROR                     0xFF0000FF
#define COLOR_INFO                      0xFF8C55FF
#define COLOR_JOINLEAVE                 0x74E800FF
#define COLOR_ME                        0x00FF40FF
#define COLOR_NPCCOMMAND                0x000000A0// This color should never be used somewhere else!
#define COLOR_USAGE                     0x008000FF
#define COLOR_WARNING                   0xFF6000FF
#define COLOR_SYSTEM                    0xC0C0C0FF
#define COLOR_TEXTDRAWHOVER             0xFF8C55FF


// Special icons
#define ICON_CONNECT                    200
#define ICON_DISCONNECT                 201


// Keys
#define KEY_GARAGE_GET                  KEY_SPRINT
#define KEY_GARAGE_NEXT                 KEY_ANALOG_RIGHT
#define KEY_GARAGE_PREVIOUS             KEY_ANALOG_LEFT
#define KEY_GARAGE_QUIT                 KEY_SECONDARY_ATTACK
#define KEY_OBJECTEDITOR_CLONE          KEY_WALK
#define KEY_OBJECTEDITOR_REMOVE         KEY_NO
#define KEY_OBJECTEDITOR_SETMOVEPOS     KEY_YES
#define KEY_OBJECT_MOVE_AUTORESET       KEY_YES
#define KEY_PICKUP_USE                  KEY_YES
#define KEY_RECNPC_STOP                 KEY_YES
#define KEY_VEHICLESHOP_BUY             KEY_SPRINT
#define KEY_VEHICLESHOP_NEXT            KEY_ANALOG_RIGHT
#define KEY_VEHICLESHOP_PREVIOUS        KEY_ANALOG_LEFT
#define KEY_VEHICLESHOP_QUIT            KEY_SECONDARY_ATTACK


// Map icon types
#define MAPICONTYPE_GARAGE              40
#define MAPICONTYPE_RACE                43
#define MAPICONTYPE_VEHICLESHOP         55


// Limits
#define MAX_AREAPOINTS                  50
#define MAX_AREAS                       50
#define MAX_COMMANDALIASES              50
#define MAX_COMMANDS                    50
#define MAX_DYNAMIC_OBJECTS             1000
#define MAX_DYNAMIC_PICKUPS             4096
#define MAX_FUNCTION_NAME               32
#define MAX_GARAGES                     150
#define MAX_HIDDENPACKAGES              100
#define MAX_INTERIORS                   150
#define MAX_LANGUAGE_STRINGS            LanguageStringLimit(248)
#define MAX_NPCS                        250
#define MAX_OBJECTMODELS                11000
#define MAX_PLAYER_MAPICONS             500
#define MAX_RACECHECKPOINTS             1000
#define MAX_RACENPCS                    3
#define MAX_RACES                       100
#define MAX_RANDOMNUMBERPLATE_TRIES     100
#define MAX_RECNPC_PLAYNPCS             10
#define MAX_SPEEDOMETER_STEPS           13
#define MAX_TELEPORTS                   50
#define MAX_TUNINGGARAGES               20
#define MAX_TUNINGPARTS                 25000
#define MAX_TUNINGPARTSPERVEHICLE       250
#define MAX_VEHICLECOMPONENT_SLOTS      14
#define MAX_VEHICLESHOPS                10


// NPC misc
#define NPC_SCRIPT_NAME                 "npcplayer"


// NPC commands
#define NPCCMD_LOG                      "log"
#define NPCCMD_PAUSE                    "pause"
#define NPCCMD_RECORDINGENDED           "recordingended"
#define NPCCMD_RESUME                   "resume"
#define NPCCMD_SETRECORDING             "setrecording"
#define NPCCMD_SETREPEAT                "setrepeat"
#define NPCCMD_START                    "start"
#define NPCCMD_STOP                     "stop"


// Races
#define RACE_CHECKPOINT_SIZE            10
#define RACE_DISQUALIFICATION_TIMEOUT   30
#define RACE_LOBBY_NPC1                 60
#define RACE_LOBBY_NPC2                 61
#define RACE_LOBBY_NPCSPECTATETIME      30000
#define RACE_PLAYERCOUNT                4


// Register
#define REGISTER_MONEY                  2000
#define REGISTER_PASSWORD_MIN           3


// Shops
#define SHOP_VEHICLE_CAM_POSX           -1658.1140
#define SHOP_VEHICLE_CAM_POSY           1211.4670
#define SHOP_VEHICLE_CAM_POSZ           21.1563
#define SHOP_VEHICLE_MOBILESHOPID       0
#define SHOP_VEHICLE_VEH_POSX           -1658.5483
#define SHOP_VEHICLE_VEH_POSY           1206.1632
#define SHOP_VEHICLE_VEH_POSZ           20.6349
#define SHOP_VEHICLE_VEH_ANGLE          29.5408


// Sounds
#define SOUND_COMMAND_DENIED            5203
#define SOUND_COMMAND_ERROR             1085
#define SOUND_COMMAND_OK                1138
#define SOUND_HIDDENPACKAGE             1150
#define SOUND_OBJECTPLACED              31810
#define SOUND_PICKUPEVENT               1150
#define SOUND_VEHICLE_LOCK              1057
#define SOUND_VEHICLE_UNLOCK            1057


// Spawn default location
#define SPAWN_POSX                      -2024.1847
#define SPAWN_POSY                      -100.8980
#define SPAWN_POSZ                      35.1641
#define SPAWN_ANGLE                     352.6504
#define SPAWN_INTERIOR                  0


// Speedometer
#define SPEEDOMETER_ANALOG_POSX         550
#define SPEEDOMETER_ANALOG_POSY         250
#define SPEEDOMETER_DIGITAL_VALUE_POSX  SPEEDOMETER_ANALOG_POSX
#define SPEEDOMETER_DIGITAL_VALUE_POSY  SPEEDOMETER_ANALOG_POSY - 10
#define SPEEDOMETER_DIGITAL_UNIT_POSX   SPEEDOMETER_DIGITAL_VALUE_POSX
#define SPEEDOMETER_DIGITAL_UNIT_POSY   SPEEDOMETER_DIGITAL_VALUE_POSY + 10
#define SPEEDOMETER_HEALTHBAR_LENGTH    40
#define SPEEDOMETER_HEALTHBAR_POSX      SPEEDOMETER_ANALOG_POSX - 21
#define SPEEDOMETER_HEALTHBAR_POSY      SPEEDOMETER_ANALOG_POSY + 22


// String sizes
#define STRINGLENGTH_AREAGROUP          10
#define STRINGLENGTH_AREANAME           100
#define STRINGLENGTH_CMDALIASPARAMS     256
#define STRINGLENGTH_COMMANDNAME        27// MAX_FUNCTION_NAME - 5; 5 = "cmd_" + 1 (For 0 byte)
#define STRINGLENGTH_DIALOGNAME         28// MAX_FUNCTION_NAME - 4; 4 = "DR_" + 1 (For 0 byte)
#define STRINGLENGTH_HASH               129// 128 + 1 (For 0 byte)
#define STRINGLENGTH_HASHSTRING         100// Maximum length of string to hash
#define STRINGLENGTH_INTERIORNAME       50
#define STRINGLENGTH_LANGUAGESTRING     256
#define STRINGLENGTH_NPCRECORDINGNAME   100
#define STRINGLENGTH_NUMBERPLATE        32
#define STRINGLENGTH_OBJECTFILENAME     32
#define STRINGLENGTH_OBJECTMODELNAME    32
#define STRINGLENGTH_PICKUPTYPE         20
#define STRINGLENGTH_RACENAME           100
#define STRINGLENGTH_TELEPORTNAME       100
#define STRINGLENGTH_VEHICLENAME        20
#define STRINGLENGTH_VEHICLETYPE        16


// Timers
#define TIMER_RESETDRIFTINGSTATS        60000// Time in milliseconds after which the drifting stats should be resetted once a drifting area was left
#define TIMER_SCREENFADER               10
#define TIMER_UPDATERACELOBBY           2000


// Tuning garages
#define TUNINGGARAGE_PRICE_NUMBERPLATE  500// Price for change of number plate text


// Virtual worlds
#define VIRTUALWORLD_GARAGE             1000// First virtual world for garages (Each player has a virtual world)
#define VIRTUALWORLD_IDLENPC            100// Virtual world for all NPCs which are currently not in use (To hide them from players)
#define VIRTUALWORLD_MODSHOP            2000// First virtual world used for mod shops (Each player has a virtual world)
#define VIRTUALWORLD_RACE               3000// First virtual world used for races (Each race has a virtual world)
#define VIRTUALWORLD_RACELOBBY          101// Virtual world for race lobby
#define VIRTUALWORLD_TUNINGGARAGE       5000// First virtual world used for tuning garages (Each player has a virtual world)
#define VIRTUALWORLD_VEHICLESHOP        4000// First virtual world used for vehicles shops (Each player has a virtual world)


// Area types
enum
{
    AREATYPE_DRIFT,
    AREATYPE_STUNT
}


// Command responses
enum
{
    COMMAND_NOT_FOUND,
    COMMAND_ERROR,
    COMMAND_OK,
    COMMAND_OK_NOSOUND,
    COMMAND_NO_CMDS_ALLOWED,
    COMMAND_NOT_IN_VEHICLE,
    COMMAND_NOT_VEHICLE_DRIVER,
    COMMAND_PERMISSION_DENIED,
    COMMAND_PLAYER_NOT_FOUND,
    COMMAND_TELEPORTED,
    COMMAND_USAGE
}


// Language IDs
enum
{
    LANGUAGE_ENGLISH,
    LANGUAGE_GERMAN
}


// Object move types
enum
{
    OBJECTMOVE_UNSET,// Must be the first (0)
    OBJECTMOVE_AUTORESET,
    OBJECTMOVE_EDIT,
    OBJECTMOVE_EDITORPREVIEW
}


// Object types
enum
{
    OBJECTTYPE_DEFAULT,// Must be the first (0)
    OBJECTTYPE_GARAGEDOOR
}


// Pickup events
enum
{
    PICKUPEVENT_KEY,
    PICKUPEVENT_PICKUP
}


// Pickup types
enum
{
    PICKUPTYPE_UNSET,// Must be the first (0)
    PICKUPTYPE_GARAGE_BOUGHT,
    PICKUPTYPE_GARAGE_FREE,
    PICKUPTYPE_HOSPITAL,
    PICKUPTYPE_RACE,
    PICKUPTYPE_VEHICLESHOP
}


// Screen fader types
enum
{
    SCREENFADER_UNSET,// Must be the first (0)
    SCREENFADER_RACE_ENTERLOBBY,
    SCREENFADER_RACE_LEAVELOBBY,
    SCREENFADER_RACE_LOBBYNPCSWITCH,
    SCREENFADER_RACE_START,
    SCREENFADER_TELEPORT
}


// Spawn types
enum
{
    SPAWNTYPE_DEFAULT,// Must be the first (0)
    SPAWNTYPE_BUYVEHICLESHOP,
    SPAWNTYPE_EXITGARAGE,
    SPAWNTYPE_EXITTUNINGGARAGE,
    SPAWNTYPE_LEAVERACE,
    SPAWNTYPE_STARTRACE
}


// Tuning parts
enum
{
    TUNINGPART_UNKNOWN,// Must be the first (0)
    TUNINGPART_FRONTBUMBER,
    TUNINGPART_HOOD,
    TUNINGPART_LIGHTS,
    TUNINGPART_NEON,
    TUNINGPART_REARBUMBER,
    TUNINGPART_ROOF,
    TUNINGPART_SPOILER
}