#include "erosion.h"
#include <bits/stdc++.h>
//Main Function
int main( int argc, char* args[] ) {
	
	//Load / Generate a World
	World world;
	world.generate();
	
	/*
	||																	 ||
	|| Truc que j'ai rajoutez pour mesurez le temps pris par une erosion ||
	|| @Guillaume														 ||
	*/
	time_t start, end;
	time(&start);
    std::ios_base::sync_with_stdio(false);

	//Main Game Loop
	while(true)
	{
	//Do Erosion Cycles!
    if(world.active )
	{
    	world.erode(world.erosionstep);
			world.remaining -= world.erosionstep;
			world.updated = true;

			if(world.remaining <= 0){
				world.active = false;
				world.remaining = 0;
				break;
			}
		}
	}

	/*
	||																					||
	|| Truc que j'ai rajoutez pour sauvez le terrain genere en .ppm format image chelou ||
	|| @Guillaume																        ||
	*/
	std::cout<<"... Done Erroding ..."<<std::endl;
		FILE *f = fopen("out.ppm", "wb");
		int width = world.dim.x;
		int height = world.dim.y;
		float pixel_value;

		fprintf(f, "P6\n%i %i 255\n", width, height);
		for (int y=0; y<height; y++) 
		{
    		for (int x=0; x<width; x++) 
			{
				pixel_value = world.heightmap[x][y];
        		fputc(pixel_value*255, f);   // 0 .. 255
        		fputc(pixel_value*255, f); // 0 .. 255
        		fputc(pixel_value*255, f);  // 0 .. 255
    		}
		}
fclose(f);
/*
||																	 ||
|| Truc que j'ai rajoutez pour mesurez le temps pris par une erosion ||
|| @Guillaume													     ||
*/
time(&end);
std::cout<<"... Image Generated ..."<<std::endl;
    double time_taken = double(end - start);
    std::cout << "... Time taken by program is : " << std::fixed
         << time_taken << std::setprecision(5);
    std::cout << " sec ..." << std::endl;

	return 0;
}
