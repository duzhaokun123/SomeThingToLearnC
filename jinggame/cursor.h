#ifndef __CURSOR_H__
#define __CURSOR_H__

//光标控制
#define CURSOR_off "\033[?25l"
#define CURSOR_on "\033[?25h"
#define CURSOR_set "\033[%d;%dH"
#define CURSOR_up "\033[%dA"
#define CURSOR_down "\033[%dB"
#define CURSOR_right "\033[%dC"
#define CURSOR_left "\033[%dD"
#define CURSOR_save "\033[s"
#define CURSOR_back "\033[u"

#endif
