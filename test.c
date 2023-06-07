#include <csapp.h>

#define DEF_MOD S_IRUSR | S_IWUSR

int main(int argc, char** argv) {
    
    char buff[MAXBUF] = "this is a test messsage\n";
    int fd = Open("./test.txt", O_WRONLY | O_CREAT, DEF_MOD);
    Rio_writen(fd, buff, strlen(buff));
    Close(fd);
    return 0;
}