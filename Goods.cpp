#include"Goods.h"

bool Goods::operator==(const Goods G)
{
	if (this->id == G.id) {
		return true;
	}
	else
	{
		return false;
	}
}
