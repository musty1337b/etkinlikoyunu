// Aşağıdakini Yeni Public Olarak Ekleyiniz:

#ifdef ENABLE_MINI_GAME_FINDM
public:
	int MiniGameFindM(LPCHARACTER ch, const char* data, size_t uiBytes);

	void InitializeMiniGameFindM(int iEnable);
	void InitializeMiniGameFindMEndTime(int iEndTime) noexcept { iFindEndTime = iEndTime; }
	void MiniGameFindMCheckEnd();

	void MiniGameFindMStartGame(LPCHARACTER pkChar);
	void MiniGameFindMClickCard(LPCHARACTER pkChar, uint8_t bFieldPos, bool bSkipCheks = false);
	void MiniGameFindMReward(LPCHARACTER pkChar, uint8_t bFlag);
	void MiniGameFindMUpgrade(LPCHARACTER pkChar, uint8_t bFlag);
	int MiniGameFindMPickRandomCard(LPCHARACTER pkChar);
#ifdef ENABLE_MINI_GAME_FINDM_HINT
	void MiniGameFindMStartHint(LPCHARACTER pkChar);
#endif
	void MiniGameFindMRegisterScore(LPCHARACTER pkChar, uint32_t dwSeconds, uint16_t wTry);
	int MiniGameFindMGetScore(lua_State* L, bool isTry);

protected:
	int iFindEndTime;
#endif // ENABLE_MINI_GAME_FINDM