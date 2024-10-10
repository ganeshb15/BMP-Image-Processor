
#include "BMP.h"

FILE *image;
int width;
int height;
int bitcount;
int bitoffset;
int w;
const char* name1; 



void header(const char* name  )
{
	
	image=fopen(name,"rb+");
	name1=name;
	HEADER h;	
	
	fseek(image,18,SEEK_SET);
	fread(&h.width,4,1,image);
	width=int(h.width);
	

	fseek(image,22,SEEK_SET);
	fread(&h.height,4,1,image);
	height=int(h.height);
	
	fseek(image,28,SEEK_SET);
	fread(&h.bitcount,2,1,image);
	bitcount=int(h.bitcount);
		 
	fseek(image,10,SEEK_SET);
	fread(&h. 	bitoffset,4,1,image);
	bitoffset=int(h.bitoffset);
	if(width%4==0)
	w=0;
	else
	{
		if(int(bitcount)==24)
		{
			w=4-((width*3)%4);

		}
		else
			w=4-(width%4);
	}
	
}


