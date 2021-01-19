

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{

	char cmd[100];

	system("! [ -d ~/.MY_RM_TRASH/.log ] && mkdir ~/.MY_RM_TRASH/.log");

	switch(argv[1])
	{
		case "-log" :
			strcpy(cmd, "[ -f ~/.MY_RM_TRASH/.log ] && cat ~/.MY_RM_TRASH/.log | more");
			return system(cmd);	
		break;

		case "-trash" :
			strcpy(cmd, "ls -l ~/.MY_RM_TRASH | more");
			return system(cmd);
		break;

		case "-clean" :
			fprintf(stderr, "ATTENTION............................./!\\ \n");
			strcpy(cmd, "sudo rm -I -r ~/.MY_RM_TRASH");
			return system(cmd);
		break;

		case "--help" :
			fprintf(stdout, "\n USAGE:  rm [Option] [File or Folder]\n");
			fprintf(stdout, " Move to ~/.MY_RM_TRASH\n");
			fprintf(stdout, "\n\t-log           Show the log of deleted files\n");
			fprintf(stdout, "\t-trash         Show the trash content (not the trash of the system)\n");
			fprintf(stdout, "\t-clean         Clean the trash (delete with the rm of the system\n");
			fprintf(stdout, "\t--help         Display this help and exit\n");
			fprintf(stdout, "\n\n AUTHOR           Abdelhaq EL AMRAOUI      Jan 19, 2021 21:37\n\n");
			exit(0);
		break;

		default :
		if(**(argv+1) == '-')
		{
			fprintf(stdout,"Try option --help for usage\n");
			exit(0);
		}
		else
		{
			int i;
			for (i = 1; i < argc; ++i)
			{
				sprintf(cmd, "mv -f %s", argv[i]);
				if(!system(cmd))
				{
					sprintf(cmd, "echo `date` : %s >> ~/.MY_RM_TRASH/.log", argv[i]);
					system(cmd);
				}
			}

			exit(0);
		}
	}

	return 0;
}