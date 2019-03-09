#include "types.h"
#include "stat.h"
#include "user.h"
char buf[5120000];
char *args;
int tail(int fd, char *name, int option_flag)
{
//	int final=0,k,p,q,index=0,m=0,l=0,b,n,i,count=0,count1 = 0; char pilot[10000];
//        char *output[10000];
//	int repeat[1000];
	int n,g=0,b=0,c=0,clc=1,l=0;
	
 while((n = read(fd, buf, sizeof(buf))) > 0)

        {  
		if(option_flag == 0)   // IF THE USER HAS ENTERED NO OPTION WITH TAIL
		{      
	//	printf(1,"Entering the loop");
			for(b=0; b<n; b++)
		 	{
                     		if(buf[b] == '\n')
                          		l++;  // LINE COUNTER
                 	}
	//	printf(1,"Number of lines = %d",l);
			if(l<=9)     // IF THE TOTAL NUMBER OF LINES IS LESS THAN OR EQUAL TO 10
			{
				for(g=0;g<n; g++)
                 		{
					printf(1,"%c",buf[g]);
				}
			}	
			else        // NO OPTION ENTERED AND THE LINES ARE GREATER THAN 10 THEN ONLY THE LAST 10 LINES GET PRINTED
			{
				for(c=0;c<n;c++)
				{	
					if(buf[c] == '\n')
						clc++;

					if(clc >= l-9 &&  clc <=l)
						printf(1,"%c",buf[c+1]);
				}
			}
		}
		else if(option_flag > 0) // USER HAS ENTERED NUMBER OF LINES TO BE PRINTED
		{
			 for(b=0; b<n; b++)
                 	{
                     		if(buf[b] == '\n')
                          		l++;
                 	}	
        //      printf(1,"Number of lines = %d",l);
			if(option_flag > l) // IF NUMBER OF TOTAL LINES IS LESSER THAN THE ONE REQUESTED BY THE USER
			{	
		      		for(g=0;g<n; g++)
                 		{
                        		printf(1,"%c",buf[g]);
                		}
			}
			else
			{
                        	for(c=0;c<n;c++)
                        	{
                                	if(buf[c] == '\n')
                                        	clc++;

                           		if(clc > l-option_flag &&  clc <=l)
                                        	printf(1,"%c",buf[c+1]);
                        	}
                	}
		}
	}
			
return 0;
}

int main(int argc, char **argv)
{
  int i,fd, r, number;char num[20];
  if(argc <= 1)
  {
    //uniq(0, "");
    printf(1,"tail: ERROR enter file name.\n");
    exit();
  }
  else if(argc == 2)
  {
  for(r = 1; r < argc; r++)
  {
    if((fd = open(argv[r], 0)) < 0)
    {
      printf(1,"tail: cannot open %s\n", argv[r]);
      exit();
    }
    tail(fd, argv[r],0);
    close(fd);
  }
  exit();
  }
  else if(argc == 3)
  {
    for(r = 2; r < argc; r++)
   {
    if((fd = open(argv[r], 0)) < 0)
    {
      printf(1,"tail: cannot open %s\n", argv[r]);
      exit();
    }
    args=argv[1];
    for(i=1;args[i]!='\0';i++)
    {
	num[i-1]=args[i];
    }
    num[i-1]='\0';
    number = atoi(num);
  //  printf(1,"The arguments are: %d",number);
    if(args[0] != '-')
	{
		printf(1,"tail: syntax error\n");
		exit();
	}
    tail(fd, argv[r],number);
    close(fd);
  }
  exit();
  }
 else {
	printf(1,"Tail : Error");
	exit();
	}
return 0;
} 
