#include "common.h"
#include "nu/nusys.h"
#include "functions.h"
#include "variables.h"

BackgroundHeader gBackgroundImage = {0};
void nuBoot(void);

int main(int argc, char** argv) {
    osInitialize();
    nuPiInit();
    nuScCreateScheduler(OS_VI_NTSC_LAN1, 1);
    osViSetSpecialFeatures(OS_VI_GAMMA_OFF | OS_VI_GAMMA_DITHER_OFF | OS_VI_DIVOT_ON | OS_VI_DITHER_FILTER_ON);
    boot_main(NULL);
    while (1) {
        if (nuIdleFunc != NULL) {
            nuIdleFunc();
        }
    }
    return 0;
}


void decode_yay0(void* src, void* dst) { }
