#include "minishell.h"

typedef struct s_split
{
    int in_double_quotes;
    int in_single_quotes;
    int *index;   
} t_split;


void *free_split(char **ret) {
    int i;

    i = 0;
    if (ret) {
        while (ret[i])
        {
            free(ret[i]);
            i++;
        }
        free(ret);
    }
    return NULL;
}

int is_remove_quotes(char **line)
{
    return 1;
}

static void init(t_split *data, int *index, char *start)
{
    data->in_double_quotes = 0;
    data->in_single_quotes = 0;
    *index = 0;
    start = NULL;
}

char **ft_split_for_lexer(char *line) 
{
    t_split data;
    int index;
    char *start;
    char **ret;

    init(&data, &index, start);
    ret = malloc(10 * sizeof(char*));
    if (!ret)
        return NULL;
    while (*line) {
        if (*line == '\"' && !data.in_single_quotes)
            data.in_double_quotes = !data.in_double_quotes;
        else if (*line == '\'' && !data.in_double_quotes) 
            data.in_single_quotes = !data.in_single_quotes;
        if (!data.in_double_quotes && !data.in_single_quotes && *line == ' ') {
            if (start) {
                int len = line - start;
                ret[index] = malloc(len + 1);
                if (!ret[index]) 
                    return free_split(ret);
                ft_strncpy(ret[index], start, len);
                ret[index][len] = '\0';
                index++;
                start = NULL;
            }
        } 
        else if (!start)
            start = line;
        line++;
    }
    if (start) {
        ret[index] = ft_strdup(start);
        if (!ret[index]) 
            return free_split(ret);
        index++;
    }
    ret[index] = NULL;
    return ret;
}

int main(int ac, char **av) {
    char **ret = ft_split_for_lexer(av[1]);
    
    if (ret) {
        for (int i = 0; ret[i] != NULL; i++) {
            printf("ret[%d]: %s\n", i, ret[i]);
        }
        
        free_split(ret);
    }

    return 0;
}