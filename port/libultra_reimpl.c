#include <PR/ultratypes.h>
#include <PR/os.h>
#include <PR/osint.h>
#include <PR/sptask.h>
#include <stddef.h>
#include <SDL3/SDL.h>

#ifdef __GNUC__
#define UNUSED __attribute__((unused))
#else
#define UNUSED
#endif

__OSEventState __osEventStateTab[OS_NUM_EVENTS];
OSViMode osViModeMpalLan1 = {0};
OSViMode osViModeNtscLan1 = {0};
OSViMode osViModeTable[3];
u32 __osShutdown = 0;
u32 osMemSize = 0;
s32 osTvType = OS_TV_NTSC;

#define N64_CYCLE_RATE 46875000ULL
OSTime __osCurrentTime = 0;

static inline uint64_t sdlCounterToN64Cycles(uint64_t counter) {
    u64 freq = SDL_GetPerformanceFrequency();
    return (counter * N64_CYCLE_RATE) / freq;
}

OSThread *	__osGetActiveQueue(void) { return NULL; }

void __osInitialize_autodetect(void) { }

void __osInitialize_common(void) { }

s32 __osMotorAccess(OSPfs* pfs, s32 flag) { return 0; }

s32 osAfterPreNMI(void) { return 0; }

u32 osAiGetLength(void) { return 0; }

u32 osAiGetStatus(void) { return 0; }

s32	osAiSetFrequency(u32) { return 0; }

s32	osAiSetNextBuffer(void *, u32) { return 0; }

OSPiHandle *osCartRomInit(void) { return NULL; }

void osContGetQuery(OSContStatus* data) { }

void osContGetReadData(OSContPad* data) {
    // TODO
}

s32 osContInit(OSMesgQueue* mq, u8* controllerBits, OSContStatus* status) {
    *controllerBits = 0;
    status->status |= 1;
    SDL_SetHint(SDL_HINT_JOYSTICK_THREAD, "1");
    SDL_Init(SDL_INIT_GAMEPAD);
}

s32 osContStartQuery(OSMesgQueue *) { return 0; }

s32 osContStartReadData(OSMesgQueue *) { return 0; }

void osCreateMesgQueue(OSMesgQueue* mq, OSMesg* msgBuf, s32 count) {
    mq->validCount = 0;
    mq->first = 0;
    mq->msgCount = count;
    mq->msg = msgBuf;
    return;
}

s32 osRecvMesg(OSMesgQueue* mq, OSMesg* msg, UNUSED s32 flag) {
    if (mq->validCount == 0) {
        return -1;
    }

    if (msg != NULL) {
        *msg = *(mq->first + mq->msg);
    }

    mq->first = (mq->first + 1) % mq->msgCount;
    mq->validCount--;

    return 0;
}

s32 osSendMesg(OSMesgQueue* mq, OSMesg msg, UNUSED s32 flag) {
    s32 index;

    if (mq->validCount >= mq->msgCount) {
        return -1;
    }

    index = (mq->first + mq->validCount) % mq->msgCount;

    mq->msg[index] = msg;
    mq->validCount++;

    return 0;
}


void osSetEventMesg(OSEvent event, OSMesgQueue *mq, OSMesg msg) {
    __OSEventState *es = &__osEventStateTab[event];
    es->messageQueue = mq;
    es->message = msg;
}


void osCreatePiManager(OSPri, OSMesgQueue *, OSMesg *, s32) { }

void osCreateThread(OSThread * t, OSId id, void (*entry)(void *), void *arg, void *sp, OSPri p) { }
void osSetThreadPri(OSThread * t, OSPri p) { }
void osStartThread(OSThread *  t) { }
void osStopThread(OSThread *   t) { }

s32 osEPiReadIo(OSPiHandle *, u32 , u32 *) { return 0; }

s32 osEPiStartDma(OSPiHandle *, OSIoMesg *, s32) { return 0; }

s32 osEPiWriteIo(OSPiHandle *, u32 , u32 ) { return 0; }

OSPiHandle *osFlashInit(void) { return NULL; }

s32 osFlashReadArray(OSIoMesg *mb, s32 priority, u32 page_num, void *dramAddr, u32 n_pages, OSMesgQueue *mq) { return 0; }

s32 osFlashSectorErase(u32 page_num) { return 0; }

s32 osFlashWriteArray(u32 page_num) { return 0; }

s32 osFlashWriteBuffer(OSIoMesg *mb, s32 priority, void *dramAddr, OSMesgQueue *mq) { return 0; }

u32 osGetCount(void) {
    return (u32)
        sdlCounterToN64Cycles(SDL_GetPerformanceCounter());
}
void osSetTime(OSTime time) {
    OSTime nowCycles =
        sdlCounterToN64Cycles(SDL_GetPerformanceCounter());

    // Match N64 behavior: osGetTime() returns (now - __osCurrentTime)
    __osCurrentTime = nowCycles + time;
}

OSTime osGetTime(void) {
    OSTime nowCycles =
        sdlCounterToN64Cycles(SDL_GetPerformanceCounter());

    return nowCycles - __osCurrentTime;
}

void osInvalDCache(void *, s32) { }

void osInvalICache(void *, s32) { }

void osWritebackDCache(void *, s32) { }

void osWritebackDCacheAll(void) { }

void osMapTLB(s32, OSPageMask, void *, u32, u32, s32) { }

void osUnmapTLB(s32) { }

void osUnmapTLBAll(void) { }

s32 osMotorInit(OSMesgQueue* mq, OSPfs* pfs, int channel) {
    pfs->channel = channel;
    return 0;
}

s32 osPfsAllocateFile(OSPfs *, u16, u32, u8 *, u8 *, int, s32 *) { return 0; }

s32 osPfsDeleteFile(OSPfs *, u16, u32, u8 *, u8 *) { return 0; }

s32 osPfsFileState(OSPfs *, s32, OSPfsState *) { return 0; }

s32 osPfsFindFile(OSPfs *, u16, u32, u8 *, u8 *, s32 *) { return 0; }

s32 osPfsFreeBlocks(OSPfs *, s32 *) { return 0; }

s32 osPfsNumFiles(OSPfs *, s32 *, s32 *) { return 0; }

s32 osPfsReadWriteFile(OSPfs *, s32, u8, int, int, u8 *) { return 0; }

s32 osPfsRepairId(OSPfs *) { return 0; }

s32 osPfsInitPak(OSMesgQueue *queue, OSPfs *pfs, int channel) { return 0; }

OSIntMask osSetIntMask(OSIntMask) { return 0; }

void osSpTaskLoad(OSTask *tp) { }

void osSpTaskStartGo(OSTask *tp) { }

void osSpTaskYield(void) { }

OSYieldResult osSpTaskYielded(OSTask *tp) { return 0; }

Uint32 __lusViCallback(void* param, SDL_TimerID timerID, Uint32 interval) {
    __OSEventState* es = &__osEventStateTab[OS_EVENT_VI];

    if (es && es->messageQueue) {
        osSendMesg(es->messageQueue, es->message, OS_MESG_NOBLOCK);
    }

    return interval;
}

void osCreateViManager(OSPri pri) {
    SDL_AddTimer(16, &__lusViCallback, NULL);
}

void osViBlack(u8) { }

void *osViGetCurrentFramebuffer(void) { return NULL; }

void *osViGetNextFramebuffer(void) { return NULL; }

void osViRepeatLine(u8) { };

u32  osVirtualToPhysical(void *) { return 0; }

void osViSetEvent(OSMesgQueue *mq, OSMesg m, u32 retraceCount) {

    __OSEventState* es = &__osEventStateTab[OS_EVENT_VI];

    es->messageQueue = mq;
    es->message = m;
}

void osViSetMode(OSViMode *) { }

void osViSetSpecialFeatures(u32) { }

void osViSetYScale(f32) { }

void osViSwapBuffer(void *) { }
