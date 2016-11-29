import string
import random

def main():
	t = 10000
	s = "1\n"
	for i in range(t):
		s+="aaa"
	s += "\n"
	for i in range(t):
		s+="aa"
	f = open("in4.txt",'wb')
	f.write(s)
	f.close()

def id_generator(size, chars=string.ascii_lowercase):
	return ''.join(random.choice(chars) for _ in range(size))

def new():
	t = 1
	s = str(t)
	s += "\n"
	for i in range(t):
		s += id_generator(8000)
		s += "\n"
		s += id_generator(8)
		s += "\n"
	f = open("in4.txt",'wb')
	f.write(s)
	f.close()
main()
#new()
