asm/%.s:
	$(CXX) -S -c -o $@ $< $(COMPILE_FLAGS)

obj/%.o: asm/%.s
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

asm/main.s: src/main.c src/main.h
