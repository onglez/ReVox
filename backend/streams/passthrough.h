#ifndef PASSTHROUGH_H
#define PASSTHROUGH_H

#include "audiostream.h"
#include "../../ui/hud.h"

class Passthrough : public AudioStream
{
public:
    Passthrough(device inputDevice,
                device outputDevice,
                int sampleRate,
                int framesPerBuffer,
                std::string dir,
                float *inputBuffer);

    ~Passthrough()
    {
        delete data.reverb;
        delete data.autotune;
    }

    void Record(int keycode);
    void Stop();

    void SetFXList(std::unordered_map<std::string, std::shared_ptr<IAudioFX>> *fxs) { this->data.fxs = fxs; }

    passthroughData data = {};

    bool recording = false;

    HUD *hud;
};

#endif // PASSTHROUGH_H
