#pragma once

#include "core.hpp"


class CM2Game;
class FCanvas;
class FRect;
class FSample;
class FName;

class CM2_API CM2Character { // TODO Members

public:

	enum SAMPLEID {}; // TODO Contents


	CM2Character(const CM2Character& other);
	CM2Character(CM2Game*);

	virtual ~CM2Character();

	CM2Character& operator=(const CM2Character& other);

	void Draw(FCanvas* canvas, const FRect& rect);
	int GetSpeechChannel() const;
	FSample* GetVolumeTestSample() const;
	void Speak(FSample* sample);
	void Speak(SAMPLEID sample);
	void StopSpeak();
	void Tick(float);


	unsigned char unk0[0x268];

protected:

	CM2Character();

private:

	int GetSampleIndex(FName name);
	void Init();

};
CM2_SIZE_GUARD(CM2Character, 0x26C);
