all: code.exe code.bin
%.exe: %.S
	$(CC) -m32 $< -no-pie -o $@
%.bin: %.o
	objcopy -S -O binary -j .text $< $@
%.o: %.S
	$(CC) -m32 -c $< -o $@

