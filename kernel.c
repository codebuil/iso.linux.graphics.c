 void printc(char b,int loc)
        {
        		   int i=loc;
			   char *fbp=(char* )i;
			   	*((char *)(fbp)) =(char)0x1;
			   		  
        }
 void kernel_main()
        {
			   int i=0xa0000;
			   char b='*';
			   int c=0;
			   for(c=0;c<65000;c=c+1)
			   printc(b,i+c);
			   
			   
			   	
			   
			  
        }
 

