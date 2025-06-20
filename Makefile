CC = gcc
CFLAGS = -g
TARGETS = end_of_time hello_segments stack_analyzer bss_test

all: $(TARGETS)

end_of_time: src/end_of_time.c
	$(CC) $(CFLAGS) $< -o $@
	$(CC) $(CFLAGS) -m32 $< -o $@_32

hello_segments: src/hello_segments.c
	$(CC) $(CFLAGS) $< -o $@
	$(CC) $(CFLAGS) $< -DARR -o $@_v2
	$(CC) $(CFLAGS) $< -DARR_INIT -o $@_v3
	$(CC) $(CFLAGS) $< -DLOCAL_ARR -o $@_v4
	$(CC) $(CFLAGS) -O0 $< -o $@_O0
	$(CC) $(CFLAGS) -O2 $< -o $@_O2

stack_analyzer: src/stack_analyzer.c
	$(CC) $(CFLAGS) $< -o $@

bss_test: src/bss_test.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(TARGETS) *_32 *_v[234] *_O[02]
