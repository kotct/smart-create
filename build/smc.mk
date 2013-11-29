$(PROGRAM_FILE): $(OBJECTS) Makefile $(wildcard build/*.mk)
	$(CXX) -o $(PROGRAM_FILE) $(OBJECTS) $(LINK_FLAGS)
