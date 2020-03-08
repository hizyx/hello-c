/** Endian
 * 判断处理器是大端序（Big Endian）还是小端序（little Endian）。
 */

#include <stdio.h>

/* 如果是 BigEndian 返回非 0 值 */
int isBigEndian() {
	int n = 1;
	return (*(char *)&n) ? 0 : 1;
}

int main(void) {
	int i, n = 1;
	char *p = (char *)&n;
	printf("The following is the structure of \"1\" in memory.\n");
	printf("Unit\t value\n");
	for(i = 0; i < sizeof(n); i++) {
		printf("%d\t %#X\t\n", i, *(p +i));
	}
	if(isBigEndian()) {
		printf("Big Endian\n");
	}
	else {
		printf("Little Endian\n");
	}
	return 0;
}
/** 什么是字节序
 * 一个数 0X0011 保存到内存中有两种情况：
 * 第一个字节是 0X00， 第二个字节是 0X11， 这叫做大端序；
 * 第一个字节是 0X11， 第二个字节是 0X00， 这叫做小端序。
 * 网络传输一律使用大端序。 因为最常见的处理器（如 X86-64 指令集处理器） 是小端序，所以面向网络底层编程需要考虑字节序问题。
 * 大端序与人们的阅读习惯相符合， 小端序与计算机硬件处理从小到大的顺序相同。 因此，才有了字节序的不同。
 */
