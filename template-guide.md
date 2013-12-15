# Smart Create Template Guide

Smart Create allows for dynamic insertion of text into files through templates.
They have extension `.tem`.
Accompanying the template file is a JSON file that contains variables that are *not* provided by Smart Create that can be referenced in the template file.

## Templates

## Variables

### Provided by Smart Create

* `FULL_FILE_PATH`
  
  The full path to the file currently being created.
  For example, if `smc file.c` is run from inside the directory `~/project`, `FULL_FILE_PATH` would have value `~/project/file.c` (with `~` expanded).

### Custom

Custom variables are defined in JSON syntax.
Therefore, the file for them has the extension `.json`.

## Functions

### Logic Functions

* `if test true-string`
  
  Checks if argument test contains a string of length greater than 0.
  If it does, argument true-string will be inserted into the file.
  
  Examples
  ```
  #{if "t" "True test!"}
  True test!
  
  #{if "" "False test!"}
  
  ```

### File Functions

* `file-strip-extension file`
  
  Strips the file extension off of argument file.
  
  Examples
  ```
  #{file-strip-extension "file.c"}
  file
  
  #{file-strip-extension "directory/file.h"}
  directory/file
  
  #{file-strip-extension "file"}
  file
  ```

* `file-strip-directory file`
  
  Strips the directory off of argument file.
  
  Examples
  ```
  #{file-strip-directory "directory/file.c"}
  file.c
  
  #{file-strip-directory "file.h"}
  file.h
  ```
