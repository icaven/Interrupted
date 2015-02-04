#ifndef __DEVICE_H__
#define __DEVICE_H__

class Device {
public:
	virtual void begin() =0;
	virtual unsigned sleepmode();

	virtual void ready() { _ready = true; }
	virtual bool is_ready() {
		if (_enabled && _ready) {
			_ready = false;
			return true;
		}
		return false;
	}

	virtual void enable(bool enable = true) { _enabled = enable; }
	bool is_enabled() { return _enabled; }

	int id() { return _id; }

protected:
	Device(int id): _id(id), _enabled(true), _ready(false) {}

private:
	int _id;
	bool _enabled;
	volatile bool _ready;
};

#define MAX_DEVICES 10

class Devices {
public:
	Devices(): _n(0) {}

	void add(Device &device) {
		if (_n < MAX_DEVICES)
			_devices[_n++] = &device;
	}

	void begin();
	int select();

private:
	int _n;
	Device *_devices[MAX_DEVICES];
};

#endif
