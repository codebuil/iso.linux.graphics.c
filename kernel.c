

void pixels(char b,int loc)
        {
        		   int i=loc;
			   char *fbp=(char* )i;
			   	*((char *)(fbp)) =(char)b;
			   		  
        }
void vline(int x,int y,int y1,char b)
{
	int i=0xa0000;
	int xx=y*320+x;
	int yyy=y1-y;
	int xxxx=0;
	int c=0;
	if (y1>=y && x<320 && x>-1 && y>-1 && y<200  && y1>-1 && y1<200)
	{
		
			   
			   for(c=0;c<(yyy*320);c=c+320)
			   	pixels(b,i+c+xx);
	}
	
}
void hline(int x,int y,int x1,char b)
{
	int i=0xa0000;
	int xx=y*320+x;
	int xxx=x1-x;
	int xxxx=0;
	int c=0;
	if (x1>=x && x<320 && x>-1 && y>-1 && y<200 && x1<320 && x1>-1)
	{
		
			   
			   for(c=0;c<xxx;c=c+1)
			   	pixels(b,i+c+xx);
	}
	
}
void box(int x,int y,int x1,int y1,char b)
{
	int n=0;
	int nn=y1-y;
	if (y1>=y && x1>=x && x<320 && x>-1 && y>-1 && y<200 && x1<320 && x1>-1 && y1>-1 && y1<200){
	for (n=0;n<nn;n=n+1)   
			hline(x,n+y,x1,0);
			}
}
 void cls()
 {
 			   int i=0xa0000;
			   char b=1;
			   int c=0;
			   for(c=0;c<65000;c=c+1)
			   	pixels(b,i+c);
 } 
 
 int kernel_main()
        {
			   
		int n=0;	   
		cls();
		for (n=0;n<200;n=n+8)   
			hline(0,n,319,0);
		for (n=0;n<320;n=n+8)   
			vline(n,0,199,0);
		box(150,75,175,100,0);	   	
			   
		return 0;	  
        }
 

