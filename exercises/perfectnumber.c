/** PerfectNumber
 * 查找完全数
 * 完全数就是一个数的因子（不包含自身）之和等于该数的的数。
 * EG: 6 = 1 +2 +3
 */

#include <stdio.h>

/* 如果是完全数返回该完全数，否则返回 0 */
unsigned int isPerfectnumber(unsigned int pn) {
	unsigned int i, j = pn, s = 1U;
	if(pn <2) { return 0U; }
	for( i =2; i < j; i++) {
		if(pn % i == 0) {
			s += i+(j = pn / i);
		}
	}
	return pn == s ? pn : 0;
}

int main(void) {
	unsigned int i;
	for(i =2; i < 10000; i++) {
		if(isPerfectnumber(i)) { printf("%u\n", i); }
	}
	return 0;
}
