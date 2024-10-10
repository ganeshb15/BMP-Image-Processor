
#include "BMP.h"

void grey_image(int *** arr);
void write(int *** arr)
{
	if(bitcount==8)
	{	
		int ***i;
		grey_image(arr);
		return;
	}
	
	FILE *image;
	

	HEADER h;
	
	image=fopen("out.bmp","wb+");

	char i[54]={0}; 
	fwrite (i, sizeof(char), sizeof(i),image);
	fseek(image,0,SEEK_SET);
	char m[2]={'B','M'}; 
	fwrite (m, sizeof(char), sizeof(m),image);
		
	
	h.width=width;
	
	h.height=height;
	fseek(image,18,SEEK_SET);
	fwrite(&h.width,4,1,image);
	
	fseek(image,22,SEEK_SET);
	fwrite(&h.height,4,1,image);


	unsigned short biPlanes=1;
	fseek(image,26,SEEK_SET);
	fwrite(&biPlanes,2,1,image);

	h.bitcount=bitcount;
	
	fseek(image,28,SEEK_SET);
	fwrite(&h.bitcount,2,1,image);

	h.bitoffset=54;
	fseek(image,10,SEEK_SET);
	fwrite(&h.bitoffset,4,1,image);

	unsigned int biSize=40;
	fseek(image,14,SEEK_SET);
	fwrite(&biSize,4,1,image);

	int x=1;
	if(bitcount==24)
	x=3;
	

	unsigned int size=(((width*x)+w)*height)+54;
	fseek(image,2,SEEK_SET);
	fwrite(&size,4,1,image);

	fseek(image,54,SEEK_SET);
	unsigned char g=0;
	
	for(int l=0;l<height;l++)
	{
		
		for(int k=0;k<width;k++)
		{
			if(bitcount==24)
			{
				g=arr[k][height-l-1][0];
				fwrite (&g, 1, 1,image);
				g=arr[k][height-l-1][1];
				fwrite (&g, 1, 1,image);
				g=arr[k][height-l-1][2];
				fwrite (&g, 1, 1,image);
			}
			else
			{
				
				
				g=int(arr[k][height-l-1][0]);

				fwrite (&g, 1, 1,image);
			}
		
			
			
			

		}
		g=0;
		fwrite (&g, w,1 ,image);
		

		
		
		
	}
	fclose(image);
}
void grey_image(int *** arr)
{
	FILE *image;
	FILE *image1;
	image=fopen(name1,"rb+");
	char ch;


	image1=fopen("out.bmp","wb+");
	int i=0;
	while(!feof(image))
	{
		fread(&ch,sizeof(char),sizeof(ch),image);
		fwrite (&ch, sizeof(char), sizeof(ch),image1);
		i++;
	}
	fseek(image1,bitoffset,SEEK_SET);
	for(int l=0;l<height;l++)
	{
		
		for(int k=0;k<width;k++)
		{
			
				unsigned char g=arr[k][height-l-1][0];
				
				

				fwrite (&g, 1, 1,image1);
				
			
		}
		fseek(image1,w,SEEK_CUR);
			
	}
	fclose(image);
	fclose(image1);
	
}

