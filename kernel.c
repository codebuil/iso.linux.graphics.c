void invertScreenRightToLeft() {
    unsigned char *videoMemory = (unsigned char *)0xA0000;
    int screenWidth = 320; // Largura da tela em pixels
    int screenHeight = 200; // Altura da tela em pixels
    int middleLine = screenHeight / 2; // Linha do meio (se ímpar, não se mexe)
    
    unsigned char temp;
    
    for (int y = 0; y < screenHeight; y++) {
        int offset = y * screenWidth;
        
        for (int x = 0; x < screenWidth / 2; x++) {
            // Troca os valores dos pixels da direita para a esquerda
            temp = videoMemory[offset + x];
            videoMemory[offset + x] = videoMemory[offset + (screenWidth - x - 1)];
            videoMemory[offset + (screenWidth - x - 1)] = temp;
        }
    }
}


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
		for (n=0;n<280;n=n+8)   
			hline(0,n,319,0);
		for (n=0;n<300;n=n+8)   
			vline(n,0,199,0);
		box(150,75,175,100,0);	   	
		invertScreenRightToLeft();	   
		return 0;	  
        }
 

