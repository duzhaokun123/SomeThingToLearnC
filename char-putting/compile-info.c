#include "compile-info.h"

char* GetCompileDate(void) {
    return __DATE__;
}

char* GetCompileTime(void) {
    return __TIME__;
}
