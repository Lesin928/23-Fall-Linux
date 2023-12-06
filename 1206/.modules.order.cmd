cmd_/root/testgit/1206/modules.order := {   echo /root/testgit/1206/hello.ko; :; } | awk '!x[$$0]++' - > /root/testgit/1206/modules.order
