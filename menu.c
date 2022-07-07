#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char menu_options()
{
    char option;

    printf("\n\tMENU - MUSICS");
    printf("\n\t 1 - Register an artist");
    printf("\n\t 2 - Register a music");
    printf("\n\t 3 - Edit an artist");
    printf("\n\t 4 - Edit a music");
    printf("\n\t 5 - List an artist");
    printf("\n\t 6 - List a music");
    printf("\n\t 7 - List all");
    printf("\n\t 8 - Remove an artist");
    printf("\n\t 9 - Remove a music");
    printf("\n\t10 - Search an artist");
    printf("\n\t11 - Search a music");
    printf("\n\t12 - Export data");
    printf("\n\t 0 - Exit");
    printf("\n\t>>");
    setbuf(stdin, NULL);
    scanf("%c", &option);

    return option;
}

void menu_main()
{
    char op;

    do
    {
        op = menu();

        if (op == '1')
            register_artist();

        else if (op == '2')
            register_music();

        else if (op == '3')
            edit_artist();

        else if (op == '4')
            edit_music();

        else if (op == '5')
            list_artist();

        else if (op == '6')
            list_music();

        else if (op == '7')
            list_all();

        else if (op == '8')
            remove_artist();

        else if (op == '9')
            remove_music();

        else if (op == '10')
            search_artist();

        else if (op == '11')
            search_music();

        else if (op == '12')
            export_data();

        else if (op == '0')
            break;

        else
            printf("\n\n\tInvalid option!!!\n");

    } while (op != '0');
}

