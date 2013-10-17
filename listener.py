#!/usr/bin/python
import msgServ
import time
import traceback
import sys

try:
  server = msgServ.Server()
  sys.exitfunc = server.stop
  while True:
    messages = server.getMessages()
    for i in messages:
      if not i.startTime:
        i.start()
      print i.text
    time.sleep(1)
except:
  server.stop()
  print traceback.format_exc()
