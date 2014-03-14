// Audio files
#define AUDIOFILE_GARAGEBOUGHT		"bought.ogg"
#define AUDIOFILE_VEHICLEBOUGHT		"bought.ogg"


// Colors
#define COLOR_CHAT			0xAAFFAAFF
#define COLOR_ERROR			0xFF0000FF
#define COLOR_INFO			0xFF8C55FF
#define COLOR_JOINLEAVE			0x74E800FF
#define COLOR_ME			0x00FF40FF
#define COLOR_USAGE			0x008000FF
#define COLOR_WARNING			0xFF6000FF
#define COLOR_SYSTEM			0xC0C0C0FF


// Garages
#define GARAGE_LARGE_CAMERA_POSX	611.025878
#define GARAGE_LARGE_CAMERA_POSY	-72.445640
#define GARAGE_LARGE_CAMERA_POSZ	997.992187
#define GARAGE_LARGE_INTERIOR		2
#define GARAGE_LARGE_VEHICLE_ANGLE	89.993965
#define GARAGE_LARGE_VEHICLE_POSX	616.760009
#define GARAGE_LARGE_VEHICLE_POSY	-74.814704
#define GARAGE_LARGE_VEHICLE_POSZ	997.474975
#define GARAGE_SMALL_CAMERA_POSX	611.378967
#define GARAGE_SMALL_CAMERA_POSY	-121.914054
#define GARAGE_SMALL_CAMERA_POSZ	997.992187
#define GARAGE_SMALL_INTERIOR		3
#define GARAGE_SMALL_VEHICLE_ANGLE	90.063156
#define GARAGE_SMALL_VEHICLE_POSX	615.791259
#define GARAGE_SMALL_VEHICLE_POSY	-124.237937
#define GARAGE_SMALL_VEHICLE_POSZ	997.474853


// Special icons
#define ICON_CONNECT			200
#define ICON_DISCONNECT			201


// Keys
#define KEY_CHECKPOINT_USE		KEY_YES
#define KEY_OBJECTEDITOR_CLONE		KEY_WALK
#define KEY_OBJECTEDITOR_REMOVE		KEY_NO
#define KEY_PICKUP_USE			KEY_YES
#define KEY_VEHICLESHOP_BUY		KEY_SPRINT
#define KEY_VEHICLESHOP_NEXT		KEY_ANALOG_RIGHT
#define KEY_VEHICLESHOP_PREVIOUS	KEY_ANALOG_LEFT
#define KEY_VEHICLESHOP_QUIT		KEY_SECONDARY_ATTACK


// Limits
#define MAX_AREAPOINTS			50
#define MAX_AREAS			50
#define MAX_CHECKPOINTS			1000
#define MAX_COMMANDALIASES		50
#define MAX_COMMANDS			50
#define MAX_DYNAMIC_OBJECTS		1000
#define MAX_FUNCTION_NAME		32
#define MAX_GARAGES			50
#define MAX_HIDDENPACKAGES		100
#define MAX_INTERIORS			150
#define MAX_LANGUAGE_STRINGS		LanguageStringLimit(149)
#define MAX_OBJECTMODELS		11000
#define MAX_RANDOMNUMBERPLATE_TRIES	100
#define MAX_TELEPORTS			50
#define MAX_VEHICLECOMPONENT_SLOTS	14
#define MAX_VEHICLESHOPS		10


// Register
#define REGISTER_MONEY			2000
#define REGISTER_PASSWORD_MIN		3


// Shops
#define SHOP_VEHICLE_CAM_POSX		-1658.1140
#define SHOP_VEHICLE_CAM_POSY		1211.4670
#define SHOP_VEHICLE_CAM_POSZ		21.1563
#define SHOP_VEHICLE_MOBILESHOPID	0
#define SHOP_VEHICLE_VEH_POSX		-1658.5483
#define SHOP_VEHICLE_VEH_POSY		1206.1632
#define SHOP_VEHICLE_VEH_POSZ		20.6349
#define SHOP_VEHICLE_VEH_ANGLE		29.5408


// Sounds
#define SOUND_COMMAND_DENIED		5203
#define SOUND_COMMAND_ERROR		1085
#define SOUND_COMMAND_OK		1138
#define SOUND_HIDDENPACKAGE		1150
#define SOUND_OBJECTPLACED		31810
#define SOUND_PICKUPEVENT		1150


// Spawn default location
#define SPAWN_POSX			-2024.1847
#define SPAWN_POSY			-100.8980
#define SPAWN_POSZ			35.1641
#define SPAWN_ANGLE			352.6504
#define SPAWN_INTERIOR			0


// String sizes
#define STRINGLENGTH_AREAGROUP		10
#define STRINGLENGTH_AREANAME		100
#define STRINGLENGTH_CMDALIASPARAMS	256
#define STRINGLENGTH_COMMANDNAME	27// MAX_FUNCTION_NAME - 5; 5 = "cmd_" + 1 (For 0 byte)
#define STRINGLENGTH_DIALOGNAME		28// MAX_FUNCTION_NAME - 4; 4 = "DR_" + 1 (For 0 byte)
#define STRINGLENGTH_HASH		129// 128 + 1 (For 0 byte)
#define STRINGLENGTH_HASHSTRING		100// Maximum length of string to hash
#define STRINGLENGTH_INTERIORNAME	50
#define STRINGLENGTH_LANGUAGESTRING	256
#define STRINGLENGTH_NUMBERPLATE	32
#define STRINGLENGTH_OBJECTFILENAME	32
#define STRINGLENGTH_OBJECTMODELNAME	32
#define STRINGLENGTH_PICKUPTYPE		20
#define STRINGLENGTH_TELEPORTNAME	100
#define STRINGLENGTH_VEHICLENAME	20
#define STRINGLENGTH_VEHICLETYPE	16

#define GREEN 			0x21DD00FF
#define RED 			0xE60000FF
#define YELLOW 			0xFFFF00FF
#define ORANGE 			0xF97804FF
#define LIGHTRED 		0xFF8080FF
#define LIGHTBLUE 		0x00C2ECFF
#define PURPLE 			0xB360FDFF
#define BLUE 			0x1229FAFF
#define LIGHTGREEN 		0x38FF06FF
#define DARKPINK 		0xE100E1FF
#define DARKGREEN 		0x008040FF
#define ANNOUNCEMENT 	0x6AF7E1FF
#define GREY 			0xCECECEFF
#define PINK 			0xD52DFFFF
#define DARKGREY    	0x626262FF
#define AQUAGREEN   	0x03D687FF
#define WHITE 			0xFFFFFFFF

#define PLAYERS 200

#define L_VEHICLE 200


//******************************************************************************
// SpeedoMeter Configurations
//******************************************************************************

//::::::::::::::::::::::::::::::::::::
// -> Functions Config <-
//::::::::::::::::::::::::::::::::::::
#define VehLockTime      10                //Define the MAX Time for Car Locked! (In Minutes!)
#define VehicleMaxSpeed  50                //Define the Speed Limit! (KPH)
#define SpeedoLogoText   "SpeedoMeter" //Define Speedo Logo (Text in Speedo Top)
#define UpdateConfig     500               //Update Speedo functions in ... (Miliseconds)


//::::::::::::::::::::::::::::::::::::
// -> Speedo TextDraw Config <-
//::::::::::::::::::::::::::::::::::::
#define TextBox         true   //Enable/Disable Speedo Box
#define TextTopLines    true   //Enable/Disable Speedo Top Lines
#define TextSideLines   true   //Enable/Disable Speedo Side Lines
#define LogoName        true   //Enable/Disable Speedo LogoName


//::::::::::::::::::::::::::::::::::::
// -> Speedo Colors Config <-
//::::::::::::::::::::::::::::::::::::
#define BoxColor         0xffffffff     //Color of Speedo Box
#define LogoColor        0xffffffff     //Color of Seedo Logo (Define logo in "SpeedoLogoText" (Line 57)
#define SideLinesColor   0xffffffff     //Color of Speedo Side Lines
#define TopLinesColor    0xffffffff     //Color of Speedo Top lines
#define CategoriesColor  "~b~"          //Color of (Vehicle,Health,Altitude,Gps)
#define MPH_KPH_Color    "~g~"          //Color of (MPH,KPH)

#define MAX_ZONE_NAME 28


// Area types
enum
{
	AREATYPE_DRIFT,
	AREATYPE_STUNT
}


// Checkpoint events
enum
{
	CHECKPOINTEVENT_ENTER,
	CHECKPOINTEVENT_KEY
}


// Checkpoint types
enum
{
	CHECKPOINTTYPE_UNSET,// Must be the first (0)
	CHECKPOINTTYPE_GARAGE
}


// Command responses
enum
{
	COMMAND_NOT_FOUND,
	COMMAND_ERROR,
	COMMAND_OK,
	COMMAND_OK_NOSOUND,
	COMMAND_NOT_IN_VEHICLE,
	COMMAND_NOT_VEHICLE_DRIVER,
	COMMAND_PERMISSION_DENIED,
	COMMAND_PLAYER_NOT_FOUND,
	COMMAND_TELEPORTED,
	COMMAND_USAGE
}


// Garage types
enum
{
	GARAGE_UNSET,// Must be the first (0)
	GARAGE_LARGE,
	GARAGE_SMALL
}


// Language IDs
enum
{
	LANGUAGE_ENGLISH,
	LANGUAGE_GERMAN
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
	PICKUPTYPE_VEHICLESHOP
}


// Spawn types
enum
{
	SPAWNTYPE_DEFAULT,// Must be the first (0)
	SPAWNTYPE_BUYVEHICLESHOP
}

enum MainZone 
{
	Zone_Name[28], 
	Float:Zone_Area[6] 
}

enum ReadPositions
{
	Float:ReadX,
	Float:ReadY,
	Float:ReadZ
}