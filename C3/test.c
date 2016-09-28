#include<ncurses.h>
int main(void)
{
  initscr();
  printw("helloworld!!!");
  refresh();
  getch();
  endwin();
  return 0;
}
