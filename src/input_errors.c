
#include "../includes/push_swap.h"

int	ft_input_errors(int argc, char *argv[])
{
	(void) argc;
	(void) argv;
	// error =	same integer twice, 
	//			an argv isnt an integer (overflow/other ASCII) : argc > 2 case
	//			a splited value isnt an interger ("") : argc == 2 case
	return (0);
}
