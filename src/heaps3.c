#include "common.h"

BSS HeapNode heap_generalHead[GENERAL_HEAP_SIZE];
BSS HeapNode heap_spriteHead[SPRITE_HEAP_SIZE];
#ifndef PLATFORM_N64
BSS HeapNode heap_battleHead;
#endif
BSS u16 gFrameBuf0[FRAME_BUFFER_SIZE / 2];
BSS u16 gFrameBuf1[FRAME_BUFFER_SIZE / 2];
BSS u16 gFrameBuf2[FRAME_BUFFER_SIZE / 2];
