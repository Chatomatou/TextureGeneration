#include <SDL2/SDL.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#define W 800
#define H 600

void textureA(SDL_Renderer** ppRenderer)
{
	Uint32 i = 0;
	Uint32 j = 0;
	 
	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			SDL_SetRenderDrawColor(*ppRenderer, rand() % 256, rand() % 256, rand() % 256, 255);
			SDL_RenderDrawPoint(*ppRenderer, j, i);
		}
	}

	SDL_RenderPresent(*ppRenderer);
}

void textureB(SDL_Renderer** ppRenderer)
{
	Uint32 i = 0;
	Uint32 j = 0;

	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			SDL_SetRenderDrawColor(*ppRenderer, i ^ j, i ^ j, i ^ j, 255);
			SDL_RenderDrawPoint(*ppRenderer, j, i);
		}
	}

	SDL_RenderPresent(*ppRenderer);
}

void textureC(SDL_Renderer** ppRenderer)
{
	Uint32 i = 0;
	Uint32 j = 0;

	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			SDL_SetRenderDrawColor(*ppRenderer, i | j, i | j, i | j, 255);
			SDL_RenderDrawPoint(*ppRenderer, j, i);
		}
	}

	SDL_RenderPresent(*ppRenderer);
}

void textureD(SDL_Renderer** ppRenderer)
{
	Uint32 i = 0;
	Uint32 j = 0;

	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			SDL_SetRenderDrawColor(*ppRenderer, i & j, i & j, i & j, 255);
			SDL_RenderDrawPoint(*ppRenderer, j, i);
		}
	}
 
	SDL_RenderPresent(*ppRenderer);
}

void textureE(SDL_Renderer** ppRenderer)
{
	Uint32 i = 0;
	Uint32 j = 0;

	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			SDL_SetRenderDrawColor(*ppRenderer, i + j, i + j, i + j, 255);
			SDL_RenderDrawPoint(*ppRenderer, j, i);
		}
	}

	SDL_RenderPresent(*ppRenderer);
}

void textureF(SDL_Renderer** ppRenderer)
{
	Uint32 i = 0;
	Uint32 j = 0;

	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			SDL_SetRenderDrawColor(*ppRenderer, i - j, i - j, i - j, 255);
			SDL_RenderDrawPoint(*ppRenderer, j, i);
		}
	}

	SDL_RenderPresent(*ppRenderer);
}

void textureG(SDL_Renderer** ppRenderer)
{
	Uint32 i = 0;
	Uint32 j = 0;

	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			SDL_SetRenderDrawColor(*ppRenderer, i * j, i * j, i * j, 255);
			SDL_RenderDrawPoint(*ppRenderer, j, i);
		}
	}

	SDL_RenderPresent(*ppRenderer);
}

void textureH(SDL_Renderer** ppRenderer)
{
	Uint32 i = 0;
	Uint32 j = 0;

	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			SDL_SetRenderDrawColor(*ppRenderer, i / (1+j), i / (1+j), i / (1+j), 255);
			SDL_RenderDrawPoint(*ppRenderer, j, i);
		}
	}

	SDL_RenderPresent(*ppRenderer);
}

void textureI(SDL_Renderer** ppRenderer)
{
	Uint32 i = 0;
	Uint32 j = 0;

	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			SDL_SetRenderDrawColor(*ppRenderer, i ^ j | 100, i ^ j | 100, i ^ j | 100, 255);
			SDL_RenderDrawPoint(*ppRenderer, j, i);
		}
	}

	SDL_RenderPresent(*ppRenderer);
}
 
void textureJ(SDL_Renderer** ppRenderer)
{
	Uint32 i = 0;
	Uint32 j = 0;

	for (i = 0; i < H; i++)
	{
		for (j = 0; j < W; j++)
		{
			SDL_SetRenderDrawColor(*ppRenderer, (i * i) + (j * j) % 256, (i * i) + (j * j) % 256, (i * i) + (j * j) % 256, 255);
			SDL_RenderDrawPoint(*ppRenderer, j, i);
		}
	}

	SDL_RenderPresent(*ppRenderer);
}

 

int main(int argc, char* argv[])
{
	SDL_Window* pWindow = NULL;
	SDL_Renderer* pRenderer = NULL;
	SDL_bool open = SDL_TRUE;
	SDL_Event events;
	Uint32 timer = 0;
	Uint32 index = 0;
	 
	void(*textures[])(SDL_Renderer**) = { textureA, textureB, textureC, textureD, textureE, textureF, textureG, textureH, textureI, textureJ };
	srand(time(NULL));

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init : %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	if (SDL_CreateWindowAndRenderer(W, H, SDL_WINDOW_SHOWN, &pWindow, &pRenderer) < 0)
	{
		SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_CreateWindowAndRenderer : %s\n", SDL_GetError());
		SDL_Quit();
		return EXIT_FAILURE;
	}

	SDL_SetWindowTitle(pWindow, "Texture Generation");

	while (open)
	{
		while (SDL_PollEvent(&events))
		{
			switch (events.type)
			{
			case SDL_QUIT:
				open = SDL_FALSE;
				break;
			}
		}

		SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
		SDL_RenderClear(pRenderer);
	
		timer += 16;

		if (timer > 1000)
		{

			timer = 0;
			if (index < 10)
			{
				textures[index](&pRenderer);
				index++;
			}
			else
			{
				index = 0;
			}
		}
 
		SDL_Delay(16);
 	}

	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);
	SDL_Quit();

	return EXIT_SUCCESS;
}