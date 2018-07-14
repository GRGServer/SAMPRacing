// built-in include guard removal
// just in case the user has a local dependency with the same file name
#if defined _inc_env
	#undef _inc_env
#endif
// custom include-guard to ensure we don't duplicate
#if defined _env_included
	#endinput
#endif
#define _env_included


native GetEnv(name[], dest[], len = sizeof dest);