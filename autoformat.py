#!/usr/bin/python3
import subprocess
import argparse
from typing import List

import git_commands

clang_format_version = 'clang-format-10'

def format_files(file_names: List[str]) -> None:
    clang_format_command_parameters = [clang_format_version, '--style=file', '-i', 'file_name']
    for file_name in file_names:
        clang_format_command_parameters[3] = file_name
        subprocess.run(clang_format_command_parameters)

def autoformat(target_type: str, re_stage: bool) -> None:
    files = git_commands.collect_files(target_type)
    format_files(files)
    if re_stage:
        git_commands.stage_files(files)

def main(arguments: argparse.Namespace) -> int:
    autoformat(arguments.targets, arguments.stage)
    return 0

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Auto-format code, using clang-format.')
    parser.add_argument('-t', '--targets', choices=['all', 'staged', 'modified'], default='modified',
                        help='Specify the set of files to format.')
    parser.add_argument('-s', '--stage', action='store_true',
                        help='Automatically stage modified files, after formatting.')

    args = parser.parse_args()
    exit(main(args))
