#include "sdl.h"
#include <iostream>
using namespace std;
#define SCREEN_WIDTH 660
#define SCREEN_HEIGHT  480
int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");
	int x=0;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "Извините СДЛ не хочет выходить";
		SDL_Quit();
		return 0;
	}
	else
	{
		SDL_Window* window = NULL;
		window = SDL_CreateWindow(u8"ЛАБАРАТОРКАААА", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			cout << "Извините окошко не хочет выходить";
			return 0;
		}
		else {
			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
			SDL_SetRenderDrawColor(renderer, 255, 192, 203, 0);
			SDL_RenderPresent(renderer);
			SDL_RenderClear(renderer);
			for (int j = 10; j <= 440; j += 20) {
				x++;
				if (x % 2 ==1) {
					for (int i = 20; i <= 600; i += 50) {
						SDL_SetRenderDrawColor(renderer, 255, 221, 91, 0);
						SDL_Rect rect1 = { i, j,50, 20 };
						SDL_RenderFillRect(renderer, &rect1);
						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
						SDL_RenderDrawRect(renderer, &rect1);
						SDL_RenderPresent(renderer);	
					}
				}
				else {
					for (int i = 20; i <= 600; i += 50){
						SDL_SetRenderDrawColor(renderer, 255, 221, 91, 0);
						SDL_Rect rect1 = { i+25, j,50, 20 };
						SDL_RenderFillRect(renderer, &rect1);
						SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
						SDL_RenderDrawRect(renderer, &rect1);
						SDL_RenderPresent(renderer);
					}
				}
			}
			SDL_RenderPresent(renderer);
			SDL_Delay(10000);
			SDL_DestroyWindow(window);
			SDL_DestroyRenderer(renderer);
		}
		SDL_Quit();
	}
	system("pause");
	return 0;
}