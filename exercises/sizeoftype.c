/* sizeof(type)
 * 获取类型大小
 */

#include <stdio.h>

int main(void) {
	printf("int = %lu\n", sizeof(int));
	printf("short = %lu\n", sizeof(short));
	printf("long = %lu\n", sizeof(long));
	printf("long long = %lu\n", sizeof(long long));
	return 0;
}

/** C 语言整数类型关键字： int
 * 修饰长短关键字： short/long/long long
 * 是否有符号位： signed/unsigned
 * int 是基本整形，其长度对应机器字长。
 * long int 或 long ≥ int， 并且至少是 32位。
 * short int 或 short ≤ int， 至少是16位。
 * C99标准提供了long long 类型， long long ≥ int， 至少是 64 位。
 * 至于各个类型具体的长度因为编译器和机器不同而不同。
 * 因此可以使用关键字 sizeof 获取其长度。
 */
