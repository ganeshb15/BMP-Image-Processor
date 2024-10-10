
#include "BMP.h"




int***  pixel()
{
	int ***arr=MATRIX3D(width,height,3);

	
	unsigned char ch;
	fseek(image,bitoffset,SEEK_SET);
		
	for(int l=0;l<height;l++)
	{
		for(int k=0;k<width;k++)
		{
			if(bitcount==24)
			{
				fread(&ch,1,1,image);
				arr[k][height-l-1][0]=int(ch);

				fread(&ch,1,1,image);
				arr[k][height-l-1][1]=int(ch);
					
				fread(&ch,1,1,image);
				arr[k][height-l-1][2]=int(ch);
			}
			else
			{
				fread(&ch,1,1,image);
				arr[k][height-l-1][0]=int(ch);
				
			}
			
		}
		fseek(image,w,SEEK_CUR);
	}
	fclose(image);
	return arr;
}

