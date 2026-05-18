#include <stdio.h>
#include <string.h>
#include "../headers/checkFile.h"
#include "../headers/struct.h"

int createFile(){
	int size=0;
	values v={NULL, NULL};
	FILE *fw = fopen("vars.config", "w");
	if (!fw){
	puts("Error open file");
	return 1;
	};

		puts("some configs are necessary");
	while(1){
		puts("How much memory RAM for VM: [default] [?]");
		scanf("%3s", v.memv);
		size = strlen(v.memv);
		if ( strcmp(v.memv, " ")){
			fprintf(fw, "512M");
			continue;
		};
		if ( !(strcmp(v.memv[size], "G")) || !(strcmp(v.memv[size], "M"))){
			fprintf(stderr, "Invalid option: %s ", v.memv);
			continue;
		};
		if ( strcmp(v.memv, "?")){
			puts("The default valus is 4G");
			puts("The option need end with upper G or upper M");
			continue;
		};
		break;
	};

	while(1){
		puts("How much cpu cores for VM: [default] [?]");
		scanf("%1s", v.cpuc);
		if (strcmp(v.cpuc, " ")){
			fprintf(fw, "1");
			continue;
		};
		if (strcmp(v.cpuc, "?")){
			fprintf(stderr, "Invalid option: %s ", v.cpuc);
			continue;
		};
		break;
	};

		fprintf(fw, "-smp %s -m %s", v.cpuc, v.memv );
	return 0;
}

int checkFile(){
	FILE *fo = fopen("vars.config", "r");
	if (!fo){
		createFile();
	}
	return 0;
}
