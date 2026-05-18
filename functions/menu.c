#include <stdio.h>
#include "../headers/menu.h"
#include "../headers/execVm.h"

int menu(){
	int opt=0;
	char* disk;
	char* iso;
	do{
		puts("1 - create");
		puts("2 - execute a existed");
		puts("3 - exit");
		scanf("%d", &opt);

		switch(opt){
			case 1:
				puts("Location of disk");
				scanf("%s", disk);
				puts("");
				puts("Location of iso");
				scanf("%s", iso);
				createVM(disk, iso);
				break;
			case 2:
				puts("Location os disk");
				scanf("%s", disk);
				execVM(disk);
				break;
			case 3:
				return 0;
			default:
				puts("Invalid option");
				break;
		}
	}while(1);
}
