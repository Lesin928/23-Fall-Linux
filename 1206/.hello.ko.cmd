cmd_/root/testgit/1206/hello.ko := ld -r  -m elf_x86_64 -z noexecstack   --build-id=sha1  -T scripts/module.lds -o /root/testgit/1206/hello.ko /root/testgit/1206/hello.o /root/testgit/1206/hello.mod.o;  true