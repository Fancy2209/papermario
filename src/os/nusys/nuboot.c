#include "common.h"
#include "nu/nusys.h"
#include "functions.h"
#include "variables.h"

#if !VERSION_PAL
NOP_FIX
#endif

u64 nuMainStack[NU_SC_STACK_SIZE / sizeof(u64)];
static OSThread IdleThread; // idle thread, id 1
static OSThread MainThread; // id 3
static u64 IdleStack[NU_SC_STACK_SIZE / sizeof(u64)];

void (*nuIdleFunc)(void);
void __osInitialize_autodetect(void);

int boot_idle(void* data);
void nuBoot(void) {
    osInitialize();
#if VERSION_PAL
    __osInitialize_autodetect();
#endif
    //osCreateThread(&IdleThread, NU_IDLE_THREAD_ID, boot_idle, NULL, &IdleStack[NU_SC_STACK_SIZE / sizeof(u64)], 10);
    //osStartThread(&IdleThread);
    SDL_CreateThread(boot_idle, "Idle Thread", NULL);
}

void boot_main(void* data);
int boot_main_sdl(void* data) {
    boot_main(data);
    return 0;
}


int boot_idle(void* data) {
    nuIdleFunc = NULL;

    nuPiInit();
    nuScCreateScheduler(OS_VI_NTSC_LAN1, 1);
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_GAMMA_DITHER_OFF | OS_VI_DIVOT_ON | OS_VI_DITHER_FILTER_ON);
    //osCreateThread(&MainThread, NU_MAIN_THREAD_ID, boot_main, NULL, &nuMainStack[NU_SC_STACK_SIZE / sizeof(u64)], NU_MAIN_THREAD_PRI);
    //osStartThread(&MainThread);
    //osSetThreadPri(&IdleThread, NU_IDLE_THREAD_PRI);
    SDL_CreateThread(boot_main_sdl, "Main Thread", NULL);

    while (1) {
        if (nuIdleFunc != NULL) {
            nuIdleFunc();
        }
    }
    return 0;
}
