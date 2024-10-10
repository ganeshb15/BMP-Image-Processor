
#include "bmp/BMP.h"

int main()
{
	header("1.bmp");

	int ***arr1=MATRIX3D(width,height,3);
	
	//printf("%d \n",width);
	int ***e;

	e=pixel();
	for(int l=1;l<height-1;l=l+2)
	{
		
		for(int k=1;k<width-1;k=k+2)
		{
			

			if(e[k][l][0]>150 && e[k][l][1]>150 && e[k][l][2]>150)
			{


				arr1[k][l][0]=255;
				arr1[k][l][1]=255;
				arr1[k][l][2]=255;
				printf("00");
			}
			else
			{
				arr1[k][l][0]=0;
				arr1[k][l][1]=0;
				arr1[k][l][2]=0;
				printf("11");
			}


	

			
			
		}
		printf("\n");
				
	}
	write(arr1);

	
	return 0;
}


