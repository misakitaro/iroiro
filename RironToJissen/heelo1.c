/*


 */
#include <stdio.h>
#include <curses.h>

/**
 * @brief 枠を描画
 * 
 */
void draw1(void){

    const int END_X = 50;
    const int END_Y = 20;
    for(int y = 0;y < END_Y; y++){
        for(int x = 0; x < END_X; x++){
            //最初と最後
            if(y==0 || y==END_Y-1){
                addstr("*");
            }else {
                if(x==0 || x==END_X-1){
                    addstr("*");
                }else {
                    addstr(" ");
                }
                
            }
        }
        addstr("\n");
    }
    refresh();
}

/**
 * @brief メインループ
 * 
 */
void main_loop(){

    char buf[256];
    draw1();

    move(5,5);
    addstr("Pleas input order!");

    move(10,5);
    addstr("__________________");

    move(10,5);
    refresh();

    keypad(stdscr, TRUE);
    while(1){
        getstr(buf);
        if(!strcmp("END",buf))
        {
            break;
        }
        else if (!strcmp("H",buf))
        {
            mvprintw(15,5,"HELLO WORLD");
        }
        else if (!strcmp("D",buf))
        {
            mvprintw(15,5,"_____________________");
        }
        else if (!strcmp("C",buf))
        {
            mvprintw(15,5,"calc....%d",6*13);
        }
        else
        {
            mvprintw(15, 5, "%s", buf);
        }
        refresh();
        move(10,5);
    }  
    //getch();
}

/**
 * @brief メイン関数
 * 
 * @return int 
 */
int main(void){
 
    initscr();

    clear();
    
    main_loop();    
    
    endwin();
}