#!/usr/bin/python3
import subprocess
import os
import argparse
from typing import List

clang_tidy_version = 'clang-tidy-10'

def collect_files(target_type: str) -> List[str]:
    switch = {
        'staged': ['git', 'diff', '--cached', '--name-only'],
        'modified': ['git', 'diff', '--name-only'],
        'all': ['git', 'ls-files']
    }

    file_candidates = subprocess.run(switch[target_type], capture_output=True, text=True)

    files_to_format = []
    for file_path in file_candidates.stdout.splitlines():
        file_name, extension = os.path.splitext(file_path)
        if extension in {'.cpp', '.cc', '.CC', '.c', '.hpp', '.h', '.H'} and 'test' not in file_name \
                and 'benchmark' not in file_name:
            files_to_format.append(file_path)

    return files_to_format


def tidy_files(file_names: List[str]) -> None:
    clang_tidy_command_parameters = [clang_tidy_version, '-p=build/Debug', 'file_name']
    for file_name in file_names:
        clang_tidy_command_parameters[2] = file_name
        subprocess.run(clang_tidy_command_parameters)


def stage_files(file_names: List[str]) -> None:
    for file_name in file_names:
        subprocess.run(['git', 'add', file_name])

def tidy(target_type: str, re_stage: bool) -> None:
    files = collect_files(target_type)
    tidy_files(files)
    if re_stage:
        stage_files(files)

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
