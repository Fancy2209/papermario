#include "common_structs.h"
BackgroundHeader gBackgroundImage = {0};
void boot_main(void* data);

int main(int argc, char** argv) {
    boot_main(NULL);
    return 0;
}

void decode_yay0(void* src, void* dst) { }
