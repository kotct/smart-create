$(MULTILIB_LIBRARY_FILE): $(MULTILIB_LOCATION)
	cd $(MULTILIB_LOCATION) && $(MAKE) shared-object
