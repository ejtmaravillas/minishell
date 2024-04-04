/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaravil <emaravil@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:17:37 by emaravil          #+#    #+#             */
/*   Updated: 2024/04/04 21:59:08 by emaravil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../lib/libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>

# define AND_IF		"&&"
# define AMPS_AND	"&"
# define OR_IF		"||"
# define DSEMI		";;"
# define DLESS		"<<"
# define LESSAND	"<&"
# define DGREAT		">>"
# define GREATAND	">&"
# define LESSGREAT	"<>"
# define DLESSDASH	"<<-"
# define CLOBBER	">|"
# define LBRACE 	"{"
# define RBRACE		"}"
# define LPARAN		"("
# define RPARAN		")"
# define D_SIGN		"$"

typedef enum nodetype
{
	s_cmnd,
	c_cmnd,
	ppln,
	rdrn,
	io_file,
	io_here,
	argmnt,
	errmsg,
}	t_nodetype;

typedef struct ast_node
{
	t_nodetype			ntype;
	char				*value;
	char				*errmsg;
	struct ast_node		**child;
	size_t				num_child;
}	t_astnode;

void		ft_printstr(char **str_split);
int			strsplit_count(char **str_split);
void		ft_freesplit(char **str);

t_astnode	*create_node(t_nodetype ntype, const char *value);
void		free_ast(t_astnode *root);
void		addnode_child(t_astnode *parent, t_astnode *child);
void		skip_whitespace(const char **cmnd);
t_astnode	*p_arg(const char **cmnd, char **errmsg);
int			strsplit_size(char **str);
char		*ft_checkoperator(char *c);
char		*ft_tokenize(char *out, char *c, int len);
int			ft_checknextchar(char *c, int index);
int			ft_checknextcharb(char *c, int index);
int			ft_checknextcharc(char *c, int index);
int			ft_handleredir(char *out, char *c, int index, int offset);
int			ft_handleoper(char *out, char *c, int index, int offset);
int			ft_checksyntax(char *str);
int			ft_checksquotes(char *str);
int			ft_checkdquotes(char *str);
int			ft_checkparenthesis(char *str);
int			ft_checkcbrackets(char *str);
char		**ft_splittoken(char *str);
char		*ft_assignstring(char *in, char *str, int start, int end);
char		**ft_realloc_dp(char **s, char *input, int len);
int			ft_strlen_dp(char **s);
void		free_pointer(char *s);
#endif