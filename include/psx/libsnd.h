#ifndef PSX_LIBSND_H
#define PSX_LIBSND_H

#define SS_MUTE_OFF 0
#define SS_MUTE_ON  1

extern void SsSetMute(char);
extern short SsVabTransCompleted(short);
extern short SsVabOpenHead(unsigned char *, short);
extern short SsVabTransBody(unsigned char *, short);
extern void SsSeqSetCrescendo(short, short, long);
extern void SsSeqSetVol(short, short, short);
extern void SsSeqReplay(short);
extern void SsSeqStop(short);
extern void SsSeqPlay(short, char, short);
extern void SsSeqPause(short);

#endif