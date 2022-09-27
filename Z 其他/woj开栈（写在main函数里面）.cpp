int size=40<<20;//40M
__asm__ ("movq %0,%%rsp\n"::"r"((char*)malloc(size)+size)); 

exit(0);
