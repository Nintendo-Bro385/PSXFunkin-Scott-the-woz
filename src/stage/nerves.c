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

u8 animation;

u8 background;
	
//Week 4 background structure
typedef struct
{
	//Stage background base structure
	StageBack back;
	
	//textures
	IO_Data arc_back, arc_back_ptr[5];

	Gfx_Tex tex_back;
	u8 back_frame, back_tex_id;
	
	Animatable back_animatable;
	
} Back_Nerves;

//fire frame data
static const CharFrame back_frame[5] = {
	{0, {  0,   0, 256,256}, {0,0}},
	{1, {  0,   0, 256,256}, {0,0}},
	{2, {  0,   0, 256,256}, {0,0}},
	{3, {  0,   0, 256,256}, {0,0}},
	{4, {  0,   0, 256,256}, {0,0}},
};
/*void Back_Nerves_DrawFG(StageBack *back)
{
	Back_Nerves *this = (Back_Nerves*)back;
	
	fixed_t fx, fy;	        
	
}*/

//fire animation
static const Animation back_anim[1] = {
	{1, (const u8[]){0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 3, 3, 3, 2, 2, 2, 1, 1, 1, 0, 0, 0,  ASCR_REPEAT}}, //play frames, then repeat
};

//FireL functions
void Nerves_back_SetFrame(void *user, u8 frame)
{
	Back_Nerves *this = (Back_Nerves*)user;
	
	//Check if this is a new frame
	if (frame != this->back_frame)
	{
		//Check if new art shall be loaded
		const CharFrame *cframe = &back_frame[this->back_frame = frame];
		if (cframe->tex != this->back_tex_id)
			Gfx_LoadTex(&this->tex_back, this->arc_back_ptr[this->back_tex_id = cframe->tex], 0);
	}
}

void Back_Nerves_DrawBG(StageBack *back)
{
	Back_Nerves *this = (Back_Nerves*)back;
	
	fixed_t fx, fy;
	
	//Draw sunset
	fx = stage.camera.x;
	fy = stage.camera.y;

	Animatable_Animate(&this->back_animatable, (void*)this, Nerves_back_SetFrame);
	
	//Draw character
	const CharFrame *cframe = &back_frame[this->back_frame];

	RECT back_src = {cframe->src[0], cframe->src[1], cframe->src[2], cframe->src[3]};
	RECT_FIXED back_dst = {
		FIXED_DEC(-165 - SCREEN_WIDEOADD2,1) - fx,
		FIXED_DEC(-140,1) - fy,
		FIXED_DEC(340 + SCREEN_WIDEOADD,1),
		FIXED_DEC(260,1)
	};
	Stage_DrawTex(&this->tex_back, &back_src, &back_dst, stage.camera.bzoom);
}
void Back_Nerves_Free(StageBack *back)
{
	Back_Nerves *this = (Back_Nerves*)back;

	Mem_Free(this->arc_back);
	
	
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
	
	//load the flame arcs
	this->arc_back = IO_Read("\\NERVES\\GOSHA.ARC;1");
	this->arc_back_ptr[0] = Archive_Find(this->arc_back, "back0.tim");
	this->arc_back_ptr[1] = Archive_Find(this->arc_back, "back1.tim");
	this->arc_back_ptr[2] = Archive_Find(this->arc_back, "back2.tim");
	this->arc_back_ptr[3] = Archive_Find(this->arc_back, "back3.tim");
	this->arc_back_ptr[4] = Archive_Find(this->arc_back, "back4.tim");

	//Initialize fire state
	Animatable_Init(&this->back_animatable, back_anim);
	Animatable_SetAnim(&this->back_animatable, 0);
	this->back_frame = this->back_tex_id = 0xFF; //Force art load

	Gfx_SetClear(34, 52, 123);
	
	return (StageBack*)this;
}
