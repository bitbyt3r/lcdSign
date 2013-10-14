#!/usr/bin/python
import io

TMPFS = "/run/sign"
ROWS=15
COLUMNS=112

buffer = bytearray(ROWS*COLUMNS)

with io.open(TMPFS, mode='b', buffering=0) as frameFile:
  

