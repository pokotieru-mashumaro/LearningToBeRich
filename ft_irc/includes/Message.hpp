#ifndef Message_HPP
#define Message_HPP

#define RED "\e[1;31m"
#define WHI "\e[0;37m"
#define GRE "\e[1;32m"
#define YEL "\e[1;33m"

#define INPUT_PASSWORD "パスワード： "
#define AUTH_SUCCESS YEL\
                    "\n\n██╗██████╗░░█████╗░\n"\
                    "██║██╔══██╗██╔══██╗\n"\
                    "██║██████╔╝██║░░╚═╝\n"\
                    "██║██╔══██╗██║░░██╗ \n"\
                    "██║██║░░██║╚█████╔╝\n"\
                    "╚═╝╚═╝░░╚═╝░╚════╝░\n"\
                    WHI\
                    "\n\nニックネーム： "
#define AUTH_FAIL "パスワード： "

#define INPUT_NICKNAME "ニックネーム　： "
#define INPUT_USERNAME "ユーザーネーム： "

#define HELLO_HOME YEL\
                    "現在あなたは以下のコマンドを実行できます! \n" \
                    "- OPEN: チャンネルを開きます\n" \
                    "- JOIN: チャンネルに参加します\n" \
                    WHI\
                    "\n" \
                    "> "

// #define HHH

#endif