//Arat:

	DWORD spawnPos[][6] = {
		{ 59000, 47100, 51700, 74200, 30600, 82800 }, // 30129
		{ 60800, 61700, 59600, 61000, 35700, 74300 }, // 30131

//Ekle:

#ifdef ENABLE_MINI_GAME_FINDM
		{ 61800, 62000, 60400, 61300, 36000, 74200 }, // 20507
#endif

//Arat:

	switch (dwVnum)
	{

//Ekle :

#ifdef ENABLE_MINI_GAME_FINDM
		case FIND_M_NPC:
			bVnumC = 4;
			break;
#endif

