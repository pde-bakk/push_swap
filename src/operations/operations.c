//
// Created by Peer De bakker on 3/29/21.
//

#include "operations.h"
#include "libft.h"
#include "push_swap.h"

static void	error(t_collection *coll)
{
	(void)coll;
	ft_putendl_fd("Error. bad instruction", STDERR_FILENO);
}

t_opcode	string2opcode(const char *str)
{
	unsigned long int			i;
	static const char			*opcode_strings[] = {
			[SA] = "sa", [SB] = "sb", [SS] = "ss",
			[PA] = "pa", [PB] = "pb",
			[RA] = "ra", [RB] = "rb", [RR] = "rr",
			[RRA] = "rra", [RRB] = "rrb", [RRR] = "rrr"
	};

	i = 0;
	if (ft_strlen(str) < 2 || ft_strlen(str) > 3)
		return (ERROR);
	while (i < sizeof(*opcode_strings))
	{
		if (!ft_strncmp(str, opcode_strings[i], ft_strlen(str)))
		{
			return (i);
		}
		++i;
	}
	return (ERROR);
}

#ifdef CHECKER
static void	print_operation(const t_opcode opcode)
{
	(void)opcode;
}
#else
static void	print_operation(const t_opcode opcode)
{
	static const char			*op_stringcodes[] = {
			[SA] = "sa", [SB] = "sb", [SS] = "ss",
			[PA] = "pa", [PB] = "pb",
			[RA] = "ra", [RB] = "rb", [RR] = "rr",
			[RRA] = "rra", [RRB] = "rrb", [RRR] = "rrr", [ERROR] = "Error"
	};

	ft_putendl_fd(op_stringcodes[opcode], STDOUT_FILENO);
}
#endif

void	execute_operation(const t_opcode opcode, t_collection *collection)
{
	static const t_operation	operations[] = {
			[SA] = &sa, [SB] = &sb, [SS] = &ss,
			[PA] = &pa, [PB] = &pb,
			[RA] = &ra, [RB] = &rb, [RR] = &rr,
			[RRA] = &rra, [RRB] = &rrb, [RRR] = &rrr, [ERROR] = &error
	};

	print_operation(opcode);
	operations[opcode](collection);
}
