#ifndef LSD_DREAM_SESSION_PATH_H
#define LSD_DREAM_SESSION_PATH_H

#include <types.h>

/* Advances the dream-session path cursor and asks the file driver to locate a
   path entry at the newly selected offset, retrying until one is found. */
s32 dream_session_path_advance(s32 arg0);

#endif
