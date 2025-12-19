#include <PR/ultratypes.h>
#include <PR/os.h>
#include <PR/sptask.h>
#include <stddef.h>

u32 osMemSize = 0;
s32 osTvType = OS_TV_NTSC;
OSViMode osViModeMpalLan1 = {0};
OSViMode osViModeNtscLan1 = {0};
OSViMode osViModeTable[3];

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
void osContGetReadData(OSContPad* data) { }
s32 osContInit(OSMesgQueue *, u8 *, OSContStatus *) { }
s32 osContStartQuery(OSMesgQueue *) { }
s32 osContStartReadData(OSMesgQueue *) { }
void osCreateMesgQueue(OSMesgQueue *, OSMesg *, s32) { }
s32 osRecvMesg(OSMesgQueue *, OSMesg *, s32) { return 0; }
s32 osSendMesg(OSMesgQueue *, OSMesg, s32) { return 0; }
void osSetEventMesg(OSEvent, OSMesgQueue *, OSMesg) { }
void osCreatePiManager(OSPri, OSMesgQueue *, OSMesg *, s32) { }
void osCreateThread(OSThread *, OSId, void (*)(void *), void *, void *, OSPri) { }
void osSetThreadPri(OSThread *, OSPri) { }
void osStartThread(OSThread *) { }
void osStopThread(OSThread *) { }
void osCreateViManager(OSPri) { }
s32 osEPiReadIo(OSPiHandle *, u32 , u32 *) { return 0; }
s32 osEPiStartDma(OSPiHandle *, OSIoMesg *, s32) { return 0; }
s32 osEPiWriteIo(OSPiHandle *, u32 , u32 ) { return 0; }
OSPiHandle *osFlashInit(void) { return NULL; }
s32 osFlashReadArray(OSIoMesg *mb, s32 priority, u32 page_num, void *dramAddr, u32 n_pages, OSMesgQueue *mq) { return 0; }
s32 osFlashSectorErase(u32 page_num) { return 0; }
s32 osFlashWriteArray(u32 page_num) { return 0; }
s32 osFlashWriteBuffer(OSIoMesg *mb, s32 priority, void *dramAddr, OSMesgQueue *mq) { return 0; }
u32 osGetCount(void) { return 0; }
OSTime osGetTime(void) { return 0; }
void osInvalDCache(void *, s32) { }
void osInvalICache(void *, s32) { }
void osWritebackDCache(void *, s32) { }
void osWritebackDCacheAll(void) { }
void osMapTLB(s32, OSPageMask, void *, u32, u32, s32) { }
void osUnmapTLB(s32) { }
void osUnmapTLBAll(void) { }
s32 osMotorInit(OSMesgQueue *, OSPfs *, int) { return 0; }
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
void osSetTime(OSTime) { }
void osSpTaskLoad(OSTask *tp) { }
void osSpTaskStartGo(OSTask *tp) { }
void osSpTaskYield(void) { }
OSYieldResult osSpTaskYielded(OSTask *tp) { return 0; }
void osViBlack(u8) { }
void *osViGetCurrentFramebuffer(void) { return NULL; }
void *osViGetNextFramebuffer(void) { return NULL; }
void osViRepeatLine(u8) { };
u32  osVirtualToPhysical(void *) { return 0; }
void osViSetEvent(OSMesgQueue *, OSMesg, u32) { }
void osViSetMode(OSViMode *) { }
void osViSetSpecialFeatures(u32) { }
void osViSetYScale(f32) { }
void osViSwapBuffer(void *) { }
