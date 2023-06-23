## Debug
`2023.6.24`  
- 该框架有一个malloc语句始终无法运行，写入message，name等数据时正常运行，且在vscode的debug模式可以运行，无法在终端中运行(`ouput/main`)，debug时该函数申请的内存末端在调试台显示"`incomplete sequence`"，后来将`(char *)malloc(sizeof(pString))`修改成`malloc(strlen(pString) + 1)`后解决该问题，估测是sizeof返回的大小不完整，导致malloc错误
- 框架在vscode运行良好，直接运行生成的exe文件则会出现几种奇怪的情况，一是终端闪出来停滞了几秒随后结束进程，二是进程结束提示并返回错误代码`3221226356`，三是终端消失后进程并未结束，通过win任务管理器查看该程序CPU占用近15%，经过数小时的debug后发现打印`\033[2J`来实现清屏会导致终端宕机,用windows.h中的`system("cls")`即可正常运行