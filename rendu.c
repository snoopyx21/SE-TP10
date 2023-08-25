#include <signal.h>

int main(int argc, char ** argv)
{
    int fo;
    sigest_t s;

    if(argc < 3)
    {
        printf("wrong nb arg \n");
        return 1;
    }
    
    fo=open("toto", O_WRONLY | O_RDONLY | O_CREAT, 0666);
    if (fo ==-1)
    {
        perror("open");
        return -1;
    }
    
    
    sigemptyset(&s);
    sigaddset(&s, SIGINT);
    if(sigprocmask(SIG_BLOCK, &s, NULL) == -1)
    {
        perror("sigprocmask");
        return -1;
    } 

    return 0;
}
