#include<stdio.h>
#include<sys/stat.h>
int main()
{
  //pointer to stat structure
  struct stat sfile;
  //invoked a structure variable sfile
  //stat system call
  stat ("hello.txt", &sfile);
  //now access the data members of structure stat
  printf ("File st_mode:%d\n", sfile.st_mode);
  printf("File st_size:%ld\n",sfile.st_size);
  printf ("File st_uid:%d\n", sfile.st_uid);
  return 0;
}
