#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 関数プロトタイプの宣言
char **ft_split_for_Lexer(char *line);
void free_split(char **ret);

int main(int ac, char **av) {
    char **ret = ft_split_for_Lexer(av[1]);
    
    if (ret) {
        for (int i = 0; ret[i] != NULL; i++) {
            printf("ret[%d]: %s\n", i, ret[i]);
        }
        
        free_split(ret);
    }

    return 0;
}

char **ft_split_for_Lexer(char *line) {
    int in_double_quotes;
    int in_single_quotes;
    char *start;
    char *p;
    char **ret;

    int index = 0;
    in_double_quotes = 0;
    in_single_quotes = 0;
    ret = malloc(10 * sizeof(char*));
    if (!ret)
        return NULL;
    start = NULL;
    p = line;

    while (*p) {
        if (*p == '\"' && !in_single_quotes) {
            in_double_quotes = !in_double_quotes;
        } else if (*p == '\'' && !in_double_quotes) {
            in_single_quotes = !in_single_quotes;
        }
        if (!in_double_quotes && !in_single_quotes && *p == ' ') {
            if (start) {
                int len = p - start;
                ret[index] = malloc(len + 1);
                if (!ret[index]) {
                    free_split(ret);
                    return NULL;
                }
                ft_strncpy(ret[index], start, len);
                ret[index][len] = '\0';
                index++;
                start = NULL;
            }
        } else if (!start) {
            start = p;
        }
        p++;
    }
    if (start) {
        ret[index] = strdup(start);
        if (!ret[index]) {
            free_split(ret);
            return NULL;
        }
        index++;
    }
    ret[index] = NULL;
    return ret;
}

void free_split(char **ret) {
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
}