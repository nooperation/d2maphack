Patch_t aKeepGameWindowPatchs[] = {
	// 0x4938: push SW_MINIMIZE; push ecx; call edi;
	{PatchFILL,   D2GFX_KeepD2WindowPatch1,   4, 1, -1}, // SW_MINIMIZE

	// 0x4917: push SW_MINIMIZE; push ecx; call edi;
	{PatchFILL,   D2GFX_KeepD2WindowPatch2,   4, 1, -1}, // SW_MINIMIZE

	// 0x4978: push SW_HIDE; push edx; call ebp;
	{PatchFILL,   D2GFX_KeepD2WindowPatch3,   4, 1, -1}, // SW_HIDE
};

//static BYTE aCellAssertPatch1[] = {0x33,0xc0, 0x5f, 0xeb,0x41}; //xor eax,eax; pop edi; jmp +0x41
//static BYTE aCellAssertPatch2[] = {0xeb, 0x03}; //jmp +0x03
//Patch_t aKillCellAssertPatchs[] = {
//	{PatchDATA,   DLLOFFSET(D2CMP, DLLBASE_D2CMP+0x2587),   (DWORD)aCellAssertPatch1, sizeof(aCellAssertPatch1), -1}, // KillCellAssert
//	{PatchDATA,   DLLOFFSET(D2CMP, DLLBASE_D2CMP+0xBD7A),   (DWORD)aCellAssertPatch2, sizeof(aCellAssertPatch2), -1}, // KillCellAssert
//};

Patch_t aPacketRecvPatchs[] = {
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x1511A),   (DWORD)GamePacketReceivedInterceptPatch_ASM, 9, -1},
};

Patch_t aD2Patchs2[] = {
	{PatchCALL,   DLLOFFSET(D2MULTI, DLLBASE_D2MULTI+0xF77B),   (DWORD)NextGameNamePatch, 5, -1},
	{PatchCALL,   DLLOFFSET(D2MULTI, DLLBASE_D2MULTI+0xF7B6),   (DWORD)NextGamePasswordPatch, 5, -1},
	{PatchCALL,   DLLOFFSET(D2MULTI, DLLBASE_D2MULTI+0x10567),   (DWORD)NextGameNamePatch, 5, -1},
	{PatchCALL,   DLLOFFSET(D2MULTI, DLLBASE_D2MULTI+0x105A2),   (DWORD)NextGamePasswordPatch, 5, -1},
};

Patch_t aD2LocalePatchs2[] = {
	// Locale
	{PatchCALL,   DLLOFFSET(D2MULTI, DLLBASE_D2MULTI+0x6143),   (DWORD)EnterChatPatch, 5, -1},
};

Patch_t aD2Patchs[] = {
	{PatchFILL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2D1CC),   INST_NOP, 2, -1}, //floors inside
	{PatchFILL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2D210),   INST_NOP, 2, -1}, //walls inside
	{PatchFILL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2D270),   INST_NOP, 6, -1}, //shrine distance

	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2CD82),   (DWORD)OverrideShrinePatch_ASM, 7, 0xffffffff},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2D2C2),   (DWORD)AddShrinePatch_ASM, 6, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2E4E0),   (DWORD)DrawAutomapCellPatch, 5, -1},
	{PatchJMP,    DLLOFFSET(D2COMMON, DLLBASE_D2COMMON+0x2041A),   (DWORD)WeatherPatch_ASM, 5, -1},

	// not found yet
//	{PatchJMP,    DLLOFFSET(D2COMMON, 0x6FD6623F),   (DWORD)LosDrawPatch_ASM, 5, -1}, // not exist
	// end

	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x19FE1),   (DWORD)LightingPatch_ASM, 8, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x96C0),   (DWORD)ShakeScreenPatch, 5, -1},
	{PatchFILL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x172BD),   INST_NOP, 2, 0xffffffff}, //force perspective shake
	{PatchVALUE,  DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x17EB7),   INST_JMPR, 1, -1}, //force get shake
	{PatchFILL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x17DA0),   INST_NOP, 14, -1}, //kill add shake
	{PatchFILL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2B6A0),   INST_NOP, 0x37, 0xffffffff}, //kill automap scroll

	{PatchCALL,   DLLOFFSET(D2WIN,    DLLBASE_D2WIN+0xA865),   (DWORD)LifeBarPatch_ASM, 5, -1},

	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x3E7DC),   (DWORD)ItemNamePatch_ASM, 5, -1},
	{PatchVALUE,  DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x80844),   0xe990, 2, -1}, //kill ground gold name
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x43B90),   (DWORD)OpenCubeStringPatch, 5, -1},

	// new
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0xADBFD),   (DWORD)InfravisionPatch_ASM, 0x44, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2EC1A),   (DWORD)HostilePlayerColor_ASM, 5, -1},
	// end

	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2E6D6),   (DWORD)MonsterBlobNamePatch_ASM, 5, -1},
	{PatchJMP,  DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2EB79),   (DWORD)MonsterBlobColPatch_ASM, 5, -1},
	
	// not found yet
//	{PatchCALL,   DLLOFFSET(D2CLIENT, 0x6FB4BAEC),   (DWORD)HideItemsPatch_ASM, 6, -1},
//	{PatchVALUE,  DLLOFFSET(D2CLIENT, 0x6FAC88B0),   (DWORD)MonsterBlobColPatch_ASM, 4, 0xffff},
//	{PatchVALUE,  DLLOFFSET(D2CLIENT, 0x6FAC88BC),   (DWORD)MonsterBlobColPatch_ASM, 4, 0xffff},
//	{PatchCALL,   DLLOFFSET(D2CLIENT, 0x6FAC8795),   (DWORD)MonsterDieingPatch_ASM, 5, -1},
//	{PatchCALL,   DLLOFFSET(D2CLIENT, 0x6FAC889C),   (DWORD)PlayerBlobColPatch_ASM, 6, 0xffffffff},
//	{PatchCALL,   DLLOFFSET(D2CLIENT, 0x6FAC86FA),   (DWORD)MixedBlobColPatch_ASM, 6, -1},
	// end

	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2E6A5),   (DWORD)DrawObjectBlobPatch, 5, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2E818),   (DWORD)DrawPlayerBlobPatch, 5, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2E6B8),   (DWORD)DrawMonsterBlobPatch_ASM, 5, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2E631),   (DWORD)DrawItemBlobPatch_ASM, 6, -1},
	{PatchCALL2,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2EE2A),   (DWORD)DrawPlayerBlobPatch2_ASM, 0x3B, -1},

	// new
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2DEC7),   (DWORD)RoomPatch_ASM, 6, -1},
	// end

	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0xA54AB),   (DWORD)MonsterDeathPatch_ASM, 5, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0xA6326),   (DWORD)MonsterDescCommaPatch1_ASM, 5, 0xffffff},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0xA63FC),   (DWORD)MonsterDescCommaPatch2_ASM, 5, 0xffffff},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x8105B),   (DWORD)MonsterDescCommaPatch3_ASM, 6, 0xffffff},
	
	// new
	{PatchCALL,   DLLOFFSET(D2WIN, DLLBASE_D2WIN+0xAC60),   (DWORD)MonsterLifebarNamePatch_ASM, 6, -1},
	{PatchCALL,   DLLOFFSET(D2WIN, DLLBASE_D2WIN+0xACD0),   (DWORD)MonsterLifebarNamePatch_ASM, 6, -1},
	// end


	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x40144),   (DWORD)ViewInventoryPatch1, 5, -1}, //draw equip items
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x40109),   (DWORD)GetViewingInventoryPlayer, 5, -1}, //draw inv items
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x482CE),   (DWORD)GetViewingInventoryPlayer, 5, -1}, //desc item
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x41EFF),   (DWORD)ViewInventoryPatch3_ASM, 5, -1}, //test has item

	
	// new added by sting
	// stats
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2FD6A),   (DWORD)GetViewingStatsPlayer, 5, -1}, //draw inv items
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x30248),   (DWORD)GetViewingStatsPlayer, 5, -1}, //draw inv items
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x30729),   (DWORD)GetViewingStatsPlayer, 5, -1}, //draw inv items
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x30A95),   (DWORD)GetViewingStatsPlayer, 5, -1}, //draw inv items
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0xADA8E),   (DWORD)GetViewingStatsPlayer, 5, -1}, //draw inv items
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x310E7),   (DWORD)GetViewingStatsPlayer, 5, -1}, //draw inv items

	//skill
/*	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x76C07),   (DWORD)GetViewingSkillsPlayer, 5, -1}, //draw inv items
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x763B7),   (DWORD)GetViewingSkillsPlayer, 5, -1}, //draw inv items
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x76416),   (DWORD)GetViewingSkillsPlayer, 5, -1}, //draw inv items
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x76A57),   (DWORD)GetViewingSkillsPlayer, 5, -1}, //draw inv items
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x768AF),   (DWORD)GetViewingSkillsPlayer, 5, -1}, //draw inv items
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x76967),   (DWORD)GetViewingSkillsPlayer, 5, -1}, //draw inv items
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x76981),   (DWORD)GetViewingSkillsPlayer, 5, -1}, //draw inv items
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x76A08),   (DWORD)GetViewingSkillsPlayer, 5, -1}, //draw inv items

	// pet
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x4D5E8),   (DWORD)GetViewingPet, 5, -1}, //draw inv items
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x4D317),   (DWORD)GetViewingPet, 5, -1}, //draw inv items
*/	// end


	// new
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x47116),   (DWORD)ViewInventoryPatch4_ASM, 5, -1}, //test has item
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x41890),   (DWORD)SocketViewtablePatch_ASM, 5, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x4302E),   (DWORD)SocketViewtablePatch2_ASM, 5, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x51CBF),   (DWORD)ItemBasicStatPatch_ASM, 5, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0xA9920),   (DWORD)OutTownSelectPatch1_ASM, 5, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x8875A),   (DWORD)OutTownSelectPatch2_ASM, 6, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x88874),   (DWORD)OutTownSelectPatch3_ASM, 6, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x471AD),   (DWORD)SocketProtectPatch1_ASM, 6, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x47BEC),   (DWORD)SocketProtectPatch2_ASM, 6, -1},
	// end

	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x64C27),   (DWORD)CowLevelQuestPatch_ASM, 6, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x80B91),   (DWORD)PermShowItemsPatch_ASM, 6, 0xffffffff},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x820D1),   (DWORD)PermShowItemsPatch_ASM, 6, 0xffffff},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x88A27),   (DWORD)PermShowItemsPatch_ASM, 5, -1},

	// new
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x7F9B3),   (DWORD)UnknownPatch5, 5, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x7C496),   (DWORD)UnknownPatch6, 5, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2E21F),   (DWORD)GameTimePatch, 5, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x328BC),   (DWORD)InputLinePatch_ASM, 5, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x323BF),   (DWORD)InputLinePatch2_ASM, 5, -1},
	{PatchVALUE,  DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x36316), 0x2EB58, 3, -1},
	{PatchVALUE,  DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x363D6), 0x2EB58, 3, -1},
	// end


	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x9640),   (DWORD)GameLoopPatch_ASM, 6, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0xB528),   (DWORD)GameEndPatch_ASM, 5, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x35A07),   (DWORD)KeydownPatch_ASM, 7, -1},
	{PatchVALUE,  DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x33430), (DWORD)"<KittyNet>: Correct usage is: %s", 4, 0xffff},
	{PatchVALUE,  DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x33599), (DWORD)"<KittyNet>: Correct usage is: %s (name) (message)", 4, 0xffff},
	
	// new
	{PatchJMP,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x30F8A),   (DWORD)ViewPlayerStatPatch_ASM, 6, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x5F102),   (DWORD)PermShowOrbPatch_ASM, 5, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x5F1E6),   (DWORD)PermShowOrbPatch2_ASM, 0x0B, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x5F1F1),   (DWORD)PermShowOrbPatch3_ASM, 6, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x5E6F8),   (DWORD)GameTimeClockPatch_ASM, 5, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x5F02C),   (DWORD)GameTimeClockPatch2_ASM, 6, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x7C64C),   (DWORD)MessageLogPatch1_ASM, 5, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x7C969),   (DWORD)MessageLogPatch2_ASM, 5, -1},
	// end

	// not exist
//	{PatchVALUE,  DLLOFFSET(D2CLIENT, 0x6FACC77E+1), (DWORD)"<MouseNet>: ", 4, 0xffff},
	// end


	// new features, added by sting
	{NULL,   D2CLIENT_InitAutomapLayer_END,   1, 1, -1},

	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0xB6D82),   (DWORD)PassingActBugFixPatch_ASM, 6, -1}, //draw inv items
	{PatchFILL,   DLLOFFSET(D2WIN, DLLBASE_D2WIN+0x7424), INST_JMPR, 1, -1}, // copy&paste bugfix
	// 0x33, 0x4A for detection request?

	// new for 64/65 antidetection
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0xAF369),   (DWORD)AntiDetectionPatch64_1_ASM, 5, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0xAF3A6),	(DWORD)AntiDetectionPatch64_2_ASM, 5, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0xB27F7),   (DWORD)AntiDetectionPatch65_1_ASM, 12, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0xB282F),   (DWORD)AntiDetectionPatch65_2_ASM, 5, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0xB2839),   (DWORD)AntiDetectionPatch65_3_ASM, 5, -1},

	// extrawork dll protection
	{PatchCALL,   DLLOFFSET(BNCLIENT, DLLBASE_BNCLIENT+0x45AB),   (DWORD)VersionCheckingPatch_ASM, 6, -1}, // Version Check Dll
	{PatchCALL,   DLLOFFSET(BNCLIENT, DLLBASE_BNCLIENT+0x390B),   (DWORD)ExtraWorkPatch_ASM, 6, -1}, // Extra Work Dll

	// right click swap
//	{PatchVALUE,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0xD5844),   (DWORD)RButtonUpHandlerPatch, 4, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x8E90),   (DWORD)RButtonUpHandlerPatch_ASM, 10, -1},
//	{PatchVALUE,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0xEEB9C),   (DWORD)LButtonDownHandlerPatch, 4, -1},

	// Patch locations in mousepad's maphack 6.1c (not exist in hackmap) for 1.10
//	{PatchCALL,   DLLOFFSET(D2MULTI, DLLBASE_D2MULTI+0x6143),   (DWORD)ExtraWorkPatch_ASM, 6, -1}, // Extra Work Dll
//	{PatchCALL,   DLLOFFSET(D2MULTI, DLLBASE_D2MULTI+0xF77B),   (DWORD)ExtraWorkPatch_ASM, 6, -1}, // Extra Work Dll
//	{PatchCALL,   DLLOFFSET(D2MULTI, DLLBASE_D2MULTI+0x10567),   (DWORD)ExtraWorkPatch_ASM, 6, -1}, // Extra Work Dll

//	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2597),   (DWORD)AntiDetectionPatch65_3_ASM, 5, -1},
//	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2DEE5),   (DWORD)AntiDetectionPatch65_3_ASM, 5, -1},
//	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2E1F6),   (DWORD)AntiDetectionPatch65_3_ASM, 5, -1},
//	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x2E20F),   (DWORD)AntiDetectionPatch65_3_ASM, 5, -1},
//	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x602C0),   (DWORD)AntiDetectionPatch65_3_ASM, 5, -1},
//	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x80D10),   (DWORD)AntiDetectionPatch65_3_ASM, 5, -1},
//	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x871A1),   (DWORD)AntiDetectionPatch65_3_ASM, 5, -1},
//	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0xA773C),   (DWORD)AntiDetectionPatch65_3_ASM, 5, -1},
// == InfravisionPatch
//	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0xADC01),   (DWORD)InfravisionPatch_ASM, 5, -1},
// ANTI 64
//	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0xAF33A),   (DWORD)AntiDetectionPatch65_3_ASM, 5, -1},
// ANTI 65
//	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0xB282A),   (DWORD)AntiDetectionPatch65_3_ASM, 5, -1},
// anti dll checking
//	{PatchCALL,   DLLOFFSET(BNCLIENT, DLLBASE_BNCLIENT+0x38EB),   (DWORD)ExtraWorkPatch_ASM, 6, -1}, // Version Check Dll
//	{PatchCALL,   DLLOFFSET(BNCLIENT, DLLBASE_BNCLIENT+0x4588),   (DWORD)ExtraWorkPatch_ASM, 6, -1}, // Version Check Dll
};

Patch_t aD2LocalePatchs[] = {
	{PatchFILL,   DLLOFFSET(D2WIN, DLLBASE_D2WIN+0xA0DD), INST_JMPR, 1, -1},
	{PatchFILL,   DLLOFFSET(D2WIN, DLLBASE_D2WIN+0xA0CE), INST_NOP, 2, -1},
	{PatchCALL,   DLLOFFSET(D2WIN, DLLBASE_D2WIN+0xAD69),   (DWORD)D2LocaleChannelChat, 5, -1},
	{PatchCALL,   DLLOFFSET(D2WIN, DLLBASE_D2WIN+0x9F62),   (DWORD)D2Win_Patch2, 5, -1},
	{PatchCALL,   DLLOFFSET(D2WIN, DLLBASE_D2WIN+0xA04D),   (DWORD)D2Win_Patch3, 5, -1},
	{PatchCALL,   DLLOFFSET(D2WIN, DLLBASE_D2WIN+0x9CE7),   (DWORD)D2Win_Patch3, 5, -1},
	{PatchCALL,   DLLOFFSET(D2WIN, DLLBASE_D2WIN+0xDAB0),   (DWORD)ChannelEnterCharPatch, 5, -1},
//	{PatchCALL,   DLLOFFSET(D2WIN, DLLBASE_D2WIN+0xDB80),   (DWORD)ChannelEnterCharPatch2, 5, -1},
	{PatchJMP,   DLLOFFSET(D2LANG, DLLBASE_D2LANG+0x1BD0),   (DWORD)D2Lang_Win2Unicode, 5, -1},
	{PatchJMP,   DLLOFFSET(D2LANG, DLLBASE_D2LANG+0x1C20),   (DWORD)D2Lang_Unicode2Win, 5, -1},
	{PatchJMP,   DLLOFFSET(D2LANG, DLLBASE_D2LANG+0x1B30),   (DWORD)D2Lang_Utf82Unicode, 5, -1},
	{PatchFILL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x7E1B4), INST_JMPR, 1, -1},
	{PatchCALL,   DLLOFFSET(D2CLIENT, DLLBASE_D2CLIENT+0x32995),   (DWORD)D2LocaleGameChat, 5, -1},
	{PatchCALL,   DLLOFFSET(D2WIN, DLLBASE_D2WIN+0xB2F0),   (DWORD)IsPritableCharacterPatch_ASM, 5, -1},
	{PatchCALL,   DLLOFFSET(BNCLIENT, DLLBASE_BNCLIENT+0x63B6),   (DWORD)D2MultiByteFixPatch_ASM, 6, -1}, // Version Check Dll
};

PatchItem_t aD2PatchItems[] = {
	{aD2Patchs, ARRAYSIZE(aD2Patchs)},
	{aKeepGameWindowPatchs, ARRAYSIZE(aKeepGameWindowPatchs), 1},
	{aPacketRecvPatchs, ARRAYSIZE(aPacketRecvPatchs), 1},
	{aD2LocalePatchs, ARRAYSIZE(aD2LocalePatchs), 1},
//	{aD2Patchs2, ARRAYSIZE(aD2Patchs2), 1},
//	{aD2LocalePatchs2, ARRAYSIZE(aD2LocalePatchs2), 1},
//	{aKillCellAssertPatchs, ARRAYSIZE(aKillCellAssertPatchs)},
};

//void KillCellAssert()
//{
//	static BYTE data1[] = {0x33,0xc0, 0x5f, 0xeb,0x41}; //xor eax,eax; pop edi; jmp +0x41
//	WriteLocalBYTES(GetDllOffset(DLLOFFSET(D2CMP, DLLBASE_D2CMP+0x2587)), data1, sizeof(data1));
//	static BYTE data2[] = {0xeb,0x03}; //jmp +0x03
//	WriteLocalBYTES(GetDllOffset(DLLOFFSET(D2CMP, DLLBASE_D2CMP+0xBD7A)), data2, sizeof(data2));
//}

