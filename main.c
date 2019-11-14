#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
int main(){
  struct stat* st = malloc(sizeof(struct stat));
  stat("demo.txt",st);
  printf("size of demo.txt: %d Bytes\n",st->st_size);
  printf("permissions of demo.txt: %d\n",st->st_mode);
  time_t* atime = &(st->st_atime);
  time_t* mtime = &(st->st_mtime);
  printf("last accessed of demo.txt: %s\n",asctime(atime));
  printf("last modified of demo.txt: %s\n",asctime(mtime));
  free(st);
  return 0;
}
