//简单计算器的c实现
//版本 7.0
//原理:
//用 if 判断输入符号
// for 无脑循环
//
//更新日志
//
// 7.0 number0 ,number1 类型改回整数
// 6.0 number0 ,number1 类型改为浮点数
// 5.0 if-else --> switch-case
// 4.0 if --> else if
// 3.0 a --> xun2huan2ci4shu4
// 2.0 在 symbol 不为 1-6 时反馈
// 1.0 初次建造
#include <stdio.h>

int main(void) {
    int number0, number1;
    int symbol = 6, xun2huan2ci4shu4 = 2;

    printf("1:+ 加法\n2:- 减法\n3:* 乘法\n4:/ 除法\n5:%% 取余\n6:= 结束\n");
    printf("输入第1个数\n");
    scanf("%d", &number0);
    
    printf("输入符号代码(空格)第%d个数\n", xun2huan2ci4shu4);
    scanf("%d %d", &symbol, &number1);

    // while循环
    while (1) {
    xun2huan2ci4shu4 = xun2huan2ci4shu4 + 1;

    //新的 switch-case 算法:
    switch (symbol) {
        case 1:
        number0 = number0 + number1;
        break;
        
        case 2:
        number0 = number0 - number1;
        break;
     
        case 3:
        number0 = number0 * number0;
        break;
     
        case 4:
        number0 = number0 / number1;
        break;
     
        case 5:
        number0 = number0 % number1;
        break;
     
        case 6:
        printf("%d\n", number0);
        return 0;
        break;
     
        default:
        printf("无效的符号代码 %d\n", symbol);
        symbol = 0;
        break;
    }

    {
        //旧的 if-else 算法:
        //
        // if (symbol == 1)number0 = number0 + number1;
        // else if (symbol == 2)number0 = number0 - number1;
        // else if (symbol == 3)number0 = number0 * number1;
        // else if (symbol == 4)number0 = number0 / number1;
        // else if (symbol == 5)number0 = number0 % number1;
        // else if (symbol == 6)
        //{
        //  printf ("%d\n",number0);
        //
        //  return 0;
        //}
        // else
        //{
        //  printf ("无效的符号代码 %d\n",symbol);
        //
        //  symbol = 0;
        //}
    }

    printf("%d\n", number0);
    printf("输入符号代码(空格)第%d个数\n", xun2huan2ci4shu4);
    scanf("%d %d", &symbol, &number1);
    }

    return 0;  //虽然理论上不可能执行，但习惯的加上了(笑)
}
