
test: test.c obliv-c/_build/libobliv.a
	obliv-c/bin/oblivcc -o $@ $^

obliv-c/_build/libobliv.a: obliv-c/Makefile | update-submodule
	make -C obliv-c

obliv-c/Makefile: | update-submodule
	cd obliv-c && ./configure

.PHONY: update-submodule
update-submodule:
	git submodule update --init --recursive || true
