#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL_keysym.h>

#include "../libpicofe/input.h"
#include "../libpicofe/in_sdl.h"
#include "../libpicofe/plat.h"
#include "../common/input_pico.h"
#include "../common/plat_sdl.h"
#include "../common/emu.h"

/* Miyoo Mini (Koriki): what its keys send through SDL 1.2
 *   A=SPACE  B=LCTRL  X=LSHIFT  Y=LALT  L1=E  R1=T  L2=TAB  R2=BACKSPACE
 *   SELECT=RCTRL  START=RETURN  MENU=ESCAPE
 * Names as in the config of Koriki's former PicoDrive, so its binds stay. */
struct in_default_bind _in_sdl_defbinds[] = {
	{ SDLK_UP,	IN_BINDTYPE_PLAYER12, GBTN_UP },
	{ SDLK_DOWN,	IN_BINDTYPE_PLAYER12, GBTN_DOWN },
	{ SDLK_LEFT,	IN_BINDTYPE_PLAYER12, GBTN_LEFT },
	{ SDLK_RIGHT,	IN_BINDTYPE_PLAYER12, GBTN_RIGHT },
	{ SDLK_SPACE,	IN_BINDTYPE_PLAYER12, GBTN_A },
	{ SDLK_LCTRL,	IN_BINDTYPE_PLAYER12, GBTN_B },
	{ SDLK_LALT,	IN_BINDTYPE_PLAYER12, GBTN_C },
	{ SDLK_LSHIFT,	IN_BINDTYPE_PLAYER12, GBTN_X },
	{ SDLK_e,	IN_BINDTYPE_PLAYER12, GBTN_Y },
	{ SDLK_t,	IN_BINDTYPE_PLAYER12, GBTN_Z },
	{ SDLK_RCTRL,	IN_BINDTYPE_PLAYER12, GBTN_MODE },
	{ SDLK_RETURN,	IN_BINDTYPE_PLAYER12, GBTN_START },
	{ SDLK_ESCAPE,	IN_BINDTYPE_EMU, PEVB_MENU },
	{ SDLK_TAB,	IN_BINDTYPE_EMU, PEVB_STATE_SAVE },
	{ SDLK_BACKSPACE,	IN_BINDTYPE_EMU, PEVB_STATE_LOAD },
	{ SDLK_e,	IN_BINDTYPE_EMU, PEVB_PICO_PPREV },
	{ SDLK_t,	IN_BINDTYPE_EMU, PEVB_PICO_PNEXT },
	{ 0, 0, 0 }
};
const struct in_default_bind *in_sdl_defbinds = _in_sdl_defbinds;

struct menu_keymap _in_sdl_key_map[] = {
	{ SDLK_UP,	PBTN_UP },
	{ SDLK_DOWN,	PBTN_DOWN },
	{ SDLK_LEFT,	PBTN_LEFT },
	{ SDLK_RIGHT,	PBTN_RIGHT },
	{ SDLK_SPACE,	PBTN_MOK },
	{ SDLK_LCTRL,	PBTN_MBACK },
	{ SDLK_RETURN,	PBTN_MA2 },
	{ SDLK_RCTRL,	PBTN_MA3 },
	{ SDLK_e,	PBTN_L },
	{ SDLK_t,	PBTN_R },
	{ SDLK_ESCAPE,	PBTN_MENU },
};
const int in_sdl_key_map_sz = sizeof(_in_sdl_key_map) / sizeof(_in_sdl_key_map[0]);
const struct menu_keymap *in_sdl_key_map = _in_sdl_key_map;

const struct menu_keymap _in_sdl_joy_map[] = {
	{ SDLK_UP,	PBTN_UP },
	{ SDLK_DOWN,	PBTN_DOWN },
	{ SDLK_LEFT,	PBTN_LEFT },
	{ SDLK_RIGHT,	PBTN_RIGHT },
	{ SDLK_WORLD_0,	PBTN_MOK },
	{ SDLK_WORLD_1,	PBTN_MBACK },
	{ SDLK_WORLD_2,	PBTN_MA2 },
	{ SDLK_WORLD_3,	PBTN_MA3 },
};
const int in_sdl_joy_map_sz = sizeof(_in_sdl_joy_map) / sizeof(_in_sdl_joy_map[0]);
const struct menu_keymap *in_sdl_joy_map = _in_sdl_joy_map;

const struct menu_keymap _in_sdl_mouse_map[] = {
	{ SDLK_WORLD_81, PBTN_MOK },
};
const int in_sdl_mouse_map_sz = sizeof(_in_sdl_mouse_map) / sizeof(_in_sdl_mouse_map[0]);
const struct menu_keymap *in_sdl_mouse_map = _in_sdl_mouse_map;

const char * _in_sdl_key_names[SDLK_LAST] = {
	[SDLK_UP] = "UP",
	[SDLK_DOWN] = "DOWN",
	[SDLK_LEFT] = "LEFT",
	[SDLK_RIGHT] = "RIGHT",
	[SDLK_SPACE] = "A",
	[SDLK_LCTRL] = "B",
	[SDLK_LSHIFT] = "X",
	[SDLK_LALT] = "Y",
	[SDLK_e] = "L1",
	[SDLK_t] = "R1",
	[SDLK_TAB] = "L2",
	[SDLK_BACKSPACE] = "R2",
	[SDLK_RCTRL] = "SELECT",
	[SDLK_RETURN] = "START",
	[SDLK_ESCAPE] = "MENU",
};
const char * const *in_sdl_key_names = _in_sdl_key_names;

const struct in_default_bind in_sdl_kbd_map[] = {
	{ 0, 0, 0 }
};

void plat_target_setup_input(void)
{
}
