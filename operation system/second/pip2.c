#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <signal.h>


int main()
{
    pid_t pid_A;
    pid_t pid_B;    
    int pipefd[2];
    char a_buffer[10];
    char b_buffer[10];       
    
    /*1.创建管道*/
    pipe(pipefd);
    
    /*2.创建子进程A*/    
    pid_A = fork();
    
    if( pid_A > 0 )
    {
        /*父进程操作*/
        pid_B = fork();
        if( pid_B > 0 )
        {
            /*父进程操作*/
            printf("This is father process\n");
            /*父进程读A数据*/
            read(pipefd[0], a_buffer, 8);       
            /*等待A进程退出*/
            wait(NULL);
            printf("father read:%s\n",a_buffer);
                        
            /*父进程读B数据*/
            read(pipefd[0], b_buffer, 8);       
            /*等待B进程退出*/
            wait(NULL);        
                    

            printf("father read:%s\n",b_buffer);
            
            close(pipefd[0]);
                    
        }else{
            /*子进程B操作*/   
                     
            /*锁定写入端*/
            lockf(pipefd[1],1,0);
            /*写入数据*/
            write(pipefd[1], "Hello_B",8);
            sleep(5);
            lockf(pipefd[1],0,0); 
            exit(0);         
        }
    }else{
        /*锁定写入端*/
        lockf(pipefd[1],1,0);
        /*写入数据*/
        write(pipefd[1], "Hello_A",8);
        sleep(5);
        lockf(pipefd[1],0,0);  

        close(pipefd[1]);              
        exit(0);  
    }
        
    exit(0);
}

