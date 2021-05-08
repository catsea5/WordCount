#include <stdio.h>
#include <string.h>
#include<malloc.h>

//计算单词数 
int Word_Count(char *filename)
{
	FILE *fp=NULL;  
	FILE *fp2=NULL;
    char s[1024];  
    char c; 
    int len,i,sum=0;   
    int end = 0;  
    int wordNum = 0; 
    if((fp=fopen(filename,"rb"))==NULL)
	{
        perror(filename);
        return NULL;
    }
    
    while(fgets(s,1024,fp)!=NULL)
	{
        len=strlen(s);
        
        for(i=0;i<len;i++)
		{
            c=s[i];
            if(c==','||c==' '||c=='\t')
			{  
                !end && wordNum++; 
                end = 1;
            }
			else if(c!='\n'&&c!='\r')
			{  
                end = 0;
            }
        }
        !end && wordNum++;  
        end = 1;  
        sum += wordNum;  
        wordNum = 0;
    }
    printf("总单词数:%d ",sum);
	return 0;
}
//计算字符数 
int Char_Count(char *filename)
{
	
	FILE *fp=NULL;
	FILE *fp2=NULL;  
    char s[1024];   
	int sum=0;
	if((fp=fopen(filename, "rb"))==NULL)
	{
	    perror(filename);
	    return NULL;
	}
	fgets(s, 1024, fp);
	sum = strlen(s);
    printf("总字符数:%d",sum);
	return 0;
}

int main(int argc,char* argv[])
{

	// 判断要执行的功能 
      if(!strcmp(argv[1],"-w")) 
      	 Word_Count(argv[2]);                
      else if(!strcmp(argv[1],"-c"))  
		 Char_Count(argv[2]);                
		 
        return 0;
}


	


