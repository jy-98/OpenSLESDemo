//
// Created by Jesson on 2022/5/26.
//

#ifndef OPENSLESDEMO_AUDIO_H
#define OPENSLESDEMO_AUDIO_H


#include "AndroidLog.h"
#include "DataQueue.h"
#include <pthread.h>
#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>
#include <time.h>

class Audio {

public:
    DataQueue *dataQueue;
    int sample_rate = 0;
    pthread_t play_thread_t;

    SLAndroidSimpleBufferQueueItf pcmBufferQueue = NULL;
    SLObjectItf engineObject= NULL;
    SLEngineItf engineEngine= NULL;
    SLObjectItf pcmPlayerObject = NULL;
    SLObjectItf outputMixObject = NULL;
    SLEnvironmentalReverbItf outputMixEnvironmentalReverb = NULL;
    SLPlayItf pcmPlayerPlay = NULL;
    SLMuteSoloItf pcmMutePlay = NULL;
    SLVolumeItf pcmVolumePlay = NULL;

public:
    Audio(DataQueue *dataQueue ,int sample_rate);

    ~Audio();

    void play();

    void initOpenSLES();

    int getCurrentSampleRateForOpensles(int sample_rate);

    void resume();

    void pause();

    void release();

    void stop();
};


#endif //OPENSLESDEMO_AUDIO_H
