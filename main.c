#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/kernel.h>
#include <sys/sysinfo.h>

int main(int ac, char **av)
{
	struct sysinfo *info;
	int av1_len;

	info = malloc(sizeof(struct sysinfo));
	sysinfo(info);
	if (ac == 1)
		printf("{"
			   "\"total\":\"%ldMB\","
			   "\"free\":\"%ldMB\""
			   "}",
			   info->totalram / 1024 / 1024,
			   info->freeram / 1024 / 1024);
	else if (ac == 2)
	{
		av1_len = strlen(av[1]) + 1;
		if (ac == 2 && 0 == memcmp("-b", av[1], av1_len))
			printf("{"
				   "\"total\":\"%ldB\","
				   "\"free\":\"%ldB\""
				   "}",
				   info->totalram,
				   info->freeram);
		else if (ac == 2 && 0 == memcmp("--kb", av[1], av1_len))
			printf("{"
				   "\"total\":\"%ldKB\","
				   "\"free\":\"%ldKB\""
				   "}",
				   info->totalram / 1024,
				   info->freeram / 1024);
		else if (ac == 2 && 0 == memcmp("--mb", av[1], av1_len))
			printf("{"
				   "\"total\":\"%ldMB\","
				   "\"free\":\"%ldMB\""
				   "}",
				   info->totalram / 1024 / 1024,
				   info->freeram / 1024 / 1024);
		else if (ac == 2 && 0 == memcmp("--gb", av[1], av1_len))
			printf("{"
				   "\"total\":\"%ldGB\","
				   "\"free\":\"%ldGB\""
				   "}",
				   info->totalram / 1024 / 1024 / 1024,
				   info->freeram / 1024 / 1024 / 1024);
		else if (ac == 2 && 0 == memcmp("--kib", av[1], av1_len))
			printf("{"
				   "\"total\":\"%ldKiB\","
				   "\"free\":\"%ldKiB\""
				   "}",
				   info->totalram / 1000,
				   info->freeram / 1000);
		else if (ac == 2 && 0 == memcmp("--mib", av[1], av1_len))
			printf("{"
				   "\"total\":\"%ldMiB\","
				   "\"free\":\"%ldMiB\""
				   "}",
				   info->totalram / 1000 / 1000,
				   info->freeram / 1000 / 1000);
		else if (ac == 2 && 0 == memcmp("--gib", av[1], av1_len))
			printf("{"
				   "\"total\":\"%ldMiB\","
				   "\"free\":\"%ldMiB\""
				   "}",
				   info->totalram / 1000 / 1000 / 1000,
				   info->freeram / 1000 / 1000 / 1000);
		else if (ac == 2 && 0 == memcmp("--help", av[1], av1_len))
			printf("Usage: getmem [OPTION...]\n"
				   "\n"
				   "  --kb\t\tprint with KB\n"
				   "  --mb\t\tprint with MB\n"
				   "  --gb\t\tprint with GB\n"
				   "  --kib\t\tprint with KiB\n"
				   "  --mib\t\tprint with MiB\n"
				   "  --giB\t\tprint with GiB\n");
		else
			return (1);
	}
	free(info);
	return (0);
}