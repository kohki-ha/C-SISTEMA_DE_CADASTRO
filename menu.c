#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

char menu_options()
{
    char option;

    printf("\n\t\tMENU\n");
    printf("\n\t0 - Exit\n");
    printf("\n\t1 - Register an artist");
    printf("\n\t  - Register a music\n");
    printf("\n\t2 - Edit an artist");
    printf("\n\t  - Edit a music\n");
    printf("\n\t3 - List an artist");
    printf("\n\t  - List a music");
    printf("\n\t  - List all\n");
    printf("\n\t4 - Remove an artist");
    printf("\n\t  - Remove a music\n");
    printf("\n\t5 - Search an artist");
    printf("\n\t  - Search a music\n");
    printf("\n\t6 - Export data\n");
    printf("\n\t7 - Clear screen\n");
    printf("\n\t>>> ");
    setbuf(stdin, NULL);
    scanf("%c", &option);

    return option;
}

void menu_main()
{
    char op;
    char trash;

    do
    {
        op = menu_options();

        if (op == '1')
        {
            // register_artist();
            // register_music();
            printf("\n\naaa\n\n");
        }

        else if (op == '2')
        {
            // edit_artist();
            // edit_music();
            printf("\n\nbbb\n\n");
        }

        else if (op == '3')
        {
            // list_artist();
            // list_music();
            // list_all();
            printf("\n\nccc\n\n");
        }

        else if (op == '4')
        {
            // remove_artist();
            // remove_music();
            printf("\n\nddd\n\n");
        }

        else if (op == '5')
        {
            // search_artist();
            // search_music();
            printf("\n\neee\n\n");
        }

        else if (op == '6')
        {
            // export_data();
            printf("\n\nfff\n\n");
        }

        else if (op == '7')
            system(CLEAN);

        else if (op == '0')
            break;

        else
        {
            printf("\n\n\tInvalid option!!!\n");
            printf("\tPress any key to continue...");
            setbuf(stdin, NULL);
            scanf("%c", &trash);
            system(CLEAN);
        }

    } while (op != '0');
}
