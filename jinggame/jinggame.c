//感谢 vim 缓存文件拯救误删代码
//把部分 int 换成 char 了直接输出 'X' 和 'O'

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    srand(time(0));
    char p1 = ' ', p2 = ' ', p3 = ' ', p4 = ' ', p5 = ' ', p6 = ' ', p7 = ' ',
	 p8 = ' ', p9 = ' ';
    int winer = 0, cp = 0, pp = 0, loop = 0, b = 0;

    printf("X : YOU\n○ : CPU\n");
    for (loop = 0; loop < 9; loop = loop + 2) {
	printf("\n%c│%c│%c\n─┼─┼─\n%c│%c│%c\n─┼─┼─\n%c│%c│%c\n\n", p1, p2, p3,
	p4, p5, p6, p7, p8, p9);

	//玩家输入
    rpp:
	printf("\n输入你的位置:");
	scanf("%d", &pp);
	switch (pp) {
	    case 1:
		if (p1 == ' ') {
		    p1 = 'X';
		    break;
		} else {
		    printf("输入的值被占用");
		    goto rpp;
		}

	    case 2:
		if (p2 == ' ') {
		    p2 = 'X';
		    break;
		} else {
		    printf("输入的值被占用");
		    goto rpp;
		}

	    case 3:
		if (p3 == ' ') {
		    p3 = 'X';
		    break;
		} else {
		    printf("输入的值被占用");
		    goto rpp;
		}

	    case 4:
		if (p4 == ' ') {
		    p4 = 'X';
		    break;
		} else {
		    printf("输入的值被占用");
		    goto rpp;
		}

	    case 5:
		if (p5 == ' ') {
		    p5 = 'X';
		    break;
		} else {
		    printf("输入的值被占用");
		    goto rpp;
		}

	    case 6:
		if (p6 == ' ') {
		    p6 = 'X';
		    break;
		} else {
		    printf("输入的值被占用");
		    goto rpp;
		}

	    case 7:
		if (p7 == ' ') {
		    p7 = 'X';
		    break;
		} else {
		    printf("输入的值被占用");
		    goto rpp;
		}

	    case 8:
		if (p8 == ' ') {
		    p8 = 'X';
		    break;
		} else {
		    printf("输入的值被占用");
		    goto rpp;
		}

	    case 9:
		if (p9 == ' ') {
		    p9 = 'X';
		    break;
		} else {
		    printf("输入的值被占用");
		    goto rpp;
		}
	    default:
		printf("无效的位置");
		goto rpp;
	}
	//判断输赢(玩家)
	if (p1 == 'X' && p2 == 'X' && p3 == 'X') {
	    winer = 1;
	    goto wined;
	} else if (p4 == 'X' && p5 == 'X' && p6 == 'X') {
	    winer = 1;
	    goto wined;
	} else if (p7 == 'X' && p8 == 'X' && p9 == 'X') {
	    winer = 1;
	    goto wined;
	} else if (p1 == 'X' && p4 == 'X' && p7 == 'X') {
	    winer = 1;
	    goto wined;
	} else if (p2 == 'X' && p5 == 'X' && p8 == 'X') {
	    winer = 1;
	    goto wined;
	} else if (p3 == 'X' && p6 == 'X' && p9 == 'X') {
	    winer = 1;
	    goto wined;
	} else if (p1 == 'X' && p5 == 'X' && p9 == 'X') {
	    winer = 1;
	    goto wined;
	} else if (p3 == 'X' && p5 == 'X' && p7 == 'X') {
	    winer = 1;
	    goto wined;
	}
	if (loop > 6) {
	    goto wined;
	}

	//电脑随机数
	do {
	rcp:
	    cp = rand() % 10;
	} while (cp == 0);
	switch (cp) {
	    case 1:
		if (p1 == ' ') {
		    p1 = 'O';
		    break;
		} else {
		    goto rcp;
		}

	    case 2:
		if (p2 == ' ') {
		    p2 = 'O';
		    break;
		} else {
		    goto rcp;
		}

	    case 3:
		if (p3 == ' ') {
		    p3 = 'O';
		    break;
		} else {
		    goto rcp;
		}

	    case 4:
		if (p4 == ' ') {
		    p4 = 'O';
		    break;
		} else {
		    goto rcp;
		}

	    case 5:
		if (p5 == ' ') {
		    p5 = 'O';
		    break;
		} else {
		    goto rcp;
		}

	    case 6:
		if (p6 == ' ') {
		    p6 = 'O';
		    break;
		} else {
		    goto rcp;
		}

	    case 7:
		if (p7 == ' ') {
		    p7 = 'O';
		    break;
		} else {
		    goto rcp;
		}

	    case 8:
		if (p8 == ' ') {
		    p8 = 'O';
		    break;
		} else {
		    goto rcp;
		}

	    case 9:
		if (p9 == ' ') {
		    p9 = 'O';
		    break;
		} else {
		    goto rcp;
		}
	    default:
		goto rcp;
	}
	//判断输赢(电脑)
	if (p1 == 'O' && p2 == 'O' && p3 == 'O') {
	    winer = 2;
	    goto wined;
	} else if (p4 == 'O' && p5 == 'O' && p6 == 'O') {
	    winer = 2;
	    goto wined;
	} else if (p7 == 'O' && p8 == 'O' && p9 == 'O') {
	    winer = 2;
	    goto wined;
	} else if (p1 == 'O' && p4 == 'O' && p7 == 'O') {
	    winer = 2;
	    goto wined;
	} else if (p2 == 'O' && p5 == 'O' && p8 == 'O') {
	    winer = 2;
	    goto wined;
	} else if (p3 == 'O' && p6 == 'O' && p9 == 'O') {
	    winer = 2;
	    goto wined;
	} else if (p1 == 'O' && p5 == 'O' && p9 == 'O') {
	    winer = 2;
	    goto wined;
	} else if (p3 == 'O' && p5 == 'O' && p7 == 'O') {
	    winer = 2;
	    goto wined;
	}
    }
wined:
    printf("\n%c│%c│%c\n─┼─┼─\n%c│%c│%c\n─┼─┼─\n%c│%c│%c\n\n", p1, p2, p3, p4,
	   p5, p6, p7, p8, p9);
    if (winer == 1) {
	printf("YOU win\n");
    } else if (winer == 2) {
	printf("CPU win\n");
    } else
	printf("DRAW\n");

	return 0;
}
