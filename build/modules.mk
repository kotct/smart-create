asm/%.s:
	$(CXX) -S -c -o $@ $< $(COMPILE_FLAGS)

obj/%.o: asm/%.s
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)


asm/io.s: src/io.c src/io.h
asm/main.s: src/main.c src/main.h asm/io.s
