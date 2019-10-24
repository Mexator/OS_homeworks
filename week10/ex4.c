#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#define FILES_IN_DIR 100
typedef struct dirent Dirent;
int main(int argc, char *argv[])
{
    const char dir_name[] = "tmp/";
    DIR *dir_pointer = opendir(dir_name);
    Dirent *Dir;
    struct stat *file_stat = malloc(sizeof(struct stat));
    int processed_inodes[FILES_IN_DIR] = {0};
    while ((Dir = readdir(dir_pointer)) != NULL)
    {
        char filename[256] = {0};
        strcat(filename, dir_name);
        strcat(filename, Dir->d_name);
        int f = stat(filename, file_stat);
        if (file_stat->st_nlink >= 2)
        {
            int found = 0;
            for (int i = 0; i < FILES_IN_DIR && !found; i++)
            {
                if (processed_inodes[i] == 0)
                {
                    printf("For inode %d:\n", file_stat->st_ino);
                    fflush(stdout);
                    char string[50] = "sudo find / -inum ";
                    sprintf(string, "%s%d", string, file_stat->st_ino);
                    system(string);
                    processed_inodes[i] = file_stat->st_ino;
                    found = 1;
                }
                else if (processed_inodes[i] == file_stat->st_ino)
                {
                    found = 1;
                }
            }
        }
    }
}