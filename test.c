// test file use rio to write hello world to rst.txt
#include <csapp.h>

#define DEF_MOD S_IRUSR | S_IWUSR

int main(int argc, char** args) {
    rio_t rio;
    int fd = Open("./rst.txt", O_WRONLY | O_CREAT, DEF_MOD);
    // redirect stdout to file descriptor fd
    Dup2(fd, STDOUT_FILENO);
    printf("hello world!");
    Close(fd);
    return 0;
}
