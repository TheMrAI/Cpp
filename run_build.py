#!/usr/bin/python3
import subprocess
import os
import argparse
import pathlib

FILE_PATH = pathlib.Path(__file__).parent.absolute()

def execute_build(build_type):
    build_directory = 'build/{0}'.format(build_type)
    os.chdir(FILE_PATH)
    subprocess.run(args=['cmake', '-S', '.', '-B', build_directory, '-DCMAKE_BUILD_TYPE={0}'.format(build_type)])
    working_directory = os.getcwd()
    os.chdir(build_directory)
    subprocess.run(args=['make'.format(build_directory)])
    os.chdir(working_directory)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Build project set.')
    parser.add_argument('-r', '--release', help='Release build', action='store_true')
    parser.add_argument('-d', '--debug', help='Debug build.', action='store_true')

    arguments = parser.parse_args()
    if arguments.release:
        execute_build('Release')
    if arguments.debug:
        execute_build('Debug')
