
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(int argc, char *argv[])
{
	if (argc <= 1) {
		printf(1, "Masukan komen sesuai [touch nama_file1 nama_file2 ...]\n");
	}

	int i, count = 0;
	for (i = 1; i < argc; i++) {		
		int fd;
		if ((fd = open(argv[i], O_RDONLY)) < 0) {

			fd = open(argv[i], O_CREATE|O_RDONLY);
			count++;
		}
		close(fd);
	}

	printf(1, "%d file sudah dibuat, %d file dilewati.\n", count, argc - 1 - count);

	exit();
}
