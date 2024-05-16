#include "minishell.h"

void double_ptr_print(char **line)
{
    while (*line)
    {
        printf("^^^^^%s\n", *line);
        line++;
    }
}

void output_error(int err_num)
{
    printf("syntax error near unexpected token `newline'");
    printf("syntax error near unexpected token `|'");
    printf("syntax error near unexpected token `;'");
}

char **put_until_pipe(char **line, char **start_ptr)
{
    int len;
    int i;
    char **ret;

    len = line - start_ptr;
    i = 0;
    ret = (char **)malloc(len + 1);
    while (i < len)
    {
        ret[i] = *start_ptr;
        i++;
        start_ptr++;
    }
    ret[i] = NULL;
    return ret;
}

int is_return_one(char *s)
{
    if (!strcmp(s, "<") || !strcmp(s, ">") || !strcmp(s, "<<") || !strcmp(s, ">>"))
        return 1;
    return 0;
}

int judgment_return_one_or_two(char **until_pipe_stk)
{
    int word_count;

    word_count = 0;
    while (until_pipe_stk[word_count])
        word_count++;
    if (is_return_one(until_pipe_stk[word_count - 1]))
        return 1;
    return 0;
}

// 後ろが<, >, <<, >>, |、それ以外かチェックし、それぞれの処理に移行
//0:それ以外 次に移行
//1:<, >, <<, >>,エラー syntax error near unexpected token `newline'
//2: < |, > |, | |,エラー syntax error near unexpected token `|'
//3: syntax error near unexpected token `;'
//4:| 待ち受け
//よくわからんところ <| a| など |にくっつく時
//よくわからんところ <>
int check_per_pipe_line_ass(char **line)
{
    int i;
    int final_is_pipe;
    char **until_pipe_stk;
    char **start_ptr;

    i = 0;
    if (!ft_strcmp(*line, "|"))
        return 2;
    if (!ft_strcmp(*line, ";"))
        return 3;

     //ここの条件がおかしい！！！
    while (*line && (ft_strcmp(*line, "|") || ft_strcmp(*line, ";")))
    {
        final_is_pipe = 0;
        start_ptr = line;

        //ここの条件がおかしい！！！
        while (*line && (ft_strcmp(*line, "|") || ft_strcmp(*line, ";")))
            line++;


        //現時点でのlineは "|" or ";" or null
        printf("------%s\n", *line);
        until_pipe_stk = put_until_pipe(line, start_ptr);
        if (judgment_return_one_or_two(until_pipe_stk) && !*line)
            return 1;
        else if (judgment_return_one_or_two(until_pipe_stk) && !ft_strcmp(*line, "|"))
            return 2;
        else if (judgment_return_one_or_two(until_pipe_stk) && !ft_strcmp(*line, ";"))
            return 3;

         //ここの条件がおかしい！！！
        if (*line && (!ft_strcmp(*line, "|") || !ft_strcmp(*line, ";")))
        {
            
            if (!ft_strcmp(*line, "|"))
                final_is_pipe = 1;
            line++;
            if (!ft_strcmp(*line, "|"))
                return 2;
            if (!ft_strcmp(*line, ";"))
                return 3;
        }
    }
    if (final_is_pipe)
        return 4;
    return 0;
}



int count_for_rearrange_line(char **line)
{
    int count;

    count = 0;
    while (*line)
    {
        if (!ft_strcmp(*line, "|"))
            count += 1;
        if (!ft_strcmp(*line, ";"))
            count += 2;
        count++;
        line++;
    }
    count += 3;
    return 0;
}

/*
< infile cmd option > outfile |
で並び替える。
ロジック：消去法 - <, >を先に移動し、その後cmd option
*/
char **rearrange_line(char **line)
{
    char **ret;

    ret = (char **)malloc(count_for_rearrange_line(line) * sizeof(char *));
    while (*line)
    {
        line++;
    }
    return ret;   
}






char **lexer(char *line)
{
    char **first;
    int error_check;

    first = ft_split(line, ' '); 
    error_check = check_per_pipe_line_ass(first);
    // if (error_check == 0)
    //     rearrange_line(line);
    return first;
}

int main(int ac, char **av)
{
    // char *line = "cat < file1 | wc -l > file2 > file3 ; echo a | grep a; echo b";
    printf("%d \n", check_per_pipe_line_ass(ft_split(av[1], ' ')));
    /*
    words[0] = cat
words[1] = <
words[2] = file1
words[3] = NULL
words[4] = wc -l
words[5] = >
words[6] = file2
words[7] = >
words[8] = file3
words[9] = NULL
words[10] = NULL
words[11] = echo a
words[12] = NULL
words[13] = grep a
words[14] = NULL
words[15] = NULL
words[16] = echo b
words[17] = NULL
words[18] = NULL
words[19] = NULL
words[20] = NULL
    */
   return 0;
}