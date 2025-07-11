//Arat (Aşağıdakini Kolay Bulmanız İçin Verdim):

	HEADER_CG_REFINE							= 96,

//Ekle (Aşağıdaki Sayı Client'den Game Giden Paket Sayıları ile Aynı Olmasın)

#ifdef ENABLE_MINI_GAME_FINDM
	HEADER_CG_MINI_GAME_FIND_M 					= 167, //Client Packet.h ile sayıları aynı olsun.
#endif

//Arat (Aşağıdakini Kolay Bulmanız İçin Verdim)

	HEADER_GC_LOVER_INFO						= 131,

//Ekle (Aşağıdaki Sayı Game'den Client'e Giden Paket Sayıları ile Aynı Olmasın)

#ifdef ENABLE_MINI_GAME_FINDM
	HEADER_GC_MINI_GAME_FIND_M					= 246, //Client Packet.h ile sayıları aynı olsun.
#endif

//En Aşağıya İnin ve #pragma pack(pop) Üstüne Ekleyiniz.

#ifdef ENABLE_MINI_GAME_FINDM
enum
{
	SUBHEADER_GC_FIND_M_START,
	SUBHEADER_GC_FIND_M_RESULT_CLICK,
	SUBHEADER_GC_FIND_M_REWARD,
	SUBHEADER_GC_FIND_M_UPGRADE,
	SUBHEADER_GC_FIND_M_END,
#ifdef ENABLE_MINI_GAME_FINDM_HINT
	SUBHEADER_GC_FIND_M_HINT,
#endif
};

typedef struct SFindMCard
{
	SFindMCard() { wMonster = 0; bIsRevealed = false; }
	SFindMCard(uint16_t monster, bool isRevealed)
	{
		wMonster = monster;
		bIsRevealed = isRevealed;
	}

	uint16_t wMonster;
	bool bIsRevealed;
} TFindMCard;

typedef struct SPacketCGMiniGameFindM {
	uint8_t bHeader;
	uint8_t bSubheader;
	uint8_t bSubArgument;
} TPacketCGMiniGameFindM;

typedef struct SPacketGCMiniGameFindM {
	uint8_t bHeader;
	uint16_t wSize;
	uint8_t bSubheader;
} TPacketGCMiniGameFindM;

typedef struct SPacketGCMiniGameFindMStart {
	uint32_t dwStartTime;
	uint32_t dwNextReveal;
#ifdef ENABLE_MINI_GAME_FINDM_HINT
	uint8_t bHintCount;
#endif
} TPacketGCMiniGameFindMStart;

typedef struct SPacketGCMiniGameFindMUpgrade {
	uint32_t dwRewardVnum;
	uint32_t dwNeedMoney;
} TPacketGCMiniGameFindMUpgrade;

typedef struct SPacketGCMiniGameFindMResult {
	uint8_t bCardIndex;
	uint16_t wMonsterVnum;
	uint8_t bHideRevealed;
	uint32_t dwNextReveal;
	uint16_t wTryCount;
} TPacketGCMiniGameFindMResult;

#ifdef ENABLE_MINI_GAME_FINDM_HINT
typedef struct SPacketGCMiniGameFindMHint {
	uint8_t bHintCount;
	uint32_t dwNextReveal;
	uint16_t wMonsterVnum[27];
} TPacketGCMiniGameFindMHint;
#endif
#endif


