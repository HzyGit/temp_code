.PHONY: all clean tags
obj-m:=create_proc.o
all: read_proc
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	-rm read_proc
	-rm *.o
	-rm tags
read_proc: read_proc.o
read_proc.o: create_proc.h

tags:
	ctags -R --c++-kinds=+p --extra=+q --fields=+aS .
