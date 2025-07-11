//Arat:

#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM", true);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM", false);
#endif

//Ekle:

#ifdef ENABLE_MINI_GAME_FINDM
	PyModule_AddIntConstant(poModule, "ENABLE_MINI_GAME_FINDM", true);

# ifdef ENABLE_MINI_GAME_FINDM_HINT
	PyModule_AddIntConstant(poModule, "ENABLE_MINI_GAME_FINDM_HINT", true);
# else
	PyModule_AddIntConstant(poModule, "ENABLE_MINI_GAME_FINDM_HINT", false);
# endif
#else
	PyModule_AddIntConstant(poModule, "ENABLE_MINI_GAME_FINDM", false);

# ifndef ENABLE_MINI_GAME_FINDM_HINT
	PyModule_AddIntConstant(poModule, "ENABLE_MINI_GAME_FINDM_HINT", false);
# endif
#endif