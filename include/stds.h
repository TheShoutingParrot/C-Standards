#ifndef STDS_H
#define STDS_H

#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include "SDL2/SDL_ttf.h"

#include "stddefine.h"
#include "structs.h"

#define MAX_INT_DIGITS 11
#define DEBUG          1

#define MAX( a, b )     ( ( a ) > ( b ) ? ( a ) : ( b ) )
#define MIN( a, b )     ( ( a ) < ( b ) ? ( a ) : ( b ) )
#define MAX3( a, b, c ) ( MAX( MAX( a, b ), c ) )
#define MIN3( a, b, c ) ( MIN( MIN( a, b ), c ) )

extern int32_t random_int( int32_t min, int32_t max );

extern f32 random_f32( f32 min, f32 max );

extern void clamp( int32_t *n, int32_t min, int32_t max );

extern void calc_slope( int32_t x1, int32_t y1, int32_t x2, int32_t y2, f32 *x_slope, f32 *y_slope );

extern f32 get_angle( int32_t x1, int32_t y1, int32_t x2, int32_t y2 );

extern int32_t get_distance( int32_t x1, int32_t y1, int32_t x2, int32_t y2 );

extern void print( const char * s, ... );

extern f32 to_radians( f32 degree_angle );

extern f32 to_degrees( f32 radian_angle );

extern bool is_mouse_over_rect( f32 x, f32 y, SDL_Rect rect );

extern char *str_substring( const char *str, int first, int last );

extern int32_t str_index_of( const char *s, const char *search_str );

extern char * strcat_int( const char *s, int32_t n );

#endif // STDS_H