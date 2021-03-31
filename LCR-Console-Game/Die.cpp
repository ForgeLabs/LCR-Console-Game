#include "Die.h"

Die::Die() {
	value = 1;
	face = 'n';

}

void Die::roll_die() {
	value = ((rand() % 6) + 1);

	if (value % 2 == 0) //die is even ( * rolled)
		face = '*';
	else if (value == 1)
		face = 'L';
	else if (value == 3)
		face = 'C';
	else if (value == 5)
		face = 'R';

}

int Die::get_value()
{
	return value;
}

char Die::get_face()
{
	return face;
}
