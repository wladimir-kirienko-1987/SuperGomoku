//The headers
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include <string>

#include "Board.h"
#include "BoardView.h"
#include "BoardControl.h"

int main(int argc, char* argv[])
{
	//Make sure the program waits for a quit
	bool quit = false;
	//Модель доски
	Board b;
	//Вид доски
	BoardView V(&b);
	//Управление доской
	BoardControl C(&b);

	//Инициализировать видео
	//звгрузить файлы
	if ( V.BoardViewInit() )
	{
		return 1;
	}

	//Нужно ли обновлять доску
	bool NeedUpdate = false;
	//Первый игрок за крестики
	player player = X_PLAYER;

	//Основной цикл 
	while( quit == false )
	{
		//Проверка событий от пользователя
		quit = C.CheckControlEvents(player, NeedUpdate);
		
		
		
		//Обновление доски
		if ( V.UpdateView(NeedUpdate))
		{
			return 1;
		}




	}

	//Очистка ресурсов в деструкторе BoardView V
	return 0; 

}

