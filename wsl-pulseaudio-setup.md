# Setting up pulseaudio with WSL

## Sources
https://research.wmz.ninja/articles/2017/11/setting-up-wsl-with-graphics-and-audio.html
https://x410.dev/cookbook/wsl/enabling-sound-in-wsl-ubuntu-let-it-sing/

## Install pulseaudio on Windows 10
1. Get binary files:
	* Download the pre-built binary package from the [PulseAudio website](https://www.freedesktop.org/wiki/Software/PulseAudio/Ports/Windows/Support/).
	* The files are also available on this repo at `pulseaudio-win`.
2. Edit `etc/pulse/default.pa`:
```pa
# Find this line.
# load-module module-native-protocol-tcp

# And change it to this line. Note, that the line is uncommented.
load-module module-native-protocol-tcp auth-ip-acl=127.0.0.1 auth-anonymous=1
```
3. Edit `etc/pulse/daemon.conf`:
```conf
# Find this line.
; exit-idle-time = 20

# And change it to this line to remove the timer. Note, this line is also uncommented.
exit-idle-time = -1
```
4. To start the pulseaudio server:
```sh
$ /bin/pulseaudio.exe
```

## Install pulseaudio on WSL
1. Uninstall pulseaudio if it already exists:
```sh
$ sudo apt-get purge pulseaudio
```
2. Install dependencies:
```sh
$ sudo apt-get install build-essential pkg-config intltool libtool libsndfile1-dev libjson-c-dev
```
3. Get pulseaudio source:
	* [Online](https://www.freedesktop.org/wiki/Software/PulseAudio/). I have tested with **pulseaudio 8.0**.
	* The files are also available on this repo at `pulseaudio-linux`. Just extract using:
	```sh
	$ tar -xf pulseaudio-8.0.tar.xz
	```
4. Edit `src/pulsecore/mutex-posix.c`:
```c
// Find this line
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

// Change it to this.
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#undef HAVE_PTHREAD_PRIO_INHERIT // <-- this line was added
```
4. At root of pulseaudio (linux):
```sh
$ cd pulseaudio-8.0 # or whichever linux version was downloaded
$ CFLAGS="$CFLAGS -g -O0" ./configure     \
      --prefix=/usr/local                 \
      --sysconfdir=/etc                   \
      --localstatedir=/var                \
      --disable-bluez4                    \
      --disable-bluez5                    \
      --disable-rpath                     \
      --disable-asyncns                   \
      --disable-udev                      \
      --disable-systemd-daemon            \
      --without-caps                      \
      --enable-force-preopen
```
5. Compile:
```sh
$ sudo make && make install
```
> Note: compiling might not be successfull, in which case I had to switch to root user and rerun `make && make install`

## Add server IP to shell profile
Add the following line to shell profile/config file (.zshrc or .bashrc) to specify pulseaudio server to be on localhost.
```sh
export PULSE_SERVER=tcp:localhost
```
