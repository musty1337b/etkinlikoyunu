//Arat:

ACMD(do_warp);

//Ekle:

#ifdef ENABLE_MINI_GAME_FINDM
ACMD(do_find_m_event);
#endif

//Arat:

	{ "warp",		do_warp,		0,			POS_DEAD,	GM_LOW_WIZARD	},

//Ekle :

#ifdef ENABLE_MINI_GAME_FINDM
	{ "find_m_event", do_find_m_event, 0, POS_DEAD, GM_IMPLEMENTOR },
#endif



