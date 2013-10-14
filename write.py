#!/usr/bin/python
with open("/run/signdata", "wb") as binaryFile:
  for i in xrange(15):
    for x in xrange(112):
      binaryFile.write(chr(0b0 if i%2 else 0b1))
