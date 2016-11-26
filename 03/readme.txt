1. riscv:模拟器可执行文件
	修改makefile，增加-DDEBUG,可以得到debug模式
	main.c当中verbose变量设置为1，可以逐条打印指令信息
2. test文件夹是测试程序
	dry2,dry2reg: dhrystone测试程序
	qsort： 快速排序
	ack： ackermann函数
	test：整数加法
example：
    cd test
    ../riscv dry2