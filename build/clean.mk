clean:
	rm -f $(OBJECTS) $(ASSEMBLY) $(PROGRAM_FILE)
	cd $(MULTILIB_LOCATION) && $(MAKE) clean

