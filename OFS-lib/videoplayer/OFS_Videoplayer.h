#pragma once

#include <cstdint>
#include <string>

#include "OFS_VideoplayerEvents.h"

class OFS_Videoplayer {
private:
    // Implementation data
    void* ctx = nullptr;
    // A OpenGL 2D_TEXTURE expected to contain the current video frame.
    uint32_t frameTexture = 0;
    // The position which was last requested via any of the seeking functions.
    float logicalPosition = 0.f;
    // Helper for Mute/Unmute
    float lastVolume = 0.f;
    VideoplayerType playerType;

public:
    OFS_Videoplayer(VideoplayerType playerType) noexcept;
    ~OFS_Videoplayer() noexcept;

    static constexpr float MinPlaybackSpeed = 0.05f;
    static constexpr float MaxPlaybackSpeed = 3.0f;

    bool Init(bool hwAccel) noexcept;
    void OpenVideo(const std::string& path) noexcept;
    void SetSpeed(float speed) noexcept;
    void AddSpeed(float speed) noexcept;
    void SetVolume(float volume) noexcept;

    // All seeking functions must update logicalPosition
    void SetPositionExact(float timeSeconds, bool pausesVideo = false) noexcept;
    void SetPositionPercent(float percentPos, bool pausesVideo = false) noexcept;
    void SeekRelative(float timeSeconds) noexcept;
    void SeekFrames(int32_t offset) noexcept;

    void SetPaused(bool paused) noexcept;
    void TogglePlay() noexcept { SetPaused(!IsPaused()); }
    void CycleSubtitles() noexcept;
    void CloseVideo() noexcept;
    void SaveFrameToImage(const std::string& directory) noexcept;
    void NotifySwap() noexcept;

    inline void Mute() noexcept
    {
        lastVolume = Volume();
        SetVolume(0.f);
    }
    inline void Unmute() noexcept
    {
        SetVolume(lastVolume);
    }
    inline void SyncWithPlayerTime() noexcept { SetPositionExact(CurrentPlayerTime()); }
    void Update(float delta) noexcept;

    uint16_t VideoWidth() const noexcept;
    uint16_t VideoHeight() const noexcept;
    float FrameTime() const noexcept;
    float CurrentSpeed() const noexcept;
    float Volume() const noexcept;
    double Duration() const noexcept;
    bool IsPaused() const noexcept;
    float Fps() const noexcept;
    bool VideoLoaded() const noexcept;
    void NextFrame() noexcept;
    void PreviousFrame() noexcept;

    // Uses the logical position which may be different from CurrentPlayerPosition()
    float CurrentPercentPosition() const noexcept;
    // Also uses the logical position
    double CurrentTime() const noexcept;

    // The "actual" position reported by the player
    double CurrentPlayerPosition() const noexcept;
    double CurrentPlayerTime() const noexcept { return CurrentPlayerPosition() * Duration(); }

    const char* VideoPath() const noexcept;
    inline uint32_t FrameTexture() const noexcept { return frameTexture; }
};
