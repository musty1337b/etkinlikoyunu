//Arat:

			case HEADER_GC_DRAGON_SOUL_REFINE:
				ret = RecvDragonSoulRefine();
				break;

//Ekle :

#ifdef ENABLE_MINI_GAME_FINDM
			case HEADER_GC_MINI_GAME_FIND_M:
				ret = RecvMiniGameFindMPacket();
				break;
#endif


//Bunu da En Altlara Ekle :

#ifdef ENABLE_MINI_GAME_FINDM
bool CPythonNetworkStream::SendMiniGameFindM(uint8_t bSubHeader, uint8_t bSubArgument)
{
	if (!__CanActMainInstance())
		return true;
	
	TPacketCGMiniGameFindM packet;
	packet.bHeader = HEADER_CG_MINI_GAME_FIND_M;
	packet.bSubheader = bSubHeader;
	packet.bSubArgument = bSubArgument;

	if (!Send(sizeof(TPacketCGMiniGameFindM), &packet))
	{
		Tracef("SendMiniGameFindM Send Packet Error\n");
		return false;
	}

	return true;
}

bool CPythonNetworkStream::RecvMiniGameFindMPacket()
{
	std::vector<char> vecBuffer;
	vecBuffer.clear();

    TPacketGCMiniGameFindM packet;
	if (!Recv(sizeof(packet), &packet))
		return false;

	int iSize = packet.wSize - sizeof(packet);
	if (iSize > 0)
	{
		vecBuffer.resize(iSize);
		if (!Recv(iSize, &vecBuffer[0]))
			return false;
	}

	switch (packet.bSubheader)
	{		
		case SUBHEADER_GC_FIND_M_START:
			{
				TPacketGCMiniGameFindMStart * packSecond = (TPacketGCMiniGameFindMStart *)&vecBuffer[0];

				PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "MiniGameFindMEventStart", Py_BuildValue("(ii)", 
								packSecond->dwStartTime, packSecond->dwNextReveal));
								
#ifdef ENABLE_MINI_GAME_FINDM_HINT
				PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "MiniGameFindMHintCount", Py_BuildValue("(i)", packSecond->bHintCount));
#endif
			}
			break;
			
		case SUBHEADER_GC_FIND_M_RESULT_CLICK:
			{
				TPacketGCMiniGameFindMResult * packSecond = (TPacketGCMiniGameFindMResult *)&vecBuffer[0];
				PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "MiniGameFindMClickCard", Py_BuildValue("(iiiii)", 
								packSecond->bCardIndex, packSecond->wMonsterVnum, packSecond->bHideRevealed, packSecond->dwNextReveal, packSecond->wTryCount));
			}
			break;
			
		case SUBHEADER_GC_FIND_M_REWARD:
			{
				uint32_t dwRewardVnum = *(uint32_t*)&vecBuffer[0];
				PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "MiniGameFindMReward", Py_BuildValue("(i)", dwRewardVnum));
			}
			break;
			
		case SUBHEADER_GC_FIND_M_UPGRADE:
			{
				TPacketGCMiniGameFindMUpgrade * packSecond = (TPacketGCMiniGameFindMUpgrade *)&vecBuffer[0];
				PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "MiniGameFindMUpgrade", Py_BuildValue("(ii)", 
								packSecond->dwRewardVnum, packSecond->dwNeedMoney));
			}
			break;
			
		case SUBHEADER_GC_FIND_M_END:
			{
				PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "MiniGameFindMGameEnd", Py_BuildValue("()"));
			}
			break;	
			
#ifdef ENABLE_MINI_GAME_FINDM_HINT
		case SUBHEADER_GC_FIND_M_HINT:
			{
				TPacketGCMiniGameFindMHint * packSecond = (TPacketGCMiniGameFindMHint *)&vecBuffer[0];
				
				PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "MiniGameFindMHintCount", Py_BuildValue("(ii)", 
									packSecond->bHintCount, packSecond->dwNextReveal));
				
				for(int i = 0; i < 27; i++)
				{
					PyCallClassMemberFunc(m_apoPhaseWnd[PHASE_WINDOW_GAME], "MiniGameFindMHint", Py_BuildValue("(ii)", 
									i, packSecond->wMonsterVnum[i]));
				}
			}
			break;
#endif	
			
		default:
			TraceError("CPythonNetworkStream::RecvMiniGameFindMPacket: Unknown subheader\n");
			break;
	}

	return true;
}
#endif