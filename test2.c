#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int  main(int argc, char const *argv[]) {
  struct stat buf;
  printf("%d\n", lstat("test1",&buf));
  printf("Mode ltestttt:                     %ld (octal)\n",
            (unsigned long) buf.st_dev);
  //printf("lstat %d\n",buf.st_mode);

  stat("test1",&buf);
  printf("Mode testttt:                     %ld (octal)\n",
              (unsigned long) buf.st_dev);

  stat("test1/hello",&buf);
  printf("Mode hello:                     %lo (octal)\n",
              (unsigned long) buf.st_mode);


  return 0;
}
