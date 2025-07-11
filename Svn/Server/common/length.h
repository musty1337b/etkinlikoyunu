//Arat (Dosyanın En Altındadır.):

#pragma pack(pop)

// Üstüne Ekle (!!!!):

#ifdef ENABLE_MINI_GAME_FINDM
enum EFindMEventInfo
{
	FIND_M_NPC = 20507,

	FIND_M_PLAY_YANG = 30000,
	FIND_M_DROP_ITEM = 79510,
	FIND_M_PLAY_ITEM = 79511,

	FIND_M_REVEAL_TIME = 10, // Seconds

	FIND_M_REWARD_GOLD = 83033,
	FIND_M_REWARD_SILVER = 83034,
	FIND_M_REWARD_BRONZE = 83035,
	FIND_M_REWARD_VIP = 83040,

	FIND_M_BRONZE_START_COST = 50000, // Start cost after every upgrade multiply by 2
	FIND_M_SILVER_START_COST = 100000,
	FIND_M_GOLD_START_COST = 1000000,

	FIND_M_UPGRADE_CHANCE = 30, // 30%

	FIND_M_DEFAULT_HIT_COUNT = 2,
};
#endif	// ENABLE_MINI_GAME_FINDM