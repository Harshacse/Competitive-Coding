import random

def main():
	s = "1\n1000000\n"
	for i in range(10000):
		s += str(random.randrange(2,1000000))
		s += "\n"
	f = open("test.txt",'wb')
	f.write(s)

main()