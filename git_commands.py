from typing import List
import subprocess
import os

def collect_files(target_type: str) -> List[str]:
    switch = {
        'staged': ['git', 'diff', '--cached', '--name-only'],
        'modified': ['git', 'diff', '--name-only'],
        'all': ['git', 'ls-files']
    }

    file_candidates = subprocess.run(switch[target_type], capture_output=True, text=True)

    collected_files = []
    for file_path in file_candidates.stdout.splitlines():
        _, extension = os.path.splitext(file_path)
        if extension in {'.cpp', '.cc', '.CC', '.c', '.hpp', '.h', '.H'}:
            collected_files.append(file_path)

    return collected_files

def stage_files(file_names: List[str]) -> None:
    for file_name in file_names:
        subprocess.run(['git', 'add', file_name])