#include"Bill.h"

bool Bill::operator==(const Bill B)
{
	if (this->Bill_ID == B.Bill_ID) {
		return true;
	}
	else
	{
		return false;
	}
}

