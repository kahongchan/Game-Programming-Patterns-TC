#include <iostream>

class AudioSystem
{
public:
  static void playSound(int id) {}
  static AudioSystem* instance() { return NULL; }
};

void example()
{
  int VERY_LOUD_BANG = 0;

  //^15
  // 使用靜態類？
  AudioSystem::playSound(VERY_LOUD_BANG);

  // 還是使用單例？
  AudioSystem::instance()->playSound(VERY_LOUD_BANG);
  //^15
}

//^9
class Audio
{
public:
  virtual ~Audio() {}
  virtual void playSound(int soundID) = 0;
  virtual void stopSound(int soundID) = 0;
  virtual void stopAllSounds() = 0;
};
//^9

//^10
class ConsoleAudio : public Audio
{
public:
  virtual void playSound(int soundID)
  {
    // 使用主機音頻API播放聲音……
  }

  virtual void stopSound(int soundID)
  {
    // 使用主機音頻API停止聲音……
  }

  virtual void stopAllSounds()
  {
    // 使用主機音頻API停止所有聲音……
  }
};
//^10

//^12
class LoggedAudio : public Audio
{
public:
  LoggedAudio(Audio &wrapped)
  : wrapped_(wrapped)
  {}

  virtual void playSound(int soundID)
  {
    log("play sound");
    wrapped_.playSound(soundID);
  }

  virtual void stopSound(int soundID)
  {
    log("stop sound");
    wrapped_.stopSound(soundID);
  }

  virtual void stopAllSounds()
  {
    log("stop all sounds");
    wrapped_.stopAllSounds();
  }

private:
  void log(const char* message)
  {
    // 記錄日誌的代碼……
  }

  Audio &wrapped_;
};
//^12

// design decisions / di
namespace Version1
{
  //^1
  class Locator
  {
  public:
    static Audio* getAudio() { return service_; }

    static void provide(Audio* service)
    {
      service_ = service;
    }

  private:
    static Audio* service_;
  };
  //^1

  Audio *Locator::service_;

  void initGame()
  {
    //^11
    ConsoleAudio *audio = new ConsoleAudio();
    Locator::provide(audio);
    //^11
  }

  void someGameCode()
  {
    int VERY_LOUD_BANG = 0;
    //^5
    Audio *audio = Locator::getAudio();
    audio->playSound(VERY_LOUD_BANG);
    //^5
  }
}

// design decisions / compile time
namespace Version2
{
  class DebugAudio: public Audio
  {
  public:
    virtual void playSound(int soundID) { /* 什麼也不做 */ }
    virtual void stopSound(int soundID) { /* 什麼也不做 */ }
    virtual void stopAllSounds()        { /* 什麼也不做 */ }
  };
  class ReleaseAudio: public DebugAudio {};

  //^2
  class Locator
  {
  public:
    static Audio& getAudio() { return service_; }

  private:
    #if DEBUG
      static DebugAudio service_;
    #else
      static ReleaseAudio service_;
    #endif
  };
  //^2
}

// design decisions / scope
namespace Version3
{
  //^3
  class Base
  {
    // 定位和設置服務的代碼……

  protected:
    // 派生類可以使用服務
    static Audio& getAudio() { return *service_; }

  private:
    static Audio* service_;
  };
  //^3
}

namespace Version4
{
  //^4
  class Locator
  {
  public:
    static Audio& getAudio()
    {
      Audio* service = NULL;

      // Code here to locate service...

      assert(service != NULL);
      return *service;
    }
  };
  //^4
}

namespace Version5
{
  //^7
  class NullAudio: public Audio
  {
  public:
    virtual void playSound(int soundID) { /* 什麼也不做 */ }
    virtual void stopSound(int soundID) { /* 什麼也不做 */ }
    virtual void stopAllSounds()        { /* 什麼也不做 */ }
  };
  //^7

  //^8
  class Locator
  {
  public:
    static void initialize() { service_ = &nullService_; }

    static Audio& getAudio() { return *service_; }

    static void provide(Audio* service)
    {
      if (service == NULL)
      {
        // 退回空服務
        service_ = &nullService_;
      }
      else
      {
        service_ = service;
      }
    }

  private:
    static Audio* service_;
    static NullAudio nullService_;
  };
  //^8

  Audio *Locator::service_ = NULL;
  NullAudio Locator::nullService_;

  //^13
  void enableAudioLogging()
  {
    // 裝飾現有的服務
    Audio *service = new LoggedAudio(Locator::getAudio());

    // 將它換進來
    Locator::provide(service);
  }
  //^13
}
