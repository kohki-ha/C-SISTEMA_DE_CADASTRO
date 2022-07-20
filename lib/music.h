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
    int id_artist;
    char name[21];
    char album[21];
    char genre[21];
    Song_length song_length;
    Date release_date;
} Music;
#endif //__MUSIC_TYPE__

#ifndef __ARTIST_TYPE__
#define __ARTIST_TYPE__
typedef struct
{
    int id;
    char name[21];
    int age;
    char gender[21];
    char country[21];
} Artist;
#endif //__ARTIST_TYPE__

#ifndef __MUSIC_H__
#define __MUSIC_H__
void register_music(Music *music);
void edit_music_name(Music *music);
void edit_music_album(Music *music);
void edit_music_genre(Music *music);
void edit_music_song_length(Music *music);
void edit_music_release_date(Music *music);
void edit_music(Music *music);
int artists_num_of_music(Artist *artist, Music *music, int music_length);
void show_artists_musics(Artist *artist, Music *music, int music_length);
void edit_music_by_artist_id(Artist *artist, Music *music, int artist_length, int music_length);
void edit_music_by_music_id(Music *music, int artist_length, int music_length);
void list_music(Music *music, int music_length, Artist *artist);
void delete_music_by_artist_id(Artist *artist, Music *music, int artist_length, int music_length);
void delete_music_by_music_id(Artist *artist, Music *music, int music_length);
void search_music_by_artist_id(Artist *artist, Music *music, int artist_length, int music_length);
void search_music_by_music_id(Artist *artist, Music *music, int artist_length, int music_length);
#endif //__MUSIC_H__