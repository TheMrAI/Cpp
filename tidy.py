#!/usr/bin/python3
import subprocess
import argparse
from typing import List
import git_commands

clang_tidy_version = 'clang-tidy-10'

def tidy_files(file_names: List[str]) -> None:
    clang_tidy_command_parameters = [clang_tidy_version, '-p=build/Debug', 'file_name']
    for file_name in file_names:
        clang_tidy_command_parameters[2] = file_name
        subprocess.run(clang_tidy_command_parameters)

def tidy(target_type: str, re_stage: bool) -> None:
    files = git_commands.collect_files(target_type)
    files = [file_name for file_name in files if 'test' not in file_name and 'benchmark' not in file_name]
    tidy_files(files)
    if re_stage:
        git_commands.stage_files(files)

def main(arguments: argparse.Namespace) -> int:
    tidy(arguments.targets, arguments.stage)
    return 0

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Auto-format code, using clang-format.')
    parser.add_argument('-t', '--targets', choices=['all', 'staged', 'modified'], default='modified',
                        help='Specify the set of files to format.')
    parser.add_argument('-s', '--stage', action='store_true',
                        help='Automatically stage modified files, after formatting.')

    args = parser.parse_args()
    exit(main(args))
