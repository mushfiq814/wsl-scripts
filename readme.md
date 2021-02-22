# WSL PowerShell Music Player
Play Music in Windows 10 through WSL using VLC's [`libvlc`](https://wiki.videolan.org/LibVLC)

## Motivation
The Windows Subsystem for Linux (WSL) is great and wasy to work with if all you need are shell sessions. You can even interface with files in the Windows filesystem. However, connecting hardware capabilities such as graphics (GUIs) and audio is still not as easy (as far as I have found). I wanted to be able to control my music player to play my local mp3 files from a WSL session and not finding any that works natively with WSL or that can interface with Groove Music (my music player of choice), I decided to try to create a command line music player using libvlc.

