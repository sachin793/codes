/*
* AUTHOR: Sachin agarwal	
* REG NO: 20164006 
*/

/* In this file I am reading the file until the file descripter do not find any character if the file descripter reaches the end then
*  it will return 0.
*/
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<ctype.h>
int main(int args,char * argv[])
{
        if(args!=2)
        printf("Please specify only a filename\n",args);
        else
        {
                int fd1;
                char c;
                printf("you looked for the file %s\n",argv[1]);
                fd1=open(argv[1],O_RDONLY);
                if(fd1==-1)
                printf("Error in opening the file\n");
                else
                {       while(read(fd1,&c,1)!=0)
                        {
                                if(isalpha(c))
                                {
                                printf("%c",toupper(c));
                                } 
                                else
                                printf("%c",c); 
                        }
                        close(fd1);
                }
        }
}
