## draw
### 用法

    ./draw

### 内部命令

`r`刷新

`q`退出

`:`进入命令模式

#### 命令模式

`color [color]`设置颜色, 颜色由终端决定

`point [y] [x]`在指定位置画点

`file [file1] [file2] ...`执行脚本文件

`info error [string]`发送`错误型`信息

`info warning [string]`发送`警告型`信息

`info info [string]`发送`信息型`信息

`info common [string]`发送`普通型`信息

`exit`退出

`null`什么也不做

### 脚本

脚本应为50行的`mp2k`格式文件, 但安全起见应多出几行以免发生非法内存访问
导致程序崩溃

执行顺序由上至下, 每行一个命令, 命令同[命令模式](#命令模式) 的命令

对于多出的行, 应用`null`填充

## TODO

* 插件支持

* 工作路径

* 日志系统
