#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
enum{ MAX_CHARS = 1024};
static int y, x, num;
static void load_map(char *filename)
{
    int i, ret;
    char buf[MAX_CHARS];
    FILE *fp = fopen(filename, "r");
    if(!fp){
        fprintf(stderr, "file open error\n");
        endwin();
        exit(1);
    }
    fgets(buf, sizeof(buf),fp);
    ret = sscanf(buf, "y=%d, x=%d, num =%d", &y, &x,&num);
    if(ret!=3){
        fprintf(stderr, "bad data file format\n");
        endwin();
        exit(1);
    }else{
        printf("y=%d, x=%d, num=%d\n",y,x,num);
    }
    for(i = 0; i< LINES; i++){
        if(fgets(buf, sizeof(buf), fp) == NULL)
            break;
        move (i, 0);
        printw("%s", buf);
    }
    fclose(fp);
}

int main(void)
{
    initscr();
    load_map("sokoban.map");
    refresh();
    getch();
    endwin();
}