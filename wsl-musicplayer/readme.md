# WSL PowerShell Music Player
Play Music in Windows 10 through WSL by invoking a Windows Media Player in the background using PowerShell.

## Motivation
The Windows Subsystem for Linux (WSL) is great and wasy to work with if all you need are shell sessions. You can even interface with files in the Windows filesystem. However, connecting hardware capabilities such as graphics (GUIs) and audio is still not as easy (as far as I have found). I wanted to be able to control my music player to play my local mp3 files from a WSL session and not finding any that works natively with WSL or that can interface with Groove Music (my music player of choice), I decided to turn to PowerShell to create Windows Media Player objects to play any local audio files while being able to be controlled through WSL.

## Disclaimer
This project has been temporarily abandoned since I couldn't find a good way to pause and play mp3 files using Windows Media Player. The project has been moved into the `windows-media-player` branch.

Currently, I am using pulseaudio to drive audio hardware through WSL. All instructions for setting up a pulseaudio server on WSL is detailed in `wsl-pulseaudio.md`. This way, I can use existing linux media players such as `mpv` and `cmus` to play my songs.

## Known Issues
* `mpv` sometimes cannot play a new song when triggered with a playlist of files. When a track change is happening, it seg faults.
* `cmus` has audio playback issues.

## Usage
1. Clone this repo (or just download the scripts to any directory in your filesystem).
	```sh
	$ git clone https://github.com/mushfiq814/wsl-musicplayer
	```
2. Add `mp3play` to local binaries at `/usr/local/bin/`. **Note**: `sudo` is required to do this.
	```sh
	$ sudo cp mp3play /usr/local/bin
	```
3. Invoke script by using `mp3play` with appropriate flags
	```
	$ mp3play --play darude-sandstorm.mp3
	```

### Currently supported options
| Option         | Description                         | Example                   |
|----------------|-------------------------------------|---------------------------|
| `--play $file` | Play the song with filepath `$file` | `mp3play --play song.mp3` |
| `--stop`       | Stop any running sessions           | `mp3play --stop`          |

### Work In Progress Options
| Option        | Description                           | Example              |
|---------------|---------------------------------------|----------------------|
| `--play $dir` | Play song in directory `$dir`         | `mp3play --play dir` |
| `--pause`     | Pause currently playing song          | `mp3play --pause`    |
| `--next`      | Go to next song in playlist           | `mp3play --next`     |
| `--prev`      | Go to previous song in playlist       | `mp3play --prev`     |
| `--list`      | Show current playlist                 | `mp3play --list`     |
| `--shuffle`   | Play current playlist in shuffle mode | `mp3play --shuffle`  |
