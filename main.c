

#include <stdio.h>

void help()
{
	printf("\n USAGE:  rm [Option] [File or Folder]\n");
	printf(" Move to ~/.MY_RM_TRASH\n");
	printf("\n\t-log           Show the log of deleted files\n");
	printf("\t-trash         Show the trash content (not the trash of the system)\n");
	printf("\t-clean         Clean the trash (delete with the rm of the system\n");
	printf("\t--help         Display this help and exit\n");
	printf("\n\n AUTHOR           Abdelhaq EL AMRAOUI      Jan 19, 2021 21:37\n\n");
}

int main(int argc, char const *argv[])
{
	char *my_rm_trash = "~/.MY_RM_TRASH";
	char *my_rm_log = "~/.MY_RM_TRASH/.log";
	char cmd[80];

	switch(argv[1])
	{
		case "-log" :
			sprintf(cmd, "[ -f %s ] && cat %s | more", &my_rm_log, &my_rm_log);
			system(cmd);
			exit(0);		
		break;

		case "-trash" :
			sprintf(cmd, "ls -l %s| more", &my_rm_trash);
			system(cmd);
			exit(0);
		break;

		case "-clean" :
			fprintf(stderr, "ATTENTION............................./!\ \n");
			sprintf(cmd, "sudo rm -I -r %s", &my_rm_trash);
			system(cmd);
			exit(0);
		break;

		case "--help" :
			help();
			exit(0);
		break;

		default :
		if(argv[1] == '-')
		{
			fprintf(stdout,"Try option --help for usage\n");
			exit(0);
		}
		else
		{
			int i;
			strcpy(cmd, "mv -f ");
			for (i = 1; i < argc; ++i)
			{
				strcat(cmd, argv[i]);
				strcat(cmd, " ");
			}
			strcat(cmd, my_rm_trash);
			system(cmd);
			strcat(cmd, "");
			system("[ $? -eq 0 ] && echo `date` : $@ >> $LOG");
			exit(0);
		}

	}


	return 0;
}