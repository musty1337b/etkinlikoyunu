//Arat:

	Set(HEADER_CG_REFINE, sizeof(TPacketCGRefine), "Refine", true);

//Ekle:

#ifdef ENABLE_MINI_GAME_FINDM
	Set(HEADER_CG_MINI_GAME_FIND_M, sizeof(TPacketCGMiniGameFindM), "MiniGameFindM");
#endif