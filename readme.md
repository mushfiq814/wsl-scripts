# WSL Scripts

Housed here are scripts that I wrote to make working with wsl a little bit nicer. Currently the projects included are as follows

* `win-term-image-preview`: a way to render images in Windows Terminal using background images as a hack
* `wsl-musicplayer`: a way to control music playback via the command line in a WSL environment

## How git repos were combined into one

the follow gin git commands were used to combine the repo contents into this single repo while keeping git history intact.

```sh
$ git remote add -f win-term-image-preview git@github.com:mushfiq814/win-term-image-preview.git
$ git merge --allow-unrelated-histories win-term-image-preview/master
# organize files fetched into own dir...

$ git remote add -f wsl-musicplayer git@github.com:mushfiq814/wsl-musicplayer.git
$ git merge --allow-unrelated-histories wsl-musicplayer/master
# organize files fetched into own dir...
$ git merge --allow-unrelated-histories wsl-musicplayer/libvlc
# organize files fetched into own dir...
$ git merge --allow-unrelated-histories wsl-musicplayer/windows-media-player
# organize files fetched into own dir...
```
