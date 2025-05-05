CC := gcc
CFLAGS := -Og -g -Wall -Wextra -Werror -Wsuggest-attribute=format $(CFLAGS)
PREFIX ?= $(HOME)

TARGETS := chcp

all: $(TARGETS)

clean:
	$(RM) $(TARGETS)

install: $(TARGETS)
	mkdir -p $(PREFIX)/bin
	cp -p $(TARGETS) $(PREFIX)/bin

check:
