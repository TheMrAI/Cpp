# Cpp tinkering

The goal of this repository is to practice the use of Cpp.

Cpp is a ridiculously complicated language with decades of added
complexities built up on top of it. It is hard to know which feature of
the language should be used in certain situations and how. For the
unassuming programmer, it becomes rather comforting to assume that he/she
knows how to implement a certain functionality until the moment that
assumption is tested. To rectify my own inadequacies and to give an honest
try in understanding what happens and why, this repository was created.

## Naming convention / Coding style

In naming variables and structuring the code I have made best efforts to follow [Google's style guide](https://google.github.io/styleguide/cppguide.html). The main motivator behind this is that I tend to like it, and it is
written down. Following it, thus becomes convenient.

## Formatting

There is no proper way to format code. People have learned to format it
this or that way and they simply don't like how it is. In my opinion
formatting is a ternary question and the only thing that really matters is
that it is kept consistent.
This repository is 100% formatted by [clang-format](https://clang.llvm.org/docs/ClangFormat.html), using a configuration based on the built in
Google style.

Auto formatting can be executed by:
> autoformat.py

Which will auto format all staged files and re-stage them after the
modification. This makes it a convenient candidate for being used as a
git pre-commit hook.

## Extra checks

To make sure as few errors are made as possible [clang-tidy](https://clang.llvm.org/extra/clang-tidy/) is also employed. Almost all checks are
enabled, that are not specific to some major project. This makes tidy a
little stringy on how things can look, but most often than not it turns out
the suggestions it makes are quite alright.

It is on my list of things to do, to enable [ASAN](https://github.com/google/sanitizers/wiki/AddressSanitizer) build checks, but I seem
to be reluctant in actually doing the job.

## Structure

The repository is divided into 3 segments:

- [Containers](containers/Containers.md)
- [Algorithms](algorithms/Algorithms.md)
- [Cpp lab exercises](cpp_lab/Cpp_lab.md)

## Building the project set

[CMake](https://cmake.org/) is used as the build system of choice.
The only dependency at the moment is [GoogleTest](https://github.com/google/googletest). Which is expected to be place in a repository next to
this one.
I.e.:

``` bash
/this_repository/
/googletest/
```

I wanted to avoid polluting the repository itself with the dependencies.
This way the user is forced to download the correct repositories
and putting them in the expected places. On the other hand the repository
only holds what the repository is supposed to. Until there are better ways
to add external dependencies to the project this way will be followed.
There are some present at the moment, but haven't had the time to
investigate them yet.

After setup the building is simply done by running:
> run_build.py

Tests then can be executed by running:
> run_tests.py
