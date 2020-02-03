# KBacklight

Adjust the brightness of your keyboard.

## Requirements

In order to build kbacklight you need C89 library and header files.

## Installation

Edit config.mk to match your local setup (kbacklight in installed into the /usr/local namespace by default).

Enter the following commands to download and build kbacklight :

```
git clone https://github.com/brezzius/kbacklight.git
cd kbacklight
sudo make install
```

## Running

Enter the following command to run kbacklight (if necessary as root) :

`kbacklight [OPTIONS]`

## Options

* `-g, --get, .` Get the current backlight
* `-i, --increase, +` Increase 1 the backlight (max MAX_BRIGHTNESS)
* `-d, --decrease, -` Decrease 1 the backlight (min 0)
* `-s, --set` Set the backlight (integer bewtween range [0, MAX_BRIGHTNESS])
* `-h, --help` Show help
* `-v, --version` Show version

## Configuration

Edit config.h to match your backlight configuration files and re(compiling) the source code.

## Uninstall

Enter the following command to uninstall kbacklight :

`sudo make uninstall`
