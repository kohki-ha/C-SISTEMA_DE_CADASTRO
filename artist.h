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

#ifndef __ARTIST_TYPE__
#define __ARTIST_TYPE__
typedef struct
{
    int id;
    char name[30];
    int age;
    char gender[30];
    char country[30];
    Music *music;
} Artist;
#endif //__ARTIST_TYPE__

#ifndef __ARTIST_H__
#define __ARTIST_H__

void register_artist(Artist *artist);
char edit_artist_options(Artist *artist);
int verify_artist_musics(Artist *artist);
void edit_artist_name(Artist *artist);
void edit_artist_age(Artist *artist);
void edit_artist_gender(Artist *artist);
void edit_artist_country(Artist *artist);
void edit_artist_music_name(Artist *artist, int i);
void edit_artist_music_album(Artist *artist, int i);
void edit_artist_music_genre(Artist *artist, int i);
void edit_artist_music_song_length(Artist *artist, int i);
void edit_artist_music_release_date(Artist *artist, int i);
void edit_artist(Artist *artist, Music *music);
void edit_artist_by_artist_id(Artist *artist, Music *music, int artist_length);
void edit_artist_by_music_id(Artist *artist, Music *music, int artist_length, int music_length);

#endif //__ARTIST_H__