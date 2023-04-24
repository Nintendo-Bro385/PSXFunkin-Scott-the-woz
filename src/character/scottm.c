/*
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "scottm.h"

#include "../mem.h"
#include "../archive.h"
#include "../stage.h"
#include "../main.h"

//ScottM character structure
enum
{
	ScottM_ArcMain_Sheet,
	
	ScottM_Arc_Max,
};

typedef struct
{
	//Character base structure
	Character character;
	
	//Render data and state
	IO_Data arc_main;
	IO_Data arc_ptr[ScottM_Arc_Max];
	
	Gfx_Tex tex;
	u8 frame, tex_id;
} Char_ScottM;

//ScottM character definitions
static const CharFrame char_ScottM_frame[] = {
	{ScottM_ArcMain_Sheet, {  0,   0,  62,  95}, { 42, 183}}, //0 idle 1
	{ScottM_ArcMain_Sheet, { 62,   0,  61,  95}, { 42, 184}}, //1 idle 2
	{ScottM_ArcMain_Sheet, {123,   0,  60,  95}, { 41, 184}}, //2 idle 3
	{ScottM_ArcMain_Sheet, {183,   0,  60,  97}, { 41, 185}}, //3 idle 4
};

static const Animation char_ScottM_anim[CharAnim_Max] = {
	{2, (const u8[]){ 0, 1, 2, 3, ASCR_BACK, 1}}, //CharAnim_Idle
	{2, (const u8[]){ 4,  5, ASCR_BACK, 1}},         //CharAnim_Left
	{0, (const u8[]){ASCR_CHGANI, CharAnim_Idle}},   //CharAnim_LeftAlt
	{2, (const u8[]){ 6,  7, ASCR_BACK, 1}},         //CharAnim_Down
	{0, (const u8[]){ASCR_CHGANI, CharAnim_Idle}},   //CharAnim_DownAlt
	{2, (const u8[]){ 8,  9, ASCR_BACK, 1}},         //CharAnim_Up
	{0, (const u8[]){ASCR_CHGANI, CharAnim_Idle}},   //CharAnim_UpAlt
	{2, (const u8[]){10, 11, ASCR_BACK, 1}},         //CharAnim_Right
	{0, (const u8[]){ASCR_CHGANI, CharAnim_Idle}},   //CharAnim_RightAlt
};

//ScottM character functions
void Char_ScottM_SetFrame(void *user, u8 frame)
{
	Char_ScottM *this = (Char_ScottM*)user;
	
	//Check if this is a new frame
	if (frame != this->frame)
	{
		//Check if new art shall be loaded
		const CharFrame *cframe = &char_ScottM_frame[this->frame = frame];
		if (cframe->tex != this->tex_id)
			Gfx_LoadTex(&this->tex, this->arc_ptr[this->tex_id = cframe->tex], 0);
	}
}

void Char_ScottM_Tick(Character *character)
{
	Char_ScottM *this = (Char_ScottM*)character;
	
	if (stage.flag & STAGE_FLAG_JUST_STEP)
	{	
		//Perform dance
		if (stage.note_scroll >= character->sing_end && (stage.song_step % stage.gf_speed) == 0)
			character->set_anim(character, CharAnim_Idle);
		
	}
	//Animate and draw
	Animatable_Animate(&character->animatable, (void*)this, Char_ScottM_SetFrame);
	Character_Draw(character, &this->tex, &char_ScottM_frame[this->frame]);
}

void Char_ScottM_SetAnim(Character *character, u8 anim)
{
	//Set animation
	Animatable_SetAnim(&character->animatable, anim);
	Character_CheckStartSing(character);
}

void Char_ScottM_Free(Character *character)
{
	Char_ScottM *this = (Char_ScottM*)character;
	
	//Free art
	Mem_Free(this->arc_main);
}

Character *Char_ScottM_New(fixed_t x, fixed_t y)
{
	//Allocate ScottM object
	Char_ScottM *this = Mem_Alloc(sizeof(Char_ScottM));
	if (this == NULL)
	{
		sprintf(error_msg, "[Char_ScottM_New] Failed to allocate ScottM object");
		ErrorLock();
		return NULL;
	}
	
	//Initialize character
	this->character.tick = Char_ScottM_Tick;
	this->character.set_anim = Char_ScottM_SetAnim;
	this->character.free = Char_ScottM_Free;
	
	Animatable_Init(&this->character.animatable, char_ScottM_anim);
	Character_Init((Character*)this, x, y);
	
	//Set character information
	this->character.spec = 0;
	
	this->character.health_i = 1;
	
	this->character.focus_x = FIXED_DEC(65,1);
	this->character.focus_y = FIXED_DEC(-115,1);
	this->character.focus_zoom = FIXED_DEC(1,1);
	
	//Load art
	this->arc_main = IO_Read("\\MENU\\SCOTTM.ARC;1");
	
	const char **pathp = (const char *[]){
		"scott.tim", //ScottM_ArcMain_Idle0
		NULL
	};
	IO_Data *arc_ptr = this->arc_ptr;
	for (; *pathp != NULL; pathp++)
		*arc_ptr++ = Archive_Find(this->arc_main, *pathp);
	
	//Initialize render state
	this->tex_id = this->frame = 0xFF;
	
	return (Character*)this;
}
