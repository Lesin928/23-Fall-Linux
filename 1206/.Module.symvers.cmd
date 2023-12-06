cmd_/root/testgit/1206/Module.symvers := sed 's/\.ko$$/\.o/' /root/testgit/1206/modules.order | scripts/mod/modpost -m -a -E -o /root/testgit/1206/Module.symvers -e -i Module.symvers   -T -
