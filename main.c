#include <string.h>
#include <unistd.h>
#include "headers/checkFile.h"
#include "headers/menu.h"

#define QEMU "qemu-system-x86_64"
#define DEFAULT_HW "-m 8G -smp 4 -enable-kvm -cpu host -boot d"
#define DEFAULT_NET "-net nic -net user "
#define DEFAULT_DEV "-device virtio-balloon-pci -device virtio-serial-pci -device virtio-rng-pci"

#define COMMAND DEFAULT_HW DEFAULT_NET DEFAULT_DEV

int main(int argv, char* argc[]){

	checkFile();
	if(argv != 0){
		menu();
		return 0;
	}

	char* exvm;
	strcat(exvm, COMMAND);
	execv(exvm, NULL);

	return 0;
}
