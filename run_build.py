#!/usr/bin/python3
import subprocess
import os

subprocess.run(args=['cmake', '-S', '.', '-B', 'build/'])
os.chdir('build/')
subprocess.run(args=['make'])