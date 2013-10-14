#!/usr/bin/python
from sprites import charset

def main():
  msg = getMessage()
  frame = renderMessage(msg)
  while True:
    draw(frame)

def getMessage():
  string = raw_input("Msg:")
  
