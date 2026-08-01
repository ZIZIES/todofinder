#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
   char path[1024];
   int linenum = 1;
   char line[1024];

      if (argc < 2) {
          printf("usage: todofinder <directory>\n");
          return 1;
       }

      DIR *d = opendir(argv[1]);
    struct dirent *entry;

    while ((entry = readdir(d)) != NULL) {
    if (entry->d_name[0] == '.') continue;
       char *currentFile = entry->d_name;

       snprintf(path, sizeof(path), "%s/%s", argv[1], entry->d_name);
      FILE *f = fopen(path, "r");

      if (f == NULL) {
         printf("todofinder: failed to open source file\n");
         return 1;
      }

      while (fgets(line, sizeof(line), f) != NULL) {
         if (strstr(line, "TODO") || strstr(line, "FIXME")) {
            printf("line %d, %s: %s", linenum, path, line);
            
         }
         linenum++;
   }
   linenum = 1;
   fclose(f);
   }

    closedir(d);

}