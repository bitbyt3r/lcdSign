#!/usr/bin/python
import msgServ
import sys

client = msgServ.Client()
message = msgServ.Message(text=" ".join(sys.argv[1:-1]), duration=int(sys.argv[-1]))
client.sendMessage(message)
print message.text, message.duration
