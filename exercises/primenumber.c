/** PrimeNumber
 * 查找质数
 */

#include <stdio.h>

/* 如果是质数返回该质数，否则返回 0 */
unsigned int isPrimenumber(unsigned int pn) {
	unsigned int i;
	if(pn <2) { return 0U; }
	for( i =2; i * i <= pn; i++) {
		if(pn % i == 0) { return 0U; }
	}
	return pn;
}

/* 枚举下一个质数 */
unsigned int enumerateNext(unsigned int startParam) {
	unsigned int param = startParam;
	while(1) {
		if(isPrimenumber(param)) { return param; }
		param++;
	}
}

int main(void) {
	unsigned long s = 0UL;
	int i;
	unsigned int pn=0U;
	for( i =0; i < 10000; i++) { s += pn = enumerateNext(pn +1); }
	printf("s = %lu\n", s);
	return 0;
}
