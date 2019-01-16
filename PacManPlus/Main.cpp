#include "Game.h"

#include <memory>

void main(int argc, char* argv[])
{
	//std::shared_ptr<Game> game = std::make_shared<Game>(argv[1]);
	std::shared_ptr<Game> game = std::make_shared<Game>("map.txt");
	game->go();
}