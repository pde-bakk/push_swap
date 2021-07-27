//
// Created by peerdb on 02-04-21.
//

#include "push_swap.h"
#include "libft.h"
#include "get_next_line.h"
#include "stack.h"
#include "operations.h"
#include "ft_printf.h"

static void	clearline(char **line)
{
	free(*line);
	*line = NULL;
}

#ifdef OPCOUNT

static void	print_status(const char *status, const unsigned int op_count)
{
	ft_dprintf(STDOUT_FILENO, "[%s] in %u instructions.\n", status, op_count);
}

#else

static void	print_status(const char *status, const unsigned int op_count)
{
	(void)op_count;
	ft_dprintf(STDOUT_FILENO, "[%s]\n", status);
}

#endif

void	checker(t_collection *coll)
{
	static const char	*is_sorted_msg[] = {"KO", "OK"};
	char				*line;
	t_opcode			opcode;
	unsigned int		op_count;

	op_count = 0;
	while (get_next_line(0, &line) > 0)
	{
		opcode = string2opcode(line);
		execute_operation(opcode, coll);
		if (opcode != ERROR)
		{
			++op_count;
		}
		clearline(&line);
	}
	clearline(&line);
	print_status(is_sorted_msg[(int) sort_is_done(coll)], op_count);
}

int	main(int argc, char **argv)
{
	t_collection	*coll;

	coll = create_stacks();
	if (argc == 1)
		return (cleanup(coll));
	else if (argc == 2)
		parse_split_array(coll, argv[1]);
	else
		parse_array(coll, argv, 1);
	checker(coll);
	return (cleanup(coll));
}
