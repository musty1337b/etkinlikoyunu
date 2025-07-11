//Arat:

		Set(HEADER_GC_DRAGON_SOUL_REFINE, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCDragonSoulRefine), STATIC_SIZE_PACKET));

//Ekle:

#ifdef ENABLE_MINI_GAME_FINDM
		Set(HEADER_GC_MINI_GAME_FIND_M, CNetworkPacketHeaderMap::TPacketType(sizeof(TPacketGCMiniGameFindM), DYNAMIC_SIZE_PACKET));
#endif

