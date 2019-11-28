# this is a minimal makefile for demo purposes, keep it that way...
obj-m:=qm.o
qm-objs:=qMessage.o
V?=0
KDIR?=/lib/modules/$(shell uname -r)/build
# in an embedded system:
#KDIR:=[where the system maker gave me kernel headers+makefile or the kernel itself which has a makefile]
#ARCH:=arm
#CROSS_COMPILE:=[path+common prefix to where the toolchain is]
# You could also use W=2 and W=3 for more warnings but most kernel headers
# fail those...
W?=1

.PHONY: all
all: modules putget

.PHONY: modules
modules:
	$(MAKE) -C $(KDIR) M=$(CURDIR) V=$(V) W=$(W) modules
.PHONY: clean
clean:
	$(MAKE) -C $(KDIR) M=$(CURDIR) V=$(V) clean
	rm -f *.stamp
	rm -f putget

putget: putget.c
	gcc -Wall -Werror -pedantic -pthread -o $@ $<

.PHONY: test_insrmmod
	VARIABLE := number
Q:=@
test_insrmmod:
	$(Q)for number in $$(seq 1 10);\
	do \
	sudo insmod qm.ko;\
	sleep 0.1;\
	(number=number+1);\
	sudo rmmod qm;\
	echo $$number;\
	done

.PHONY: test_all
test_all: insrmmod insmod putget

.PHONY: insmod
insmod: 
	sudo insmod qm.ko
	sleep 1
	sudo chmod 666 /dev/qm*

.PHONY: rmmod
rmmod: 
	sudo rmmod qm
	
.PHONY: remod
remod: rmmod insmod
