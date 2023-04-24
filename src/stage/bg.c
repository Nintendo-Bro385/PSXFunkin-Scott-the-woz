/*
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "bg.h"

#include "../archive.h"
#include "../mem.h"
#include "../stage.h"
#include "../random.h"
#include "../timer.h"
#include "../animation.h"

//Week 4 background structure
typedef struct
{
	//Stage background base structure
	StageBack back;
	
	//Textures
	Gfx_Tex tex_back0; //Hallway floor left
	Gfx_Tex tex_back1; //Hallway floor right
	
} Back_Bg;





void Back_Bg_DrawFG(StageBack *back)
{
	Back_Bg *this = (Back_Bg*)back;
	
	fixed_t fx, fy;	        
	
}

void Back_Bg_DrawBG(StageBack *back)
{
	Back_Bg *this = (Back_Bg*)back;
	

	
	fixed_t fx, fy;
	
	
	
	//Draw sunset
	fx = stage.camera.x;
	fy = stage.camera.y;
	
	RECT halll_src = {0, 0, 256, 256};
	RECT_FIXED halll_dst = {
		FIXED_DEC(-165 - SCREEN_WIDEOADD2,1) - fx,
		FIXED_DEC(-140,1) - fy,
		FIXED_DEC(340 + SCREEN_WIDEOADD,1),
		FIXED_DEC(260,1)
	};

	RECT hallr_src = {0, 0, 256, 256};
	RECT_FIXED hallr_dst = {
		FIXED_DEC(173 - SCREEN_WIDEOADD2,1) - fx,
		FIXED_DEC(-140,1) - fy,
		FIXED_DEC(340 + SCREEN_WIDEOADD,1),
		FIXED_DEC(260,1)
	};
	
	Stage_DrawTex(&this->tex_back0, &halll_src, &halll_dst, stage.camera.bzoom);
	Stage_DrawTex(&this->tex_back1, &hallr_src, &hallr_dst, stage.camera.bzoom);
}

void Back_Bg_Free(StageBack *back)
{
	Back_Bg *this = (Back_Bg*)back;
	
	
	//Free structure
	Mem_Free(this);
}

StageBack *Back_Bg_New(void)
{
	//Allocate background structure
	Back_Bg *this = (Back_Bg*)Mem_Alloc(sizeof(Back_Bg));
	if (this == NULL)
		return NULL;
	
	//Set background functions
	this->back.draw_fg = Back_Bg_DrawFG;
	this->back.draw_md = NULL;
	this->back.draw_bg = Back_Bg_DrawBG;
	this->back.free = Back_Bg_Free;
	
	//Load background textures
	IO_Data arc_back = IO_Read("\\SCOTT\\BG.ARC;1");
	Gfx_LoadTex(&this->tex_back0, Archive_Find(arc_back, "back0.tim"), 0);
	Gfx_LoadTex(&this->tex_back1, Archive_Find(arc_back, "back1.tim"), 0);
	Mem_Free(arc_back);

	Gfx_SetClear(0, 0, 0);
	
	
	
	return (StageBack*)this;
}
