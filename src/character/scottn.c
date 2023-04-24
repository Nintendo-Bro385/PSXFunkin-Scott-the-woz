/*
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#include "scottn.h"

#include "../mem.h"
#include "../archive.h"
#include "../stage.h"
#include "../main.h"

//Scottn character structure
enum
{
	Scottn_ArcMain_Idle0,
	Scottn_ArcMain_Idle1,
	Scottn_ArcMain_Left,
	Scottn_ArcMain_Down0,
	Scottn_ArcMain_Down1,
	Scottn_ArcMain_Up,
	Scottn_ArcMain_Right,
	
	Scottn_Arc_Max,
};

typedef struct
{
	//Character base structure
	Character character;
	
	//Render data and state
	IO_Data arc_main;
	IO_Data arc_ptr[Scottn_Arc_Max];
	
	Gfx_Tex tex;
	u8 frame, tex_id;
} Char_Scottn;

//Scottn character definitions
static const CharFrame char_Scottn_frame[] = {
	{Scottn_ArcMain_Idle0, {  0,   0, 112, 186}, { 41, 150}}, //0 idle 1
	{Scottn_ArcMain_Idle0, {112,   0, 99, 186}, { 41, 150}}, //1 idle 2
	{Scottn_ArcMain_Idle1, {  0,   0, 91, 198}, { 41, 165}}, //2 idle 3
	{Scottn_ArcMain_Idle1, {91,   0, 85, 198}, { 41, 165}}, //3 idle 4
	
	{Scottn_ArcMain_Left, {  0,   0, 113, 196}, { 61, 165}}, //4 left 1
	{Scottn_ArcMain_Left, {113,   0, 110, 196}, { 81, 165}}, //5 left 2
	
	{Scottn_ArcMain_Down0, {  0,   0, 122, 160}, { 41, 128}}, //6 down 1
	{Scottn_ArcMain_Down1, {  0,   0, 136, 142}, { 41, 115}}, //7 down 2
	
	{Scottn_ArcMain_Up, {  0,   0,  90, 222}, { 41, 195}}, //8 up 1
	{Scottn_ArcMain_Up, { 90,   0,  84, 222}, { 41, 195}}, //9 up 2
	
	{Scottn_ArcMain_Right, {  0,   0, 108, 194}, { 41, 165}}, //10 right 1
	{Scottn_ArcMain_Right, {108,   0, 114, 194}, { 41, 165}}, //11 right 2
};

static const Animation char_Scottn_anim[CharAnim_Max] = {
	{2, (const u8[]){ 0,  1,  2,  3, ASCR_BACK, 1}}, //CharAnim_Idle
	{2, (const u8[]){ 4,  5, ASCR_BACK, 0}},         //CharAnim_Left
	{0, (const u8[]){ASCR_CHGANI, CharAnim_Idle}},   //CharAnim_LeftAlt
	{2, (const u8[]){ 6,  7, ASCR_BACK, 0}},         //CharAnim_Down
	{0, (const u8[]){ASCR_CHGANI, CharAnim_Idle}},   //CharAnim_DownAlt
	{2, (const u8[]){ 8,  9, ASCR_BACK, 0}},         //CharAnim_Up
	{0, (const u8[]){ASCR_CHGANI, CharAnim_Idle}},   //CharAnim_UpAlt
	{2, (const u8[]){10, 11, ASCR_BACK, 0}},         //CharAnim_Right
	{0, (const u8[]){ASCR_CHGANI, CharAnim_Idle}},   //CharAnim_RightAlt
};

//Scottn character functions
void Char_Scottn_SetFrame(void *user, u8 frame)
{
	Char_Scottn *this = (Char_Scottn*)user;
	
	//Check if this is a new frame
	if (frame != this->frame)
	{
		//Check if new art shall be loaded
		const CharFrame *cframe = &char_Scottn_frame[this->frame = frame];
		if (cframe->tex != this->tex_id)
			Gfx_LoadTex(&this->tex, this->arc_ptr[this->tex_id = cframe->tex], 0);
	}
}

void Char_Scottn_Tick(Character *character)
{
	Char_Scottn *this = (Char_Scottn*)character;
	
	//Perform idle dance
	if ((character->pad_held & (INPUT_LEFT | INPUT_DOWN | INPUT_UP | INPUT_RIGHT)) == 0)
		Character_PerformIdle(character);
	
	//Animate and draw
	Animatable_Animate(&character->animatable, (void*)this, Char_Scottn_SetFrame);
	Character_Draw(character, &this->tex, &char_Scottn_frame[this->frame]);
}

void Char_Scottn_SetAnim(Character *character, u8 anim)
{
	//Set animation
	Animatable_SetAnim(&character->animatable, anim);
	Character_CheckStartSing(character);
}

void Char_Scottn_Free(Character *character)
{
	Char_Scottn *this = (Char_Scottn*)character;
	
	//Free art
	Mem_Free(this->arc_main);
}

Character *Char_Scottn_New(fixed_t x, fixed_t y)
{
	//Allocate Scottn object
	Char_Scottn *this = Mem_Alloc(sizeof(Char_Scottn));
	if (this == NULL)
	{
		sprintf(error_msg, "[Char_Scottn_New] Failed to allocate scottn object");
		ErrorLock();
		return NULL;
	}
	
	//Initialize character
	this->character.tick = Char_Scottn_Tick;
	this->character.set_anim = Char_Scottn_SetAnim;
	this->character.free = Char_Scottn_Free;
	
	Animatable_Init(&this->character.animatable, char_Scottn_anim);
	Character_Init((Character*)this, x, y);
	
	//Set character information
	this->character.spec = 0;
	
	this->character.health_i = 8;
	
	this->character.focus_x = FIXED_DEC(65,1);
	this->character.focus_y = FIXED_DEC(-110,1);
	this->character.focus_zoom = FIXED_DEC(1,1);
	
	//Load art
	this->arc_main = IO_Read("\\CHAR\\SCOTTN.ARC;1");
	
	const char **pathp = (const char *[]){
		"idle0.tim", 
		"idle1.tim", 
		"left.tim",  
		"down0.tim",
		"down1.tim", 
		"up.tim",    
		"right.tim", 
		NULL
	};
	IO_Data *arc_ptr = this->arc_ptr;
	for (; *pathp != NULL; pathp++)
		*arc_ptr++ = Archive_Find(this->arc_main, *pathp);
	
	//Initialize render state
	this->tex_id = this->frame = 0xFF;
	
	return (Character*)this;
}
