/* 计量某命令行执行所需时间 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* 把命令行参数连接起来复制到缓冲区。如果 buffer 传入 NULL， 那么返回 buffer 需要的的大小。 */
size_t joinCommandLine(int argc, char *argv[], char *buffer, int length)
{
	size_t offset = 0, len;
	int i;
	if(buffer)
	{
		for(i = 1; i < argc && offset < length; i++)
		{
			/* 把命令行参数填入 buffer */
			len = strlen(argv[i]);
			strncpy((buffer +offset), argv[i], len < length -offset ? len: length -offset);

			/* 填入空格符 */
			if(length > offset +len) { *(buffer +offset +len) = ' '; }

			/* 命令行参数和空格符的长度 */
			offset += len +1;
		}
		/* 防止缓冲区溢出攻击 */
		*(buffer +offset) = '\0';
		return offset;
	}
	else
	{
		for(i = 1; i < argc; i++)
		{
			/* 命令行参数和空格符的长度 */
			offset += strlen(argv[i]) +1;
		}
		return offset;
	}
}

int main(int argc, char *argv[])
{
	if(1 == argc)
	{
		printf("usage: stopwatch <command>\n");
		return 0;
	}
	int result;
	clock_t startClock, finishClock, elapsed;
	size_t len = joinCommandLine(argc, argv, NULL, 0);
	char *commandLineBuffer = malloc(sizeof(char) * len);
	joinCommandLine(argc, argv, commandLineBuffer, len);
	printf("Run: %s\n", commandLineBuffer);
	startClock = clock();
	result = system(commandLineBuffer);
	finishClock = clock();
	elapsed = finishClock -startClock;
	printf("Elapsed: %ld.%ld Seconds.\n", elapsed / CLOCKS_PER_SEC, elapsed % CLOCKS_PER_SEC);
	printf("Exit status code: %d .\n", result);
	return 0;
}
