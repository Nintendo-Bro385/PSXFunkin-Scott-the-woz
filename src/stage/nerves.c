/*
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "nerves.h"

#include "../archive.h"
#include "../mem.h"
#include "../stage.h"
#include "../random.h"
#include "../timer.h"
#include "../animation.h"

u8 animation = 0;
	
//Week 4 background structure
typedef struct
{
	//Stage background base structure
	StageBack back;
	
	//Textures
	Gfx_Tex tex_back0; //Hallway floor left
	Gfx_Tex tex_back1; //Hallway floor right
	Gfx_Tex tex_back2;
	Gfx_Tex tex_back3;
	Gfx_Tex tex_back4;
	
} Back_Nerves;

void Back_Nerves_DrawFG(StageBack *back)
{
	Back_Nerves *this = (Back_Nerves*)back;
	
	fixed_t fx, fy;	        
	
}

void Back_Nerves_DrawBG(StageBack *back)
{
	Back_Nerves *this = (Back_Nerves*)back;
	
	fixed_t fx, fy;
	
	//Draw sunset
	fx = stage.camera.x;
	fy = stage.camera.y;
	
	RECT ani1_src = {0, 0, 256, 256};
	RECT_FIXED ani1_dst = {
		FIXED_DEC(-165 - SCREEN_WIDEOADD2,1) - fx,
		FIXED_DEC(-140,1) - fy,
		FIXED_DEC(340 + SCREEN_WIDEOADD,1),
		FIXED_DEC(260,1)
	};

	switch (animation)
	{
		case 0:
			Stage_DrawTex(&this->tex_back0, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 1:
			Stage_DrawTex(&this->tex_back1, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 2:
			Stage_DrawTex(&this->tex_back1, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 3:
			Stage_DrawTex(&this->tex_back1, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 4:
			Stage_DrawTex(&this->tex_back1, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 5:
			Stage_DrawTex(&this->tex_back1, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 6:
			Stage_DrawTex(&this->tex_back1, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 7:
			Stage_DrawTex(&this->tex_back2, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 8:
			Stage_DrawTex(&this->tex_back2, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 9:
			Stage_DrawTex(&this->tex_back2, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 10:
			Stage_DrawTex(&this->tex_back2, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 11:
			Stage_DrawTex(&this->tex_back2, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 12:
			Stage_DrawTex(&this->tex_back2, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 13:
			Stage_DrawTex(&this->tex_back3, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 14:
			Stage_DrawTex(&this->tex_back3, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 15:
			Stage_DrawTex(&this->tex_back3, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 16:
			Stage_DrawTex(&this->tex_back3, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 17:
			Stage_DrawTex(&this->tex_back3, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 18:
			Stage_DrawTex(&this->tex_back3, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 19:
			Stage_DrawTex(&this->tex_back4, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 20:
			Stage_DrawTex(&this->tex_back4, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 21:
			Stage_DrawTex(&this->tex_back4, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 22:
			Stage_DrawTex(&this->tex_back4, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 23:
			Stage_DrawTex(&this->tex_back4, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 24:
			Stage_DrawTex(&this->tex_back4, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 25:
			Stage_DrawTex(&this->tex_back3, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 26:
			Stage_DrawTex(&this->tex_back3, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 27:
			Stage_DrawTex(&this->tex_back3, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 28:
			Stage_DrawTex(&this->tex_back3, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 29:
			Stage_DrawTex(&this->tex_back3, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 30:
			Stage_DrawTex(&this->tex_back3, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 31:
			Stage_DrawTex(&this->tex_back2, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 32:
			Stage_DrawTex(&this->tex_back2, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 33:
			Stage_DrawTex(&this->tex_back2, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 34:
			Stage_DrawTex(&this->tex_back2, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 35:
			Stage_DrawTex(&this->tex_back2, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation++;
			break;
		case 36:
			Stage_DrawTex(&this->tex_back2, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation = 0;
			break;
		default:
			Stage_DrawTex(&this->tex_back0, &ani1_src, &ani1_dst, stage.camera.bzoom);
			animation = 0;
			break;
	}
	
}

void Back_Nerves_Free(StageBack *back)
{
	Back_Nerves *this = (Back_Nerves*)back;
	
	
	//Free structure
	Mem_Free(this);
}

StageBack *Back_Nerves_New(void)
{
	//Allocate background structure
	Back_Nerves *this = (Back_Nerves*)Mem_Alloc(sizeof(Back_Nerves));
	if (this == NULL)
		return NULL;
	
	//Set background functions
	this->back.draw_fg = NULL;
	this->back.draw_md = NULL;
	this->back.draw_bg = Back_Nerves_DrawBG;
	this->back.free = Back_Nerves_Free;
	
	//Load background textures
	IO_Data arc_back = IO_Read("\\NERVES\\GOSHA.ARC;1");
	Gfx_LoadTex(&this->tex_back0, Archive_Find(arc_back, "back0.tim"), 0);
	Gfx_LoadTex(&this->tex_back1, Archive_Find(arc_back, "back1.tim"), 0);
	Gfx_LoadTex(&this->tex_back2, Archive_Find(arc_back, "back2.tim"), 0);
	Gfx_LoadTex(&this->tex_back3, Archive_Find(arc_back, "back3.tim"), 0);
	Gfx_LoadTex(&this->tex_back4, Archive_Find(arc_back, "back4.tim"), 0);
	Mem_Free(arc_back);

	Gfx_SetClear(34, 52, 123);
	
	return (StageBack*)this;
}
