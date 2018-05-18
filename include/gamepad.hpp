#pragma once

#include "util/common.hpp"
#include "midi.hpp"


namespace rack {


const int GAMEPAD_DRIVER = -10;


struct GamepadInputDevice : MidiInputDevice {
	int deviceId;
	std::vector<uint8_t> ccs;
	std::vector<bool> states;
	void step();
};


struct GamepadDriver : MidiDriver {
	GamepadInputDevice devices[16];

	GamepadDriver();
	std::string getName() override {return "Gamepad";}
	std::vector<int> getInputDeviceIds() override;
	std::string getInputDeviceName(int deviceId) override;
	MidiInputDevice *subscribeInputDevice(int deviceId, MidiInput *midiInput) override;
	void unsubscribeInputDevice(int deviceId, MidiInput *midiInput) override;
};


void gamepadStep();
GamepadDriver *gamepadGetDriver();


} // namespace rack
