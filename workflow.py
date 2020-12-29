#!/usr/bin/python3
import autoformat
import run_build
import run_tests
import tidy

autoformat.autoformat('modified', False)
tidy.tidy('modified', False)
run_build.execute_build('Debug')
run_tests.execute_tests('Debug')