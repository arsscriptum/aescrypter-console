SRCDIR := src

.PHONY: all debug release install clean test

all:
	$(MAKE) -C $(SRCDIR) all

debug:
	$(MAKE) -C $(SRCDIR) debug

release:
	$(MAKE) -C $(SRCDIR) release

install:
	$(MAKE) -C $(SRCDIR) install

clean:
	$(MAKE) -C $(SRCDIR) clean

test:
	$(MAKE) -C $(SRCDIR) test
