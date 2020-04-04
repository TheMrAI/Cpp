#!/usr/bin/python3.8
import subprocess
import os

git_diff = subprocess.run(['git', 'diff', '--cached', '--name-only'], capture_output=True, text=True)
clang_format_command_parameters = ['clang-format', '--style=file', '-i', 'file_name']

for file_path in git_diff.stdout.splitlines():
    _, extension = os.path.splitext(file_path)
    if extension not in {'.cpp', '.cc', '.CC', '.c', '.hpp', '.h', '.H'}:
        continue
    clang_format_command_parameters[3] = file_path
    subprocess.run(clang_format_command_parameters)
    subprocess.run(['git', 'add', file_path])
