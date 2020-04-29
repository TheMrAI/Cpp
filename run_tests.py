#!/usr/bin/python3
import subprocess
import argparse
import os

def execute_tests(build_type):
    build_directory = 'build/{0}'.format(build_type)
    working_directory = os.getcwd()
    os.chdir(build_directory)
    subprocess.run(args=['make', 'test'])
    os.chdir(working_directory)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Run tests.')
    parser.add_argument('-r', '--release', help='Tests for Release build', action='store_true')
    parser.add_argument('-d', '--debug', help='Tests for Debug build.', action='store_true')

    arguments = parser.parse_args()
    if arguments.release:
        execute_tests('Release')
    if arguments.debug:
        execute_tests('Debug')