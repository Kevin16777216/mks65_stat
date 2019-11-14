#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
int main(){
  struct stat* st = malloc(sizeof(struct stat));
  stat("demo.txt",st);
  printf("size of demo.txt: %d Bytes\n",st->st_size);
  printf("permissions of demo.txt: %d\n",st->st_mode);
  printf("last accessed of demo.txt: %d\n",ctime(st->st_atime));
  printf("last modified of demo.txt: %d\n",ctime(st->st_mtime));
  free(st);
  return 0;
}
