#include "demo.h"

void openAndRead();
void creatAndWrite();

int test()
{
	char filename[128];
	sprintf(filename, "tmp");
	creatAndWrite(filename);
	openAndRead(filename);
}

void openAndRead(const char * filename)
{
	int n;
	char buf[1024];

	int fd = open(filename, O_RDONLY);

	memset(buf,0,sizeof(buf));
	while((n=read(fd, &buf, 1024))>0)
	{
		printf("%s", buf);
		memset(buf,0,sizeof(buf));
	}

	int ret=close(fd);
}

void creatAndWrite(const char * filename)
{
	char buf[1024];
	int fd = open(filename, O_WRONLY|O_CREAT|O_TRUNC, S_IRUSR|S_IWUSR);
	
	memset(buf,0,sizeof(buf));
	sprintf(buf, "I writed some thing to here!\n");
	write(fd, &buf, strlen(buf));
	close(fd);
}
