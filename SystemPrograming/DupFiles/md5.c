MD5Status calculateMD5(char* filePath, unsigned char** MD5)
{
	int i;
	MD5_CTX c;
	char buf[BUF_SIZE];
	ssize_t bytes;
	FILE* file;
	int fd;
	unsigned char* newMD5;

	if(!filePath)return 0;

	newMD5 = malloc(MD5_DIGEST_LENGTH+1);
	if(!newMD5)return 0;

	file = fopen(filePath, "r");
	if(!file)return 0;

	fd = fileno(file);

	MD5_Init(&c);
	bytes=read(fd, buf, BUF_SIZE);

	while(bytes > 0)
	{
		MD5_Update(&c, buf, bytes);
		bytes=read(fd, buf, BUF_SIZE);
	}

	MD5_Final(newMD5, &c);

	newMD5[MD5_DIGEST_LENGTH+1] = '\0';

	*MD5 = newMD5;
	
	fclose(file);
	return 1;
}
