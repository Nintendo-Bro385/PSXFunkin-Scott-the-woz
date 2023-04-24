	{ //StageId_1_1 (Bopeebo)
		//Characters
		{Char_BF_New,    FIXED_DEC(310,1),  FIXED_DEC(100,1)},
		{Char_Scott_New, FIXED_DEC(55,1),  FIXED_DEC(75,1)},
		{Char_GFS_New,     FIXED_DEC(100,1),  FIXED_DEC(-15,1)},
		
		//Stage background
		Back_Bg_New,
		
		//Song info
		{FIXED_DEC(15,10),FIXED_DEC(18,10),FIXED_DEC(23,10)},
		1, 1,
		XA_Bopeebo, 0,
		
		StageId_1_2, STAGE_LOAD_FLAG
	},
	{ //StageId_1_2 (Fresh)
		//Characters
		{Char_BF_New,    FIXED_DEC(310,1),  FIXED_DEC(100,1)},
		{Char_Scott_New, FIXED_DEC(55,1),  FIXED_DEC(75,1)},
		{Char_GFS_New,     FIXED_DEC(100,1),  FIXED_DEC(-15,1)},
		
		//Stage background
		Back_Bg_New,
		
		//Song info
		{FIXED_DEC(18,10),FIXED_DEC(2,1),FIXED_DEC(25,10)},
		1, 2,
		XA_Fresh, 2,
		
		StageId_1_3, STAGE_LOAD_FLAG
	},
	{ //StageId_1_3 (Dadbattle)
		//Characters
		{Char_BF_New,    FIXED_DEC(310,1),  FIXED_DEC(100,1)},
		{Char_Scott_New, FIXED_DEC(55,1),  FIXED_DEC(75,1)},
		{Char_GFS_New,     FIXED_DEC(100,1),  FIXED_DEC(-15,1)},
		
		//Stage background
		Back_Bg_New,
		
		//Song info
		{FIXED_DEC(22,10),FIXED_DEC(26,10),FIXED_DEC(29,10)},
		1, 3,
		XA_Dadbattle, 0,
		
		StageId_2_1, STAGE_LOAD_FLAG | STAGE_LOAD_PLAYER | STAGE_LOAD_OPPONENT | STAGE_LOAD_GIRLFRIEND
	},
	{ //StageId_1_4 (Tutorial)
		//Characters
		{Char_BF_New, FIXED_DEC(60,1),  FIXED_DEC(100,1)},
		{Char_GF_New,  FIXED_DEC(0,1),  FIXED_DEC(-15,1)}, //TODO
		{NULL,           FIXED_DEC(0,1),  FIXED_DEC(-10,1)},
		
		//Stage background
		Back_Week1_New,
		
		//Song info
		{FIXED_DEC(1,1),FIXED_DEC(1,1),FIXED_DEC(1,1)},
		1, 4,
		XA_Tutorial, 2,
		
		StageId_1_4, 0
	},
	
	{ //StageId_2_1 (Spookeez)
		//Characters
		{Char_BF_New,    FIXED_DEC(100,1),  FIXED_DEC(100,1)},
		{Char_Scottn_New, FIXED_DEC(-80,1),  FIXED_DEC(85,1)},
		{Char_GF_New,     FIXED_DEC(20,1),  FIXED_DEC(-15,1)},
		
		//Stage background
		Back_Nerves_New,
		
		//Song info
		{FIXED_DEC(25,10),FIXED_DEC(28,10),FIXED_DEC(31,10)},
		2, 1,
		XA_Spookeez, 0,
		
		StageId_2_1, 0
	},
	{ //StageId_2_2 (South)
		//Characters
		{Char_BF_New,      FIXED_DEC(56,1),   FIXED_DEC(85,1)},
		{Char_Scott_New,  FIXED_DEC(-90,1),   FIXED_DEC(85,1)},
		{Char_GF_New,       FIXED_DEC(0,1),  FIXED_DEC(-15,1)},
		
		//Stage background
		Back_Bg_New,
		
		//Song info
		{FIXED_DEC(25,10),FIXED_DEC(25,10),FIXED_DEC(25,10)},
		2, 2,
		XA_South, 2,
		
		StageId_2_3, STAGE_LOAD_FLAG | STAGE_LOAD_OPPONENT
	},
	
	{ //StageId_Kapi_1 (Wocky)
		//Characters
		{Char_BF_New,   FIXED_DEC(105,1),  FIXED_DEC(100,1)},
		{Char_Dad_New, FIXED_DEC(-120,1),  FIXED_DEC(100,1)},
		{Char_GF_New,     FIXED_DEC(0,1),    FIXED_DEC(0,1)},
		
		//Stage background
		Back_Dummy_New,
		
		//Song info
		{FIXED_DEC(22,10),FIXED_DEC(22,10),FIXED_DEC(22,10)},
		0x80, 1,
		XA_Wocky, 0,
		
		StageId_Kapi_2, STAGE_LOAD_FLAG
	},
	{ //StageId_Kapi_2 (Beathoven)
		//Characters
		{Char_BF_New,   FIXED_DEC(105,1),  FIXED_DEC(100,1)},
		{Char_Dad_New, FIXED_DEC(-120,1),  FIXED_DEC(100,1)},
		{Char_GF_New,     FIXED_DEC(0,1),  FIXED_DEC(-15,1)},
		
		//Stage background
		Back_Dummy_New,
		
		//Song info
		{FIXED_DEC(21,10),FIXED_DEC(21,10),FIXED_DEC(21,10)},
		0x80, 2,
		XA_Beathoven, 2,
		
		StageId_Kapi_3, STAGE_LOAD_FLAG
	},
	{ //StageId_Kapi_3 (Hairball)
		//Characters
		{Char_BF_New,   FIXED_DEC(105,1),  FIXED_DEC(100,1)},
		{Char_Dad_New, FIXED_DEC(-120,1),  FIXED_DEC(100,1)},
		{Char_GF_New,     FIXED_DEC(0,1),  FIXED_DEC(-15,1)},
		
		//Stage background
		Back_Dummy_New,
		
		//Song info
		{FIXED_DEC(19,10),FIXED_DEC(19,10),FIXED_DEC(19,10)},
		0x80, 3,
		XA_Hairball, 0,
		
		StageId_Kapi_4, STAGE_LOAD_FLAG
	},
	{ //StageId_Kapi_4 (Nyaw)
		//Characters
		{Char_BF_New,   FIXED_DEC(105,1),  FIXED_DEC(100,1)},
		{Char_Dad_New, FIXED_DEC(-120,1),  FIXED_DEC(100,1)},
		{Char_GF_New,     FIXED_DEC(0,1),  FIXED_DEC(-15,1)},
		
		//Stage background
		Back_Dummy_New,
		
		//Song info
		{FIXED_DEC(25,10),FIXED_DEC(25,10),FIXED_DEC(25,10)},
		0x80, 4,
		XA_Nyaw, 2,
		
		StageId_Kapi_4, 0
	},
	
	{ //StageId_Clwn_1 (Improbable Outset)
		//Characters
		{Char_BF_New,    FIXED_DEC(105,1),  FIXED_DEC(100,1)},
		{Char_Tank_New, FIXED_DEC(-120,1),  FIXED_DEC(100,1)},
		{Char_GF_New,      FIXED_DEC(0,1),  FIXED_DEC(-15,1)},
		
		//Stage background
		Back_Dummy_New,
		
		//Song info
		{FIXED_DEC(2,1),FIXED_DEC(25,10),FIXED_DEC(3,1)},
		0x81, 1,
		XA_ImprobableOutset, 0,
		
		StageId_Clwn_2, STAGE_LOAD_FLAG | STAGE_LOAD_OPPONENT
	},
	{ //StageId_Clwn_2 (Madness)
		//Characters
		{Char_BF_New,    FIXED_DEC(105,1),  FIXED_DEC(100,1)},
		{Char_Tank_New, FIXED_DEC(-120,1),  FIXED_DEC(100,1)},
		{Char_GF_New,      FIXED_DEC(0,1),  FIXED_DEC(-15,1)},
		
		//Stage background
		Back_Dummy_New,
		
		//Song info
		{FIXED_DEC(2,1),FIXED_DEC(25,10),FIXED_DEC(3,1)},
		0x81, 2,
		XA_Madness, 2,
		
		StageId_Clwn_3, 0
	},
	{ //StageId_Clwn_3 (Hellclown)
		//Characters
		{Char_BF_New,    FIXED_DEC(105,1),  FIXED_DEC(100,1)},
		{Char_Tank_New, FIXED_DEC(-120,1),  FIXED_DEC(100,1)},
		{Char_GF_New,      FIXED_DEC(0,1),  FIXED_DEC(-15,1)},
		
		//Stage background
		Back_Dummy_New,
		
		//Song info
		{FIXED_DEC(2,1),FIXED_DEC(25,10),FIXED_DEC(3,1)},
		0x81, 3,
		XA_Hellclown, 0,
		
		StageId_Clwn_3, 0
	},
	{ //StageId_Clwn_4 (Expurgation)
		//Characters
		{Char_BF_New,    FIXED_DEC(105,1),  FIXED_DEC(100,1)},
		{Char_Tank_New, FIXED_DEC(-120,1),  FIXED_DEC(100,1)},
		{Char_GF_New,      FIXED_DEC(0,1),  FIXED_DEC(-15,1)},
		
		//Stage background
		Back_Dummy_New,
		
		//Song info
		{FIXED_DEC(34,10),FIXED_DEC(34,10),FIXED_DEC(34,10)},
		0x81, 4,
		XA_Expurgation, 2,
		
		StageId_Clwn_4, 0
	},
	{ //StageId_2_4 (Clucked)
		//Characters
		{Char_BF_New,       FIXED_DEC(60,1),  FIXED_DEC(100,1)},
		{Char_Clucky_New, FIXED_DEC(-120,1),  FIXED_DEC(100,1)},
		{Char_GF_New,        FIXED_DEC(0,1),    FIXED_DEC(0,1)},
		
		//Stage background
		Back_Week1_New,
		
		//Song info
		{FIXED_DEC(25,10),FIXED_DEC(25,10),FIXED_DEC(25,10)},
		2, 4,
		XA_Clucked, 2,
		
		StageId_2_4, 0
	},
