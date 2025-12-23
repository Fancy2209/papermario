#include "common.h"

#ifndef PLATFORM_N64
BSS HeapNode heap_generalHead[GENERAL_HEAP_SIZE];
BSS HeapNode heap_spriteHead[SPRITE_HEAP_SIZE];
BSS HeapNode heap_battleHead[BATTLE_HEAP_SIZE];
#else
BSS u8 heap_generalHead[GENERAL_HEAP_SIZE];
BSS u8 heap_spriteHead[SPRITE_HEAP_SIZE];
#endif
BSS u16 gFrameBuf0[FRAME_BUFFER_SIZE / 2];
BSS u16 gFrameBuf1[FRAME_BUFFER_SIZE / 2];
BSS u16 gFrameBuf2[FRAME_BUFFER_SIZE / 2];
