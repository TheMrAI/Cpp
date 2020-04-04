#!/usr/bin/python3
import subprocess
import os

os.chdir('build/')
subprocess.run(args=['make', 'test'])