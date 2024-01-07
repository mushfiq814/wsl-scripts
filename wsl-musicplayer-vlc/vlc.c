/* #include <stdio.h> */
/* #include <vlc/vlc.h> */
/* #include <stdlib.h> */

/* int main(int c, char * av[]) { */
/* 	libvlc_instance_t *my_instance; */

/* 	my_instance = libvlc_new(0, NULL); */

/* 	if(my_instance == NULL) { */
/* 		printf("There was an error initializing VLC\n"); */
/* 		exit(1); */
/* 	} else { */
/* 		printf("VLC initialized successfully\n"); */
/* 	} */
/* } */

#include <stdio.h>
#include <stdlib.h>

#include <vlc/vlc.h>

int main(int argc, char **argv)
{
	libvlc_instance_t *inst;
	libvlc_media_player_t *mp;
	libvlc_media_t *m;

	// load the vlc engine
	inst = libvlc_new(0, NULL);

	// create a new item
	m = libvlc_media_new_path(inst, "path to MP3 file");

	// create a media play playing environment
	mp = libvlc_media_player_new_from_media(m);

	// no need to keep the media now
	libvlc_media_release(m);

	// play the media_player
	libvlc_media_player_play(mp);

	sleep(10);

	// stop playing
	libvlc_media_player_stop(mp);

	// free the media_player
	libvlc_media_player_release(mp);

	libvlc_release(inst);


	return 0;
}
