CXX      := g++
CXXFLAGS := -std=c++17 -Wall
LDFLAGS  :=

# ---------------------------------------------------------------------------
# Platform  (pass PLATFORM=WIN64 for cross-compile; default is LINUX)
# ---------------------------------------------------------------------------
ifeq ($(PLATFORM),WIN64)
  CXXFLAGS += -DWIN64
  TARGET   := aescrypter.exe
else
  CXXFLAGS += -DLINUX
  TARGET   := aescrypter
endif

# ---------------------------------------------------------------------------
# Build type  (make debug | make release)
# ---------------------------------------------------------------------------
BUILD ?= release

ifeq ($(BUILD),debug)
  CXXFLAGS += -g -O0 -D_DEBUG
  OBJDIR   := ../build/debug/obj
  BINDIR   := ../build/debug
else
  CXXFLAGS += -O2 -DNDEBUG
  OBJDIR   := ../build/release/obj
  BINDIR   := ../build/release
endif

# ---------------------------------------------------------------------------
# Sources / objects
# ---------------------------------------------------------------------------
ifeq ($(PLATFORM),WIN64)
  # opts.cpp defines custom getopt; on Linux these symbols clash with libc
  SRCS := main.cpp aescrypt.cpp aes.cpp sha256.cpp \
          log.cpp password.cpp opts.cpp terminal_formatting.cpp
else
  SRCS := main.cpp aescrypt.cpp aes.cpp sha256.cpp \
          log.cpp password.cpp terminal_formatting.cpp
endif
OBJS := $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))

INSTALL_PREFIX ?= /usr/local

# ---------------------------------------------------------------------------
# Targets
# ---------------------------------------------------------------------------
.PHONY: all debug release install clean test

all: $(BINDIR)/$(TARGET)

debug:
	$(MAKE) BUILD=debug all

release:
	$(MAKE) BUILD=release all

$(BINDIR)/$(TARGET): $(OBJS) | $(BINDIR)
	$(CXX) $(LDFLAGS) -o $@ $^
	@echo "Built: $@"

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(BINDIR) $(OBJDIR):
	mkdir -p $@

install: all
	install -Dm755 $(BINDIR)/$(TARGET) $(DESTDIR)$(INSTALL_PREFIX)/bin/$(TARGET)
	@echo "Installed: $(DESTDIR)$(INSTALL_PREFIX)/bin/$(TARGET)"

clean:
	rm -rf ../build

# ---------------------------------------------------------------------------
# Smoke test: encrypt then decrypt a file and diff the result
# ---------------------------------------------------------------------------
test: all
	@echo "=== AesCrypter smoke tests ==="
	@TMPDIR=$$(mktemp -d) && \
	 echo "Hello World AES test 1234567890" > $$TMPDIR/input.txt && \
	 $(BINDIR)/$(TARGET) --encrypt $$TMPDIR/input.txt \
	     --password testpass123 --output $$TMPDIR/enc.aes && \
	 $(BINDIR)/$(TARGET) --decrypt $$TMPDIR/enc.aes \
	     --password testpass123 --output $$TMPDIR/dec.txt && \
	 diff $$TMPDIR/input.txt $$TMPDIR/dec.txt && \
	 echo "PASS: encrypt/decrypt round-trip" && \
	 rm -rf $$TMPDIR || { echo "FAIL"; rm -rf $$TMPDIR; exit 1; }
