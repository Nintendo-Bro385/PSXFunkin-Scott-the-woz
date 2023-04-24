/*
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "gfscott.h"

#include "../mem.h"
#include "../archive.h"
#include "../stage.h"
#include "../main.h"

//GFS character structure
enum
{
	GFS_ArcMain_Idle0,
	GFS_ArcMain_Idle1,
	GFS_ArcMain_Idle2,
	GFS_ArcMain_Idle3,
	GFS_ArcMain_Idle4,
	GFS_ArcMain_Idle5,
	GFS_ArcMain_Idle6,
	GFS_ArcMain_Idle7,
	GFS_ArcMain_Idle8,
	GFS_ArcMain_Idle9,
	GFS_ArcMain_Idle10,
	GFS_ArcMain_Idle11,
	GFS_ArcMain_Idle12,
	GFS_ArcMain_Idle13,
	GFS_ArcMain_Idle14,
	GFS_ArcMain_Idle15,
	GFS_ArcMain_Idle16,
	GFS_ArcMain_Idle17,
	GFS_ArcMain_Idle18,
	GFS_ArcMain_Idle19,
	
	GFS_Arc_Max,
};

typedef struct
{
	//Character base structure
	Character character;
	
	//Render data and state
	IO_Data arc_main;
	IO_Data arc_ptr[GFS_Arc_Max];
	
	Gfx_Tex tex;
	u8 frame, tex_id;
	
	
	//Pico test
	u16 *pico_p;
} Char_GFS;

//GFS character definitions
static const CharFrame char_GFS_frame[] = {
	{GFS_ArcMain_Idle0, {  0,   0, 170, 176}, { 30, 100}}, //0 idle 1
	{GFS_ArcMain_Idle1, {  0,   0, 170, 176}, { 30, 100}}, //1 idle 2
	{GFS_ArcMain_Idle2, {  0,   0, 170, 176}, { 30, 100}}, //2 idle 3
	{GFS_ArcMain_Idle3, {  0,   0, 170, 176}, { 30, 100}}, //3 idle 4
	{GFS_ArcMain_Idle4, {  0,   0, 170, 176}, { 30, 100}}, //4
	{GFS_ArcMain_Idle5, {  0,   0, 170, 176}, { 30, 100}}, //5
	{GFS_ArcMain_Idle6, {  0,   0, 170, 176}, { 30, 100}}, //6
	{GFS_ArcMain_Idle7, {  0,   0, 170, 176}, { 30, 100}}, //7
	{GFS_ArcMain_Idle8, {  0,   0, 170, 176}, { 30, 100}}, //8
	{GFS_ArcMain_Idle9, {  0,   0, 170, 176}, { 30, 100}}, //9
	{GFS_ArcMain_Idle10, {  0,   0, 170, 176}, { 30, 100}}, //10
	{GFS_ArcMain_Idle11, {  0,   0, 170, 176}, { 30, 100}}, //11
	{GFS_ArcMain_Idle12, {  0,   0, 170, 176}, { 30, 100}}, //12
	{GFS_ArcMain_Idle13, {  0,   0, 170, 176}, { 30, 100}}, //13
	{GFS_ArcMain_Idle14, {  0,   0, 170, 176}, { 30, 100}}, //14
	{GFS_ArcMain_Idle15, {  0,   0, 170, 176}, { 30, 100}}, //15
	{GFS_ArcMain_Idle16, {  0,   0, 170, 176}, { 30, 100}}, //16
	{GFS_ArcMain_Idle17, {  0,   0, 170, 176}, { 30, 100}}, //17
	{GFS_ArcMain_Idle18, {  0,   0, 170, 176}, { 30, 100}}, //18
	{GFS_ArcMain_Idle19, {  0,   0, 170, 176}, { 30, 100}}, //19
};

static const Animation char_GFS_anim[CharAnim_Max] = {
	{0, (const u8[]){ASCR_CHGANI, CharAnim_LeftAlt}},                        //CharAnim_Idle
	{2, (const u8[]){ASCR_CHGANI, CharAnim_LeftAlt}},                                 //CharAnim_Left
	{1, (const u8[]){ 0,  1, 2, 3, 4, 5, 6, 7, 8, 9, ASCR_BACK, 1}}, //CharAnim_LeftAlt
	{2, (const u8[]){ASCR_CHGANI, CharAnim_LeftAlt}},                                 //CharAnim_Down
	{1, (const u8[]){ASCR_CHGANI, CharAnim_LeftAlt}},                      //CharAnim_DownAlt
	{2, (const u8[]){ASCR_CHGANI, CharAnim_LeftAlt}},                                 //CharAnim_Up
	{2, (const u8[]){ASCR_CHGANI, CharAnim_LeftAlt}},                                 //CharAnim_UpAlt
	{2, (const u8[]){ASCR_CHGANI, CharAnim_LeftAlt}},                                 //CharAnim_Right
	{1, (const u8[]){ 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, ASCR_BACK, 1}}, //CharAnim_RightAlt
};

//GFS character functions
void Char_GFS_SetFrame(void *user, u8 frame)
{
	Char_GFS *this = (Char_GFS*)user;
	
	//Check if this is a new frame
	if (frame != this->frame)
	{
		//Check if new art shall be loaded
		const CharFrame *cframe = &char_GFS_frame[this->frame = frame];
		if (cframe->tex != this->tex_id)
			Gfx_LoadTex(&this->tex, this->arc_ptr[this->tex_id = cframe->tex], 0);
	}
}

void Char_GFS_Tick(Character *character)
{
	Char_GFS *this = (Char_GFS*)character;
	
	if (this->pico_p != NULL)
	{
		if (stage.note_scroll >= 0)
		{
			//Scroll through Pico chart
			u16 substep = stage.note_scroll >> FIXED_SHIFT;
			while (substep >= ((*this->pico_p) & 0x7FFF))
			{
				//Play animation and bump speakers
				character->set_anim(character, ((*this->pico_p) & 0x8000) ? CharAnim_RightAlt : CharAnim_LeftAlt);
				this->pico_p++;
			}
		}
	}
	else
	{
		if (stage.flag & STAGE_FLAG_JUST_STEP)
		{
			//Stage specific animations
			if (stage.note_scroll >= 0)
			{
				switch (stage.stage_id)
				{
					case StageId_1_4: //Tutorial cheer
						if (stage.song_step > 64 && stage.song_step < 192 && (stage.song_step & 0x3F) == 60)
							character->set_anim(character, CharAnim_UpAlt);
						break;
					default:
						break;
				}
			}
			
			//Perform dance
			if (stage.note_scroll >= character->sing_end && (stage.song_step % stage.gf_speed) == 0)
			{
				//Switch animation
				if (character->animatable.anim == CharAnim_LeftAlt || character->animatable.anim == CharAnim_Right)
					character->set_anim(character, CharAnim_RightAlt);
				else
					character->set_anim(character, CharAnim_LeftAlt);
				
			}
		}
	}
	
	//Get parallax
	fixed_t parallax;
	if (stage.stage_id >= StageId_1_1 && stage.stage_id <= StageId_1_4)
		parallax = FIXED_DEC(7,10);
	else
		parallax = FIXED_UNIT;
	
	//Animate and draw
	Animatable_Animate(&character->animatable, (void*)this, Char_GFS_SetFrame);
	Character_DrawParallax(character, &this->tex, &char_GFS_frame[this->frame], parallax);
	
}

void Char_GFS_SetAnim(Character *character, u8 anim)
{
	//Set animation
	if (anim == CharAnim_Left || anim == CharAnim_Down || anim == CharAnim_Up || anim == CharAnim_Right || anim == CharAnim_UpAlt)
		character->sing_end = stage.note_scroll + FIXED_DEC(22,1); //Nearly 2 steps
	Animatable_SetAnim(&character->animatable, anim);
}

void Char_GFS_Free(Character *character)
{
	Char_GFS *this = (Char_GFS*)character;
	
	//Free art
	Mem_Free(this->arc_main);
}

Character *Char_GFS_New(fixed_t x, fixed_t y)
{
	//Allocate GFS object
	Char_GFS *this = Mem_Alloc(sizeof(Char_GFS));
	if (this == NULL)
	{
		sprintf(error_msg, "[Char_GFS_New] Failed to allocate GFS object");
		ErrorLock();
		return NULL;
	}
	
	//Initialize character
	this->character.tick = Char_GFS_Tick;
	this->character.set_anim = Char_GFS_SetAnim;
	this->character.free = Char_GFS_Free;
	
	Animatable_Init(&this->character.animatable, char_GFS_anim);
	Character_Init((Character*)this, x, y);
	
	//Set character information
	this->character.spec = 0;
	
	this->character.health_i = 1;
	
	this->character.focus_x = FIXED_DEC(2,1);
	this->character.focus_y = FIXED_DEC(-40,1);
	this->character.focus_zoom = FIXED_DEC(2,1);
	
	//Load art
	this->arc_main = IO_Read("\\CHAR\\GFS.ARC;1");
	
	const char **pathp = (const char *[]){
		"idle0.tim",  //Titlepsy_ArcMain_idle0
		"idle1.tim",  //Titlepsy_ArcMain_idle1
		"idle2.tim",  //Titlepsy_ArcMain_idle2
		"idle3.tim",  //Titlepsy_ArcMain_idle3
		"idle4.tim",  //Titlepsy_ArcMain_idle4
		"idle5.tim",  //Titlepsy_ArcMain_idle5
		"idle6.tim",
		"idle7.tim",
		"idle8.tim",
		"idle9.tim",
		"idle10.tim",
		"idle11.tim",
		"idle12.tim",
		"idle13.tim",
		"idle14.tim",
		"idle15.tim",
		"idle16.tim",
		"idle17.tim",
		"idle18.tim",
		"idle19.tim",
		NULL
	};
	IO_Data *arc_ptr = this->arc_ptr;
	for (; *pathp != NULL; pathp++)
		*arc_ptr++ = Archive_Find(this->arc_main, *pathp);
	
	//Initialize render state
	this->tex_id = this->frame = 0xFF;
	
	
	this->pico_p = NULL;
	
	return (Character*)this;
}
