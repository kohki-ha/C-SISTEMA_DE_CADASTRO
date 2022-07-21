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
    // Music *music;
} Artist;
#endif //__ARTIST_TYPE__

#ifndef __ARTIST_H__
#define __ARTIST_H__
void register_artist(Artist *artist);
char edit_artist_menu();
void edit_artist_name(Artist *artist);
void edit_artist_age(Artist *artist);
void edit_artist_gender(Artist *artist);
void edit_artist_country(Artist *artist);
void edit_artist(Artist *artist, Music *music);
void edit_artist_by_artist_id(Artist *artist, Music *music, int artist_length);
void edit_artist_by_music_id(Artist *artist, Music *music, int artist_length, int music_length);
void list_artist(Artist *artist, Music *music, int artist_length, int music_length);
void delete_artist_by_artist_id(Artist *artist, Music *music, int artist_length, int music_length, int id, int alert);
void delete_artist_by_music_id(Artist *artist, Music *music, int artist_length, int music_length);
void search_artist_by_artist_id(Artist *artist, Music *music, int artist_length, int music_length);
void search_artist_by_music_id(Artist *artist, Music *music, int artist_length, int music_length);
void export_artist(Artist *artist, int artist_length);
#endif //__ARTIST_H__
