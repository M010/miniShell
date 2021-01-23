#include <error_tools.h>
#include <ft_stdio.h>
#include <ft_string.h>
#include <ft_stdlib.h>

extern unsigned char g_question;

int bi_exit(int argc, char **argv, char **envp)
{
	(void)envp;
	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (argc == 1)
		exit(g_question);
	if(!ft_strisnumeric(argv[1]))
	{
		ft_putstr_fd("bash: exit: ", STDERR_FILENO);
		ft_putstr_fd(argv[1] , STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit(2);
	}
	if(argc > 2)
		return (putstr_err("bash: exit: too many arguments\n", 1));
	exit(ft_atoi(argv[1]));
}