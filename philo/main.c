#include "philo.h"

// #include <libc.h>

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

/*
- 人以上の哲学者が円卓に座っている。
テーブルの中央にはスパゲッティが入った大きなボウルがある。
- 哲学者たちは交互に食べたり、考えたり、眠ったりする。
食べている間は考えもせず眠りもせず、考えている間は食べもせず眠りもしない；
そしてもちろん、眠っている間は食べてもいないし、考えてもいない。
- テーブルの上にはフォークもある。哲学者の数だけフォークがある。
- スパゲッティをフォーク1本で食べるのはとても不便なので、哲学者は右フォークと左フォークを使う。
哲学者は右手と左手にフォークを持って食べる。
- 哲学者は食べ終わるとフォークをテーブルに戻し、眠り始める。目が覚めると、再び思考を始める。哲学者が餓死すると、シミュレーションは停止する。
- すべての哲学者は食べる必要があり、決して飢えてはならない。
- 哲学者同士は話をしない。
- 哲学者は、他の哲学者が死のうとしているかどうかを知らない。
- 哲学者は死ぬことを避けるべきだなどと言う必要はない！
*/

/*
- あなたの（複数の）プログラムは以下の引数を取るべきである：
number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
◦ number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat］
number_of_philosophers: 哲学者の数とフォークの数。
time_to_die： 哲学者が最後の食事を始めてから、あるいはシミュレーションを始めてから、time_to_dieミリ秒経過しても食事を始めなかった場合、
            その哲学者は死ぬ。
time_to_eat： 哲学者が食事をするまでの時間。その間、2本のフォークを持つ必要がある。
time_to_sleep： 哲学者が睡眠に費やす時間。
number_of_times_each_philosopher_must_eat (オプション引数)： すべての哲学者がnumber_of_times_each_philosopher_must_eat回以上食事をした場合、
                        シミュレーションは停止します。指定がない場合、哲学者が死亡した時点でシミュレーションは停止します。
- 各哲学者は1からnumber_of_philosophersまでの番号を持ちます。
- 哲学者番号1は哲学者番号number_of_philosophersの隣に座ります。その他の哲学者番号Nは、哲学者番号N - 1と哲学者番号N + 1の間に位置する。
*/

/*
隣の人が食事できるかをmutex
*/

int free_config(t_config *config)
{
    if (config->philos != NULL)
	    free(config->philos);
    if (config->forks != NULL)
	    free(config->forks);
    if (config != NULL)
	    free(config);
    return 0;
}

int main(int ac, char **av)
{
    t_config *config;

    if (ac != 5 && ac != 6)
        return (0);
    config = init_config(av);
	if (!config)
		return free_config(config);
	ohhh_ikuzo(config);
    return free_config(config);
}
