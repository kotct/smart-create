asm/%.s:
	$(CXX) -S -c -o $@ $< $(COMPILE_FLAGS)

obj/%.o: asm/%.s
	$(CXX) -c -o $@ $< $(COMPILE_FLAGS)

asm/touch.s: src/touch.c src/touch.h
asm/main.s: src/main.c src/main.h asm/touch.s
