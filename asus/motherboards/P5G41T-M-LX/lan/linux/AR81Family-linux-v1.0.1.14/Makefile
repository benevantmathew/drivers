obj-m += src/

Version=1.0.1.7
ModName=atl1e

TAR=tar
RM=rm -fr
RPMBUILD=rpmbuild
MKDIR=mkdir
CP= cp -a
CD=cd
DKMS=dkms
SourceDir=$(ModName)-$(Version)
SourceTar=/usr/src/redhat/SOURCES/$(ModName)-$(Version).tar.gz

all:
	$(MAKE) -C ./src 

install:
	$(MAKE) -C ./src/ install

clean:
	$(MAKE) -C ./src/ clean
	$(RM) ./src/tags ./src/cscope.out ./src/cscope.*.out
rpm:
	dos2unix atl1e.spec
	$(MAKE) -C ./src/ clean
	$(RM) /tmp/$(SourceDir)
	$(MKDIR) /tmp/$(SourceDir)
	$(CP) ./* /tmp/$(SourceDir)
	tmppwd=`pwd`
	$(CD) /tmp/;echo `pwd`; $(TAR) -czvf $(SourceTar) $(SourceDir)
	$(CD) $(tmppwd)
	$(RPMBUILD) -ba $(ModName).spec

dkms:
	$(MAKE) -C ./src/ clean
	#$(DKMS) remove -m $(ModName) -v $(Version) --all
	$(RM) /usr/src/$(SourceDir)
	$(MKDIR) /usr/src/$(SourceDir)
	$(CP) ./* /usr/src/$(SourceDir)
	$(DKMS) add -m $(ModName) -v $(Version)
	$(DKMS) build -m $(ModName) -v $(Version)
	$(DKMS) mkdeb -m $(ModName) -v $(Version)


