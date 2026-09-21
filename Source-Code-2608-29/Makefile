CC=i686-elf-gcc
TARGET=WarblerOS

C_FILES=./libc/string/memcmp.c \
	./libc/string/memset.c \
	./libc/string/strcat.c \
	./libc/string/strchr.c \
	./libc/string/strcmp.c \
	./libc/string/strcpy.c \
	./libc/string/strlen.c \
	./libc/string/strncmp.c \
	./libc/string/strstr.c \
	./libc/string/strutil.c \
	./libc/string/ctos.c \
	./kernel/tty.c \
	./kernel/io.c \
	./kernel.c

OBJS=$(C_FILES:.c=.o)

.PHONY: all compile clean finale

all: finale

compile: $(TARGET)

%.o: %.c
	$(CC) -c $< -o $@ -ffreestanding -fno-exceptions -m32

$(TARGET): $(OBJS)
	nasm -f elf start.asm -o start.o
	$(CC) -m32 -nostdlib -nodefaultlibs -lgcc start.o $(OBJS) -T linker.ld -o $(TARGET)

finale: $(TARGET)
	cp $(TARGET) ./iso/boot/$(TARGET)
	i686-elf-grub-mkrescue iso --output=$(TARGET).iso

clean:
	rm -f $(TARGET) $(TARGET).iso start.o
	find . -name \*.o -type f -delete
