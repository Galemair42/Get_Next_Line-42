#include "get_next_line.h"

int main(int ac, char **av)
{
	char *line;
	int	ret;

	while ((ret = get_next_line(0, &line)) > 0)
	{
		printf("return = %d : %s\n", ret, line);
		free(line);
	}
	return 0;
}
