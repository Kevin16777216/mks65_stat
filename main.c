#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main(){
  char *r = ".";
  printf("Statistics for Directory: %s\n",r);
  char *RegFiles[500];
  char *DirFiles[500];
  struct stat temp;
  int Reglen = 0;
  int Dirlen = 0;
  int size = 0;
  DIR *d = opendir(r);
  struct dirent *dir;
  while(dir = readdir(d)){
    stat(dir->d_name,&temp);
    size += temp.st_size;
    if(dir->d_type != 4){
      RegFiles[Reglen] = strdup(dir->d_name);
      Reglen++;
      continue;
    }
    DirFiles[Dirlen] = strdup(dir->d_name);
    Dirlen++;
  }
  printf("\nSize of %s: %d Bytes\n\n",r,size);
  printf("Directories:\n\t");
  int i = -1;
  while(++i < Dirlen){
    printf("%s\n\t",DirFiles[i]);
    free(DirFiles[i]);
  }
  i = -1;
  printf("\nRegular Files:\n\t");
  while(++i < Reglen){
    printf("%s\n\t",RegFiles[i]);
    free(RegFiles[i]);
  }
  closedir(d);
  return 0;
}
