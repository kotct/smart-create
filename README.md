Smart Create
============

**Note!**
The description of Smart Create below is what will be the description when the program is done.
The program is not currently done, and therefore the description is not completely true.

Smart Create is a command-line utility for creating files and modifying the dates of files, like GNU's touch.
Where it is special, however, is that it will automatically insert text based on the type of file that is present.
For example, if you are making a C header, you probably want a header guard.
If you call `smc file.h`, a header guard will automatically be included with the new file.
The following will be put into your file with the default configuration.

```c
#ifndef FILE_H
#define FILE_H



#endif
```

There are templates per file type, and those templates can be customized.
Therefore, one can customize the intelligence to just as they want it.

One can also use the system to add license stubs and author stubs.

Aliasing
--------

One can alias the touch command to Smart Create by calling `alias touch=smc` in their `.bashrc` file.
This is suggested, as Smart Create provides all the functionality of touch and more.

Contributing
------------

Contributions are very welcome, especially for making templates for lesser-known languages.
We do not know all of the languages in existence, so we can not make templates for all of them.
Some guidelines, which are below, must be followed in pull requests.
They are primarily written for the owners of the repository, however.

* Do not push directly to `master`; make branches and merge instead.
  * An exception to this rule would be fixing merge conflicts after a merge.
* Merge the created branch into `master` when the feature/bug-fix is thought to be done and **not before**.
Do not merge after each commit.
* After merging into `master`,
  * consider making a new release.
  * delete the branch if you do not think any new work will be done in it.
    * If the branch is for a feature and the feature is done, delete it; a different branch can be used for bug fixes.

Following these guidelines, let's pretend there was a bug that you forked to fix.
You would first make a new branch besides `master` to do your work.
Then you would do your work, and submit a pull request from your work branch.
We would then review and hopefully accept.
