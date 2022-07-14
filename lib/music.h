#ifndef __MUSIC_TYPE__
#define __MUSIC_TYPE__
typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    int minutes;
    int seconds;
} Song_length;

typedef struct
{
    int id;
    char name[30];
    char album[30];
    char genre[30];
    Song_length song_length;
    Date release_date;
} Music;
#endif //__MUSIC_TYPE__

#ifndef __MUSIC_H__
#define __MUSIC_H__

void register_music(Music *music);

#endif //__MUSIC_H__