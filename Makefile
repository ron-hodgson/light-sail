PROJECT?=$(notdir $(CURDIR))
FQBN?=esp32:esp32:featheresp32
PORT?=/dev/ttyUSB0

.PHONY: compile upload clean

default: compile upload clean

compile:
	arduino-cli compile --fqbn $(FQBN)

upload:
	arduino-cli upload --fqbn $(FQBN) --port $(PORT)

clean:
	rm -r build