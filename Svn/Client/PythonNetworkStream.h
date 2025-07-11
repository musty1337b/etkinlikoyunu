//Arat:

	bool SendExchangeItemDelPacket(uint8_t pos) const;
	bool SendExchangeAcceptPacket();
	bool SendExchangeExitPacket();

//Ekle:

#ifdef ENABLE_MINI_GAME_FINDM
	bool SendMiniGameFindM(uint8_t bSubHeader, uint8_t bSubArgument);
	bool RecvMiniGameFindMPacket();
#endif
