$(PROGRAM_FILE): $(OBJECTS) Makefile $(wildcard build/*.mk) $(MULTILIB_LIBRARY_FILE)
	$(CXX) -o $(PROGRAM_FILE) $(OBJECTS) $(LINK_FLAGS)
